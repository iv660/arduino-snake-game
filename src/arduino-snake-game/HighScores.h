#if !defined(HIGH_SCORES_H)
#define HIGH_SCORES_H

#include "HighScore.h"

class HighScores
{
private:
    static const unsigned int MAX_HIGH_SCORES = 3;
    HighScore scores[MAX_HIGH_SCORES];
    void shiftLowerScoresDown(unsigned int fromIndex);
public:
    unsigned int getSize();
    HighScore get(unsigned int position);
    void addCandidate(unsigned long score);
    HighScores* setHighScore(unsigned int position, unsigned long score);
};


#endif // HIGH_SCORES_H
