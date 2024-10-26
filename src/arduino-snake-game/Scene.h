#if !defined(SCENE_H)
#define SCENE_H

#include "const.h"
#include "DrawableInterface.h"
#include "TFT.h"
#include "SPI.h"

class Scene
{
private:
    const int gridSizeX = 10;
    const int gridSizeY = 14;
    const long width = 160;
    const long height = 128;
    TFT* screen;
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
    void setScreen(TFT* screen);
};


#endif // SCENE_H
