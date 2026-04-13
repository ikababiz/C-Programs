#include <stdio.h>
#define F 5
int main()
{   // Mayor con punteros
    int arr[F]={0}, may = 0, i = 0;
    printf("Escriba 5 numeros enteros\n");
    for (i = 0; i < F; ++i)
    {
        printf("#%d:", i+1);
        scanf("%d", arr + i);
    }

    may = *(arr + 0); // igual a *arr
    for (i = 0; i < F; ++i)
    {
        if(may < *(arr + i))
        may = *(arr + i);
    }
    printf("El arreglo es:{");
    for (i = 0; i < F; ++i)
    {
        printf("%d", *(arr + i));
        if(i < F - 1)
        printf(", ");
        else
        putchar('}');
    }
    printf("\nEl mayor del arreglo es = %d\n", may);
    return 0;
}