#include "AnalogJoystickDirectionSwitch.h"

#include <Arduino.h>

AnalogJoystickDirectionSwitch::AnalogJoystickDirectionSwitch(unsigned int vrxPin, unsigned int vryPin)
{
    this->vrxPin = vrxPin;
    this->vryPin = vryPin;

    pinMode(vrxPin, INPUT);
    pinMode(vryPin, INPUT);
}

XC::Hardware::DirectionSwitchInterface::Direction AnalogJoystickDirectionSwitch::getDirection()
{
    int xValue = analogRead(vrxPin);
    int yValue = analogRead(vryPin);

    if (xValue > 1000) {
        return Direction::RIGHT;
    } else if (xValue < 23) {
        return Direction::LEFT;
    } else if (yValue > 1000) {
        return Direction::DOWN;
    } else if (yValue < 23) {
        return Direction::UP;
    } else {
        return Direction::NONE;
    }
}