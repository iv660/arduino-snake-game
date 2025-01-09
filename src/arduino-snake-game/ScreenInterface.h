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

                virtual void textSize(int size) = 0;
                virtual void background(int b, int g, int r) = 0; 
                virtual void fill(int b, int g, int r) = 0;
                virtual void stroke(int b, int g, int r) = 0;

                virtual void text(char *text, int x, int y) = 0;
                virtual void rect(int x, int y, int w, int h) = 0;
        };
    }; // namespace Hardware
}; // namespace XC


#endif // SCREEN_INTERFACE_H
