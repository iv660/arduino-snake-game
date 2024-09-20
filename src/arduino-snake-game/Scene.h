#if !defined(SCENE_H)
#define SCENE_H

#define cs 10 // пин для подключения CS
#define dc 8  // пин для подключения A0
#define rst 9 // пин для подключения reset

#include "DrawableInterface.h"
#include "TFT.h"
#include "SPI.h"

class Scene
{
private:
    const int gridSizeX = 10;
    const int gridSizeY = 12;
    const long width = 160;
    const long height = 128;
    TFT screen = TFT(cs, dc, rst);
    int locationColumnToScreenX(int xPosition);
    int locationRowToScreenY(int yPosition);
public:
    Scene(/* args */);
    void draw(DrawableInterface* drawable);
    void erase(DrawableInterface* drawable);
    void begin();
    long getWidth();
    long getHeight();
    int getColumns();
    int getRows();
    void clear();
    void putText(char *text, int column, int row);
};


#endif // SCENE_H
