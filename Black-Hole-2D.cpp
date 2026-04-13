#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
// Definimos el maximo de rayos para el arreglo
#define MAX_RAYOS 100
struct Rayo 
{
    float x, y;
    float vx, vy;
    int activo;
};
int main() 
{
    // 1. Inicializar la ventana (1000x600)
    int gd = DETECT, gm;
    initwindow(1000, 600, "Simulacion: Agujero Negro BGI");
    srand(time(NULL));
    // Parametros del Agujero Negro
    float centroX = 500, centroY = 300;
    float radioEvento = 80;
    float masaGravedad = 1500;
    float tiempo = 0;
    // Lista de rayos (Arreglo estatico)
    struct Rayo rayos[MAX_RAYOS];
    // Inicializar rayos
    for (int i = 0; i < MAX_RAYOS; i++) 
    {
        rayos[i].x = 0;
        rayos[i].y = rand() % 600;
        rayos[i].vx = 5;
        rayos[i].vy = 0;
        rayos[i].activo = 1;
    }
    // Doble buffer para evitar parpadeo (IMPORTANTE en la extension)
    int page = 0;
    while (!kbhit()) // Corre hasta que presiones una tecla
    {
        setactivepage(page);      // Dibujamos en la pagina oculta
        setvisualpage(1 - page);  // Mostramos la pagina anterior
        cleardevice();            // Limpiamos pantalla
        // 2. Dibujar Agujero Negro (Fondo Negro, Borde Rojo)
        tiempo += 0.1;
        float pulso = sin(tiempo) * 10; // Efecto de latido
        setcolor(RED);           // El color naranja de SFML ahora es ROJO
        setfillstyle(SOLID_FILL, BLACK);
        fillellipse(centroX, centroY, radioEvento + pulso, radioEvento + pulso);
        // Dibujar borde grueso (simulando outline)
        circle(centroX, centroY, radioEvento + pulso + 2);
        // 3. Logica de Fisica y Dibujo de Rayos
        for (int i = 0; i < MAX_RAYOS; i++) 
        {
            if (rayos[i].activo) 
            {
                // Calcular distancia
                float dx = centroX - rayos[i].x;
                float dy = centroY - rayos[i].y;
                float distSq = dx * dx + dy * dy;
                float dist = sqrt(distSq);
                if (dist < radioEvento) // Radio del Event Horizon
                {
                    // Absorbido: lo reiniciamos a la izquierda
                    rayos[i].x = 0;
                    rayos[i].y = rand() % 600;
                    rayos[i].vx = 5;
                    rayos[i].vy = 0;
                }
                else 
                {
                    // Atraccion gravitatoria
                    float fuerza = masaGravedad / distSq;
                    rayos[i].vx += (dx / dist) * fuerza;
                    rayos[i].vy += (dy / dist) * fuerza;
                    // Movimiento
                    rayos[i].x += rayos[i].vx;
                    rayos[i].y += rayos[i].vy;
                    // Dibujar rayo (un punto blanco pequeño)
                    setcolor(WHITE);
                    putpixel(rayos[i].x, rayos[i].y, WHITE);
                    // O un circulo pequeño:
                    // fillellipse(rayos[i].x, rayos[i].y, 1, 1);
                }
                // Reiniciar si sale de pantalla
                if (rayos[i].x > 1000 || rayos[i].y > 600 || rayos[i].y < 0) 
                {
                    rayos[i].x = 0;
                    rayos[i].y = rand() % 600;
                    rayos[i].vx = 5;
                    rayos[i].vy = 0;
                }
            }
        }
        page = 1 - page; // Cambiamos de pagina
        delay(10);       // Pequeña pausa para controlar la velocidad
    }
    closegraph();
    return 0;
}