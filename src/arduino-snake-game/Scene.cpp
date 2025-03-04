#include "Scene.h"
#include "ScreenView.h"

int Scene::locationColumnToScreenX(int xPosition)
{
    return xPosition * gridSizeX;
}

int Scene::locationRowToScreenY(int yPosition)
{
    return yPosition * gridSizeY;
}

void Scene::draw(DrawableInterface *drawable)
{
    screen->stroke(0, 255, 0);
    screen->textSize(2);
    screen->text(drawable->getText(), 
        locationColumnToScreenX(drawable->getColumn()), 
        locationRowToScreenY(drawable->getRow()));
}

void Scene::render(DrawableInterface *drawable)
{
    ScreenView viewport(screen, 
        locationColumnToScreenX(drawable->getColumn()), 
        locationRowToScreenY(drawable->getRow()));

    drawable->renderOn(&viewport);
}

void Scene::erase(DrawableInterface *drawable)
{
    screen->stroke(0, 0, 0);
    screen->fill(0, 0, 0);
    screen->rect(
        locationColumnToScreenX(drawable->getColumn()), 
        locationRowToScreenY(drawable->getRow()), 
        gridSizeX, gridSizeY);
}

void Scene::begin()
{
    screen->textSize(2);
    screen->background(0, 0, 0);
}

long Scene::getWidth()
{
    return width;
}

long Scene::getHeight()
{
    return height;
}

int Scene::getColumns()
{
    return getWidth() / gridSizeX;
}

int Scene::getRows()
{
    return getHeight() / gridSizeY;
}

void Scene::clear()
{
    screen->background(0, 0, 0);
}

void Scene::putText(char *text, int column, int row)
{
    screen->stroke(0, 255, 0);
    screen->textSize(2);
    screen->text(text, locationColumnToScreenX(column), 
        locationRowToScreenY(row));
}

void Scene::putSmallText(char *text, int column, int row)
{
    screen->stroke(0, 255, 0);
    screen->textSize(1);
    screen->text(text, locationColumnToScreenX(column), 
        locationRowToScreenY(row));
}

void Scene::setScreen(ScreenInterface *screen)
{
    this->screen = screen;
}
