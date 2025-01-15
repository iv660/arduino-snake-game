#include <Arduino.h>
#include "Apple.h"

Apple::Apple()
{
}

int Apple::getColumn()
{
    return column;
}

int Apple::getRow()
{
    return row;
}

char *Apple::getText()
{
    return "@";
}

void Apple::setColumn(int column)
{
    this->column = column;
}

void Apple::setRow(int row)
{
    this->row = row;
}

bool Apple::occupies(GridLocation location)
{
    if (location.column == column && location.row == row) {
        return true;
    }
    
    return false;
}

void Apple::renderOn(ScreenInterface *screen)
{
    screen->stroke(0, 255, 0);
    screen->textSize(2);    
    screen->text(getText(), 0, 0);

    return;

    // ================================================================

    // const uint8_t bitmap[] PROGMEM = {
    //     0b00000001,  
    //     0b00000111,  
    //     0b00001110,  
    //     0b00001000,  
    //     0b01100110,  
    //     0b11111111,  
    //     0b11111111,  
    //     0b11111111,  
    //     0b11111111,  
    //     0b11111111,  
    //     0b01111110,  
    //     0b00111100,  
    // };

    // int width = 8;
    // int height = 12;

    // static const uint16_t DARK_GREEN = 0x6669;
    // static const uint16_t YELLOW = 0xFFA4;

    // // screen->drawBitmap(0, 0, bitmap, width, height, YELLOW, ST7735_BLACK);
    
    // for (int y = 0; y < height; y++) {
    //     for (int x = 0; x < width; x++) {
    //         if (bitmap[y] & (1 << (7 - x))) {
    //             screen->drawPixel(x, y, (y <= 3) ? DARK_GREEN : YELLOW);
    //         } else {
    //             screen->drawPixel(x, y, ST7735_BLACK);
    //         }
    //     }
    // }
}
