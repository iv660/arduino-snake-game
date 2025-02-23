#if !defined(SCREEN_INTERFACE_H)
#define SCREEN_INTERFACE_H

#include <stdint.h>

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
                virtual void drawPixel(int x, int y, uint16_t color) = 0;
                virtual void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {}
                virtual void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {}
        };
    }; // namespace Hardware
}; // namespace XC


#endif // SCREEN_INTERFACE_H
