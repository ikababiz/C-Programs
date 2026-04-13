#include <stdio.h>
#define F 60
#define H 24
int main() // Punteros 
{   
    int d, h = 0, m = 0, s = 0;
    int *pd = NULL, *ph = NULL, *pm = NULL, *ps = NULL;
    pd = &d;
    ph = &h;
    pm = &m;
    ps = &s;
    do
    {
        printf("Dias: ");
        scanf("%d", &d);
        if(d < 1)
        printf("Error, los dias deben ser mayores a 0, vuelva a intentar\n");
    } 
    while (d < 1);// Desreferenciacion 
    h = d * H; // es igual a *ph = *pd * H;
    m = h * F; // es igual a *pm = *ph * T;
    s = m * F; // es igual a *ps = *pm * T;
    printf("Horas = %d\n", *ph); // = printf("Horas = %d\n", h);
    printf("Minutos = %d\n", *pm); // = printf("Minutos = %d\n", m);
    printf("Segundos = %d\n", *ps); // = printf("Segundos = %d\n", s);
    printf("Direccion de d = %p\n", ph);
    printf("Direccion de m = %p\n", pm); // opcional
    printf("Direccion de s = %p\n", ps);
    return 0;
} // Elaboro Garcia Resendis Itztli Kaban