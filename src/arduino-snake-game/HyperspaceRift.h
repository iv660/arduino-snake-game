#pragma once

#include "DrawableInterface.h"
#include "ScreenInterface.h"
#include "GridArea.h"

class HyperspaceRift: public DrawableInterface
{
    private:
        GridArea area;
    public:
        HyperspaceRift(GridArea area): area(area) {}

        int getColumn() override;
        int getRow() override;
        char* getText() override;
        void renderOn(ScreenInterface* screen) override;
};
