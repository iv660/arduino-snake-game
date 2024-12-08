#if !defined(PERSISTENT_STATE_H)
#define PERSISTENT_STATE_H

#include "const.h"
#include "HighScoreState.h"

struct PersistentState {
    HighScoreState highScores[MAX_HIGH_SCORES];
};


#endif // PERSISTENT_STATE_H
