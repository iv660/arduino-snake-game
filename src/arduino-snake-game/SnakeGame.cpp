#include "SnakeGame.h"

void SnakeGame::drawSnake()
{
    snakeSegment.setX(10);
    snakeSegment.setY(70);
    scene.draw(&snakeSegment);
}

void SnakeGame::drawApple()
{
    apple.setX(100);
    apple.setY(0);

    scene.draw(&apple);
}

void SnakeGame::stretchHead()
{
}

void SnakeGame::retractTail()
{
}

bool SnakeGame::isOver()
{
    return false;
}

bool SnakeGame::reachedAnApple()
{
    return false;
}

SnakeGame *SnakeGame::startUp()
{
    scene.begin();

    drawSnake();
    drawApple();

    return this;
}

SnakeGame *SnakeGame::moveSnake()
{
    stretchHead();
    retractTail();

    return this;
}

SnakeGame *SnakeGame::growSnake()
{
    stretchHead();

    return this;
}

SnakeGame *SnakeGame::deductScore()
{
    return this;
}

SnakeGame *SnakeGame::placeNewApple()
{
    return this;
}

SnakeGame *SnakeGame::removeApple()
{
    return this;
}

SnakeGame *SnakeGame::increaseScore()
{
    return this;
}

void SnakeGame::end()
{
}

