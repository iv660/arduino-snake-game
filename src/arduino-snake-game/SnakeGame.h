#if !defined(SNAKE_GAME_H)
#define SNAKE_GAME_H

#include "Scene.h"
#include "Apple.h"
#include "SnakeSegment.h"
#include "GridLocation.h"
#include "Snake.h"
#include "Direction.h"

class SnakeGame
{
private:
    Scene scene;
    Apple apple;
    Snake snake;

    void drawSnake(SnakeSegment *snakeSegment);
    void drawApple();
    void stretchHead();
    void retractTail();
    GridLocation getNextLocation(SnakeSegment *snakeSegment);
    GridLocation getAppleLocation();
    SnakeSegment *getTail();
    SnakeSegment *getHead();
    void removeTail();
    Direction getDirection();
    bool locationIsOutOfBounds(GridLocation location);

public:
    bool isOver();
    bool reachedAnApple();
    SnakeGame* startUp();
    SnakeGame* moveSnake();
    SnakeGame* growSnake();
    SnakeGame* deductScore();
    SnakeGame* placeNewApple();
    SnakeGame* removeApple();
    SnakeGame* increaseScore();
    void end();
};

#endif // SNAKE_GAME_H
