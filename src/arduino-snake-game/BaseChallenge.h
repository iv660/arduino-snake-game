#pragma once

#include "Scene.h"
#include "GridAllocator.h"
#include "GridLocation.h"
#include "Direction.h"
#include "GridOccupantInterface.h"
#include "SnakeGameState.h"

class BaseChallenge: public GridOccupantInterface
{
    private:
    protected:
        Scene* scene;
        GridAllocator gridAllocator;
        Direction direction;
        bool isPaused;
    public:
        virtual BaseChallenge* setScene(Scene* scene)
        {
            this->scene = scene;

            return this;
        }

        virtual BaseChallenge* setGridAllocator(GridAllocator gridAllocator)
        {
            this->gridAllocator = gridAllocator;

            return this;
        }

        virtual BaseChallenge* setDirection(Direction direction)
        {
            this->direction = direction;
            
            return this;
        }

        virtual void setPausedState(bool isPaused)
        {
            this->isPaused = isPaused;
        }

        virtual void startRound() {}
        virtual void startCycle(SnakeGameState state) {}
        virtual void endCycle() {}
        virtual void beforeRoundStart() {}

        virtual bool hasFailed()
        {
            return false;
        }

        virtual void handleCollisionAt(GridLocation location) {}
        
        virtual GridLocation adjustNextLocation(GridLocation currentLocation, GridLocation nextLocation) 
        {
            return nextLocation;
        }

        virtual bool locationIsOutOfBounds(GridLocation location) 
        {
            return false;
        } 

        virtual bool occupies(GridLocation location) override 
        {
            return false;
        }

        virtual unsigned long adjustLengthRequirementForNextLevel(unsigned long proposedLengthRequirement) 
        {
            return proposedLengthRequirement;
        }
};

