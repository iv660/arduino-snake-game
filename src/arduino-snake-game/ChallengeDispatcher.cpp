#include "ChallengeDispatcher.h"

#define TIMEBOMB_CHALLENGE_ODDS 7
#define HYPERSPACE_CHALLENGE_ODDS 1
#define EMPTY_CHALLENGE_ODDS 2

#define TIMEBOMB_CHALLENGE_STARTING_LEVEL 3
#define HYPERSPACE_CHALLENGE_STARTING_LEVEL 5

BaseChallenge* ChallengeDispatcher::getActiveChallenge()
{
    return activeChallenge;
}

BaseChallenge *ChallengeDispatcher::getRandomChallenge()
{
    unsigned int totalOdds = EMPTY_CHALLENGE_ODDS;
    if (state.level > TIMEBOMB_CHALLENGE_STARTING_LEVEL) {
        totalOdds += TIMEBOMB_CHALLENGE_ODDS;
    }

    if (state.level > HYPERSPACE_CHALLENGE_STARTING_LEVEL) {
        totalOdds += HYPERSPACE_CHALLENGE_ODDS;
    }

    unsigned int randomValue = random(1, totalOdds);

    unsigned int threshold = EMPTY_CHALLENGE_ODDS;
    if (randomValue <= threshold) {
        return &emptyChallenge;
    }

    threshold += TIMEBOMB_CHALLENGE_ODDS;
    if (randomValue <= threshold) {
        return &timebombChallenge;
    }

    return &hyperspaceChallenge;
}

void ChallengeDispatcher::initActiveChallenge() 
{
    if (state.level == TIMEBOMB_CHALLENGE_STARTING_LEVEL) {
        activeChallenge = &timebombChallenge;
    } else if (state.level == HYPERSPACE_CHALLENGE_STARTING_LEVEL) {
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

unsigned long ChallengeDispatcher::adjustLengthRequirementForNextLevel(unsigned long proposedLengthRequirement)
{
    return getActiveChallenge()->adjustLengthRequirementForNextLevel(proposedLengthRequirement);
}
