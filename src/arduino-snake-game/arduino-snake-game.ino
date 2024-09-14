#include "SnakeGame.h"

SnakeGame game;

void setup()
{

}

void loop()
{
    game.startUp();

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
    }

    game.end();
}