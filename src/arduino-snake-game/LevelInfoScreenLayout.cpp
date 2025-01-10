#include <Arduino.h>
#include "LevelInfoScreenLayout.h"
#include "CenteredText.h"

void LevelInfoScreenLayout::initScreen()
{
    background(BACKGROUND_COLOR);
}

void LevelInfoScreenLayout::renderLevelNumber()
{
    stroke(STROKE_COLOR);
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

void LevelInfoScreenLayout::countdown(unsigned int from)
{
    for (unsigned int count = from; count > 0; count--) {
        CenteredText counter(toFormat("%d", count));

        stroke(STROKE_COLOR);
        counter.size(3)
            ->top(70)
            ->renderOn(screen);

        delay(1000);

        stroke(BACKGROUND_COLOR);
        counter.renderOn(screen);
    }
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
    countdown(3);
}
