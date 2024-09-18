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

    Direction direction = Direction::NONE;
    void shuffle();
    void drawSnake(SnakeSegment *snakeSegment);
    void drawApple(Apple *apple);
    void stretchHead();
    void retractTail();
    Apple getNewApple();
    GridLocation getNextLocation(SnakeSegment *snakeSegment);
    GridLocation getAppleLocation();
    GridLocation getNewAppleLocation();
    SnakeSegment *getTail();
    SnakeSegment *getHead();
    void removeTail();
    Direction getDirection();
    bool locationIsOutOfBounds(GridLocation location);
    void updateDirection();

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
    void delay();
    void end();
};

#endif // SNAKE_GAME_H
