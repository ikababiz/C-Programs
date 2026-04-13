#include <conio.h> 
#include <time.h>
#include <graphics.h>
#include <stdio.h>
int main() // Fondo, tramas y cuadrado
{
    int gd = DETECT, mode, i, x;
    initgraph(&gd, &mode, ""); 
    srand((unsigned)time(NULL)); // Para que sea aleatorio entre ejecuciones
    unsigned int gbc = getbkcolor();
    printf("El color del fondo es %d\n", gbc); // 0 Que es BLACK
    setbkcolor(WHITE); // 15 que es WHITE
    cleardevice(); // Para limpiar la pantalla, importante para que se vea el cambio
    gbc = getbkcolor(); 
    printf("El color activo de la pantalla es %d\n", gbc);
    setcolor(GREEN);
    rectangle(50, 50, 400, 400);
    for (i = 0; i <= 11; i++) // Evitando el 12
    {   
        x = rand()%14; // Todos los colores menos el 15(blanco) 
        setfillstyle(i, x); // Tramas del 0-11 y colores aleatorios
        floodfill(75, 75, GREEN);
        delay(500); // 500 ms de retraso (medio segundo para que sea visible)
    }
    settextstyle(1, 1, 2);
    outtextxy(450, 50, "Proceso terminado, presione una tecla para salir."); // Mensaje final
    getch();
    closegraph();
    return 0;
} // Elaboro Garcia Resendis Itztli Kaban