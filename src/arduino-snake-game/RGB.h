#if !defined(RGB_H)
#define RGB_H

struct RGB {
    int red;
    int green;
    int blue;

    RGB(int r, int g, int b) : red(r), green(g), blue(b) {}
};

#endif // RGB_H
