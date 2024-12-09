#include "TimebombChallenge.h"

bool TimebombChallenge::isTimeToArm()
{
    return false;
}

void TimebombChallenge::armTimebomb()
{
    timebomb.armFor(15000);
}

void TimebombChallenge::redraw()
{
    if (!timebomb.isArmed()) {
        return;
    }

    scene->draw(&timebomb);
}

TimebombChallenge *TimebombChallenge::setScene(Scene *scene)
{
    this->scene = scene;

    return this;
}

void TimebombChallenge::startCycle()
{
    if (isTimeToArm()) {
        armTimebomb();
    }

    redraw();
}

void TimebombChallenge::endCycle()
{

}

bool TimebombChallenge::hasFailed()
{
    return timebomb.hasGoneOff();
}
