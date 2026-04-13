#include <stdio.h>
#include <time.h>
#include <conio.h> 
#include <graphics.h>
int main() // Noche estrellada
{   
    int gd = DETECT, mode, x, y, color;
    initgraph(&gd, &mode, ""); 
    srand((unsigned)time(NULL));
    do
    {
        x = rand()%getmaxx(); // Toda la pantalla
        y = rand()%getmaxy();
        color = rand()%15; // Todos los colores menos el 0 (BLACK)
        putpixel(x, y, color);
        delay(1);
    } while (!kbhit()); // Mientras no haya cambios en el teclado
    closegraph();
    return 0;
} // Elaboro Garcia Resendis Itztli Kaban