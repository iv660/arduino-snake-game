#if !defined(SNAKE_GAME_H)
#define SNAKE_GAME_H

#include "Scene.h"
#include "Apple.h"
#include "SnakeSegment.h"

class SnakeGame
{
private:
    Scene scene;
    Apple apple;
    SnakeSegment *snakeSegment = nullptr;

    void drawSnake(SnakeSegment *snakeSegment);
    void drawApple();
    void stretchHead();
    void retractTail();
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
