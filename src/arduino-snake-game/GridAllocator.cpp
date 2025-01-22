#include <Arduino.h>
#include "GridAllocator.h"

bool GridAllocator::locationIsOccupied(GridLocation location)
{
    for (uint8_t i = 0; i <= occupantsIndex - 1; i++) {
        if (occupants[i]->occupies(location)) {
            return true;
        }
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
    addOccupant(snake);

    return this;
}

GridAllocator *GridAllocator::setApple(GridOccupantInterface *apple)
{
    addOccupant(apple);

    return this;
}

GridAllocator *GridAllocator::setTimebombChallenge(GridOccupantInterface *timebombChallenge)
{
    addOccupant(timebombChallenge);

    return this;
}

GridAllocator *GridAllocator::addOccupant(GridOccupantInterface *occupant)
{
    if (occupantsIndex > (MAX_OCCUPANTS_COUNT - 1)) {
        // Subscript out of bounds
        // We cannot throw exception, so we just freeze
        while(true) {}
    }

    occupants[occupantsIndex] = occupant;
    occupantsIndex++;
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