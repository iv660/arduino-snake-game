#if !defined(TIMEBOMB_CHALLENGE_H)
#define TIMEBOMB_CHALLENGE_H

#include "Timebomb.h"
#include "Scene.h"
#include "GridLocation.h"
#include "GridAllocator.h"
#include "SnakeGameState.h"

class TimebombChallenge
{
    private:
        static unsigned int const TIMEBOMBS_STARTING_LEVEL = 3;
        static unsigned int const BASE_ACTIVATION_TRESHOLD = 100;
        static unsigned int const MIN_ACTIVATION_TRESHOLD = 1;

        Timebomb timebomb;
        Scene* scene;
        GridAllocator gridAllocator;

        bool isPaused = false;

        bool isTimeToArm(SnakeGameState state);
        void armTimebomb();
        void redraw();
        bool pausedStateHasChanged(bool newPausedState);
        bool gotPaused(bool newPausedState);
        bool gotUnpaused(bool newPausedState);
        unsigned int getActivationTreshold(SnakeGameState state);
    public:
        TimebombChallenge* setScene(Scene *scene);
        TimebombChallenge* setGridAllocator(GridAllocator gridAllocator);

        void startCycle(SnakeGameState state);
        void endCycle();
        void startRound();
        bool hasFailed();
        void setPausedState(bool isPaused);
        handleCollisionAt(GridLocation location);
};


#endif // TIMEBOMB_CHALLENGE_H
