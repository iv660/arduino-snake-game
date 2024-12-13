#if !defined(TIMEBOMB_H)
#define TIMEBOMB_H

#include "DrawableInterface.h"
#include "GridLocation.h"

class Timebomb: public DrawableInterface
{
    private:
        int column = 0;
        int row = 0;
        long armedAt = 0;
        long pausedAt = 0;
        long detonationDelay = 0;

        char* counter = "9";
        char* getCounter();
        void updateCouner();

        bool isPaused();

    public:
        int getColumn();
        int getRow();
        char* getText();
        GridLocation getLocation();

        Timebomb* setColumn(int column);
        Timebomb* setRow(int row);

        void armFor(long detonationDelay);
        void pause();
        void resume();
        bool isArmed();
        bool hasGoneOff();
        void reset();
};

#endif // TIMEBOMB_H
