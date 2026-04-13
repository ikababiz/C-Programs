#include<conio.h> 
#include<dos.h> // Para lectura de disco
#include<graphics.h>
main() // Para pixeles de pantalla
{
   int ojo = DETECT, pie;
   initgraph(&ojo, &pie, "C:\\TC\\BGI");
   setfillstyle(SOLID_FILL, WHITE); // Fondo blanco
   bar(0, 0, getmaxx(), getmaxy()); // Rectangulo enorme
   printf("horizontal =%d\n",getmaxx());
   printf("vertical   =%d\n",getmaxy());
   getch();
   closegraph();
} // Elaboro Garcia Resendis Itztli Kaban