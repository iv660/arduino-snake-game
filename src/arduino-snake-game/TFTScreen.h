#if !defined(TFT_SCREEN_H)
#define TFT_SCREEN_H)

#include "ScreenInterface.h"
#include "TFT.h"

using XC::Hardware::ScreenInterface;

class TFTScreen: public ScreenInterface, public TFT
{
    public:
        TFTScreen(int CSPin, int DCPin, int RSTPin) : TFT(CSPin, DCPin, RSTPin) {}
};

#endif // TFT_SCREEN_H)
