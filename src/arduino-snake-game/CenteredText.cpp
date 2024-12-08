#include "CenteredText.h"

unsigned int CenteredText::getTextWidth(char *text)
{
    return strlen(text) * getCharWidth();
}

unsigned int CenteredText::getCharWidth()
{
    return baseCharWidth * textSize;
}

CenteredText::CenteredText(char *text)
{
    this->text = text;
}

CenteredText *CenteredText::size(unsigned int textSize)
{
    this->textSize = textSize;

    return this;
}

CenteredText *CenteredText::top(unsigned int top)
{
    this->topPosition = top;

    return this;
}

void CenteredText::renderOn(TFT *screen)
{
    screen->textSize(textSize);
    screen->text(text, (screen->width() - getTextWidth(text)) / 2, topPosition);
}
