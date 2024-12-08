#if !defined(HIGH_SCORE_STATE_H)
#define HIGH_SCORE_STATE_H

struct HighScoreState {
    char name[6] = "";
    unsigned long score = 0;
};

#endif // HIGH_SCORE_STATE_H
