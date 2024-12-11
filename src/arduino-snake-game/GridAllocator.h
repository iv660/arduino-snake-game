#if !defined(GRID_ALLOCATOR_H)
#define GRID_ALLOCATOR_H

#include "GridLocation.h"
#include "Snake.h"
#include "Apple.h"

class GridAllocator
{
    private:
        int gridColumns;
        int gridRows;
        Snake* snake;
        Apple* apple;

        bool locationIsOccupied(GridLocation location);
    public:
        GridAllocator* setGridColumns(int columns);
        GridAllocator* setGridRows(int rows);
        GridAllocator* setSnake(Snake* snake);
        GridAllocator* setApple(Apple* apple);

        GridLocation getRandomVacantLocation();
};


#endif // GRID_ALLOCATOR_H
