#include <stdio.h>
#include <math.h>
#define F 4
void Leer(int *);
void Raiz(int *, double *);
void Imprimir(int *, double *);
int main()
{
    int arr[F]={0};
    double ara[F]={0};
    Leer(arr);
    Raiz(arr, ara);
    Imprimir(arr, ara);
    return 0;
}
void Leer(int *arr)
{   int i = 0;
        printf("Escriba 4 numeros enteros\n");
        for (i = 0; i < F; ++i)
        {
            do
            {
                //printf("#%d:", i+1);
                scanf("%d",(arr + i));
                if(*(arr + i) < 1)
                printf("Error, solo se aceptan datos mayores a 0, vuelva a intentar\n");
            }
            while (*(arr + i) < 1);
        }
}
void Imprimir(int *arr, double *ara)
{   int i = 0;
    for (i = 0; i < F; ++i)
    {
        printf("\n%4d %40.2f\n",*(arr + i), *(ara + i));
    }
}
void Raiz(int *arr, double *ara)
{   int i = 0;
    for (i = 0; i < F; ++i)
    {
        *(ara + i) = sqrt(*(arr + i));
    }
}