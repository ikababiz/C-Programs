#include<graphics.h>
#include<stdio.h>
//#include<conio.h>
#include<time.h>
#include<stdlib.h>
void Flor(int, int, int);
void Tallo(int,int,int,int,int);
void Pasto(int , int);
main()
{
	int p = DETECT, m, x, y, r = 30;
	//initgraph(&p, &m,"");
    initwindow(639, 479, (char*)"Flores");
	setbkcolor(15);
	cleardevice();
	x = getmaxx();
	y = getmaxy();
	
	Flor(x/2,y/2,r);
	Flor(x/4+(x/8),(y/4)*3,r/2);
	Tallo(0,y/2+50,270,357,x/2);
	Tallo(x-49,y/2-50,210,219,x/2+x/8);
	Pasto(x,y);
	
	getch();
	closegraph();
}
void Pasto(int x, int y)
{
	int i = 0, y1;
	srand((unsigned)time(NULL));
	for(i = 0;i < x; i+=1)
	{
		y1 = rand()%20+10;
		line(i,y,i,y-y1);
	}
}
void Tallo(int x,int y, int ai,int af,int r)
{
	setcolor(GREEN);
	int i;
	for(i = 0; i < 4; ++i)
	{
		arc(x+i,y,ai,af,r);
	}
}
void Flor(int x, int y,int  r)
{
	int a1 = 0, a2 = 90, a3= 180, a4 = 270, r1 = 0;
	int a1_1 = 45, a2_2 = 135, a3_3 = 225, a4_4 = 315;
	setcolor(BLACK);
	r1 = r+(r/4);
	arc(x+r,y+r,a3,a2,r);
	arc(x,y+r1,a3_3,a4_4,r);
	arc(x+r,y-r,a4,a3,r);
	arc(x,y-r1,a1_1,a2_2,r);
	arc(x-r,y-r,a1,a4,r);
	arc(x-r1,y,a2_2,a3_3,r);
	arc(x-r,y+r,a2,a1,r);
	arc(x+r1,y,a4_4,a1_1,r);
	
	r1 += r1/2;
	setfillstyle(1, RED);
	floodfill(x, y, BLACK);
    
    setfillstyle(1, CYAN);
	floodfill(x - r1, y, BLACK);
	floodfill(x + r1, y, BLACK);
	floodfill(x, y - r1, BLACK);
	floodfill(x, y + r1, BLACK);

	setcolor(YELLOW);
	circle(x, y, r);
	setfillstyle(SOLID_FILL, YELLOW);
	floodfill(x, y, YELLOW);
}
