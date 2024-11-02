#include "SnakeGame.h"

SnakeGame game;

void setup()
{

}

void loop()
{
    game.startUp();

    while (game.hasLivesLeft()) {
        game.startRound()
            ->showLevelInfo();
        while (!game.isOver()) {
            if (game.reachedAnApple()) {
                game.removeApple()
                    ->growSnake()
                    ->placeNewApple()
                    ->increaseScore();
                
                if (game.reachedLevelUp()) {
                    game.levelUp()
                        ->showLevelInfo();
                }
            } else {
                game.moveSnake()
                    ->deductScore();
            }

            game.slowDown();
        }

        game.loseLife();
    }

    game.updateHighScore()
        ->end();
}