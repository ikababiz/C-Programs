#include <graphics.h>
#include <math.h>
#include <conio.h>
#define PI 3.14159
void dibujarFlor(int, int, int, int, int);
int main() {
    int gd = DETECT, mode;
    initgraph(&gd, &mode, "");
    floodfill(1, 1, 15);
    setcolor(LIGHTBLUE); // Maceta
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    line((getmaxx()/2) - 100, (getmaxy()/2) + 100, (getmaxx()/2) + 100, (getmaxy()/2) + 100); // Borde superior
    line((getmaxx()/2) - 100, (getmaxy()/2) + 100, (getmaxx()/2) - 70, (getmaxy()/2) + 200);  // Lado izquierdo
    line((getmaxx()/2) + 100, (getmaxy()/2) + 100, (getmaxx()/2) + 70, (getmaxy()/2) + 200);  // Lado derecho
    line((getmaxx()/2) - 70, (getmaxy()/2) + 200, (getmaxx()/2) + 70, (getmaxy()/2) + 200);   // Borde inferior
    floodfill((getmaxx()/2), (getmaxy()/2) + 150, LIGHTBLUE);
    setcolor(BLACK);
    setfillstyle(1, BROWN);
    ellipse((getmaxx()/2), (getmaxy()/2) + 100, 0, 360, 100, 15);
    floodfill((getmaxx()/2), (getmaxy()/2) + 100, BLACK);
    setcolor(BLACK); // Tallo
    ellipse((getmaxx()/2), (getmaxy()/2) + 30, 90, 270, 15, 70);
    ellipse((getmaxx()/2) + 10, (getmaxy()/2) + 30, 90, 270, 15, 70);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, GREEN);
    arc((getmaxx()/2) - 55, (getmaxy()/2) + 60, 0, 90, 40); // Hoja
    arc((getmaxx()/2) - 15, (getmaxy()/2) + 20, 180, 270, 40);
    floodfill(292, 278, BLACK);
    setcolor(BLACK);
    line(264, 262, 303, 298);
    dibujarFlor((getmaxx()/2), (getmaxy()/2)-100, 5, 60, 70); // 5 petalos
    setfillstyle(SOLID_FILL, GREEN); // Rellena el tallo
    floodfill(310, 270, BLACK);

    getch();
    closegraph();
    return 0;
}
void dibujarFlor(int xCentro, int yCentro, int numPetalos, int radioPetalo, int centroRosa) 
{   int i;
    double angulo, rad;
    setcolor(BLACK); // Borde negro
    setfillstyle(SOLID_FILL, RED); // Petalos rojos
    for (i = 0; i < numPetalos; i++) 
    {
        angulo = i * (360.0 / numPetalos);
        rad = angulo * PI / 180.0;
        // Calculamos el centro de cada elipse/petalo desplazado del centro de la flor
        int px = xCentro + cos(rad) * radioPetalo;
        int py = yCentro + sin(rad) * radioPetalo;
        fillellipse(px, py, radioPetalo, radioPetalo); 
    }
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, YELLOW); // Nucleo
    fillellipse(xCentro, yCentro, centroRosa, centroRosa);
}