#include <stdio.h>
#define A 3
#define T 50
typedef struct regustri // A 3 y T 50
{
    char nombre[T];
    float cals[A];
    double prom;
}reg;
void Entrada(reg *);
void Promedio(reg *);
void Salida(reg);
int main()
{
    reg var1, *ap =  NULL;
    ap = &var1;
    Entrada(&var1); // Metodo 1
    Promedio(ap); // Metodo 2
    Salida(var1); // Solo lectura
    return 0;
}
void Entrada(reg *x)
{   int i;
    printf("Escriba el nombre: ");
    fgets(x->nombre, T, stdin);
    for(i = 0; i < A; ++i)
    {
        do
        {
            printf("Escriba la calificacion %d: ", i+1);
            scanf("%f", &x->cals[i]);
            if(x->cals[i] < 0 || x->cals[i] > 10)
            printf("Error, escriba una calificacion valida\n");
        } while (x->cals[i] < 0 || x->cals[i] > 10);
    }
}
void Promedio(reg *x)
{   float total = 0;
    int i;
    for(i = 0; i < A; ++i)
        total += x->cals[i];
    total /= A;
    x->prom = total;
}
void Salida(reg x)
{
    printf("Nombre: %s", x.nombre);
    for (int i = 0; i < A; i++)
        printf("Calificacion %d: %.1f\n", i+1, x.cals[i]);
    printf("Promedio = %.1f\n", x.prom);
}