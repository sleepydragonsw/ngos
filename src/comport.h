#ifndef _NGOS_COMPORT_H_
#define _NGOS_COMPORT_H_

#include <stdint.h>

class ComPort {

    private:
        const uint16_t mBaseIoPort;

    public:
        ComPort();
        bool isSupported() const;
        uint16_t getBaseIoPort() const;
        bool write(char c);
        bool read(char *c);

    private:
        enum DataBits {
            DATA_BITS_5,
            DATA_BITS_6,
            DATA_BITS_7,
            DATA_BITS_8,
        };
        enum StopBits {
            STOP_BITS_1,
            STOP_BITS_1_5,
            STOP_BITS_2,
        };
        enum Parity {
            PARITY_NONE,
            PARITY_ODD,
            PARITY_EVEN,
            PARITY_MARK,
            PARITY_SPACE,
        };
        const char INTERRUPT_DATA_AVAILABLE = 0x01;
        const char INTERRUPT_TRANSMITTER_EMPTY = 0x02;
        const char INTERRUPT_BREAK_ERROR = 0x4;
        const char INTERRUPT_STATUS_CHANGE = 0x8;

        bool regWrite(uint8_t reg, char value);
        bool regRead(uint8_t reg, char *value);
        bool setBaudRate(uint32_t baudRate);
        bool setLineControl(DataBits dataBits, StopBits stopBits, Parity parity);
        bool setEnabledInterrupts(char interrupts);
        bool waitForDataReceived();
};

#endif /* #ifndef _NGOS_COMPORT_H_ */
