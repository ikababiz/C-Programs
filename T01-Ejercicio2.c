#include <stdio.h>
#define C 5
int main()
{
    char cars[C];
    int i;
    for (i = 0;i < C; ++i)
    {
        printf("Introduzca un caracter: ");
        cars[i] = getchar();
        fflush(stdin);
    }
    printf("El arreglo es:\n{");
    for (i = 0; i < C; ++i)
    {
        putchar(cars[i]);
    }
    putchar('}');
    return 0;
}