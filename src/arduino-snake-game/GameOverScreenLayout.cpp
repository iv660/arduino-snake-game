#include "GameOverScreenLayout.h"

void GameOverScreenLayout::initScreen()
{
    screen->background(0, 0, 0);
}

void GameOverScreenLayout::renderGameOverTitle()
{
    screen->stroke(255, 255, 255);
    screen->setTextSize(2);
    screen->text("0        1         2         3", 0, 0);
    screen->text("123456789012345678901234567890", 0, 16);
    screen->text("GAME OVER", 30, 25);
}

void GameOverScreenLayout::renderScore()
{
    screen->stroke(255, 255, 255);
    screen->setTextSize(1);
    screen->text("Your score:", leaderNameTabStop, cursorY);
    screen->text(toString(score), leaderScoreTabStop, cursorY);
    newLine();
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
    screen->text("High scores:", leaderNameTabStop, cursorY);
    newLine();
    screen->text("1.", leaderPositionTabStop, cursorY);
    screen->text(toString(highScore), leaderScoreTabStop, cursorY);
    newLine();
    screen->text("2.", leaderPositionTabStop, cursorY);
    screen->text(toString(0), leaderScoreTabStop, cursorY);
    newLine();
    screen->text("3.", leaderPositionTabStop, cursorY);
    screen->text(toString(0), leaderScoreTabStop, cursorY);
    newLine();
}

GameOverScreenLayout *GameOverScreenLayout::newLine()
{
    cursorY += lineHeight;

    return this;
}

void GameOverScreenLayout::render()
{
    initScreen();
    renderGameOverTitle();
    cursorY = 50;
    renderHighScores();
    newLine();
    renderScore();
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
