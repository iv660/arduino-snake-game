#pragma once

#include "GridLocation.h"
#include "GridOccupantInterface.h"

class GridArea: public GridOccupantInterface
{
    public:
        GridLocation topLeft;
        GridLocation bottomRight;

        GridArea(GridLocation topLeft, GridLocation bottomRight): topLeft(topLeft), bottomRight(bottomRight) {}

        bool occupies(GridLocation location) override;
};