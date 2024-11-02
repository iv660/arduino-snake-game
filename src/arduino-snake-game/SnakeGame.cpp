#include <EEPROM.h>
#include "SnakeGame.h"
#include "StartupScreenLayout.h"
#include "GameOverScreenLayout.h"
#include "HighScore.h"
#include "LevelInfoScreenLayout.h"

#define VRX_PIN A0
#define VRY_PIN A1
#define RANDOM_SEED_PIN A2

void SnakeGame::showStartupScreen()
{
    scene.clear();
    
    StartupScreenLayout().setScreen(&screen)->render();

    while (direction == Direction::NONE) {
        updateDirection();
    }

    scene.clear();
}

void SnakeGame::shuffle()
{
    randomSeed(analogRead(RANDOM_SEED_PIN));
}

void SnakeGame::initDirectionControl()
{
    pinMode(VRX_PIN, INPUT);
    pinMode(VRY_PIN, INPUT);
    direction = Direction::NONE;
}

void SnakeGame::placeNewSnake()
{
    resetSnake();
    moveSnakeToStartingPoint();
    scene.draw(getHead());
}

void SnakeGame::resetSnake()
{
    snake.reset();
}

void SnakeGame::drawSnake(SnakeSegment *snakeSegment)
{
    SnakeSegment *currentSegment = snakeSegment;
    do {
        scene.draw(currentSegment);
    } while ((currentSegment = currentSegment->getNextSegment()) != nullptr);

}

void SnakeGame::drawApple(Apple *apple)
{
    GridLocation location = getNewAppleLocation();
    apple->setColumn(location.column);
    apple->setRow(location.row);

    scene.draw(apple);
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

Apple SnakeGame::getNewApple()
{
    GridLocation location = getNewAppleLocation();
    Apple newApple;
    newApple.setColumn(location.column);
    newApple.setRow(location.row);

    return newApple;
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

GridLocation SnakeGame::getNewAppleLocation()
{
    GridLocation newLocation;

    do {
        long newColumn = random(0, scene.getColumns() - 1);
        long newRow = random(0, scene.getRows() - 1);
        
        newLocation.column = newColumn;
        newLocation.row = newRow;
    } while (locationIsOccupied(newLocation));

    return newLocation;
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

bool SnakeGame::locationIsOccupied(GridLocation location)
{
    if (hitsSnake(location)) {
        return true;
    }

    if (hitsApple(location)) {
        return true;
    }

    return false;
}

bool SnakeGame::hitsApple(GridLocation location)
{
    if (getAppleLocation().column == location.column
        && getAppleLocation().row == location.row) {
        return true;
    }   

    return false;
}

void SnakeGame::showLifeLostScreen(int livesBefore, int livesAfter)
{
    char messageBuffer[16];

    scene.clear();
    sprintf(messageBuffer, "Lives: %d", livesBefore);
    scene.putText(messageBuffer, 3, 3);
    
    delay(500);
    
    scene.clear();
    sprintf(messageBuffer, "Lives: %d", livesAfter);
    scene.putText(messageBuffer, 3, 3);

    scene.putSmallText("Push joystick to continue", 1, 5);

    waitForDirection();
    scene.clear();
}

void SnakeGame::moveSnakeToStartingPoint()
{
    snake.clearLocations();
    getHead()->setColumn(0);
    getHead()->setRow(5);
    getHead()->show();
}

void SnakeGame::waitForDirection()
{
    while (direction == Direction::NONE) {
        updateDirection();
    }
}

void SnakeGame::storeHighScores(HighScores highScores)
{
    storage.storeHighScores(highScores);
}

inline void SnakeGame::applyLifeBonus()
{
    if (lives >= MAX_LIVES) {
        return;
    }

    lives++;
}

inline void SnakeGame::updateLengthLevelRequirement()
{
    unsigned long maxLength = scene.getRows() * scene.getColumns() / 2;

    if (snakeLengthForNextLevel + SNAKE_LENGTH_REQUIREMENT_GROWTH > maxLength) {
        return;
    }

    snakeLengthForNextLevel += SNAKE_LENGTH_REQUIREMENT_GROWTH;
}

void SnakeGame::initLevel()
{
    level = 1;
    snakeLengthForNextLevel = INITIAL_LENGTH_REQUIREMENT;
    lives = 3;
}

HighScores SnakeGame::loadHighScores()
{
    return storage.getHighScores();
}

SnakeGame::SnakeGame()
{
    scene.setScreen(&screen);
}

bool SnakeGame::hasLivesLeft()
{
    if (lives > 0) {
        return true;
    }

    return false;
}

SnakeGame *SnakeGame::loseLife()
{
    initDirectionControl();
    showLifeLostScreen(lives, lives - 1);
    lives--;

    return this;
}

SnakeGame *SnakeGame::startRound()
{
    scene.clear();
    moveSnakeToStartingPoint();
    placeNewApple();

    return this;
}

SnakeGame *SnakeGame::updateHighScore()
{
    if (highScores.updateHighScore(score)) {
        storeHighScores(highScores);
    }

    return this;
}

bool SnakeGame::hitsSnake(GridLocation location)
{
    if (getDirection() == Direction::NONE) {
        return false;
    }

    SnakeSegment *snakeSegment = snake.getHead();
    
    do {
        if (snakeSegment->getColumn() == location.column 
            && snakeSegment->getRow() == location.row
            && snakeSegment->isVisible()) {
            return true;
        }
        snakeSegment = snakeSegment->getNextSegment();
    } while (snakeSegment != nullptr);

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
    GridLocation nextLocation = getNextLocation(getHead());
    if (locationIsOutOfBounds(nextLocation)) {
        return true;
    }

    if (hitsSnake(nextLocation)) {
        return true;
    }

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

    score = 0;
    lives = 3;

    shuffle();
    initLevel();
    initDirectionControl();
    showStartupScreen();
    resetSnake();
    highScores = loadHighScores();

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
    if (score == 0) {
        return this;
    }

    score--;

    return this;
}

SnakeGame *SnakeGame::placeNewApple()
{
    apple = getNewApple();
    drawApple(&apple);

    return this;
}

SnakeGame *SnakeGame::removeApple()
{
    scene.erase(&apple);
    return this;
}

SnakeGame *SnakeGame::increaseScore()
{
    score += bonus;
    return this;
}

SnakeGame *SnakeGame::showLevelInfo()
{
    LevelInfoScreenLayout()
        .setScreen(&screen)
        ->setLevel(level)
        ->render();
    return this;
}

bool SnakeGame::reachedLevelUp()
{
    if (snake.getLength() >= snakeLengthForNextLevel) {
        return true;
    }

    return false;
}

SnakeGame *SnakeGame::levelUp()
{
    level++;
    resetSnake();
    direction = Direction::RIGHT;
    updateLengthLevelRequirement();
    applyLifeBonus();

    return this;
}

void SnakeGame::slowDown()
{
    unsigned long startTime = millis();

    while ((millis() - startTime) < 300) {
        updateDirection();
    }
}

void SnakeGame::end()
{
    scene.clear();

    GameOverScreenLayout().setScreen(&screen)
        ->setHighScores(highScores)
        ->setScore(score)
        ->render();

    delay(6000);
    scene.clear();
}

