#include "SnakeGame.h"

void SnakeGame::drawSnake(SnakeSegment* snakeSegment)
{
    scene.draw(snakeSegment);
}

void SnakeGame::drawApple()
{
    apple.setColumn(10);
    apple.setRow(5);

    scene.draw(&apple);
}

void SnakeGame::stretchHead()
{
    SnakeSegment *oldHead = getHead();

    GridLocation nextLocation = getNextLocation(oldHead);
    
    SnakeSegment *newHead = new SnakeSegment();
    newHead->setColumn(nextLocation.column);
    newHead->setRow(nextLocation.row);
    newHead->setNextSegment(oldHead);

    scene.draw(newHead);

    snakeSegment = newHead;
}

void SnakeGame::retractTail()
{
    SnakeSegment *tailSegment = getTail();
    scene.erase(tailSegment);
    removeTail();
}

GridLocation SnakeGame::getNextLocation(SnakeSegment *snakeSegment)
{
    GridLocation nextLocation;

    nextLocation.column = snakeSegment->getColumn() + 1;
    nextLocation.row = snakeSegment->getRow();

    return nextLocation;
}

GridLocation SnakeGame::getAppleLocation()
{
    GridLocation appleLocation;

    appleLocation.column = apple.getColumn();
    appleLocation.row = apple.getRow();

    return appleLocation;
}

SnakeSegment *SnakeGame::getTail()
{
    return snakeSegment->getNextSegment();
}

SnakeSegment *SnakeGame::getHead()
{
    return snakeSegment;
}

void SnakeGame::removeTail()
{
    SnakeSegment* tailSegment = getTail();
    snakeSegment->removeNextSegment();
    delete tailSegment;
}

bool SnakeGame::isOver()
{
    return false;
}

bool SnakeGame::reachedAnApple()
{
    if (getNextLocation(snakeSegment) == getAppleLocation()) {
        return true;
    }

    return false;
}

SnakeGame *SnakeGame::startUp()
{
    scene.begin();

    snakeSegment = new SnakeSegment();
    snakeSegment->setColumn(0);
    snakeSegment->setRow(5);
    scene.draw(snakeSegment);

    drawApple();

    return this;
}

SnakeGame *SnakeGame::moveSnake()
{
    if (snakeSegment->getColumn() > 14) {
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

