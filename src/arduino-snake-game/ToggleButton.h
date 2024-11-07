#if !defined(TOGGLE_BUTTON_H)
#define TOGGLE_BUTTON_H

class ToggleButton {
private:
    int pin;
    bool on = false;

    inline void toggleState();

public:
    ToggleButton(int pin) : pin(pin) {};

    void tick();
    bool isOn();
};

#endif // TOGGLE_BUTTON_H
    