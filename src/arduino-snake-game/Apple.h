#if !defined(APPLE_H)
#define APPLE_H

#include "DrawableInterface.h"

class Apple: public DrawableInterface
{
private:
    int column = 0;
    int row = 0;
public:
    Apple(/* args */);
    int getColumn();
    int getRow();
    char* getText();
    void setColumn(int column);
    void setRow(int row);
};


#endif // APPLE_H
