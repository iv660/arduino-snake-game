#include "HyperspaceRift.h"

int HyperspaceRift::getColumn()
{
    return area.topLeft.column;
}

int HyperspaceRift::getRow()
{
    return area.topLeft.row;
}

char *HyperspaceRift::getText()
{
    return nullptr;
}

void HyperspaceRift::renderOn(ScreenInterface *screen)
{
    static const int x = 9;
    static const int width = 4;

    screen->fill(0, 0, 255);
    screen->stroke(255, 255, 255);
    screen->rect(x, 0, width, 128);
}
