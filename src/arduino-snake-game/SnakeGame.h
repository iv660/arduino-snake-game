#if !defined(SNAKE_GAME_H)
#define SNAKE_GAME_H

#include "Scene.h"
#include "Apple.h"
#include "SnakeSegment.h"
#include "GridLocation.h"
#include "Snake.h"
#include "Direction.h"

#define STORAGE_ADDRESS 0
#define STORAGE_KEY_ADDRESS STORAGE_ADDRESS + sizeof(highScore)
#define STORAGE_KEY 17

class SnakeGame
{
private:
    Scene scene;
    Apple apple;
    Snake snake;

    Direction direction = Direction::NONE;
    const unsigned long bonus = 100;
    unsigned long score = 0;
    unsigned long highScore = 0;
    int lives = 3;
    char lifeIcon = (char) 0x2b; // (char) 0x3;

    void showStartupScreen();
    void shuffle();
    void initDirectionControl();
    void placeNewSnake();
    void resetSnake();
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
    bool locationIsOccupied(GridLocation location);
    bool hitsSnake(GridLocation location);
    bool hitsApple(GridLocation location);
    void showLifeLostScreen(int livesBefore, int livesAfter);
    void moveSnakeToStartingPoint();
    void waitForDirection();
    void storeHighScore(unsigned long highScore);
    unsigned long loadHighScore();
    bool hasStoredHighScore();
    void initStorage();

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
    SnakeGame* loseLife();
    SnakeGame* startRound();
    SnakeGame* updateHighScore();
    bool hasLivesLeft();
    void slowDown();
    void end();
};

#endif // SNAKE_GAME_H
