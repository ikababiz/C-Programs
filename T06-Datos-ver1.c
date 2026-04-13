#include <stdio.h>
void Leer(int *, int *);
void Proceso(int, int, int *, int *, int *, int *, int *);
void Imprimir(int, int, int, int, int, int, int);
int main()
{   // Funcion paso x referencia
    int dato1, dato2, f = 0; // F de flag
    int s = 0, r = 0, m = 0, d = 0;
    Leer(&dato1, &dato2);
    Proceso(dato1, dato2, &s, &r, &m, &d, &f);
    Imprimir(dato1, dato2, s, r, m, d, f);
    return 0;
}
void Leer(int *pd1, int *pd2)
{
    printf("Dato 1: ");
    scanf("%d", pd1);
    printf("Dato 2: ");
    scanf("%d", pd2);
}
void Proceso(int d1, int d2, int *ps,int *pr, int *pm, int *pd, int *pf)
{
    *ps = d1 + d2;
    *pr = d1 - d2;
    *pm = d1 * d2;
    if(d2 != 0)
    *pd = d1 / d2; // valor definido
    else // cuando la divison no esta definida
    *pf = 1; // 
}
void Imprimir(int d1, int d2, int s, int r, int m, int d, int f)
{
    printf("La suma d1 + d2 es: %d + %d = %d\n", d1, d2, s);
    printf("La resta d1 - d2 es: %d - %d = %d\n", d1, d2, r);
    printf("La multiplicacion d1 * d2 es: %d * %d = %d\n", d1, d2, m);
    if(f == 0) 
    printf("La divison d1 / d2 es: %d / %d = %d\n", d1, d2, d);
    else
    printf("La division %d / %d es indefinida\n", d1, d2);
} // Elaboro Garcia Resendis Itztli Kaban