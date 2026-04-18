#include <graphics.h>
#include <stdio.h> 
int main()
{
    int ancho = 800, alto = 600;
    initwindow(ancho, alto, (char*)"Pez");
    int tx = 70, tx2 = 120, vel = 3, c = 0;
    int rtx = 70, rtx2 = 120;
    setfillstyle(1, COLOR(245, 155, 22));
    while (!kbhit()) 
    {   
        cleardevice();
        switch (c)
        {
            case 0: 
            {   
                int t_der[] = {tx, 230, tx, 310, tx + 50, 270, tx, 230};
                int t2_der[] = {tx2, 190, tx2, 330, tx2 + 150, 260, tx2, 190};
                fillpoly(4, t_der);
                fillpoly(4, t2_der);
                tx += vel;
                tx2 += vel;
                if(tx2 >= (ancho - 150)) 
                {
                    c = 1; 
                }
                break;
            }   
            case 1: 
            {  
                int t2_izq[] = {tx, 260,tx + 150, 190,tx + 150, 330,tx, 260};
                int t_izq[] = {tx + 150, 270,tx + 200, 230,tx + 200, 310,tx + 150, 270};
                fillpoly(4, t_izq);
                fillpoly(4, t2_izq);
                tx -= vel;
                tx2 -= vel;
                if(tx <= 0) 
                {
                    c = 0; 
                }
                break;
            }   
        }
        refresh(); 
        delay(10);
    }
    getch();
    closegraph();
    return 0;
}