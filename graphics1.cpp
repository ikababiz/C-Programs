#include <graphics.h> 
#include <stdlib.h> 
#include <time.h>
#define C 3 // Cantidad de donas
#define D 30 // Cantidad en ms de delay
typedef struct Donitas 
{
    int x, y;         
    int vx, vy;       
    int r1, r2;       
    int color_base;   
}donut;
int main() 
{
    int ancho = 800, alto = 600;
    initwindow(ancho, alto, (char*)"Bouncy Donuts");
    srand(time(NULL));
    donut donas[C];
    for (int i = 0; i < C; i++) 
    {
        donas[i].r1 = 50 + rand()%15;
        donas[i].r2 = donas[i].r1/2;
        donas[i].x = 100 + (rand()%ancho - 100);
        donas[i].y = 100 + (rand()%alto - 100);
        donas[i].vx = 5 + rand()%5; // velocidad horizontal
        donas[i].vy = 5 + rand()%5; // velocidad vertical
        donas[i].color_base = COLOR(rand()%255,rand()%255,rand()%255);
    }
    while (!kbhit()) 
    {
        cleardevice(); // Borra el buffer oculto
        ancho = getmaxx(); 
        alto = getmaxy();
        for (int i = 0; i < C; i++) 
        {
            setcolor(donas[i].color_base);
            setfillstyle(SOLID_FILL, donas[i].color_base);
            fillellipse(donas[i].x, donas[i].y, donas[i].r1, donas[i].r1);
            setcolor(BLACK); // Color del fondo
            setfillstyle(SOLID_FILL, BLACK);
            fillellipse(donas[i].x, donas[i].y, donas[i].r2, donas[i].r2);
            donas[i].x += donas[i].vx; // Movimiento horizontal en pixeles
            donas[i].y += donas[i].vy; // Movimieto vertical en pixeles
            if (donas[i].x - donas[i].r1 < 0) // Rebote horizontal izquierda
            {
                donas[i].x = donas[i].r1; // Corregir posición para que no se salga
                donas[i].vx = -donas[i].vx; // Cambia de direccion
                donas[i].color_base = 1 + rand()%15;
            }
            else 
            if(donas[i].x + donas[i].r1 > ancho) // Rebote horizontal derecha
            {
                donas[i].x = ancho - donas[i].r1;
                donas[i].vx = -donas[i].vx; // Cambia de direccion
                donas[i].color_base = 1 + rand()%15;
            }
            if (donas[i].y - donas[i].r1 < 0) // Rebote vertical superior
            {
                donas[i].y = donas[i].r1;
                donas[i].vy = -donas[i].vy; // Cambia de direccion
                donas[i].color_base = 1 + rand()%15;
            }
            else 
            if (donas[i].y + donas[i].r1 > alto) // Rebote vertical inferior
            {
                donas[i].y = alto - donas[i].r1;
                donas[i].vy = -donas[i].vy; // Cambia de direccion
                donas[i].color_base = 1 + rand()%15;
            }
        }
        refresh(); // SDL2 fluidez
        delay(D);  
    }
    closegraph();
    return 0;
}