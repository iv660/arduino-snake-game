#include <Arduino.h>
#include "Timebomb.h"

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
    return "*";
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
}

bool Timebomb::isArmed()
{
    return armedAt > 0;
}

bool Timebomb::hasGoneOff()
{
    return false;
}

void Timebomb::reset()
{
}
