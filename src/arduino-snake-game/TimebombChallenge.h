#if !defined(TIMEBOMB_CHALLENGE_H)
#define TIMEBOMB_CHALLENGE_H

#include "Timebomb.h"
#include "Scene.h"
#include "GridLocation.h"
#include "SnakeGameState.h"

class TimebombChallenge
{
    private:
        Timebomb timebomb;
        Scene* scene;

        bool isTimeToArm(SnakeGameState state);
        void armTimebomb();
        void redraw();
    public:
        TimebombChallenge* setScene(Scene *scene);

        void startCycle(SnakeGameState state);
        void endCycle();
        void startRound();
        bool hasFailed();
        handleCollisionAt(GridLocation location);
};


#endif // TIMEBOMB_CHALLENGE_H
