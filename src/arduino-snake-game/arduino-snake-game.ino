#include "SnakeGame.h"

SnakeGame game;

void setup()
{

}

void loop()
{
    game.startUp();

    while (game.hasLivesLeft()) {
        game.startRound();
        while (!game.isOver()) {
            if (game.reachedAnApple()) {
                game.removeApple()
                    ->growSnake()
                    ->placeNewApple()
                    ->increaseScore();
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