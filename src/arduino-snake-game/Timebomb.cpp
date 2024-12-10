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

int Timebomb::getColumn()
{
    return 0;
}

int Timebomb::getRow()
{
    return 0;
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
    return this;
}

Timebomb *Timebomb::setRow(int row)
{
    return this;
}

void Timebomb::armFor(long detonationDelay)
{
    armedAt = millis();
    this->detonationDelay = detonationDelay;
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
}
