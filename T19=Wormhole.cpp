#include <graphics.h>
#include <conio.h>
#define RAD1 350
#define RAD2 200
int main() // Tunel del tiempo
{
    int gd = DETECT, mode;
    int x, y, rx = RAD1, ry = RAD2;
    initgraph(&gd, &mode, "");
    floodfill(1, 1, 15);
    setcolor(0);
    for (int i = 0; i < 500; i+=5)
    {
        x = (getmaxx()/2) - i;
        y = (getmaxy()/2);
        rx -= 7;
        ry -= 4;
        ellipse(x, y, 0, 360, rx, ry);
        if(rx <= 0 || ry <= 0) 
        break;
        delay(50);
    }
    getch();
    closegraph();
    return 0;
} // Elaboro Garcia Resendis Itztli Kaban