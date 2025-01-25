#include "HyperspaceRift.h"

uint8_t HyperspaceRift::getCenterOfScreenX(ScreenInterface* screen)
{
    return screen->width() / 2;
}

int HyperspaceRift::getColumn()
{
    return 0;
}

int HyperspaceRift::getRow()
{
    return 0;
}

char *HyperspaceRift::getText()
{
    return nullptr;
}

void HyperspaceRift::renderOn(ScreenInterface *screen)
{
    const uint8_t riftWidth = 4;
    uint8_t x = getCenterOfScreenX(screen) - (riftWidth / 2); 
    
    screen->fill(0, 0, 255);
    screen->stroke(255, 255, 255);
    screen->rect(x, 0, 4, 128);
}
