#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main() // Numeros aleatorios
{   
    int i, x; // time(NULL) devuelve el numero de segundos desde 01/01/1970
    srand((unsigned)time(NULL)); // Para cambiar la "semilla" de aleatoriedad cada vez
    printf("Este programa imprime 10 valores enteros aleatorios\n");
    for (i = 1; i <= 10; ++i)
    {   
        x = (rand()%100) + 1; // Genera un numero aleatorio entre 1 y 100
        printf("%d\n", x);
    }
    return 0;
} // Elaboro Garcia Resendis Itztli Kaban