#pragma once

#include "Scene.h"
#include "GridAllocator.h"
#include "Direction.h"
#include "GridLocation.h"
#include "GridOccupantInterface.h"

class ChallengeInterface: public GridOccupantInterface
{
    public:
        virtual ChallengeInterface* setScene(Scene* scene) = 0;
        virtual ChallengeInterface* setGridAllocator(GridAllocator gridAllocator) = 0;
        virtual ChallengeInterface* setDirection(Direction direction) = 0;
        virtual void startRound() = 0;
        virtual void beforeRoundStart() = 0;
        virtual GridLocation adjustNextLocation(GridLocation currentLocation, GridLocation nextLocation) = 0;
        virtual bool locationIsOutOfBounds(GridLocation location) = 0;
        virtual bool occupies(GridLocation location) override = 0;
};
