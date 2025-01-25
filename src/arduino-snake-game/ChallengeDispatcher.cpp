#include "ChallengeDispatcher.h"

ChallengeDispatcher* ChallengeDispatcher::setScene(Scene* scene) 
{
    hyperspaceChallenge.setScene(scene);

    return this;
}

ChallengeDispatcher* ChallengeDispatcher::setGridAllocator(GridAllocator gridAllocator) 
{
    hyperspaceChallenge.setGridAllocator(gridAllocator);

    return this;
}

ChallengeDispatcher* ChallengeDispatcher::setDirection(Direction direction) 
{
    hyperspaceChallenge.setDirection(direction);

    return this;
}

void ChallengeDispatcher::startRound() 
{
    hyperspaceChallenge.startRound();
}

void ChallengeDispatcher::beforeRoundStart() 
{
    hyperspaceChallenge.beforeRoundStart();
}

GridLocation ChallengeDispatcher::adjustNextLocation(GridLocation currentLocation, GridLocation nextLocation) 
{
    return hyperspaceChallenge.adjustNextLocation(currentLocation, nextLocation);
}

bool ChallengeDispatcher::locationIsOutOfBounds(GridLocation location) 
{
    return hyperspaceChallenge.locationIsOutOfBounds(location);
}

bool ChallengeDispatcher::occupies(GridLocation location)
{
    return hyperspaceChallenge.occupies(location);
}
