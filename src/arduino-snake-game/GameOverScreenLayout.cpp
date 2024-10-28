#include "GameOverScreenLayout.h"
#include "CenteredText.h"

void GameOverScreenLayout::initScreen()
{
    screen->background(0, 0, 0);
}

void GameOverScreenLayout::renderGameOverTitle()
{
    screen->stroke(255, 255, 255);

    CenteredText("GAME OVER").size(2)
        ->top(cursorY)
        ->renderOn(screen);
}

void GameOverScreenLayout::renderScore()
{
    screen->stroke(255, 255, 255);
    setTextSize(1);
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
    setTextSize(1);
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

unsigned int GameOverScreenLayout::getTextWidth(char *text)
{
    return strlen(text) * getCharWidth();
}

unsigned int GameOverScreenLayout::getCharWidth()
{
    return baseCharWidth * textSize;
}

GameOverScreenLayout *GameOverScreenLayout::newLine()
{
    cursorY += lineHeight;

    return this;
}

GameOverScreenLayout *GameOverScreenLayout::setTextSize(unsigned int size)
{
    textSize = size;
    screen->textSize(textSize);

    return this;
}

void GameOverScreenLayout::render()
{
    initScreen();
    cursorY = 25;
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
