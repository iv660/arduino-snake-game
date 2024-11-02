#if !defined(SNAKE_H)
#define SNAKE_H)

#include "SnakeSegment.h"
#include "GridLocation.h"

class Snake
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
};

#endif // SNAKE_H)
