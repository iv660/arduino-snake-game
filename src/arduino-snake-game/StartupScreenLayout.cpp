#include "StartupScreenLayout.h"
#include <Arduino.h>

void StartupScreenLayout::initScreen()
{
    screen->begin();
    screen->background(22, 97, 28);
}

void StartupScreenLayout::renderTitle()
{
    screen->stroke(255, 255, 255);
    screen->setTextSize(2);
    screen->text("SNAKE GAME", 20, 40);
}

void StartupScreenLayout::renderStartupInstructions()
{
    screen->stroke(255, 255, 255);
    screen->setTextSize(1);
    screen->text("Push joystick to start", 15, 60);
}

void StartupScreenLayout::wait(unsigned long ms)
{
    delay(ms);
}

void StartupScreenLayout::render()
{
    initScreen();
    renderTitle();
    wait(700);
    renderStartupInstructions();
}
