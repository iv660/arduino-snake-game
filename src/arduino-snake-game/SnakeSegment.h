#if !defined(SNAKE_SEGMENT_H)
#define SNAKE_SEGMENT_H

#include "DrawableInterface.h"

class SnakeSegment: public DrawableInterface
{
private:
    int column = 0;
    int row = 0;
    SnakeSegment * nextSegment = nullptr;

public:
    SnakeSegment(/* args */);

    int getColumn();
    int getRow();
    char* getText();
    void setColumn(int column);
    void setRow(int row);
    void setNextSegment(SnakeSegment * segment);
    SnakeSegment* getNextSegment();
    void removeNextSegment();
    bool isTail();
};


#endif // SNAKE_SEGMENT_H
