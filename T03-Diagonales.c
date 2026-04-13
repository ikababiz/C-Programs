#include <stdio.h>
#define C 3
int main() // Diagonales de matrices cuadradas
{
    int i, j, matriz[C][C];
    for(i = 0; i < C; ++ i)
    {
        for(j = 0; j < C; ++j)
        {
            printf("Escriba el valor de a%d%d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("La matriz ingresada es: \n");
    for(i = 0; i < C; ++ i)
    {
        for(j = 0; j < C; ++j)
        {
            printf("%4d", matriz[i][j]);
        }
        putchar('\n');
    }
    printf("La diagonal principal de la matriz ingresada es: \n");
    for(i = 0; i < C; ++ i)
    {
        for(j = 0; j < C; ++j)
        {
            if(i == j)
            printf("%4d", matriz[i][j]);
            else
            putchar(' ');
        }
        putchar('\n');
    }
    printf("La diagonal secundaria de la matriz ingresada es: \n");
    for(i = 0; i < C; ++ i)
    {
        for(j = 0; j < C; ++j)
        {
            if(i+j == 2)
            printf("%4d", matriz[i][j]);
            else
            putchar(' ');
        }
        putchar('\n');
    }
    return 0; // Elaboro Garcia Resendis Itztli Kaban
}