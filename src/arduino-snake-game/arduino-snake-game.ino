#include "SnakeGame.h"

SnakeGame game;

void setup()
{
    pinMode(PIN3, INPUT_PULLUP);
}

void loop()
{
    game.startUp()->
        showLevelInfo();

    while (game.hasLivesLeft()) {
        game.startRound();
        while (!game.isOver()) {
            if (game.reachedAnApple()) {
                game.removeApple()
                    ->growSnake()
                    ->placeNewApple()
                    ->increaseScore();
                
                if (game.reachedLevelUp()) {
                    game.levelUp()
                        ->showLevelInfo()
                        ->startRound();
                }
            } else {
                game.moveSnake()
                    ->deductScore();
            }

            game.wait();

            while (game.isPaused()) {
                game.updatePausedState();
            }
        }

        game.loseLife();
    }

    game.updateHighScore()
        ->end();
}