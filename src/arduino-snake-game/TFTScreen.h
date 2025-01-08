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
            TFT::begin();
        }

        void background(int b, int g, int r) override
        {
            TFT::background(b, g, r);
        }

        void stroke(int b, int g, int r) override
        {
            TFT::stroke(b, g, r);
        }

        void textSize(int size) override
        {
            TFT::textSize(size);
        }
};

#endif // TFT_SCREEN_H)
