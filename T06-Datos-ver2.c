#include <stdio.h>
int Leer(void);
int Suma(int, int);
int Resta(int, int);
int Multiplicacion(int, int);
int Division(int, int);
void Imprimir(int, int, int, int, int, int, int);
int main()
{   // Funcion paso x valor
    int dato1, dato2, f = 0; // Banderita
    int s = 0, r = 0, m = 0, d = 0;
    printf("Dato 1: ");
    dato1 = Leer();
    printf("Dato 2: ");
    dato2 = Leer();
    s = Suma(dato1, dato2);
    r = Resta(dato1, dato2);
    m = Multiplicacion(dato1, dato2);
    if(dato2 != 0)
    d = Division(dato1, dato2);
    else 
    f = 1; 
    Imprimir(dato1, dato2, s, r, m, d, f);
    return 0;
}
int Leer(void)
{   int x;
    scanf("%d", &x);
    return x;
}
int Suma(int d1, int d2)
{   int s = 0;
    s = d1 + d2;
    return s;
}
int Resta(int d1, int d2)
{   int r = 0;
    r = d1 - d2;
    return r;
}
int Multiplicacion(int d1, int d2)
{   int m = 0;
    m = d1 * d2;
    return m;
}
int Division(int d1, int d2)
{   int d = 0;
    d = d1 / d2;
    return d;
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