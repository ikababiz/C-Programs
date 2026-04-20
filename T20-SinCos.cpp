#include <graphics.h>
#include <stdio.h> 
#include <math.h>
#include <time.h>
int main()
{
    int a = 0, b = 20; // de 0 a 20 en el plano
    initwindow(800, 600, (char*)"Seno y Coseno");
    int ALTO = 700;
    int ANCHO = 800;
    floodfill(1, 1, 15);
    double escalaX = 40.0; // Ajustar según el intervalo [a, b]
    double escalaY = 40.0; // Ajustar según el valor de f(x)
    setcolor(0);// 1. Dibujar Ejes
    line(0, ALTO - 50, ANCHO, ALTO - 50); // Eje X
    line(50, 0, 50, ALTO);                // Eje Y
    setcolor(YELLOW);// 2. Dibujar la Curva (f(x))
    for (double x = a; x <= b; x += 0.01) 
    {   int px = 50 + (x - a) * escalaX;
        int py = (ALTO - 50) - sin(x) * escalaY;
        putpixel(px, py, YELLOW);
        refresh(); // necesario por SDL2
        delay(1);
    }
    for (double x = a; x <= b; x += 0.01) 
    {   int px = 50 + (x - a) * escalaX;
        int py = (ALTO - 50) - cos(x) * escalaY;
        putpixel(px, py, GREEN);
        refresh();
        delay(1);
    }
    settextstyle(1, 0, 2);
    setcolor(LIGHTCYAN);
    outtextxy(200, 20, (char*)"Presiona cualquier tecla para finalizar...");
    setcolor(YELLOW);
    outtextxy(120, 580, (char*)"f(x) = sen(x)");
    setcolor(GREEN);
    outtextxy(170, 720, (char*)"f(x) = cos(x)");
    getch();
    while(!kbhit()) 
    {
        if (ismouseclick(WM_LBUTTONDOWN)) 
        {   int mouseX = mousex();
            int mouseY = mousey();
            printf("Click en: X=%d, Y=%d\n", mouseX, mouseY);
            clearmouseclick(WM_LBUTTONDOWN);
        }
        delay(100); 
    }
    closegraph();
    return 0;
}