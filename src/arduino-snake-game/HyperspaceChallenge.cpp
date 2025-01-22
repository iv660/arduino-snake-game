#include "HyperspaceChallenge.h"

void HyperspaceChallenge::beforeRoundStart()
{
    GridLocation portALocation = gridAllocator.getRandomVacantLocation();
    portA.setColumn(portALocation.column);
    portA.setRow(portALocation.row);

    GridLocation portBLocation = gridAllocator.getRandomVacantLocation();
    portB.setColumn(portBLocation.column);
    portB.setRow(portBLocation.row);

    scene->render(&portA);
    scene->render(&portB);
}

bool HyperspaceChallenge::occupies(GridLocation location)
{
    if (portA.occupies(location)) {
        return true;
    }

    if (portB.occupies(location)) {
        return true;
    }

    return false;
}
