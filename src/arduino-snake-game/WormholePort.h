#pragma once

#include "DrawableInterface.h"
#include "ScreenInterface.h"
#include "GridOccupantInterface.h"
#include "GridLocation.h"
#include "Direction.h"

class WormholePort: public DrawableInterface, public GridOccupantInterface
{
    private:
        int column = -1;
        int row = -1;
    public:
        WormholePort* setColumn(int column);
        WormholePort* setRow(int row);
        int getColumn() override;
        int getRow() override;
        char* getText() override;
        void renderOn(ScreenInterface* screen) override;

        bool occupies(GridLocation location) override;

        GridLocation getExitLocation(Direction direction);
};
