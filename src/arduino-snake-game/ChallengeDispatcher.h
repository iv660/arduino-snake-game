#pragma once

#include "BaseChallenge.h"
#include "HyperspaceChallenge.h"
#include "Scene.h"

/**
 * @brief Challenge dispatcher
 * 
 * @details This class holds the instances for all challenges, chooses 
 * one or more challenges to be activated on each individual level, 
 * and delegates handling all game events to those selected challenges.
 */
class ChallengeDispatcher: public BaseChallenge<ChallengeDispatcher>
{
    private:
        HyperspaceChallenge hyperspaceChallenge;

    public:
        ChallengeDispatcher* setScene(Scene* scene) override;
        ChallengeDispatcher* setGridAllocator(GridAllocator gridAllocator) override;
        ChallengeDispatcher* setDirection(Direction direction) override;
        void startRound() override;
        void beforeRoundStart() override;
        GridLocation adjustNextLocation(GridLocation currentLocation, GridLocation nextLocation) override;
        bool locationIsOutOfBounds(GridLocation location) override;

        bool occupies(GridLocation location) override;
};

