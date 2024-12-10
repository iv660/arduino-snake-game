#include "SnakeSegment.h"

void SnakeSegment::removeNextSegment()
{
    nextSegment = nullptr;
}

bool SnakeSegment::isTail()
{
    if (nextSegment == nullptr) {
        return true;
    }

    return false;
}

bool SnakeSegment::isVisible()
{
    return visible;
}

void SnakeSegment::hide()
{
    visible = false;
}

void SnakeSegment::show()
{
    visible = true;
}

GridLocation SnakeSegment::getLocation()
{
    GridLocation location;
    location.row = row;
    location.column = column;

    return location;
}

SnakeSegment::SnakeSegment() : DrawableInterface(/* args */)
{
}

int SnakeSegment::getColumn()
{
    return column;
}

int SnakeSegment::getRow()
{
    return row;
}

char *SnakeSegment::getText()
{
    return "#";
}

void SnakeSegment::setColumn(int column)
{
    this->column = column;
}

void SnakeSegment::setRow(int row)
{
    this->row = row;
}

void SnakeSegment::setNextSegment(SnakeSegment *segment)
{
    this->nextSegment = segment;
}

SnakeSegment *SnakeSegment::getNextSegment()
{
    return nextSegment;
}
