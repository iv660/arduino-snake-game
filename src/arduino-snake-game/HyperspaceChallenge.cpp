#include "HyperspaceChallenge.h"
#include "HyperspaceRift.h"

GridArea HyperspaceChallenge::getSpaceA()
{
    return GridArea({
        {0, 0}, 
        {
            scene->getColumns() / 2 - 1, 
            scene->getRows() - 1
        }
    });
}

GridArea HyperspaceChallenge::getSpaceB()
{
    return GridArea({
        {
            scene->getColumns() / 2 + 2, 
            0
        }, 
        {
            scene->getColumns() - 1, 
            scene->getRows() - 1
        }
    });
}

void HyperspaceChallenge::beforeRoundStart()
{
    GridLocation portALocation = gridAllocator.getRandomVacantLocationWithin(getSpaceA());
    portA.setColumn(portALocation.column);
    portA.setRow(portALocation.row);

    GridLocation portBLocation = gridAllocator.getRandomVacantLocationWithin(getSpaceB());
    portB.setColumn(portBLocation.column);
    portB.setRow(portBLocation.row);

    scene->render(&portA);
    scene->render(&portB);

    HyperspaceRift rift;
    scene->render(&rift);
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
