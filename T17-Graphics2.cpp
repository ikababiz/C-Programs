#include<conio.h> 
#include<graphics.h>
int main() // Puntos, circulos y lineas
{
    int gd = DETECT, mode, i, x;
    initgraph(&gd, &mode, ""); // C:\\TC\\BGI es para TurboC
    setcolor(LIGHTCYAN);
    for(i = 1, x = 100 ;i < 50; ++i, x++) // Salto de un solo pixel
    {
        putpixel(x, 100, RED); // Parece el radio del circulo
    }
    setcolor(GREEN);
    circle(100, 100, 50);
    setcolor(WHITE);
    line(100, 200, 170, 360);
    setlinestyle(10, 1, 50);
        getch();
        closegraph();
} // Elaboro Garcia Resendis Itztli Kaban