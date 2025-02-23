#include "Movement.h"

GridLocation Movement::calculateNextLocation(GridLocation currentLocation, Direction direction)
{
    GridLocation nextLocation;

    switch (direction) {
        case Direction::RIGHT:
            nextLocation.column = currentLocation.column + 1;
            nextLocation.row = currentLocation.row;
            break;

        case Direction::LEFT:   
            nextLocation.column = currentLocation.column - 1;
            nextLocation.row = currentLocation.row;
            break;

        case Direction::UP:
            nextLocation.column = currentLocation.column;
            nextLocation.row = currentLocation.row - 1;
            break;

        case Direction::DOWN:
            nextLocation.column = currentLocation.column;
            nextLocation.row = currentLocation.row + 1;
            break;

        default:
            nextLocation.column = currentLocation.column;
            nextLocation.row = currentLocation.row;
            break;
    }

    return nextLocation;
}