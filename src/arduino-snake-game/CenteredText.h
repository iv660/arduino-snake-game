#if !defined(CENTERED_TEXT_H)
#define CENTERED_TEXT_H

#include "TFT.h"

class CenteredText {
    private:
        char* text;
        unsigned int textSize;
        unsigned int topPosition;
        unsigned int baseCharWidth = 6;

        unsigned int getTextWidth(char* text);
        unsigned int getCharWidth();

    public:
        CenteredText(char* text);
        CenteredText* size(unsigned int textSize);
        CenteredText* top(unsigned int top);
        void renderOn(TFT* screen);
};


#endif // CENTERED_TEXT_H
