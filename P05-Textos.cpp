#include <graphics.h>
#include <stdio.h>
int main() 
{
    int gd = DETECT, mode;
    initgraph(&gd, &mode, ""); 
    setbkcolor(WHITE); // 15 que es WHITE
    cleardevice(); // Para limpiar la pantalla, importante para que se vea el cambio
    settextstyle(0, 0, 4);
    setcolor(GREEN);
    outtextxy(50, 50, "Lorem Ipsum"); 

    settextstyle(0, 0, 2);
    setcolor(YELLOW);
    outtextxy(50, 100, "Lorem Ipsum2"); 

    settextstyle(1, 0, 6);
    setcolor(LIGHTCYAN);
    outtextxy(50, 150, "Lorem Ipsum3"); 

    settextstyle(2, 0, 2);
    setcolor(WHITE);
    outtextxy(50, 200, "Lorem Ipsum4"); 
    
    settextstyle(3, 0, 7);
    setcolor(RED);
    outtextxy(50, 250, "Lorem Ipsum5"); 

    settextstyle(4, 1, 5);
    setcolor(LIGHTMAGENTA);
    outtextxy(10, 450, "Lorem Ipsum6"); 
    
    setcolor(BLACK);
    arc(getmaxx()/2, getmaxy()/2, 180, 0, 80);
    //ellipse(getmaxx()/2, getmaxy()/2, );
    //arc(250, 100 , 90, 270, 70);
    //setcolor(LIGHTMAGENTA);
    //arc(280, 100 , 260, 90, 50);
    setcolor(RED);
    setfillstyle(2, RED);
    //ellipse(200, 200, 0, 360, 150, 50);
    fillellipse(200, 200, 50, 150);
    getch();
    closegraph();
    return 0;
} // Elaboro Garcia Resendis Itztli Kaban