#if !defined(DRAWABLE_INTERFACE_H)
#define DRAWABLE_INTERFACE_H

class DrawableInterface
{
private:
    
public:
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual char* getText() = 0; 
};


#endif // DRAWABLE_INTERFACE_H
