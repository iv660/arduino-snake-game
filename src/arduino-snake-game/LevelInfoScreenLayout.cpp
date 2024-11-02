#include "LevelInfoScreenLayout.h"
#include "CenteredText.h"

void LevelInfoScreenLayout::initScreen()
{
    background(RGB(0, 0, 0));
}

void LevelInfoScreenLayout::renderLevelNumber()
{
    stroke(RGB(255, 255, 255));
    CenteredText(toFormat("Level: %d", level)).size(2)
        ->top(40)
        ->renderOn(screen);
}

void LevelInfoScreenLayout::background(RGB color)
{
    screen->background(color.blue, color.green, color.red);
}

void LevelInfoScreenLayout::stroke(RGB color)
{
    screen->stroke(color.blue, color.green, color.red);
}

LevelInfoScreenLayout *LevelInfoScreenLayout::setLevel(unsigned int level)
{
    this->level = level;

    return this;
}

void LevelInfoScreenLayout::render()
{
    initScreen();
    renderLevelNumber();
    delay(1500);
}
