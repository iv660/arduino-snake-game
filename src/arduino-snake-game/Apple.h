#if !defined(APPLE_H)
#define APPLE_H

#include "DrawableInterface.h"

class Apple: public DrawableInterface
{
private:
    int x = 0;
    int y = 0;
public:
    Apple(/* args */);
    int getX();
    int getY();
    char* getText();
    void setX(int x);
    void setY(int y);
};


#endif // APPLE_H