#include <graphics.h>
#include <conio.h>
//#include <dos.h>   
#include <stdlib.h> // Para rand()
#define ANCHO 620
#define ALTO 480
#define C 1 // cantidad de donas
#define D 40
struct Dona
{
    int x, y;         // Posición del centro
    int vx, vy;       // Velocidad en X, Y
    int r1, r2;       // Radio exterior e interior
    int color_base;   // Color de la dona
    int color_centro; // Color del hueco
};
int main()
{
    int gd = DETECT, gm;             // Detectar y abrir la ventana gráfica
    initgraph(&gd, &gm, (char *)""); // formato

    if (graphresult() != 0)
    {            // Si no se pudo inicializar, salimos
        getch(); // Esperar una tecla antes de salir
        return 1;
    }
    // Configuración para doble buffer (evita el parpadeo)
    int pagina = 0;
    Dona donas[C];
    for (int i = 0; i < C; i++)
    {
        donas[i].r1 = 50 + (i * 10);
        donas[i].r2 = 30 + (i * 5);
        donas[i].x = donas[i].r1 + rand() % (ANCHO - 2 * donas[i].r1);
        donas[i].y = donas[i].r1 + rand() % (ALTO - 2 * donas[i].r1);
        donas[i].vx = (rand() % 2 == 0 ? 5 : -5) + (i % 2);
        donas[i].vy = (rand() % 2 == 0 ? 5 : -5) - (i % 2);
        donas[i].color_base = LIGHTCYAN + (i % 2);
        donas[i].color_centro = BLACK; // Color del fondo de la ventana
    }
    // El bucle principal de la animación (se ejecuta hasta presionar una tecla)
    while (!kbhit())
    {
        // --- PARTE 1: Dibujar en la página oculta ---
        setactivepage(pagina);
        cleardevice(); // Limpiar la  pantalla
        // Dibujar y actualizar cada dona
        for (int i = 0; i < C; i++)
        {
            // Dibujar la dona (círculo grande relleno)
            setcolor(donas[i].color_base);
            setfillstyle(SOLID_FILL, donas[i].color_base);
            fillellipse(donas[i].x, donas[i].y, donas[i].r1, donas[i].r1);
            // Dibujar el hueco (círculo pequeño relleno del color de fondo)
            setcolor(donas[i].color_centro);
            setfillstyle(SOLID_FILL, donas[i].color_centro);
            fillellipse(donas[i].x, donas[i].y, donas[i].r2, donas[i].r2);
            // --- PARTE 2: Actualizar la posición para el siguiente frame ---
            donas[i].x += donas[i].vx;
            donas[i].y += donas[i].vy;
            // Rebotar en los bordes izquierdo y derecho
            if (donas[i].x - donas[i].r1 < 0 || donas[i].x + donas[i].r1 > ANCHO)
            {
                donas[i].vx = -donas[i].vx;
                // 1. Color aleatorio (1 al 15, evitando el negro que es 0)
                donas[i].color_base = 1 + rand() % 15;
            }

            // Rebotar en los bordes superior e inferior
            if (donas[i].y - donas[i].r1 < 0 || donas[i].y + donas[i].r1 > ALTO)
            {
                donas[i].vy = -donas[i].vy;
                // Color aleatorio al rebotar arriba/abajo
                donas[i].color_base = 1 + rand() % 15;
            }
        }
        // --- PARTE 3: Intercambiar las páginas (Doble Buffer) ---
        setvisualpage(pagina); // Mostrar lo que acabamos de dibujar
        pagina = 1 - pagina;   // Cambiar a la otra página para el siguiente frame
        delay(D);             // Un pequeño retraso para controlar la velocidad (aprox 60 FPS)
    }
    // Cerramos el modo gráfico y terminamos
    closegraph();
    return 0;
}