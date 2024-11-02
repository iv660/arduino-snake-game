#ifndef LEVEL_INFO_SCREEN_LAYOUT_H
#define LEVEL_INFO_SCREEN_LAYOUT_H

#include "BaseScreenLayout.h"
#include "RGB.h"

class LevelInfoScreenLayout : public BaseScreenLayout<LevelInfoScreenLayout>
{
private:
    unsigned int level = 0;

    const RGB BACKGROUND_COLOR = RGB(0, 0, 0);
    const RGB STROKE_COLOR = RGB(255, 255, 255);

    void initScreen();
    void renderLevelNumber();
    void background(RGB color);
    void stroke(RGB color);
    void countdown(unsigned int from);

public:
    LevelInfoScreenLayout* setLevel(unsigned int level);
    void render() override;
};

#endif // LEVEL_INFO_SCREEN_LAYOUT_H
