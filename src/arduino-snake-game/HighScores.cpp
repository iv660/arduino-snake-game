#include "HighScores.h"

void HighScores::shiftLowerScoresDown(unsigned int fromIndex)
{
    for (unsigned int index = MAX_HIGH_SCORES - 1; 
        index > fromIndex; index--) {
        scores[index] = scores[index - 1];
    }
}

unsigned int HighScores::getSize()
{
    return MAX_HIGH_SCORES;
}

HighScore HighScores::get(unsigned int position) {
    unsigned int index = position - 1;

    if (index <= MAX_HIGH_SCORES - 1) {
        return scores[index];
    }

    // Return a default HighScore if index is out of bounds
    return HighScore("", 0);
}

void HighScores::updateHighScore(unsigned long score) {
    for (unsigned int index = 0; index < MAX_HIGH_SCORES; index++) {
        if (score > scores[index].getScore()) {
            shiftLowerScoresDown(index);
            scores[index] = HighScore("", score); // Default name
            break;
        }
    }
}

HighScores *HighScores::setHighScore(unsigned int position, unsigned long score)
{
    scores[position - 1] = HighScore("", score);

    return this;
}
