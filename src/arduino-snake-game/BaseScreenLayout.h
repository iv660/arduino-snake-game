#if !defined(BASE_SCREEN_LAYOUT_H)
#define BASE_SCREEN_LAYOUT_H

template <typename Derived>
class BaseScreenLayout
{
    protected:
        // TFT* screen = nullptr;
    public:
        // Derived* setScreen(TFT* screen);
        virtual void render() = 0;
};

#endif // BASE_SCREEN_LAYOUT_H
