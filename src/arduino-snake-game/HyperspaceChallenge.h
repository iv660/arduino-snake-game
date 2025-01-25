#pragma once

#include "BaseChallenge.h"
#include "GridOccupantInterface.h"
#include "WormholePort.h"
#include "GridLocation.h"
#include "Direction.h"
#include "GridArea.h"
#include "HyperspaceRift.h"

class HyperspaceChallenge: public BaseChallenge<HyperspaceChallenge>, public GridOccupantInterface
{
    private:
        GridArea getSpaceA();
        WormholePort portA;

        GridArea getSpaceB();
        WormholePort portB;

        HyperspaceRift getRift();
    public:
        void beforeRoundStart() override;
        GridLocation adjustNextLocation(GridLocation currentLocation, GridLocation nextLocation) override;

        bool occupies(GridLocation location) override;
};
