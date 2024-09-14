#include "Scene.h"
// #include "Apple.h"

Scene::Scene()
{
}

void Scene::draw(DrawableInterface* drawable)
{
    screen.text(drawable->getText(), drawable->getX(), drawable->getY());
}

void Scene::begin()
{
    screen.begin();

    screen.setTextSize(2);
    screen.background(0, 0, 0);
    screen.stroke(0, 255, 0);
}
