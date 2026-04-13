#include <graphics.h>
#include <conio.h>
int main() 
{
    int gd = DETECT, mode;
    initgraph(&gd, &mode, "");
    //floodfill(1, 1, 15);
    //setcolor(0);
    circle((getmaxx()/2), (getmaxy()/2)-75, 50);
    ellipse(getmaxx()/2, (getmaxy()/2)-75, 180, 0, 75, 25);
    while(!kbhit()) // Coordenadas
    {
        if (ismouseclick(WM_LBUTTONDOWN)) 
        {
            int mouseX = mousex();
            int mouseY = mousey();
            printf("Coordenadas click: (%d, %d)\n", mouseX, mouseY);
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
    getch();
    closegraph();
    return 0;
} 