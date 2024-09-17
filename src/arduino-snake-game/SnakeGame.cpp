#include "SnakeGame.h"

#define VRX_PIN A0
#define VRY_PIN A1

void SnakeGame::drawSnake(SnakeSegment* snakeSegment)
{
    SnakeSegment *currentSegment = snakeSegment;
    do {
        scene.draw(currentSegment);
    } while ((currentSegment = currentSegment->getNextSegment()) != nullptr);

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
    snake.stretchHeadTo(nextLocation);
    scene.draw(snake.getHead());
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

    switch (getDirection()) {
        case Direction::RIGHT:
            nextLocation.column = snakeSegment->getColumn() + 1;
            nextLocation.row = snakeSegment->getRow();
            break;

        case Direction::LEFT:   
            nextLocation.column = snakeSegment->getColumn() - 1;
            nextLocation.row = snakeSegment->getRow();
            break;

        case Direction::UP:
            nextLocation.column = snakeSegment->getColumn();
            nextLocation.row = snakeSegment->getRow() - 1;
            break;

        case Direction::DOWN:
            nextLocation.column = snakeSegment->getColumn();
            nextLocation.row = snakeSegment->getRow() + 1;
            break;

        default:
            nextLocation.column = snakeSegment->getColumn();
            nextLocation.row = snakeSegment->getRow();
            break;
    }

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
    return snake.getTail();
}

SnakeSegment *SnakeGame::getHead()
{
    return snake.getHead();
}

void SnakeGame::removeTail()
{
    snake.removeTail();
}

Direction SnakeGame::getDirection()
{
    return direction;
}

bool SnakeGame::locationIsOutOfBounds(GridLocation location)
{
    if (location.column < 0 ) {
        return true;
    }

    if (location.row < 0) {
        return true;
    }

    if (location.column > scene.getColumns() - 1) {
        return true;
    }

    if (location.row > scene.getRows() - 1) {
        return true;
    }

    return false;
}



void SnakeGame::updateDirection()
{
    long xValue = analogRead(VRX_PIN);
    long yValue = analogRead(VRY_PIN);

    if (xValue > 1000) {
        direction = Direction::RIGHT;
    } else if (xValue < 23) {
        direction = Direction::LEFT;
    } else if (yValue > 1000) {
        direction = Direction::DOWN;
    } else if (yValue < 23) {
        direction = Direction::UP;
    }
}

bool SnakeGame::isOver()
{
    return false;
}

bool SnakeGame::reachedAnApple()
{
    if (getNextLocation(getHead()) == getAppleLocation()) {
        return true;
    }

    return false;
}

SnakeGame *SnakeGame::startUp()
{
    scene.begin();

    pinMode(VRX_PIN, INPUT);
    pinMode(VRY_PIN, INPUT);

    getHead()->setColumn(0);
    getHead()->setRow(5);
    scene.draw(getHead());

    drawApple();

    return this;
}

SnakeGame *SnakeGame::moveSnake()
{
    GridLocation nextLocation = getNextLocation(getHead());
    if (locationIsOutOfBounds(nextLocation)) {
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

void SnakeGame::delay()
{
    unsigned long startTime = millis();

    while ((millis() - startTime) < 300) {
        updateDirection();
    }
}

void SnakeGame::end()
{
}

