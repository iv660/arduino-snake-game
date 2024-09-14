#include "SnakeSegment.h"

SnakeSegment::SnakeSegment(): DrawableInterface(/* args */)
{
}

int SnakeSegment::getX()
{
    return x;
}

int SnakeSegment::getY()
{
    return y;
}

char *SnakeSegment::getText()
{
    return "#";
}

void SnakeSegment::setX(int x)
{
    this->x = x;
}

void SnakeSegment::setY(int y)
{
    this->y = y;
}
