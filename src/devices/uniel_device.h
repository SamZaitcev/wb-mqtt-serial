#pragma once

#include <exception>
#include <memory>
#include <stdint.h>
#include <string>

#include "serial_config.h"
#include "serial_device.h"

class TUnielDevice: public TSerialDevice, public TUInt32SlaveId
{
public:
    enum RegisterType
    {
        REG_RELAY = 0,
        REG_INPUT,
        REG_PARAM,
        REG_BRIGHTNESS
    };

    TUnielDevice(PDeviceConfig config, PPort port, PProtocol protocol);
    uint64_t ReadRegister(PRegister reg);
    void WriteRegister(PRegister reg, uint64_t value);

    static void Register(TSerialDeviceFactory& factory);

private:
    void WriteCommand(uint8_t cmd, uint8_t mod, uint8_t b1, uint8_t b2, uint8_t b3);
    void ReadResponse(uint8_t cmd, uint8_t* response);
};

typedef std::shared_ptr<TUnielDevice> PUnielDevice;
