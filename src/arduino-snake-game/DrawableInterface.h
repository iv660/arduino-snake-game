#if !defined(DRAWABLE_INTERFACE_H)
#define DRAWABLE_INTERFACE_H

class DrawableInterface
{
private:
    
public:
    virtual int getColumn() = 0;
    virtual int getRow() = 0;
    virtual char* getText() = 0; 
};


#endif // DRAWABLE_INTERFACE_H
