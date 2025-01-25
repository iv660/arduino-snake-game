#pragma once

#include "BaseChallenge.h"
#include "GridOccupantInterface.h"
#include "WormholePort.h"
#include "GridLocation.h"
#include "Direction.h"
#include "GridArea.h"

class HyperspaceChallenge: public BaseChallenge<HyperspaceChallenge>, public GridOccupantInterface
{
    private:
        GridArea getSpaceA();
        WormholePort portA;

        GridArea getSpaceB();
        WormholePort portB;
    public:
        void beforeRoundStart() override;
        GridLocation adjustNextLocation(GridLocation currentLocation, GridLocation nextLocation) override;

        bool occupies(GridLocation location) override;
};
