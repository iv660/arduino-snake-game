#include <Arduino.h>
#include "GridAllocator.h"

bool GridAllocator::locationIsOccupied(GridLocation location)
{
    if (snake->occupies(location)) {
        return true;
    }

    if (apple->occupies(location)) {
        return true;
    }

    if (timebombChallenge->occupies(location)) {
        return true;
    }

    return false;
}

GridAllocator *GridAllocator::setGridColumns(int columns)
{
    gridColumns = columns;

    return this;
}

GridAllocator *GridAllocator::setGridRows(int rows)
{
    gridRows = rows;

    return this;
}

GridAllocator *GridAllocator::setSnake(GridOccupantInterface *snake)
{
    this->snake = snake;

    return this;
}

GridAllocator *GridAllocator::setApple(GridOccupantInterface *apple)
{
    this->apple = apple;

    return this;
}

GridAllocator *GridAllocator::setTimebombChallenge(GridOccupantInterface *timebombChallenge)
{
    this->timebombChallenge = timebombChallenge;

    return this;
}

GridLocation GridAllocator::getRandomVacantLocation()
{
    GridLocation newLocation;

    do {
        long newColumn = random(0, gridColumns - 1);
        long newRow = random(0, gridRows - 1);
        
        newLocation.column = newColumn;
        newLocation.row = newRow;
    } while (locationIsOccupied(newLocation));

    return newLocation;

}