#if !defined(SCREEN_INTERFACE_H)
#define SCREEN_INTERFACE_H

namespace XC 
{
    namespace Hardware
    {
        class ScreenInterface
        {
            public:
                virtual void begin() = 0;

                virtual void background(int b, int g, int r) = 0; 
        };
    }; // namespace Hardware
}; // namespace XC


#endif // SCREEN_INTERFACE_H
