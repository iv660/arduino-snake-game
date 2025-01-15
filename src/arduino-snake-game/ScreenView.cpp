#include "ScreenView.h"

void ScreenView::begin()
{
    screen->begin();
}

int ScreenView::width()
{
    return screen->width() - x;
}

void ScreenView::textSize(int size)
{
    screen->textSize(size);
}

void ScreenView::background(int r, int g, int b)
{
    screen->background(r, g, b);
}

void ScreenView::fill(int r, int g, int b)
{
    screen->fill(r, g, b);
}

void ScreenView::stroke(int r, int g, int b)
{
    screen->stroke(r, g, b);
}

void ScreenView::text(char *text, int x, int y)
{
    screen->text(text, x + this->x, y + this->y);
}

void ScreenView::rect(int x, int y, int w, int h)
{
    screen->rect(x + this->x, y + this->y, w, h);
}

void ScreenView::drawPixel(int x, int y, uint16_t color)
{
    screen->drawPixel(x + this->x, y + this->y, color);
}
