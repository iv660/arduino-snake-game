#include <string.h>
#include "HighScore.h"

HighScore::HighScore() : HighScore("", 0) { }

HighScore::HighScore(const char* name, unsigned long score)
{
    strncpy(this->name, name, sizeof(this->name));
    this->score = score;
}

const char* HighScore::getName() const
{
    return this->name;
}

unsigned long HighScore::getScore() const
{
    return this->score;
}
