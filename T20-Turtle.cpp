#include <graphics.h>
#include <stdio.h> 
#include <math.h>
int main()
{
    int a = 0, b = 20;
    
    initwindow(1000, 800, (char*)"Tortuga");
    floodfill(1, 1, 15);
    setcolor(0);
    ellipse(getmaxx()/2, (getmaxy()/2), 0, 360, 200, 100);
    ellipse(getmaxx()/2, (getmaxy()/2)-40, 0, 360, 225, 65);
    setfillstyle(8, BROWN);
    floodfill(305, 350, 0); 
    floodfill(450, 350, 0);
    setfillstyle(7, YELLOW);
    floodfill(500, 450, 0);     
    setcolor(BROWN);
    ellipse(getmaxx()/2, (getmaxy()/2), 0, 360, 200, 100);
    setcolor(GREEN);
    arc(340, 470, 220, 350, 75);
    arc(320, 470, 220, 350, 60);
    arc(540, 470, 240, 350, 75);
    arc(520, 480, 240, 350, 60);
    line(380, 480, 412, 488);
    line(575, 495, 613, 486);
    setfillstyle(1, GREEN);
    floodfill(377, 510, GREEN);     
    floodfill(587, 512, GREEN);   
    arc(687, 380, 270, 365, 50);
    arc(670, 380, 270, 365, 75);
    circle(740, 390, 25);
    line(670, 455, 690, 428);
    floodfill(718, 420, GREEN);  
    floodfill(740, 388, GREEN);  
    setcolor(WHITE);
    fillellipse(750, 390, 7, 7);
    setfillstyle(1, WHITE);
    floodfill(748, 387, WHITE); 
    putpixel(750, 387, BLACK);
    setcolor(0);
    arc(748, 400, 250, 330, 10);
    getch();
    while(!kbhit()) 
    {
        if (ismouseclick(WM_LBUTTONDOWN)) 
        {   int mouseX = mousex();
            int mouseY = mousey();
            printf("Click en: X=%d, Y=%d\n", mouseX, mouseY);
            clearmouseclick(WM_LBUTTONDOWN);
        }
        delay(100); 
    }
    closegraph();
    return 0;
}