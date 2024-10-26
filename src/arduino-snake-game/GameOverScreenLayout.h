#if !defined(GAME_OVER_SCREEN_LAYOUT_H)
#define GAME_OVER_SCREEN_LAYOUT_H

#include "TFT.h"

class GameOverScreenLayout {
private:
    TFT* screen;
    unsigned long highScore;
    unsigned long score = 0;
    unsigned int leaderPositionTabStop = 0;
    unsigned int leaderNameTabStop = 16;
    unsigned int leaderScoreTabStop = 100;

    void initScreen();
    void renderGameOverTitle();
    void renderScore();
    char* toString(unsigned long number);
    void renderHighScores();
    // void wait(unsigned long ms);

public:
    void render();
    GameOverScreenLayout* setScreen(TFT* screen);
    GameOverScreenLayout* setHighScore(unsigned long highScore);
    GameOverScreenLayout* setScore(unsigned long score);
};


#endif // GAME_OVER_SCREEN_LAYOUT_H
