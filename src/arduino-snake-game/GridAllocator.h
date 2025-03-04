#if !defined(GRID_ALLOCATOR_H)
#define GRID_ALLOCATOR_H

#include "GridLocation.h"
#include "GridOccupantInterface.h"
#include "GridArea.h"

class GridAllocator
{
    private:
        static const uint8_t MAX_OCCUPANTS_COUNT = 10;

        int gridColumns;
        int gridRows;

        GridOccupantInterface* occupants[MAX_OCCUPANTS_COUNT];
        uint8_t occupantsIndex = 0;

        bool locationIsOccupied(GridLocation location);
    public:
        GridAllocator* setGridColumns(int columns);
        GridAllocator* setGridRows(int rows);
        GridAllocator* addOccupant(GridOccupantInterface* occupant);

        GridLocation getRandomVacantLocation();
        GridLocation getRandomVacantLocationWithin(GridArea area);
};


#endif // GRID_ALLOCATOR_H
