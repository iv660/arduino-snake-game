#if !defined(BASE_SCREEN_LAYOUT_H)
#define BASE_SCREEN_LAYOUT_H

#include "TFT.h"

template <typename Derived>
class BaseScreenLayout
{
protected:
    TFT* screen = nullptr;
public:
    virtual void render() = 0;

    Derived* setScreen(TFT* screen);
    char* toFormat(char* format, unsigned long number);
};

template<typename Derived>
Derived * BaseScreenLayout<Derived>::setScreen(TFT * screen)
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
