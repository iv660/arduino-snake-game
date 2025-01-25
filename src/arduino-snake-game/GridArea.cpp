#include "GridArea.h"

bool GridArea::occupies(GridLocation location)
{
    if (location.column < topLeft.column) {
        return false;
    }

    if (location.column > bottomRight.column) {
        return false;
    }

    if (location.row < topLeft.row) {
        return false;
    }

    if (location.row > bottomRight.row) {
        return false;
    }

    return true;
}