#if !defined(HIGH_SCORES_H)
#define HIGH_SCORES_H

#include "const.h"
#include "HighScore.h"

class HighScores
{
private:
    HighScore scores[MAX_HIGH_SCORES];
    void shiftLowerScoresDown(unsigned int fromIndex);
public:
    unsigned int getSize();
    HighScore get(unsigned int position);
    bool updateHighScore(unsigned long score);
    HighScores* setHighScore(unsigned int position, unsigned long score);
};


#endif // HIGH_SCORES_H
