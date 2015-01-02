#include "comport.h"

/*
Much of the implementation of this class is based on information from
http://wiki.osdev.org/Serial_Ports
*/

/* The address in memory where the Base I/O port for COM1 is specified by the BIOS */
#define BIOS_DATA_AREA_COM1_ADDRESS  0x0400

/*
The register offsets from the base I/O port
*/
static const uint8_t REG_DLAB_BAUD_DIVISOR_LSB = 0;
static const uint8_t REG_DLAB_BAUD_DIVISOR_MSB = 1;
static const uint8_t REG_DATA = 0;
static const uint8_t REG_INTERRUPT_ENABLE = 1;
static const uint8_t REG_INTERRUPT_ID = 2;
static const uint8_t REG_LINE_CONTROL = 3;
static const uint8_t REG_MODEM_CONTROL = 4;
static const uint8_t REG_LINE_STATUS = 5;
static const uint8_t REG_MODEM_STATUS = 6;
static const uint8_t REG_SCRATCH = 7;

static uint16_t findBaseIoPort() {
    return *(reinterpret_cast<uint16_t*>(BIOS_DATA_AREA_COM1_ADDRESS));
}

static void writeToPort(uint16_t port, char value) {
    asm(
        "mov dx, %0\n\t"
        "mov al, %1\n\t"
        "out dx, al"
        : /* no output */
        : "irm" (port), "irm" (value)
    );
}

static void readFromPort(uint16_t port, char *value) {
    asm(
        "mov dx, %1\n\t"
        "in al, dx\n\t"
        "mov %0, al"
        : "=rm" (*value)
        : "irm" (port)
    );
}

ComPort::ComPort() : mBaseIoPort(findBaseIoPort()) {
    setBaudRate(57600);
}

bool ComPort::isSupported() const {
    // The BIOS will set the Base I/O port number to zero if it is not supported
    return getBaseIoPort() != 0;
}

uint16_t ComPort::getBaseIoPort() const {
    return mBaseIoPort;
}

bool ComPort::setBaudRate(uint32_t baudRate) {
    if (baudRate > 115200 || baudRate == 0 || 115200 % baudRate != 0) {
        return false;
    }
    const uint16_t divisor = 115200 / baudRate;

    // Set the MSB of the Line Control Register to enable setting baud
    char origLineControl;
    if (! regRead(REG_LINE_CONTROL, &origLineControl)) return false;
    if (! regWrite(REG_LINE_CONTROL, origLineControl | 0x80)) return false;

    // Set the baud divisor
    if (! regWrite(REG_DLAB_BAUD_DIVISOR_LSB, static_cast<uint8_t>(divisor))) return false;
    if (! regWrite(REG_DLAB_BAUD_DIVISOR_MSB, static_cast<uint8_t>(divisor >> 8))) return false;

    // Restore the MSB of the Line Control Register to disable setting baud
    if (! regWrite(REG_LINE_CONTROL, origLineControl & 0x7F)) return false;

    return true;
}

bool ComPort::regWrite(uint8_t reg, char value) {
    const uint16_t basePort = getBaseIoPort();
    if (basePort == 0) {
        return false;
    }
    const uint16_t port = basePort + reg;
    writeToPort(port, value);
    return true;
}

bool ComPort::regRead(uint8_t reg, char *value) {
    const uint16_t basePort = getBaseIoPort();
    if (basePort == 0) {
        return false;
    }
    const uint16_t port = basePort + reg;
    readFromPort(port, value);
    return true;
}
