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

GridLocation HyperspaceChallenge::adjustNextLocation(GridLocation currentLocation, GridLocation nextLocation)
{
    if (portA.occupies(nextLocation)) {
        return portB.getExitLocation(direction);
    }

    if (portB.occupies(nextLocation)) {
        return portA.getExitLocation(direction);
    }

    return nextLocation;
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
