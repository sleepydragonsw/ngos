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

    private:
        bool regWrite(uint8_t reg, char value);
        bool regRead(uint8_t reg, char *value);
        bool setBaudRate(uint32_t baudRate);
};

#endif /* #ifndef _NGOS_COMPORT_H_ */
