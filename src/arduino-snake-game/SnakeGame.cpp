#include "SnakeGame.h"

void SnakeGame::drawSnake(SnakeSegment* snakeSegment)
{
    scene.draw(snakeSegment);
}

void SnakeGame::drawApple()
{
    apple.setColumn(12);
    apple.setRow(2);

    scene.draw(&apple);
}

void SnakeGame::stretchHead()
{
    SnakeSegment *oldSegment = snakeSegment;
    
    int newXPosition = snakeSegment->getColumn() + 1;
    int newYPosition = snakeSegment->getRow();
    SnakeSegment *newHead = new SnakeSegment();
    newHead->setColumn(newXPosition);
    newHead->setRow(newYPosition);
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
    snakeSegment->setColumn(3);
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

