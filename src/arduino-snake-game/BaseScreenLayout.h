#if !defined(BASE_SCREEN_LAYOUT_H)
#define BASE_SCREEN_LAYOUT_H

#include "TFT.h"

template <typename Derived>
class BaseScreenLayout
{
    protected:
        TFT* screen = nullptr;
    public:
        Derived* setScreen(TFT* screen);
        virtual void render() = 0;
};

template<typename Derived>
Derived * BaseScreenLayout<Derived>::setScreen(TFT * screen)
{
    this->screen = screen;
    return this;
}

#endif // BASE_SCREEN_LAYOUT_H
