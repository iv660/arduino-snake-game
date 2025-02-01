#include "ChallengeDispatcher.h"

BaseChallenge* ChallengeDispatcher::getActiveChallenge()
{
    if (state.level == 1) {
        return &hyperspaceChallenge;
    }

    return &timebombChallenge;
}

void ChallengeDispatcher::updateState(SnakeGameState state)
{
    this->state = state;
}

BaseChallenge *ChallengeDispatcher::setScene(Scene *scene)
{
    getActiveChallenge()->setScene(scene);

    return this;
}

BaseChallenge* ChallengeDispatcher::setGridAllocator(GridAllocator gridAllocator) 
{
    getActiveChallenge()->setGridAllocator(gridAllocator);

    return this;
}

BaseChallenge* ChallengeDispatcher::setDirection(Direction direction) 
{
    getActiveChallenge()->setDirection(direction);

    return this;
}

void ChallengeDispatcher::startRound() 
{
    getActiveChallenge()->startRound();
}

void ChallengeDispatcher::beforeRoundStart() 
{
    getActiveChallenge()->beforeRoundStart();
}

void ChallengeDispatcher::startCycle(SnakeGameState state)
{
    getActiveChallenge()->startCycle(state);
}

void ChallengeDispatcher::endCycle()
{
    getActiveChallenge()->endCycle();
}

void ChallengeDispatcher::setPausedState(bool paused)
{
    getActiveChallenge()->setPausedState(paused);
}

bool ChallengeDispatcher::hasFailed()
{
    return getActiveChallenge()->hasFailed();
}

GridLocation ChallengeDispatcher::adjustNextLocation(GridLocation currentLocation, GridLocation nextLocation) 
{
    return getActiveChallenge()->adjustNextLocation(currentLocation, nextLocation);
}

bool ChallengeDispatcher::locationIsOutOfBounds(GridLocation location) 
{
    return getActiveChallenge()->locationIsOutOfBounds(location);
}

void ChallengeDispatcher::handleCollisionAt(GridLocation location)
{
    getActiveChallenge()->handleCollisionAt(location);
}

bool ChallengeDispatcher::occupies(GridLocation location)
{
    return getActiveChallenge()->occupies(location);
}
