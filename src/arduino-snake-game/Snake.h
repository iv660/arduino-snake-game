#if !defined(SNAKE_H)
#define SNAKE_H)

#include "SnakeSegment.h"
#include "GridLocation.h"
#include "GridOccupantInterface.h"

class Snake: public GridOccupantInterface
{
private:
    SnakeSegment *head = new SnakeSegment();
public:
    SnakeSegment *getHead();
    SnakeSegment *getTail();
    Snake *stretchHeadTo(GridLocation location);
    Snake *removeTail();
    Snake *reset();
    Snake *clearLocations();
    unsigned long getLength();

    bool occupies(GridLocation location);
};

#endif // SNAKE_H)
