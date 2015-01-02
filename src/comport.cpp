#include "comport.h"

/*
Much of the implementation of this class is based on information from
http://wiki.osdev.org/Serial_Ports
*/

/* The address in memory where the Base I/O port for COM1 is specified by the BIOS */
#define BIOS_DATA_AREA_COM1_ADDRESS  0x0400

static uint16_t findBaseIoPort() {
    return *(reinterpret_cast<uint16_t*>(BIOS_DATA_AREA_COM1_ADDRESS));
}

ComPort::ComPort() : mBaseIoPort(findBaseIoPort()) {
}

bool ComPort::isSupported() const {
    // The BIOS will set the Base I/O port number to zero if it is not supported
    return getBaseIoPort() != 0;
}

uint16_t ComPort::getBaseIoPort() const {
    return mBaseIoPort;
}
