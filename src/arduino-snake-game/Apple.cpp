#include "Apple.h"

Apple::Apple()
{
}

int Apple::getColumn()
{
    return column;
}

int Apple::getRow()
{
    return row;
}

char *Apple::getText()
{
    return "@";
}

void Apple::setColumn(int column)
{
    this->column = column;
}

void Apple::setRow(int row)
{
    this->row = row;
}

bool Apple::occupies(GridLocation location)
{
    if (location.column == column && location.row == row) {
        return true;
    }
    
    return false;
}
