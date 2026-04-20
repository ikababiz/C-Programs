#include <graphics.h>
#include <stdio.h> 

int main()
{
    int ancho = 800, alto = 600;
    initwindow(ancho, alto, (char*)"Trotuga Animada");
    int x1 = 120; 
    int vel = 3, c = 0;
    setbkcolor(WHITE);
    while (!kbhit()) 
    {   
        cleardevice();
        setcolor(COLOR(240, 230, 75)); // Caparazon simetrico
        setfillstyle(1, COLOR(240, 230, 75)); 
        fillellipse(x1, alto/2, 100, 50);
        setcolor(COLOR(200, 110, 20));
        setfillstyle(1, COLOR(200, 110, 20));
        fillellipse(x1, (alto/2)-25, 120, 45);
        switch (c) // Direccion de patas, cabeza, ojo y boca
        {
            case 0:
            {   
                int x2 = x1 + 115; // Cabeza a la derecha
                int cx = x1 + 123; // Ojo más a la derecha
                int l_leg[] = {x1-70, 333, x1-38, 345, x1-49, 369, x1-75, 368, x1-70, 333}; // Pata trasera
                int r_leg[] = {x1+30, 345, x1+62, 338, x1+51, 369, x1+25, 368, x1+30, 345}; // Pata delantera
                setcolor(COLOR(10, 150, 50));
                setfillstyle(1, COLOR(10, 150, 50)); 
                fillpoly(5, l_leg); // Patas
                fillpoly(5, r_leg); 
                fillellipse(x2, 307, 25, 25); // Cabeza
                setcolor(0);
                setfillstyle(1, 15); fillellipse(cx, 300, 10, 10);
                setfillstyle(1, 0);  fillellipse(cx+5, 300, 2, 2);
                line(x1+127, 320, x1+135, 320); // Boca
                x1 += vel; // Movimiento
                if((x1 + 140) >= ancho) // Rebotes
                c = 1; 
                break;
            }   
            case 1: 
            {  
                int x2 = x1 - 115; 
                int cx = x1 - 123; 
                int l_leg[] = {x1+70, 333, x1+38, 345, x1+49, 369, x1+75, 368, x1+70, 333}; // Patas inversas
                int r_leg[] = {x1-30, 345, x1-62, 338, x1-51, 369, x1-25, 368, x1-30, 345}; 
                setcolor(COLOR(10, 150, 50));
                setfillstyle(1, COLOR(10, 150, 50)); 
                fillpoly(5, l_leg); // Patas
                fillpoly(5, r_leg); 
                fillellipse(x2, 307, 25, 25); // Cabeza
                setcolor(0); // Ojo
                setfillstyle(1, 15); fillellipse(cx, 300, 10, 10);
                setfillstyle(1, 0);  fillellipse(cx-5, 300, 2, 2); 
                line(x1-135, 320, x1-127, 320); // Boca
                x1 -= vel; // Regreso
                if((x1 - 140) <= 0) // Rebote
                c = 0; 
                break;
            }   
        }
        refresh(); 
        delay(10);
    }
    closegraph();
    return 0;
}