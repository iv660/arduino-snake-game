#if !defined(GRID_OCCUPANT_INTERFACE_H)
#define GRID_OCCUPANT_INTERFACE_H

#include "GridLocation.h"

class GridOccupantInterface {
    public:
        virtual bool occupies(GridLocation location) = 0;
};


#endif // GRID_OCCUPANT_INTERFACE_H
