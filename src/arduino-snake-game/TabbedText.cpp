#include <stdio.h>
#include "TabbedText.h"

using XC::Hardware::ScreenInterface;

bool TabbedText::shouldResetTabs()
{
    return isRendered && numTabs > 0;
}

bool TabbedText::canAddTab()
{
    if (numTabs < MAX_TABS) {
        return true;
    }
    
    return false;
}

void TabbedText::resetTabs()
{
    numTabs = 0;
    nextTextSlot = 0;
    isRendered = false;
}

char *TabbedText::toString(unsigned long number)
{
    static char buffer[10];
    sprintf(buffer, "%lu", number);

    return buffer;
}

TabbedText *TabbedText::tab(unsigned int tabStop)
{

    if (shouldResetTabs()) {
        resetTabs();
    }

    tabStops[numTabs] = tabStop;
    numTabs++;

    return this;
}

TabbedText *TabbedText::size(unsigned int textSize)
{
    this->textSize = textSize;

    return this;
}

TabbedText *TabbedText::empty()
{
    text("");

    return this;
}

TabbedText *TabbedText::text(char *text)
{
    tabsText[nextTextSlot] = text;
    nextTextSlot++;

    return this;
}

TabbedText *TabbedText::number(unsigned long number)
{
    text(toString(number));

    return this;
}

TabbedText *TabbedText::top(unsigned int top)
{
    cursorY = top;

    return this;
}

void TabbedText::renderOn(ScreenInterface *screen)
{
    screen->textSize(textSize);

    for (unsigned int i = 0; i < numTabs; i++) {
        screen->text(tabsText[i], cursorX + tabStops[i], cursorY);
    }

    isRendered = true;
}
