#pragma once

#include "DrawableInterface.h"
#include "ScreenInterface.h"
#include "GridArea.h"
#include "GridOccupantInterface.h"
#include "GridLocation.h"

class HyperspaceRift: public DrawableInterface, public GridOccupantInterface
{
    private:
        GridArea area;
    public:
        HyperspaceRift(GridArea area): area(area) {}

        int getColumn() override;
        int getRow() override;
        char* getText() override;
        void renderOn(ScreenInterface* screen) override;

        bool occupies(GridLocation location) override;
};
