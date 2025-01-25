#if !defined(TIMEBOMB_CHALLENGE_H)
#define TIMEBOMB_CHALLENGE_H

#include "Timebomb.h"
#include "GridLocation.h"
#include "SnakeGameState.h"
#include "BaseChallenge.h"

class TimebombChallenge: public BaseChallenge
{
    private:
        static unsigned int const TIMEBOMBS_STARTING_LEVEL = 3;
        static unsigned int const BASE_ACTIVATION_TRESHOLD = 100;
        static unsigned int const MIN_ACTIVATION_TRESHOLD = 1;

        Timebomb timebomb;

        bool isPaused = false;

        bool isTimeToArm(SnakeGameState state);
        void armTimebomb();
        void redraw();
        bool pausedStateHasChanged(bool newPausedState);
        bool gotPaused(bool newPausedState);
        bool gotUnpaused(bool newPausedState);
        unsigned int getActivationTreshold(SnakeGameState state);

    public:
        void startRound() override;

        bool occupies(GridLocation location) override;

        void startCycle(SnakeGameState state);
        void endCycle();
        bool hasFailed();
        void setPausedState(bool isPaused);
        void handleCollisionAt(GridLocation location);
};


#endif // TIMEBOMB_CHALLENGE_H
