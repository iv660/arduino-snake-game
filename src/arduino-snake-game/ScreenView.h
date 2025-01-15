#if !defined(SCREEN_VIEW_H)
#define SCREEN_VIEW_H

#include "ScreenInterface.h"

using XC::Hardware::ScreenInterface;

class ScreenView: public ScreenInterface
{
    private:
        ScreenInterface* screen;
        int x;
        int y;
    public:
        ScreenView(ScreenInterface* screen, int x, int y) 
            : screen(screen), x(x), y(y) {}

        void begin() override;
        int width() override;
        void textSize(int size) override;
        void background(int r, int g, int b) override;
        void fill(int r, int g, int b) override;
        void stroke(int r, int g, int b) override;
        void text(char *text, int x, int y) override;
        void rect(int x, int y, int w, int h) override;
};


#endif // SCREEN_VIEW_H
