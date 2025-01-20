#pragma once

#include "BaseChallenge.h"
#include "GridOccupantInterface.h"
#include "WormholePort.h"

class HyperspaceChallenge: public BaseChallenge<HyperspaceChallenge>, public GridOccupantInterface
{
    private:
        WormholePort portA;
        WormholePort portB;
    public:
        void startRound() override;

        bool occupies(GridLocation location) override;
};
