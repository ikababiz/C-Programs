#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define MAX_RAYOS 500
typedef struct Rayos 
{
    float x, y;
    float vx, vy;
    int activo;
}ray;
int main() 
{
    int w = 800, h = 600;
    initwindow(w, h, (char*)"Black Hole 2D");
    srand(time(NULL));
    float cx = w/2, cy = h/2;
    float rEvent = 80;
    float masaGravedad = 1500;
    float tiempo = 0;
    ray rayos[MAX_RAYOS];
    for (int i = 0; i < MAX_RAYOS; i++) 
    {
        rayos[i].x = 0;
        rayos[i].y = rand() % 600;
        rayos[i].vx = 5;
        rayos[i].vy = 0;
        rayos[i].activo = 1;
    }
    while (!kbhit()) 
    {
        cleardevice();
        tiempo += 0.1;
        float pulso = sin(tiempo) * 10;
        setcolor(COLOR(247, 176, 8));
        setfillstyle(SOLID_FILL, BLACK);
        fillellipse(cx, cy, rEvent + pulso, rEvent + pulso);
        fillellipse(cx, cy, (rEvent+40) + pulso, (rEvent+40) + pulso);
        circle(cx, cy, rEvent + pulso + 2);
        circle(cx, cy, (rEvent+40) + pulso + 2);
        for (int i = 0; i < MAX_RAYOS; i++) 
        {
            if (rayos[i].activo) 
            {
                float dx = cx - rayos[i].x;
                float dy = cy - rayos[i].y;
                float distSq = dx * dx + dy * dy;
                float dist = sqrt(distSq);
                if (dist < (rEvent + pulso)) 
                {
                    rayos[i].x = 0;
                    rayos[i].y = rand() % 600;
                    rayos[i].vx = 5;
                    rayos[i].vy = 0;
                } 
                else 
                {
                    float fuerza = masaGravedad / (distSq + 1);
                    rayos[i].vx += (dx / dist) * fuerza;
                    rayos[i].vy += (dy / dist) * fuerza;
                    rayos[i].x += rayos[i].vx;
                    rayos[i].y += rayos[i].vy;
                    putpixel((int)rayos[i].x, (int)rayos[i].y, COLOR(rand()%255,rand()%255,rand()%255));
                }
                if (rayos[i].x > 1000 || rayos[i].x < 0 || rayos[i].y > 600 || rayos[i].y < 0) 
                {
                    rayos[i].x = 0;
                    rayos[i].y = rand() % 600;
                    rayos[i].vx = 5;
                    rayos[i].vy = 0;
                }
            }
        }
        refresh(); 
        delay(16); // Control de FPS
    }
    closegraph();
    return 0;
}