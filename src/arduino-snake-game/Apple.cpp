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
