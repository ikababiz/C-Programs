#include <graphics.h>
#include <conio.h>
int main() // Flor
{
    int gd = DETECT, mode;
    initgraph(&gd, &mode, "");
    floodfill(1, 1, 15);
    setcolor(0);
    // FLor 1, con elipses en vez de arcos, para cambiar la curvatura
    circle((getmaxx()/2)+100, (getmaxy()/2)-75, 50); // Nucleo
    ellipse((getmaxx()/2)+100, (getmaxy()/2)-75, 180, 0, 50, 100); // arriba
    ellipse((getmaxx()/2)+100, (getmaxy()/2)-75, 0, 180, 50, 100); // abajo
    ellipse((getmaxx()/2)+100, (getmaxy()/2)-75, 90, 270, 100, 50); // izquierda
    ellipse((getmaxx()/2)+100, (getmaxy()/2)-75, 270, 90, 100, 50); // derecha
    //ellipse((getmaxx()/2), (getmaxy()/2)-75, 225, 45, 50, 100);

    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    arc((getmaxx()/2) - 50, (getmaxy()/2) + 100, 90, 180, 60); 
    arc((getmaxx()/2) - 50, (getmaxy()/2) + 100, 90, 180, 62);

    // Maceta
    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    line((getmaxx()/2) - 100, (getmaxy()/2) + 100, (getmaxx()/2) + 100, (getmaxy()/2) + 100); // Borde superior
    line((getmaxx()/2) - 100, (getmaxy()/2) + 100, (getmaxx()/2) - 70, (getmaxy()/2) + 200);  // Lado izquierdo
    line((getmaxx()/2) + 100, (getmaxy()/2) + 100, (getmaxx()/2) + 70, (getmaxy()/2) + 200);  // Lado derecho
    line((getmaxx()/2) - 70, (getmaxy()/2) + 200, (getmaxx()/2) + 70, (getmaxy()/2) + 200);   // Borde inferior
    floodfill((getmaxx()/2), (getmaxy()/2) + 150, LIGHTBLUE);
    setcolor(BROWN);
    setfillstyle(HATCH_FILL, BROWN);
    ellipse((getmaxx()/2), (getmaxy()/2) + 100, 0, 360, 100, 15);
    floodfill((getmaxx()/2), (getmaxy()/2) + 100, BROWN);

    //arc(getmaxx()/2, (getmaxy()/2)-46, 190, 350, 50);
    //arc(getmaxx()/2, (getmaxy()/2)-65, 0, 180, 50);
    getch();
    closegraph();
    return 0;
} // Elaboro Garcia Resendis Itztli Kaban