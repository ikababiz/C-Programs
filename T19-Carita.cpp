#include <graphics.h>
#include <conio.h>
int main() // Carita feliz
{
    int gd = DETECT, mode;
    initgraph(&gd, &mode, "");
    floodfill(1, 1, 15);
    setcolor(0);
    ellipse(getmaxx()/2, getmaxy()/2, 0, 181, 300, 150);
    ellipse(getmaxx()/2, getmaxy()/2, 179, 0, 300, 75);
    arc((getmaxx()/2), (getmaxy()/2)-50, 70, 270, 20);
    circle((getmaxx()/2)-125, (getmaxy()/2)-50, 25);
    circle((getmaxx()/2)+125, (getmaxy()/2)-50, 25);
    ellipse(getmaxx()/2, getmaxy()/2, 160, 340, 75, 25);
    //setfillstyle(1, 14);
    //floodfill(getmaxx()/2, getmaxy()/2, 0);
    arc((getmaxx()/2)-150, (getmaxy()/2)-150, 0, 130, 70);
    arc((getmaxx()/2)-50, (getmaxy()/2)-150, 0, 130, 70);
    arc((getmaxx()/2)+70, (getmaxy()/2)-135, 0, 130, 70);
    circle(200, 190, 10);
    circle(440, 190, 10);
    setfillstyle(1, 0);
    floodfill(201, 191, 0);
    floodfill(441, 191, 0);
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
} // Elaboro Garcia Resendis Itztli Kaban