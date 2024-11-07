#include <Arduino.h>
#include "ToggleButton.h"

inline void ToggleButton::toggleState()
{
    on = !on;
}

void ToggleButton::tick()
{
    static int lastState = HIGH;
    static unsigned long lastTime = 0;

    unsigned long currentTime = millis();
    int currentState = digitalRead(pin);

    if (currentTime - lastTime > 50) {
        lastTime = currentTime;
        if (lastState != currentState) {
            lastState = currentState;
            
            if (currentState == HIGH) {
                toggleState();
            }
        }
    }
}

bool ToggleButton::isOn()
{
    return on;
}
