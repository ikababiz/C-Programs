#include <stdio.h>
#define F 3
#define C 3
int main() // Practicar matrices (arreglos  bidimensionales tipo int)
{
    int i, j, arr[F][C];
    printf("Este programa solicita al usuario valores enteros para almacenar en una matriz 3x3\n");
    for(i = 0; i < F; ++ i)
    {
        for(j = 0; j < C; ++j)
        {
            printf("Escriba el valor de a%d%d: ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("La matriz ingresada es: \n");
    for(i = 0; i < F; ++ i)
    {
        for(j = 0; j < C; ++j)
        {
            printf("%4d", arr[i][j]);
        }
        putchar('\n');
    }
    return 0; // Elaboro Garcia Resendis Itztli Kaban
}