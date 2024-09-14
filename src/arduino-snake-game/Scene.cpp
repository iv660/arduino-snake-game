#include "Scene.h"
// #include "Apple.h"

int Scene::xPositionToCoordinate(int xPosition)
{
    return xPosition * gridSizeX;
}

int Scene::yPositionToCoordinate(int yPosition)
{
    return yPosition * gridSizeY;
}

Scene::Scene()
{
}

void Scene::draw(DrawableInterface* drawable)
{
    screen.text(drawable->getText(), 
        xPositionToCoordinate(drawable->getX()), 
        yPositionToCoordinate(drawable->getY()));
}

void Scene::begin()
{
    screen.begin();

    screen.setTextSize(2);
    screen.background(0, 0, 0);
    screen.stroke(0, 255, 0);
}
