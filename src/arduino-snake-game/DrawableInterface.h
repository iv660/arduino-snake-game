#if !defined(DRAWABLE_INTERFACE_H)
#define DRAWABLE_INTERFACE_H

#include "ScreenInterface.h"

using XC::Hardware::ScreenInterface;

class DrawableInterface
{
private:
    
public:
    virtual int getColumn() = 0;
    virtual int getRow() = 0;
    virtual char* getText() = 0; 
    virtual void renderOn(ScreenInterface* screen) {}
};


#endif // DRAWABLE_INTERFACE_H
