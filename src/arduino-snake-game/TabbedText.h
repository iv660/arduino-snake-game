#ifndef TABBED_TEXT_H
#define TABBED_TEXT_H

#include "TFT.h"

class TabbedText
{
    private:
        static const unsigned int MAX_TABS = 5;
        char* tabsText[MAX_TABS];
        unsigned int tabStops[MAX_TABS];
        unsigned int textSize = 1;
        unsigned int numTabs = 0;
        unsigned int nextTextSlot = 0;
        unsigned int cursorX = 0;
        unsigned int cursorY = 0;
        bool isRendered = false;

        bool shouldResetTabs();
        bool canAddTab();
        void resetTabs();
        char* toString(unsigned long number);
    public:
        TabbedText* tab(unsigned int tabStop);
        TabbedText* size(unsigned int textSize);
        TabbedText* empty();
        TabbedText* text(char* text);
        TabbedText* number(unsigned long number);
        TabbedText* top(unsigned int top);
        void renderOn(TFT* screen);
};

#endif // TABBED_TEXT_H
