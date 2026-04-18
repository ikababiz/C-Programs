#include<graphics.h>
#include<stdio.h>
#include<math.h>
//Valores de los radios de la manzana.
int rx_manzana = 8,  ry_manzana = rx_manzana+rx_manzana/6;

void Manzana(int,int);
void MueveMan(int,int);
void OcultaMan(int, int);
void Arbol(int, int);
void Hoja(int, int);
void Tallo(int, int);
main()
{
	int p = DETECT, m;
	initgraph(&p,&m, (char*)"Arbol");
	setbkcolor(15);
	cleardevice();
	Arbol(getmaxx(),getmaxy());
   	getch();
	closegraph();
}
void Arbol(int x,int y)
{
	int x1, y1, re = 170/17, r_hoja = 22, angle = 10, anglef =170, a1 = 275, a2 = 90;
	int i =0, x_inicio, y_inicio;
	double xf = 0, yf = 0;
  	struct arccoordstype a;
	setlinestyle(1,1,4);
    x1 = x / 4;
    y1 = 7 * y / 10; 
    setcolor(BROWN);
	ellipse(x-x1-r_hoja, (y+y1)/2, 98, 270,x1/2,y-y1);
	ellipse(x1+r_hoja,(y+y1)/2, 270, 82,x1/2,y-y1);
	while(angle <= anglef)
    {
	    setcolor(15);
		setlinestyle(0,0,0);
   		arc(x/2,(5*y)/8,angle,angle,240);
	    getarccoords(&a);
	    setcolor(GREEN);
	    setlinestyle(1,1,4);
	    ellipse(a.xstart,a.ystart,a1+=re,a2+=re,r_hoja,r_hoja);
	    if(angle ==10)
    	{
    		x_inicio = a.xstart;	y_inicio = a.ystart;
		}
		angle += 10;
    	delay(5);
    }
    x1 = a.xend;    y1 = a.yend;
    arc(x1,y1,anglef,330,r_hoja);
    for(i = 3; i <= 9; i += 3)
    {
    	arc(x1+(i*r_hoja/2),y1,210,330,r_hoja);
	}
	arc(x_inicio,y_inicio,210,10,r_hoja);
	for(i = 3; i <= 9; i += 3)
    {
    	arc(x_inicio-(i*r_hoja/2),y_inicio,210,330,r_hoja);
	}
    xf = a.xend - 22 * cos(a1-re);
    yf = a.yend - 22 * sin(a2-re);
    yf += 3*ry_manzana/2;
    Manzana(xf,yf);
    Hoja(xf, yf);
    Tallo(xf, yf);
    MueveMan(xf,yf);
}
void OcultaMan(int x, int y)
{
	setcolor(getbkcolor());
	setfillstyle(1,getbkcolor());
	setlinestyle(1,0,2);
	fillellipse(x,y,ry_manzana+5,ry_manzana+1);
}
void MueveMan(int x,int y)
{
	int aux = 2;
	getch();
	while(y <= getmaxy()-ry_manzana)
	{
		OcultaMan(x,y);
		y += aux;
		Manzana(x,y);
		delay(30);
		
	}
}
void Hoja(int x,int y)
{
	int x1,y1;
	setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    x1 = (x+2*rx_manzana/3);
    y1 = ((y-ry_manzana)+(y-3*ry_manzana/2))/2;
    fillellipse(x1, y1, rx_manzana/3, 2*rx_manzana/16);
}
void Tallo(int x, int y)
{
	setcolor(BROWN);
    setlinestyle(SOLID_LINE, 0, 3);
    line(x,y-ry_manzana, x + rx_manzana/2, y-3*ry_manzana/2);
}
void Manzana(int x, int y)
{
	int x1 = 300/(rx_manzana*14), y1;
	//MANZANA
	setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    setlinestyle(SOLID_LINE, 0, 2);
	setcolor(0);
	ellipse(x-x1,y,70,295,rx_manzana,ry_manzana);
	ellipse(x+x1,y,250,115,rx_manzana,ry_manzana);
	floodfill(x,y,0);
}

