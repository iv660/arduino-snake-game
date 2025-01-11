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

                virtual int width() = 0;

                virtual void textSize(int size) = 0;
                virtual void background(int r, int g, int b) = 0; 
                virtual void fill(int r, int g, int b) = 0;
                virtual void stroke(int r, int g, int b) = 0;

                virtual void text(char *text, int x, int y) = 0;
                virtual void rect(int x, int y, int w, int h) = 0;
        };
    }; // namespace Hardware
}; // namespace XC


#endif // SCREEN_INTERFACE_H
