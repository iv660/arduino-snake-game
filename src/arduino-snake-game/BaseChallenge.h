#pragma once

#include "Scene.h"
#include "GridAllocator.h"
#include "GridLocation.h"
#include "Direction.h"
#include "GridOccupantInterface.h"

template <typename Derived>
class BaseChallenge: public GridOccupantInterface
{
    private:
    protected:
        Scene* scene;
        GridAllocator gridAllocator;
        Direction direction;
    public:
        virtual Derived* setScene(Scene* scene)
        {
            this->scene = scene;

            return this;
        }

        virtual Derived* setGridAllocator(GridAllocator gridAllocator)
        {
            this->gridAllocator = gridAllocator;

            return this;
        }

        virtual Derived* setDirection(Direction direction)
        {
            this->direction = direction;
            
            return this;
        }

        virtual void startRound() {}
        virtual void beforeRoundStart() {}
        
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
};

