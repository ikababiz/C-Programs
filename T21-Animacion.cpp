#include <graphics.h>
#include <time.h>
int main() // Circulo y triangulo animados
{   int swide = 800, sheight = 800; // Pantalla cuadrada
    initwindow(swide, sheight, (char*)"Circulo y Triangulo");
    int r = 50, l = 40, c = 0;
    int x = r, y = r, i = 0, j = 0; 
    int cx = r, cy = r; // Centro circulo
    int tx = r, ty = r; // Centro triangulo
    int vel = 3;     
    while (!kbhit()) 
    {   int triangulo[] = { tx, ty - l, tx - l, ty + l, tx + l, ty + l, tx, ty - l };
        cleardevice(); // Borra  el dibujo completo anterior
        setcolor(WHITE);
        circle(cx, cy, r);
        setfillstyle(1, COLOR(22, 220, 154)); // Alternativa a setrgbpalette(1, 22, 220, 154); 
        floodfill(cx, cy, WHITE); 
        setfillstyle(1, COLOR(118, 20, 138)); 
        fillpoly(4, triangulo);
        switch (c) 
        {   case 0: 
                cx += vel; // 1-2
                ty += vel; // 1-4
                if(cx >= swide - r){cx = swide - r; ty = sheight - r; c = 1;}
            break;
            case 1: 
                cy += vel; // 2-3
                tx += vel; // 4-3
                if(cy >= sheight - r){cy = sheight - r; tx = swide - r; c = 2;}
                break;
            case 2:
                cy -= vel; // 3-2
                tx -= vel; // 3-4
                if(cy <= r){cy = r; tx = r; c = 3;}
                break;
            case 3: 
                cx -= vel; // 2-1
                ty -= vel; // 4-1
                if(cx <= r){cx = r; ty = r; c = 0;}
                break;
        }
        refresh(); // Necesario para recordar a la ventana que aun termina la animacion
        delay(10);  
    }
    getch();
    closegraph();
    return 0;
}