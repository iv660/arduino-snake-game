#pragma once

#include "BaseChallenge.h"
#include "GridOccupantInterface.h"
#include "WormholePort.h"
#include "GridLocation.h"
#include "Direction.h"

class HyperspaceChallenge: public BaseChallenge<HyperspaceChallenge>, public GridOccupantInterface
{
    private:
        WormholePort portA;
        WormholePort portB;
    public:
        void beforeRoundStart() override;
        GridLocation adjustNextLocation(GridLocation currentLocation, GridLocation nextLocation) override;

        bool occupies(GridLocation location) override;
};
