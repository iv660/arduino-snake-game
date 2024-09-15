#if !defined(SNAKE_SEGMENT_H)
#define SNAKE_SEGMENT_H

#include "DrawableInterface.h"

class SnakeSegment: public DrawableInterface
{
private:
    int x = 0;
    int y = 0;
    SnakeSegment * nextSegment;

public:
    SnakeSegment(/* args */);

    int getX();
    int getY();
    char* getText();
    void setX(int x);
    void setY(int y);
    void setNextSegment(SnakeSegment * segment);
    SnakeSegment* getNextSegment();
    void removeNextSegment();
};


#endif // SNAKE_SEGMENT_H
