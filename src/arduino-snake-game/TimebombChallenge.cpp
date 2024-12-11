#include "TimebombChallenge.h"

bool TimebombChallenge::isTimeToArm(SnakeGameState state)
{
    if (state.level < MIN_LEVEL) {
        return false;
    }

    if (timebomb.isArmed()) {
        return false;
    }
    
    return true;
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

TimebombChallenge::handleCollisionAt(GridLocation location)
{
    if (timebomb.getLocation() == location) {
        scene->erase(&timebomb);
        timebomb.reset();
    }
}
