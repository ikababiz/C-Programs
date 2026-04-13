#include <stdio.h>
#define F 2
void Entrada(int *[F]);
void Salida(int *[F]);
void Asigna(int *[F]);
int main() // Uso de matrices de punteros
{
    int *arr[F];
    Asigna(arr);
    Entrada(arr);
    Salida(arr);
    return 0;
}
void Asigna(int *arr[F])
{   int c;
    int otro[] = {4,5}; // Este arreglo tiene que ser del mismo tamanio que T
    for(c=0;c<F;++c)
    *(arr+c)=(otro+c);
}
void Entrada(int *arr[F])
{   int c;
    printf("Ecriba dos numeros enteros: ");
    for(c=0;c<F;++c)
    scanf("%d", *(arr+c));
}
void Salida(int *arr[F])
{   int c;
    printf("Los numeros fueron = ");
    for(c=0;c<F;++c)
    printf("%d ", *(*(arr+c)));
}// Elboro Garcia Resendis Itzlti Kaban