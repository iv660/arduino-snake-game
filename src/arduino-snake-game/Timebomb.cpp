#include <Arduino.h>
#include "Timebomb.h"

char *Timebomb::getCounter()
{
    updateCouner();
    
    return counter;
}

void Timebomb::updateCouner()
{
    if (!isArmed()) {
        return;
    }

    if(hasGoneOff()) {
        return;
    }

    int interval = detonationDelay / 9;
    int counterValue = 9 - (millis() - armedAt) / interval;
    sprintf(counter, "%d", counterValue);
}

bool Timebomb::isPaused()
{
    return pausedAt > 0;
}

int Timebomb::getColumn()
{
    return column;
}

int Timebomb::getRow()
{
    return row;
}

char *Timebomb::getText()
{
    if (hasGoneOff()) {
        return "*";
    }

    return getCounter();
}

GridLocation Timebomb::getLocation()
{
    GridLocation location;
    location.column = column;
    location.row = row;

    return location;
}

Timebomb *Timebomb::setColumn(int column)
{
    this->column =  column;

    return this;
}

Timebomb *Timebomb::setRow(int row)
{
    this->row = row;

    return this;
}

void Timebomb::armFor(long detonationDelay)
{
    armedAt = millis();
    this->detonationDelay = detonationDelay;
}

void Timebomb::pause()
{
    if (!isArmed()) {
        return;
    }

    if (isPaused()) {
        return;
    }

    pausedAt = millis();
}

void Timebomb::resume()
{
    if (!isArmed()) {
        return;
    }

    if (!isPaused()) {
        return;
    }

    long hasBeenPausedFor = millis() - pausedAt;
    armedAt += hasBeenPausedFor;
}

bool Timebomb::isArmed()
{
    return armedAt > 0;
}

bool Timebomb::hasGoneOff()
{
    if (!isArmed()) {
        return false;
    }

    if (millis() > (armedAt + detonationDelay)) {
        return true;
    }

    return false;
}

void Timebomb::reset()
{
    armedAt = 0;
    detonationDelay = 0;
    pausedAt = 0;
}
