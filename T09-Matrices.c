#include <stdio.h>
#define F 4
void Leer(int a[F][F]);
void Proceso(int a[F][F]);
void Imprimir(int a[F][F]);
int main() // Arreglos bidimensionales con punteros
{   int arr[F][F]={0};
    Leer(arr);
    Imprimir(arr);
    Proceso(arr);
    return 0;
}
void Leer(int arr[F][F]) // Cargar la matriz
{   int i = 0, j = 0;
    printf("Escriba los valores negativos de una matriz 4x4:\n");
        for (i = 0; i < F; ++i)
        {
            for (j = 0;j < F; ++j)
            {
                do // Valicadion opcional
                {
                    printf("a%d%d:", i,j);
                    scanf("%d", (*(arr + i)+j));
                    if((*(*(arr + i)+j)) >= 0)
                    printf("Error, solo se aceptan datos menores a 0, vuelva a intentar\n");
                }
            while ((*(*(arr + i)+j)) >= 0);
            }
        }
}
void Imprimir(int arr[F][F]) // Salida en forma de matriz5
{   int i = 0, j = 0;
    for (i = 0; i < F; ++i)
        {
            for (j = 0;j < F; ++j)
            {
                printf("%4d", (*(*(arr + i)+j)));
            }
            putchar('\n');
        }
}
void Proceso(int arr[F][F]) // Encontrar y mostrar el mayor de cada fila
{   int i = 0, j = 0, may = 0;
    for (i = 0; i < F; ++i)
        {
            may = *(*(arr+i)+0);
            for (j = 0;j < F; ++j)
            {
                if(may < (*(*(arr + i)+j)))
                may = (*(*(arr + i)+j));
            }
            printf("El mayor de la fila %d es = %d\n", i, may);
        }
} // Elboro Garcia Resendis Itzlti Kaban