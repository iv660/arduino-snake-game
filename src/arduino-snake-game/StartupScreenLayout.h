#if !defined(STARTUP_SCREEN_LAYOUT_H)
#define STARTUP_SCREEN_LAYOUT_H)

#include "const.h"
#include "TFT.h"

class StartupScreenLayout
{
private:
    TFT* screen;

    void initScreen();
    void renderTitle();
    void renderStartupInstructions();
    void wait(unsigned long ms);
public:
    void render();
    StartupScreenLayout* setScreen(TFT* screen);
};


#endif // STARTUP_SCREEN_LAYOUT_H)
