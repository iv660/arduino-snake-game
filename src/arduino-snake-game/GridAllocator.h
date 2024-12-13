#if !defined(GRID_ALLOCATOR_H)
#define GRID_ALLOCATOR_H

#include "GridLocation.h"
#include "GridOccupantInterface.h"

class GridAllocator
{
    private:
        int gridColumns;
        int gridRows;
        GridOccupantInterface* snake;
        GridOccupantInterface* apple;
        GridOccupantInterface* timebombChallenge;

        bool locationIsOccupied(GridLocation location);
    public:
        GridAllocator* setGridColumns(int columns);
        GridAllocator* setGridRows(int rows);
        GridAllocator* setSnake(GridOccupantInterface* snake);
        GridAllocator* setApple(GridOccupantInterface* apple);
        GridAllocator* setTimebombChallenge(GridOccupantInterface* timebombChallenge);

        GridLocation getRandomVacantLocation();
};


#endif // GRID_ALLOCATOR_H
