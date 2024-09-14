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
    const int gridSizeX = 8;
    const int gridSizeY = 12;
    TFT screen = TFT(cs, dc, rst);
    int xPositionToCoordinate(int xPosition);
    int yPositionToCoordinate(int yPosition);
public:
    Scene(/* args */);
    void draw(DrawableInterface* drawable);
    void begin();
};


#endif // SCENE_H
