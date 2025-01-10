#if !defined(STARTUP_SCREEN_LAYOUT_H)
#define STARTUP_SCREEN_LAYOUT_H)

#include "const.h"
#include "BaseScreenLayout.h"

class StartupScreenLayout : public BaseScreenLayout<StartupScreenLayout>
{
private:
    void initScreen();
    void renderTitle();
    void renderStartupInstructions();
    void wait(unsigned long ms);
public:
    void render();
    using BaseScreenLayout<StartupScreenLayout>::setScreen;
};


#endif // STARTUP_SCREEN_LAYOUT_H)
