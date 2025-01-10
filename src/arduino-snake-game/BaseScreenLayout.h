#if !defined(BASE_SCREEN_LAYOUT_H)
#define BASE_SCREEN_LAYOUT_H

#include <stdio.h>
#include "ScreenInterface.h"

using XC::Hardware::ScreenInterface;

template <typename Derived>
class BaseScreenLayout
{
    protected:
        ScreenInterface* screen = nullptr;
    public:
        virtual void render() = 0;

        Derived* setScreen(ScreenInterface* screen);
        char* toFormat(char* format, unsigned long number);
};

template<typename Derived>
Derived * BaseScreenLayout<Derived>::setScreen(ScreenInterface* screen)
{
    this->screen = screen;
    return this;
}

template<typename Derived>
char* BaseScreenLayout<Derived>::toFormat(char* format, unsigned long number)
{
    static char buffer[10];

    sprintf(buffer, format, number);

    return buffer;
}


#endif // BASE_SCREEN_LAYOUT_H
