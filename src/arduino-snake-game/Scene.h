#if !defined(SCENE_H)
#define SCENE_H

#include "const.h"
#include "DrawableInterface.h"
#include "ScreenInterface.h"
#include "SPI.h"

class Scene
{
    using ScreenInterface = XC::Hardware::ScreenInterface;

    private:
        const int gridSizeX = 10;
        const int gridSizeY = 14;
        const long width = 160;
        const long height = 128;
        ScreenInterface* screen;
        int locationColumnToScreenX(int xPosition);
        int locationRowToScreenY(int yPosition);
    public:
        void draw(DrawableInterface* drawable);
        void erase(DrawableInterface* drawable);
        void begin();
        long getWidth();
        long getHeight();
        int getColumns();
        int getRows();
        void clear();
        void putText(char *text, int column, int row);
        void putSmallText(char *text, int column, int row);
        void setScreen(ScreenInterface* screen);
};


#endif // SCENE_H
