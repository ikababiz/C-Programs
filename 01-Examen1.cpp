#include <stdio.h> // Programa 1 Examen
#define H 40
#define Ph 150.00
#define Phe 250.00
void Entrada(int *);
void F_Extra(int *, int *);
void Proceso(int, int, float, float *, float *, float *, float *);
void Imprimir(float, float, float, float);
int main() 
{   int h, he = 0;
    float bruto = 0, im = 0, imhe = 0, neto = 0;
    const float iva = 0.16;
    Entrada(&h);
    F_Extra(&h, &he);
    Proceso(h, he, iva, &bruto, &im, &imhe, &neto);
    Imprimir(neto, bruto, imhe, im);
    return 0; 
}
void Entrada(int *h)
{   do
    {   printf("Horas: ");
        scanf("%d", h);
        if(*h <= 0)
        printf("Error, deben ser mayores a 0, vuelva a intentar\n");
    } while (*h <= 0);
}
void F_Extra(int *h, int *he)
{
    if(*h > H)
    {   *he = *h - H;
        *h -= *he;
    }
    else
    *he = 0; // No hace falta porque estaba inicializado
}
void Proceso(int h, int he, float iva, float *b, float *im, float *imhe, float *net)
{
    *b = h * Ph;
    *im = *b * iva;
    if(he != 0)
    *imhe = he * Phe;
    else
    *imhe = 0;
    *net = *b - *im + *imhe;
}
void Imprimir(float net, float b, float imhe, float im)
{
    printf("Importe a pagar = $%.2f\n", net);
    printf("Importe bruto = $%.2f\n", b);
    printf("Importes extras = $%.2f\n", imhe);
    printf("Importe iva = $%.2f\n", im);
} // Elaboro Garcia Resendis Itztli Kaban