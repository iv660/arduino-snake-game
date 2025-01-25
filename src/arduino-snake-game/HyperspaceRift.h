#pragma once

#include "DrawableInterface.h"
#include "ScreenInterface.h"

class HyperspaceRift: public DrawableInterface
{
    private:
        uint8_t getCenterOfScreenX(ScreenInterface* screen);
    public:
        int getColumn() override;
        int getRow() override;
        char* getText() override;
        void renderOn(ScreenInterface* screen) override;
};
