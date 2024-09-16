#include "Scene.h"
// #include "Apple.h"

int Scene::locationColumnToScreenX(int xPosition)
{
    return xPosition * gridSizeX;
}

int Scene::locationRowToScreenY(int yPosition)
{
    return yPosition * gridSizeY;
}

Scene::Scene()
{
}

void Scene::draw(DrawableInterface *drawable)
{
    screen.stroke(0, 255, 0);
    screen.text(drawable->getText(), 
        locationColumnToScreenX(drawable->getColumn()), 
        locationRowToScreenY(drawable->getRow()));
}

void Scene::erase(DrawableInterface *drawable)
{
    screen.stroke(0, 0, 0);
    screen.text(drawable->getText(), 
        locationColumnToScreenX(drawable->getColumn()), 
        locationRowToScreenY(drawable->getRow()));
}

void Scene::begin()
{
    screen.begin();

    screen.setTextSize(2);
    screen.background(0, 0, 0);
}
