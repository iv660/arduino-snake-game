#include "WormholePort.h"

WormholePort * WormholePort::setColumn(int column)
{
    this->column = column;
    return this;
}

WormholePort * WormholePort::setRow(int row)
{
    this->row = row;
    return this;
}

int WormholePort::getColumn()
{
    return column;
}

int WormholePort::getRow()
{
    return row;
}

char *WormholePort::getText()
{
    return nullptr;
}

void WormholePort::renderOn(ScreenInterface *screen)
{
    screen->fillCircle(4, 7, 4, 0xFFFF);
    screen->fillCircle(4, 7, 3, 0x001F);
    screen->fillCircle(4, 7, 1, 0xFFFF);
}

bool WormholePort::occupies(GridLocation location)
{
    if (location.row != row) {
        return false;
    } 
    
    if (location.column != column) {
        return false;
    }

    return true;
}
