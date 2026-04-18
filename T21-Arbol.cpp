#include <graphics.h>
int main() 
{
    int swide = 800, sheight = 600;
    initwindow(swide, sheight, (char*)"La manzana de Newton");
    int y = 280;
    setbkcolor(WHITE);
    while (!kbhit())
    {   
        cleardevice();
        setfillstyle(1, COLOR(139, 69, 19)); // Alternativa a setrgbpallette usando SDL2
        setcolor(0);
        bar(375, 350, 425, 500); 
        setcolor(COLOR(0, 102, 0));
        setfillstyle(1, COLOR(0, 102, 0));
        fillellipse(400, 300, 80, 80); // Circulo principal
        fillellipse(350, 320, 60, 60); // Lado izquierdo
        fillellipse(450, 320, 60, 60); // Lado derecho
        setcolor(COLOR(255, 0, 0));
        setfillstyle(1, COLOR(255, 0, 0));
        fillellipse(380, y, 10, 12); 
        setcolor(0);
        line(380, y-10, 380, y-15);
        getch();
        if(y <= (sheight - 30))
        y++;
        refresh(); 
        delay(5);  
    }
    closegraph();
    return 0;
}