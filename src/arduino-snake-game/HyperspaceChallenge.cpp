#include "HyperspaceChallenge.h"
#include "WormholePort.h"

void HyperspaceChallenge::startRound()
{
    WormholePort portA;
    WormholePort portB;

    portA.setColumn(8);
    portA.setRow(6);

    portB.setColumn(12);
    portB.setRow(2);

    scene->render(&portA);
    scene->render(&portB);
}