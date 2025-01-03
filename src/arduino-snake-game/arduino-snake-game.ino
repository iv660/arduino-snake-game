#include "SnakeGame.h"

SnakeGame game;

void setup()
{
}

void loop()
{
    game.startUp()
        ->showLevelInfo();

    while (game.hasLivesLeft()) {
        game.startRound();
        while (!game.isOver()) {
            game.startCycle();
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

            game.endCycle();

            while (game.isPaused()) {
                game.updatePausedState();
            }
        }

        game.loseLife();
    }

    game.updateHighScore()
        ->end();
}