#include <stdio.h>
#define F 24
void Leer(int *); 
void Proceso(int, int *, int *, int *, int);
void Imprimir(int, int, int, int);
int main()
{
    const int x = 60;
    int d = 0, h = 0, m = 0, s = 0;
    Leer(&d);
    Proceso(d, &h, &m, &s, x);
    Imprimir(d, h, m, s);
    return 0;
}
void Leer(int *d)
{
    printf("Escriba los dias: ");
    do
    {
       scanf("%d", d);
       if(d < 1)
       printf("Error, los dias deben ser mayores a 0, vuelva a intentar\n");
    } 
    while (d < 1);
}
void Proceso(int d, int *ph, int *pm, int *ps, int x)
{
    *ph = d * F;
    *pm = *ph * x;
    *ps = *pm * x;
}
void Imprimir(int d, int h, int m, int s)
{
    printf("Los dias son = %d\n", d);
    printf("Las horas son = %d\n", h);
    printf("Los minutos son = %d\n", m);
    printf("Los segundos son = %d\n", s);
}
