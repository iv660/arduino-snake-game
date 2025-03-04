#if !defined(GAME_OVER_SCREEN_LAYOUT_H)
#define GAME_OVER_SCREEN_LAYOUT_H

#include "TabbedText.h"
#include "HighScores.h"
#include "BaseScreenLayout.h"

class GameOverScreenLayout : public BaseScreenLayout<GameOverScreenLayout>
{
private:
    HighScores highScores;
    unsigned long score = 0;
    unsigned int leaderPositionTabStop = 10;
    unsigned int leaderNameTabStop = 26;
    unsigned int leaderScoreTabStop = 116;
    unsigned int cursorY = 0;
    unsigned int lineHeight = 10;
    unsigned int textSize = 1;
    unsigned int baseCharWidth = 6;

    void initScreen();
    void renderGameOverTitle();
    void renderScore();
    void renderHighScores();
    TabbedText tabs();
    GameOverScreenLayout* newLine();
    GameOverScreenLayout* setTextSize(unsigned int size);
    char* toFormat(char* format, unsigned long number);

public:
    void render();
    using BaseScreenLayout<GameOverScreenLayout>::setScreen;
    GameOverScreenLayout* setHighScores(HighScores highScores);
    GameOverScreenLayout* setScore(unsigned long score);
};


#endif // GAME_OVER_SCREEN_LAYOUT_H
