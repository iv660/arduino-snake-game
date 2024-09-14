#if !defined(SCENE_H)
#define SCENE_H

#define cs 10 // пин для подключения CS
#define dc 8  // пин для подключения A0
#define rst 9 // пин для подключения reset

#include "Apple.h"
#include "TFT.h"
#include "SPI.h"

class Scene
{
private:
    TFT screen = TFT(cs, dc, rst);
public:
    Scene(/* args */);
    void draw(Apple apple);
    void begin();
};


#endif // SCENE_H
