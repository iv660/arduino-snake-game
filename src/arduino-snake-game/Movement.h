#pragma once

#include "GridLocation.h"
#include "Direction.h"

class Movement
{
    private:
    public:
        GridLocation calculateNextLocation(GridLocation currentLocation, Direction direction);
};
