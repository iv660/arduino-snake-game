#if !defined(APPLE_H)
#define APPLE_H

class Apple
{
private:
    int x = 0;
    int y = 0;
public:
    Apple(/* args */);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
};


#endif // APPLE_H
