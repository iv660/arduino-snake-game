#pragma once

#include "BaseChallenge.h"
#include "HyperspaceChallenge.h"
#include "Scene.h"
#include "GridAllocator.h"
#include "Direction.h"
#include "SnakeGameState.h"
#include "GridLocation.h"
#include "TimebombChallenge.h"

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
        TimebombChallenge timebombChallenge;
        HyperspaceChallenge hyperspaceChallenge;

        SnakeGameState state;

        BaseChallenge* getActiveChallenge();
    public:
        void updateState(SnakeGameState state);

        BaseChallenge* setScene(Scene* scene) override;
        BaseChallenge* setGridAllocator(GridAllocator gridAllocator) override;
        BaseChallenge* setDirection(Direction direction) override;
        void startRound() override;
        void beforeRoundStart() override;
        void startCycle(SnakeGameState state) override;
        void endCycle() override;

        void setPausedState(bool paused) override;
        bool hasFailed() override;
        GridLocation adjustNextLocation(GridLocation currentLocation, GridLocation nextLocation) override;
        bool locationIsOutOfBounds(GridLocation location) override;
        void handleCollisionAt(GridLocation location) override;

        bool occupies(GridLocation location) override;
};

