#include "SnakeGame.h"

void SnakeGame::drawSnake(SnakeSegment* snakeSegment)
{
    scene.draw(snakeSegment);
}

void SnakeGame::drawApple()
{
    apple.setX(12);
    apple.setY(2);

    scene.draw(&apple);
}

void SnakeGame::stretchHead()
{
    SnakeSegment *oldSegment = snakeSegment;
    
    int newXPosition = snakeSegment->getX() + 1;
    int newYPosition = snakeSegment->getY();
    SnakeSegment *newHead = new SnakeSegment();
    newHead->setX(newXPosition);
    newHead->setY(newYPosition);
    newHead->setNextSegment(oldSegment);

    scene.draw(newHead);

    snakeSegment = newHead;
}

void SnakeGame::retractTail()
{
    SnakeSegment* tailSegment = snakeSegment->getNextSegment();
    snakeSegment->removeNextSegment();
    scene.erase(tailSegment);
    delete tailSegment;
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

    snakeSegment = new SnakeSegment();
    snakeSegment->setX(3);
    snakeSegment->setY(5);
    scene.draw(snakeSegment);

    drawApple();

    return this;
}

SnakeGame *SnakeGame::moveSnake()
{
    if (snakeSegment->getX() > 14) {
        return;
    }
    
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

