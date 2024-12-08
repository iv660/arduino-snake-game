#if !defined(TOGGLE_BUTTON_H)
#define TOGGLE_BUTTON_H

#include <Arduino.h>

class ToggleButton {
private:
    int pin;
    bool on = false;
    int lastState = HIGH;

    inline void toggleState();

public:
    ToggleButton(int pin);

    void tick();
    bool isOn();
    void reset();
};

#endif // TOGGLE_BUTTON_H
    