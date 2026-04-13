#include <stdio.h>
#define C 7
int main()
{
    int i, j, arr[C], temp = 0;
    printf("Introduzca 7 numeros enteros: ");
    for(i = 0; i < C; ++i)
    {
        scanf("%d", &arr[i]);
    }
    printf("El arreglo original es:\n{");
    for (i = 0; i < C; ++i) // Arreglo original
    {
        printf("%d", arr[i]);
        if(i < C - 1)
        printf(", ");
    }
    putchar('}');
    for (i = 0; i < C-1; ++i) // Reordenamiento
    {
        for (j = 0; j < C - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1]) // SI el numero subsecuente es mayor
            { // se hace el reordenamiento
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        
        }
    }    
    printf("\nEl arreglo reordenado: \n{");
    for (i = 0; i < C; ++i) // Arreglo reordenado
    {
        printf("%d", arr[i]);
        if(i < C - 1)
        printf(", ");
    }
    putchar('}');
    return 0;
}