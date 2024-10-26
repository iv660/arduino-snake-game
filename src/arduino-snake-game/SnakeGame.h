#if !defined(SNAKE_GAME_H)
#define SNAKE_GAME_H

#include "Scene.h"
#include "Apple.h"
#include "SnakeSegment.h"
#include "GridLocation.h"
#include "Snake.h"
#include "Direction.h"
#include "TFT.h"

#define STORAGE_ADDRESS 0
#define STORAGE_KEY_ADDRESS STORAGE_ADDRESS + sizeof(highScore)
#define STORAGE_KEY 17

class SnakeGame
{
private:
    Scene scene;
    Apple apple;
    Snake snake;
    TFT screen = TFT(cs, dc, rst);

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
    SnakeGame();
    
    /**
     * @brief Returns true if the game is over, false otherwise.
     *
     * This happens when the snake's head is out of bounds or when the snake
     * hits itself.
     *
     * @return True if the game is over, otherwise false.
     */
    bool isOver();

    /**
     * @brief Returns true if the snake has reached an apple, false otherwise.
     *
     * This happens if the location of the snake's head is equal to the location of
     * the apple.
     *
     * @return True if the snake has reached an apple, otherwise false.
     */
    bool reachedAnApple();

    /**
     * @brief Starts a new game.
     *
     * Resets the game state and initializes the game UI.
     *
     * @return A pointer to the current SnakeGame instance.
     */
    SnakeGame* startUp();

    /**
     * @brief Moves the snake one segment in the current direction.
     *
     * This does not check if the snake has reached an apple or if the game is over.
     *
     * @return A pointer to the current SnakeGame instance.
     */
    SnakeGame* moveSnake();

    /**
     * @brief Increases the length of the snake by one segment.
     *
     * @return A pointer to the current SnakeGame instance.
     */
    SnakeGame* growSnake();

    /**
     * @brief Decreases the score by 1, unless it is already 0.
     *
     * @return A pointer to the current SnakeGame instance.
     */
    SnakeGame* deductScore();

    /**
     * @brief Places a new apple in the game.
     *
     * @return A pointer to the current SnakeGame instance.
     */
    SnakeGame* placeNewApple();

    /**
     * @brief Removes the apple from the scene.
     *
     * This function erases the apple from the current scene,
     * effectively removing it from the display.
     *
     * @return A pointer to the current SnakeGame instance.
     */
    SnakeGame* removeApple();

    /**
     * @brief Increases the score by a certain amount of points.
     *
     * @return A pointer to the current SnakeGame instance.
     */
    SnakeGame* increaseScore();

    /**
     * @brief Reduces the number of lives left by one and shows a "life lost" animation.
     *
     * @return A pointer to the current SnakeGame instance.
     */
    SnakeGame* loseLife();

    /**
     * @brief Initializes a new round.
     *
     * @return A pointer to the current SnakeGame instance.
     */
    SnakeGame* startRound();

    /**
     * @brief Updates the high score if the current score is higher than the high score.
     *
     * @return A pointer to the current SnakeGame instance.
     */
    SnakeGame* updateHighScore();

    /**
     * @brief Returns true if the game has lives left, false otherwise.
     *
     * @return True if there are lives left, otherwise false.
     */
    bool hasLivesLeft();

    /**
     * @brief This function waits for a certain amount of time before continuing
     * execution. It is used to create a delay between the frames of the game.
     * The function also updates the direction of the snake while it is waiting
     * so that the user can change the direction of the snake during the delay.
     */
    void slowDown();

    /**
     * @brief Displays the game over screen.
     */
    void end();
};

#endif // SNAKE_GAME_H
