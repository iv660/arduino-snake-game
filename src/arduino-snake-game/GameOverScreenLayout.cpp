#include "GameOverScreenLayout.h"

void GameOverScreenLayout::initScreen()
{
    screen->background(0, 0, 0);
}

void GameOverScreenLayout::renderGameOverTitle()
{
    screen->stroke(255, 255, 255);
    screen->setTextSize(2);
    screen->text("GAME OVER", 20, 40);
}

void GameOverScreenLayout::renderScore()
{
    screen->stroke(255, 255, 255);
    screen->setTextSize(1);
    screen->text("Score:", leaderPositionTabStop, 60);
    screen->text(toString(score), leaderScoreTabStop, 60);
}

char *GameOverScreenLayout::toString(unsigned long number)
{
    static char buffer[10];
    sprintf(buffer, "%d", number);

    return buffer;
}

void GameOverScreenLayout::renderHighScores()
{
    screen->stroke(255, 255, 255);
    screen->setTextSize(1);
    screen->text("High score:", leaderPositionTabStop, 70);
    screen->text(toString(highScore), leaderScoreTabStop, 70);
}

void GameOverScreenLayout::render()
{
    initScreen();
    renderGameOverTitle();
    renderScore();
    renderHighScores();
}

GameOverScreenLayout *GameOverScreenLayout::setScreen(TFT *screen)
{
    this->screen = screen;
    
    return this;
}

GameOverScreenLayout *GameOverScreenLayout::setScore(unsigned long score)
{
    this->score = score;
    
    return this;
}

GameOverScreenLayout *GameOverScreenLayout::setHighScore(unsigned long highScore)
{
    this->highScore = highScore;
    
    return this;
}
