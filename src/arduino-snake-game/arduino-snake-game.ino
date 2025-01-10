#include "const.h"
#include "SnakeGame.h"
#include "Appliance.h"
#include "TFTScreen.h"
#include "ToggleButton.h"
#include "AnalogJoystickDirectionSwitch.h"

SnakeGame game;

XC::Hardware::Appliance appliance;

TFTScreen screen(cs, dc, rst);
ToggleButton pauseButton(PIN3);
AnalogJoystickDirectionSwitch directionSwitch = 
        AnalogJoystickDirectionSwitch(VRX_PIN, VRY_PIN);

void setup()
{
    appliance.screen = &screen;
    appliance.pauseButton = &pauseButton;
    appliance.directionSwitch = &directionSwitch;
    
    game.setAppliance(appliance);
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