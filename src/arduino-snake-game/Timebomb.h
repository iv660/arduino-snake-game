#if !defined(TIMEBOMB_H)
#define TIMEBOMB_H

#include "DrawableInterface.h"

class Timebomb: public DrawableInterface
{
    private:
        int column = 0;
        int row = 0;
        bool armed = false;
        long armedAt = 0;
        long detonationDelay = 0;

    public:
        int getColumn();
        int getRow();
        char* getText();

        Timebomb* setColumn(int column);
        Timebomb* setRow(int row);

        void armFor(long detonationDelay);
        bool isArmed();
        bool hasGoneOff();
        void reset();
};

#endif // TIMEBOMB_H
