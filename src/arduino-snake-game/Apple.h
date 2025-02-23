#if !defined(APPLE_H)
#define APPLE_H

#include "DrawableInterface.h"
#include "GridLocation.h"
#include "GridOccupantInterface.h"

#include "ScreenInterface.h"

using XC::Hardware::ScreenInterface;

class Apple: public DrawableInterface, public GridOccupantInterface
{
    private:
        int column = 0;
        int row = 0;
    public:
        Apple(/* args */);
        int getColumn();
        int getRow();
        char* getText();
        void setColumn(int column);
        void setRow(int row);
        bool occupies(GridLocation location);
        void renderOn(ScreenInterface* screen);
};


#endif // APPLE_H
