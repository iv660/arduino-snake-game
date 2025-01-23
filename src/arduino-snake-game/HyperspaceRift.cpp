#include "HyperspaceRift.h"

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
    screen->fill(0, 0, 255);
    screen->stroke(255, 255, 255);
    screen->rect(0, 0, 4, 128);
}
