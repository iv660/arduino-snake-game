#include <Arduino.h>
#include "TimebombChallenge.h"

bool TimebombChallenge::isTimeToArm(SnakeGameState state)
{
    if (state.level < TIMEBOMBS_STARTING_LEVEL) {
        return false;
    }

    if (timebomb.isArmed()) {
        return false;
    }

    if (random(1, getActivationTreshold(state)) == 1) {
        return true;
    }
    
    return false;
}

void TimebombChallenge::armTimebomb()
{
    GridLocation vacantLocation = gridAllocator.getRandomVacantLocation();
    timebomb.setColumn(vacantLocation.column);
    timebomb.setRow(vacantLocation.row);

    timebomb.armFor(15000);
}

void TimebombChallenge::redraw()
{
    if (!timebomb.isArmed()) {
        return;
    }

    scene->erase(&timebomb);
    scene->draw(&timebomb);
}

bool TimebombChallenge::pausedStateHasChanged(bool newPausedState)
{
    return isPaused != newPausedState;
}

bool TimebombChallenge::gotPaused(bool newPausedState)
{
    if (!pausedStateHasChanged(newPausedState)) {
        return false;
    }

    if (true == newPausedState) {
        return true;
    }

    return false;
}

bool TimebombChallenge::gotUnpaused(bool newPausedState)
{
    if (!pausedStateHasChanged(newPausedState)) {
        return false;
    }

    if (false == newPausedState) {
        return true;
    }

    return false;
}

unsigned int TimebombChallenge::getActivationTreshold(SnakeGameState state)
{
    int treshold = BASE_ACTIVATION_TRESHOLD - ((state.level - TIMEBOMBS_STARTING_LEVEL) * 10);

    if (treshold < MIN_ACTIVATION_TRESHOLD) {
        return MIN_ACTIVATION_TRESHOLD;
    }

    return treshold;
}

TimebombChallenge *TimebombChallenge::setScene(Scene *scene)
{
    this->scene = scene;

    return this;
}

TimebombChallenge *TimebombChallenge::setGridAllocator(
    GridAllocator gridAllocator)
{
    this->gridAllocator = gridAllocator;

    return this;
}

bool TimebombChallenge::occupies(GridLocation location)
{
    if (timebomb.getLocation() == location) {
        return true;
    }

    return false;
}

void TimebombChallenge::startCycle(SnakeGameState state)
{
    if (isTimeToArm(state)) {
        armTimebomb();
    }

    redraw();
}

void TimebombChallenge::endCycle()
{

}

void TimebombChallenge::startRound()
{
    timebomb.reset();
}

bool TimebombChallenge::hasFailed()
{
    return timebomb.hasGoneOff();
}

void TimebombChallenge::setPausedState(bool isPaused)
{
    if (gotPaused(isPaused)) {
        timebomb.pause();
    }

    if (gotUnpaused(isPaused)) {
        timebomb.resume();
    }

    this->isPaused = isPaused;
}

void TimebombChallenge::handleCollisionAt(GridLocation location)
{
    if (timebomb.getLocation() == location) {
        scene->erase(&timebomb);
        timebomb.reset();
    }
}
