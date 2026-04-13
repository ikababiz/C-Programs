#include <stdio.h>
#define F 5
void Leer(int *);
void Proceso(int *, int *);
void Imprimir(int *, int *);
int main()
{   // Mayor paso x referencia
    int arr[F]={0}, may = 0;
    Leer(arr);
    Proceso(arr, &may);
    Imprimir(arr, &may);
    return 0;
}
void Leer(int *ap)
{   int i;
    printf("Escriba 5 numeros enteros\n");
    for (i = 0; i < F; ++i)
    {
        printf("#%d:", i+1);
        scanf("%d", ap + i);
    }
}
void Proceso(int *ap, int *mp)
{   int i = 0;
    *mp = *(ap + 0); // igual a *ap
    for (i = 0; i < F; ++i)
    {
        if(*mp < *(ap + i))
        *mp = *(ap + i);
    }
}
void Imprimir(int *ap, int *mp)
{   int i;
    printf("El arreglo es:{");
    for (i = 0; i < F; ++i)
    {
        printf("%d", *(ap + i));
        if(i < F - 1)
        printf(", ");
        else
        putchar('}');
    }
    printf("\nEl mayor del arreglo es = %d\n",*mp);
} 