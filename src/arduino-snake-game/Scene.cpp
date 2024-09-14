#include "Scene.h"
// #include "Apple.h"

Scene::Scene()
{
}

void Scene::draw(Apple apple)
{
    screen.setTextSize(2);
    screen.background(0, 0, 0);
    screen.stroke(0, 255, 0);

    screen.text("@", apple.getX(), apple.getY());
}

void Scene::begin()
{
    screen.begin();
}
