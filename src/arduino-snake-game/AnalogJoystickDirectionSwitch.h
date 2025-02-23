#if !defined(ANALOG_JOYSTICK_DIRECTION_SWITCH_H)
#define ANALOG_JOYSTICK_DIRECTION_SWITCH_H

#include "DirectionSwitchInterface.h"

class AnalogJoystickDirectionSwitch: public XC::Hardware::DirectionSwitchInterface
{
    using XC::Hardware::DirectionSwitchInterface::Direction;

    private:
        unsigned int vrxPin;
        unsigned int vryPin;
    public:
        AnalogJoystickDirectionSwitch(unsigned int vrxPin, 
            unsigned int vryPin);
        Direction getDirection();
};

#endif // ANALOG_JOYSTICK_DIRECTION_SWITCH_H
