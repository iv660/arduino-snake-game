#if !defined(SNAKE_SEGMENT_H)
#define SNAKE_SEGMENT_H

#include "DrawableInterface.h"

class SnakeSegment: public DrawableInterface
{
private:
    int x = 0;
    int y = 0;
public:
    SnakeSegment(/* args */);

    int getX();
    int getY();
    char* getText();
    void setX(int x);
    void setY(int y);
};


#endif // SNAKE_SEGMENT_H
