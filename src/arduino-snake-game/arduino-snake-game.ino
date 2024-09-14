// #include "TFT.h"
// #include "SPI.h"
#include "Apple.h"
#include "Scene.h"
#include "SnakeSegment.h"

// #define cs 10 // пин для подключения CS
// #define dc 8  // пин для подключения A0
// #define rst 9 // пин для подключения reset

// TFT screen = TFT(cs, dc, rst);
    Scene scene;

void setup()
{
    scene.begin();

//     screen.begin();

//     // цвет экрана ( r , g , b )
//     screen.background(0, 0, 0);
//     // размер шрифта
//     screen.setTextSize(1);
//     // цвет текста ( r , g , b )
//     screen.stroke(255, 255, 255);

//     // вывод на экран текста с координатами x и y
//     screen.text("Snake/spider Game", 45, 20);
//     delay(1000);
}

void loop()
{
    Apple apple;
    SnakeSegment snakeSegment;
    apple.setX(140);
    apple.setY(0);
    snakeSegment.setX(20);
    snakeSegment.setY(60);

    scene.draw(&apple);
    scene.draw(&snakeSegment);
    delay(1000);


    // // очистка экрана дисплея
    // screen.background(0, 0, 0);
    // // размер шрифта
    // screen.setTextSize(2);

    // // плавное изменение цвета текста
    // for (int i = 0; i <= 255; i = i + 5)
    // {
    //     screen.stroke(i, 255 - i, 255);
    //     screen.text("Snake/spider Game", 5, 50);
    //     delay(5);
    // }
    // delay(1000);

    // // очистка экрана дисплея
    // screen.background(0, 0, 0);
    // // размер шрифта
    // screen.setTextSize(4);

    // // прокрутка текста справа - налево
    // for (int i = 130; i >= -360; i = i - 10)
    // {
    //     screen.background(0, 0, 0);
    //     screen.stroke(0, 255, 0);
    //     if (i >= 16)
    //     {
    //         screen.text("@", 0, 40);
    //     }
    //     screen.text("$((((()))))", i, 40);
    //     delay(5);
    // }
    // delay(1000);
}