#if !defined(SNAKE_GAME_H)
#define SNAKE_GAME_H

#define VRX_PIN A0
#define VRY_PIN A1
#define RANDOM_SEED_PIN A2

#include "Appliance.h"
#include "Scene.h"
#include "Apple.h"
#include "SnakeSegment.h"
#include "GridLocation.h"
#include "Snake.h"
#include "Direction.h"
#include "const.h"
#include "HighScores.h"
#include "Storage.h"
#include "TimebombChallenge.h"
#include "SnakeGameState.h"
#include "GridAllocator.h"
#include "HyperspaceChallenge.h"

class SnakeGame
{
private:
    // Constants
    static const long INITIAL_LENGTH_REQUIREMENT = 15;
    static const unsigned long SNAKE_LENGTH_REQUIREMENT_GROWTH = 5;
    static const int INITIAL_LIVES = 3;
    static const int MAX_LIVES = 5;

    // Dependencies
    XC::Hardware::Appliance appliance;

    Scene scene;
    Apple apple;
    Snake snake;


    TimebombChallenge timebombChallenge;
    HyperspaceChallenge hyperspaceChallenge;

    HighScores highScores;
    Storage storage;

    // Game state
    Direction direction = Direction::NONE;
    const unsigned long bonus = 100;
    unsigned long snakeLengthForNextLevel = INITIAL_LENGTH_REQUIREMENT;
    unsigned long score = 0;
    unsigned int level = 1;
    int lives = INITIAL_LIVES;
    char lifeIcon = (char) 0x2b; // (char) 0x3;
    bool paused = false;
    long cycleStartTime = 0;

    // Common accessors
    SnakeGameState getState();
    GridAllocator getGridAllocator();

    // Startup
    void initLevel();
    void initDirectionControl();
    void showStartupScreen();
    void showLifeLostScreen(int livesBefore, int livesAfter);
    HighScores loadHighScores();
    void storeHighScores(HighScores highScores);
    inline void updateLengthLevelRequirement();

    // Game lifecycle
    // void beforeMoveSnake();
    void beforeRoundStart();
    GridLocation afterGettingNextLocation(GridLocation currentLocation, GridLocation nextLocation);
    
    // Direction
    Direction getDirection();
    void updateDirection();
    void waitForDirection();
    
    // Game objects
    SnakeSegment *getTail();
    SnakeSegment *getHead();
    Apple getNewApple();
    GridLocation getAppleLocation();
    GridLocation getNewAppleLocation();

    // Game actions
    void unpause();
    void shuffle();
    void drawSnake(SnakeSegment *snakeSegment);
    void drawApple(Apple *apple);
    void placeNewSnake();
    void resetSnake();
    void moveSnakeToStartingPoint();
    void stretchHead();
    void retractTail();
    void removeTail();
    inline void applyLifeBonus();
    
    // Location & collisions
    GridLocation getNextLocation(SnakeSegment *snakeSegment);
    bool locationIsOutOfBounds(GridLocation location);
    bool locationIsOccupied(GridLocation location);
    bool hitsSnake(GridLocation location);
    bool hitsApple(GridLocation location);

public:
    void setAppliance(XC::Hardware::Appliance appliance);

    void updatePausedState();
    bool isPaused();
    
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
     * @brief Shows information about the current level.
     *
     * @return A pointer to the current SnakeGame instance.
     */
    SnakeGame* showLevelInfo();

    /**
     * @brief Checks if the snake has reached the next level.
     *
     * @return True if the snake has reached the next level, otherwise false.
     */
    bool reachedLevelUp();

    /**
     * @brief Increases level by one and applies level bonuses.
     *
     * @return A pointer to the current SnakeGame instance.
     */
    SnakeGame* levelUp();

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
    void endCycle();

    /**
     * @brief Starts a new game cycle.
     * 
     * @return A pointer to the current SnakeGame instance.
     */
    SnakeGame* startCycle();

    /**
     * @brief Displays the game over screen.
     */
    void end();
};

#endif // SNAKE_GAME_H
