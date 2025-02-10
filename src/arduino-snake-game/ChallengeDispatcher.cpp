#include "ChallengeDispatcher.h"

BaseChallenge* ChallengeDispatcher::getActiveChallenge()
{
    return activeChallenge;
}

BaseChallenge *ChallengeDispatcher::getRandomChallenge()
{
    unsigned int const timebombChallengeOdds = 7;
    unsigned int const hyperspaceChallengeOdds = 1;
    unsigned int const emptyChallengeOdds = 2;

    unsigned int overallOdds = emptyChallengeOdds;
    if (state.level > 3) {
        overallOdds += timebombChallengeOdds;
    }

    if (state.level > 8) {
        overallOdds += hyperspaceChallengeOdds;
    }

    unsigned int const randomOdds = random(1, overallOdds);

    unsigned int currentTreshold = emptyChallengeOdds;
    if (randomOdds <= currentTreshold) {
        return &emptyChallenge;
    }

    currentTreshold += timebombChallengeOdds;
    if (randomOdds <= currentTreshold) {
        return &timebombChallenge;
    } 

    return &hyperspaceChallenge;
}

void ChallengeDispatcher::initActiveChallenge() 
{
    if (state.level == 3) {
        activeChallenge = &timebombChallenge;
    } else if (state.level == 8) {
        activeChallenge = &hyperspaceChallenge;
    } else {
        activeChallenge = getRandomChallenge();
    }

    activeChallenge->setScene(scene);
    activeChallenge->setGridAllocator(gridAllocator);
}

void ChallengeDispatcher::updateState(SnakeGameState state)
{
    this->state = state;

    initActiveChallenge();
}

BaseChallenge *ChallengeDispatcher::setScene(Scene *scene)
{
    this->scene = scene;

    getActiveChallenge()->setScene(scene);

    return this;
}

BaseChallenge* ChallengeDispatcher::setGridAllocator(GridAllocator gridAllocator) 
{
    this->gridAllocator = gridAllocator;

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
