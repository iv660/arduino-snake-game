#pragma once

#include "DrawableInterface.h"
#include "ScreenInterface.h"

class WormholePort: public DrawableInterface
{
    private:
        int column = 0;
        int row = 0;
    public:
        WormholePort* setColumn(int column);
        WormholePort* setRow(int row);
        int getColumn() override;
        int getRow() override;
        char* getText() override;
        void renderOn(ScreenInterface* screen) override;
};
