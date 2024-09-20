#include "Snake.h"
#include "SnakeSegment.h"
#include "GridLocation.h"

SnakeSegment *Snake::getHead()
{
    return head;
}

SnakeSegment *Snake::getTail()
{
    SnakeSegment *currentSegment = head;

    while (!currentSegment->isTail()) {
        currentSegment = currentSegment->getNextSegment();
    }

    return currentSegment;
}

Snake *Snake::stretchHeadTo(GridLocation location)
{
    SnakeSegment *oldHead = getHead();

    SnakeSegment *newHead = new SnakeSegment();
    newHead->setColumn(location.column);
    newHead->setRow(location.row);
    newHead->setNextSegment(oldHead);

    head = newHead;

    return this;
}

Snake *Snake::removeTail()
{
    SnakeSegment* tailSegment = getTail();
    SnakeSegment* currentSegment = getHead();

    while (!currentSegment->getNextSegment()->isTail()) {
        currentSegment = currentSegment->getNextSegment();
    }
    
    currentSegment->removeNextSegment();
    delete tailSegment;

    return this;
}


Snake *Snake::reset()
{
    while (false == getHead()->isTail())
    {
        removeTail();
    }

    // delete head;
    // head = new SnakeSegment();
    
    return this;
}
