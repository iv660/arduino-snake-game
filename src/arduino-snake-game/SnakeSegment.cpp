#include "SnakeSegment.h"

void SnakeSegment::removeNextSegment()
{
    nextSegment = nullptr;
}

SnakeSegment::SnakeSegment() : DrawableInterface(/* args */)
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

void SnakeSegment::setNextSegment(SnakeSegment *segment)
{
    this->nextSegment = segment;
}

SnakeSegment *SnakeSegment::getNextSegment()
{
    return nextSegment;
}
