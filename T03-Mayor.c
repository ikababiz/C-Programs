#include <stdio.h>
#define C 3
int main() // Mayor de negativos en arreglo inicializado
{
    int i, j, mayor = 0;
    int matriz[][C]={{-4,-14,-13},{-6,-68,-1},{-15,-18,-31},{-74,-154,-138},{-54,-138,-21},{-79,-76,-78}};
    mayor = matriz[0][0]; // El primer elemento
    for(i = 0; i < sizeof(matriz)/sizeof(matriz[0]); ++ i)
    {
        for(j = 0; j < C; ++j)
        {
            if(mayor < matriz[i][j])
            mayor = matriz[i][j];
        }
    }
    printf("La matriz es: \n");
    for(i = 0; i < sizeof(matriz)/sizeof(matriz[0]); ++ i)
    {
        for(j = 0; j < C; ++j)
        {
            printf("%5d", matriz[i][j]);
        }
        putchar('\n');
    }
    printf("El mayor valor del arreglo es: %d\n", mayor);
    return 0; // Elaboro Garcia Resendis Itztli Kaban
}