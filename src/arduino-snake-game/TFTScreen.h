#if !defined(TFT_SCREEN_H)
#define TFT_SCREEN_H)

#include "ScreenInterface.h"
#include "TFT.h"

using XC::Hardware::ScreenInterface;

class TFTScreen: public ScreenInterface, public TFT
{
    public:
        TFTScreen(int CSPin, int DCPin, int RSTPin) : TFT(CSPin, DCPin, RSTPin) {}

        void begin() override 
        {
            initR(INITR_BLACKTAB);
            setRotation(1);
        }

        void background(int r, int g, int b) override
        {
            TFT::background(b, g, r);
        }

        void stroke(int r, int g, int b) override
        {
            TFT::stroke(b, g, r);
        }

        void textSize(int size) override
        {
            TFT::textSize(size);
        }

        void text(char *text, int x, int y) override
        {
            TFT::text(text, x, y);
        }

        void fill(int r, int g, int b) override
        {
            TFT::fill(b, g, r);
        }

        void rect(int x, int y, int w, int h) override
        {
            TFT::rect(x, y, w, h);
        }

        int width() override
        {
            return TFT::width();
        }

        void drawPixel(int x, int y, uint16_t color) override
        {
            TFT::drawPixel(x, y, color);
        }

};

#endif // TFT_SCREEN_H)
