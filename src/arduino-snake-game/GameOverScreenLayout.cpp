#include "GameOverScreenLayout.h"
#include "CenteredText.h"
#include "TabbedText.h"

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

    tabs().empty()
        ->text("Your score:")
        ->number(score)
        ->renderOn(screen);

    newLine();
}

void GameOverScreenLayout::renderHighScores()
{
    screen->stroke(255, 255, 255);

    tabs().empty()
        ->text("High scores:")
        ->renderOn(screen);
    newLine();
    
    tabs().text("1.")
        ->empty()
        ->number(highScore)
        ->renderOn(screen);
    newLine();

    tabs().text("2.")
        ->empty()
        ->number(0)
        ->renderOn(screen);
    newLine();

    tabs().text("3.")
        ->empty()
        ->number(0)
        ->renderOn(screen);
    newLine();
}

TabbedText GameOverScreenLayout::tabs()
{
    TabbedText tabbedText = TabbedText();

    tabbedText
        .tab(leaderPositionTabStop)
        ->tab(leaderNameTabStop)
        ->tab(leaderScoreTabStop)
        ->size(1)
        ->top(cursorY);

    return tabbedText;
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

