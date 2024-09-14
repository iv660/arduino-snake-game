#include "Apple.h"

Apple::Apple()
{
}

int Apple::getX()
{
    return x;
}

int Apple::getY()
{
    return y;
}

char *Apple::getText()
{
    return "@";
}

void Apple::setX(int x)
{
    this->x = x;
}

void Apple::setY(int y)
{
    this->y = y;
}
