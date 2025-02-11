#include <EEPROM.h>
#include "SnakeGame.h"
#include "StartupScreenLayout.h"
#include "GameOverScreenLayout.h"
#include "HighScore.h"
#include "LevelInfoScreenLayout.h"
#include "Movement.h"
#include "freeMemory.h"

SnakeGameState SnakeGame::getState()
{
    SnakeGameState state;

    state.level = level;

    return state;
}

GridAllocator SnakeGame::getGridAllocator()
{
    GridAllocator allocator;

    allocator.setGridColumns(scene.getColumns())
        ->setGridRows(scene.getRows())
        ->addOccupant(&snake)
        ->addOccupant(&apple)
        ->addOccupant(&challengeDispatcher);

    return allocator;
}

void SnakeGame::showStartupScreen()
{
    scene.clear();
    
    StartupScreenLayout().setScreen(appliance.screen)->render();

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

    scene.render(apple);
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
    GridLocation nextLocation = Movement().calculateNextLocation(snakeSegment->getLocation(), getDirection());

    return afterGettingNextLocation(snakeSegment->getLocation(), nextLocation);
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
    return getGridAllocator().getRandomVacantLocation();
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

void SnakeGame::beforeRoundStart()
{
    challengeDispatcher.beforeRoundStart();
}

GridLocation SnakeGame::afterGettingNextLocation(GridLocation currentLocation, GridLocation nextLocation)
{
    return challengeDispatcher.adjustNextLocation(currentLocation, nextLocation);
}

void SnakeGame::afterUpdateDirection(Direction newDirection)
{
    challengeDispatcher.setDirection(newDirection);
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

    if (challengeLocationIsOutOfBounds(location)) {
        return true;
    }

    return false;
}

bool SnakeGame::challengeLocationIsOutOfBounds(GridLocation location)
{
    return challengeDispatcher.locationIsOutOfBounds(location);
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

bool SnakeGame::memoryIsLow()
{
    if (freeMemory() < FREE_MEMORY_REQUIREMENT) {
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
    getHead()->setColumn(1);
    getHead()->setRow(5);
    getHead()->show();
    scene.draw(getHead());
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

void SnakeGame::setSnakeLengthForNextLevel(unsigned long lengthRequirement)
{
    snakeLengthForNextLevel = lengthRequirement;
    snakeLengthForNextLevel = challengeDispatcher.adjustLengthRequirementForNextLevel(snakeLengthForNextLevel);
}

void SnakeGame::updateLengthLevelRequirement()
{
    if (snakeLengthForNextLevel + SNAKE_LENGTH_REQUIREMENT_GROWTH > MAX_SNAKE_LENGTH) {
        return;
    }

    unsigned long maxLengthToFitOnScreen = scene.getRows() * scene.getColumns() / 2;

    if (snakeLengthForNextLevel + SNAKE_LENGTH_REQUIREMENT_GROWTH > maxLengthToFitOnScreen) {
        return;
    }

    setSnakeLengthForNextLevel(snakeLengthForNextLevel + SNAKE_LENGTH_REQUIREMENT_GROWTH);

}

void SnakeGame::initLevel()
{
    level = 1;
    challengeDispatcher.updateState(getState());

    setSnakeLengthForNextLevel(INITIAL_LENGTH_REQUIREMENT);
    lives = INITIAL_LIVES;
}

HighScores SnakeGame::loadHighScores()
{
    return storage.getHighScores();
}

void SnakeGame::unpause()
{
    paused = false;
    appliance.pauseButton->reset();
}

void SnakeGame::setAppliance(XC::Hardware::Appliance appliance)
{
    this->appliance = appliance;
    scene.setScreen(this->appliance.screen);
}

bool SnakeGame::isPaused()
{
    return paused;
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
    
    unpause();
    moveSnakeToStartingPoint();
    
    beforeRoundStart();
    placeNewApple();
    challengeDispatcher.startRound();

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

    return snake.occupies(location);
}

void SnakeGame::updateDirection()
{
    switch (appliance.directionSwitch->getDirection()) {
        case XC::Hardware::DirectionSwitchInterface::Direction::LEFT:
            direction = Direction::LEFT;
            break;
        case XC::Hardware::DirectionSwitchInterface::Direction::RIGHT:
            direction = Direction::RIGHT;
            break;
        case XC::Hardware::DirectionSwitchInterface::Direction::UP:
            direction = Direction::UP;
            break;
        case XC::Hardware::DirectionSwitchInterface::Direction::DOWN:
            direction = Direction::DOWN;
            break; 
    }

    afterUpdateDirection(direction);
}

void SnakeGame::updatePausedState()
{
    appliance.pauseButton->tick();
    paused = appliance.pauseButton->isOn();
    challengeDispatcher.setPausedState(paused);
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

    if (challengeDispatcher.hasFailed()) {
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

    shuffle();
    initLevel();
    initDirectionControl();

    showStartupScreen();
    resetSnake();
    highScores = loadHighScores();

    challengeDispatcher.setScene(&scene)
        ->setGridAllocator(getGridAllocator());

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
        .setScreen(appliance.screen)
        ->setLevel(level)
        ->render();
    return this;
}

bool SnakeGame::reachedLevelUp()
{
    if (memoryIsLow()) {
        // Force level up to avoid running out of memory
        return true;
    }

    if (snake.getLength() >= snakeLengthForNextLevel) {
        return true;
    }

    return false;
}

SnakeGame *SnakeGame::levelUp()
{
    level++;
    challengeDispatcher.updateState(getState());

    resetSnake();
    direction = Direction::RIGHT;
    updateLengthLevelRequirement();
    applyLifeBonus();


    return this;
}

void SnakeGame::endCycle()
{
    while ((millis() - cycleStartTime) < 300) {
        updateDirection();
        updatePausedState();
    }

    challengeDispatcher.endCycle();
}

SnakeGame *SnakeGame::startCycle()
{
    cycleStartTime = millis();
    
    SnakeGameState state = getState();
    challengeDispatcher.startCycle(state);
    challengeDispatcher.handleCollisionAt(getNextLocation(getHead()));

    return this;
}

void SnakeGame::end()
{
    scene.clear();

    GameOverScreenLayout().setScreen(appliance.screen)
        ->setHighScores(highScores)
        ->setScore(score)
        ->render();

    delay(6000);
    scene.clear();
}

