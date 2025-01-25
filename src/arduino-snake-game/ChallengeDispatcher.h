#pragma once

#include "BaseChallenge.h"
#include "HyperspaceChallenge.h"
#include "Scene.h"
#include "ChallengeInterface.h"

/**
 * @brief Challenge dispatcher
 * 
 * This class holds the instances for all challenges, chooses 
 * one or more challenges to be activated on each individual level, 
 * and delegates handling all game events to those selected challenges.
 */
class ChallengeDispatcher: public BaseChallenge
{
    private:
        HyperspaceChallenge hyperspaceChallenge;
        BaseChallenge* getActiveChallenge();
    public:
        BaseChallenge* setScene(Scene* scene) override;
        BaseChallenge* setGridAllocator(GridAllocator gridAllocator) override;
        BaseChallenge* setDirection(Direction direction) override;
        void startRound() override;
        void beforeRoundStart() override;
        GridLocation adjustNextLocation(GridLocation currentLocation, GridLocation nextLocation) override;
        bool locationIsOutOfBounds(GridLocation location) override;

        bool occupies(GridLocation location) override;
};

