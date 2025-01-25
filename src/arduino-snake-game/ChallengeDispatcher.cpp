#include "ChallengeDispatcher.h"

BaseChallenge* ChallengeDispatcher::getActiveChallenge()
{
    return &hyperspaceChallenge;
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

GridLocation ChallengeDispatcher::adjustNextLocation(GridLocation currentLocation, GridLocation nextLocation) 
{
    return getActiveChallenge()->adjustNextLocation(currentLocation, nextLocation);
}

bool ChallengeDispatcher::locationIsOutOfBounds(GridLocation location) 
{
    return getActiveChallenge()->locationIsOutOfBounds(location);
}

bool ChallengeDispatcher::occupies(GridLocation location)
{
    return getActiveChallenge()->occupies(location);
}
