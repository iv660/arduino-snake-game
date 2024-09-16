#include "SnakeSegment.h"

void SnakeSegment::removeNextSegment()
{
    nextSegment = nullptr;
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
