#include <stdio.h>  // Programa 2 Examen
#include <stdlib.h>
#define F 2 // 10, 2 por conveniencia
#define C 10 
void CreaMA(int ***); 
void CreaR(int **, int **); 
void Cargar(int **); 
void Proceso(int **, int *);
void Liberar(int **, int**, int);
void Imprimir(int **, int *);
int main()  
{   int **m = NULL, *pares = NULL;
    CreaMA(&m);
    CreaR(m, &pares);
    Cargar(m);
    Proceso(m, pares);
    Imprimir(m, pares);
    Liberar(m, &pares, F); 
    return 0;
}
void CreaMA(int ***mp)
{   int t = sizeof(int*) * F; 
    *mp = (int**)malloc(t); 
    if(*mp == NULL)
    {   printf("Error en memoria, no se pudo realizar el proceso\n");
        exit(1); 
    }
}
void CreaR(int **m, int **pares)
{   int i;
    for(i = 0; i < F; i++)
    {   *(m+i) = (int *)malloc(sizeof(int) * C);
        if(*(m+i) == NULL)
        {   printf("Error en memoria, no se pudo realizar el proceso\n");
            Liberar(m, pares, i);
            exit(1); 
        }
    }
    *pares = (int*)malloc(sizeof(int) * F); 
    if(*pares == NULL)
    {   printf("Error en memoria, no se pudo realizar el proceso\n");
        Liberar(m, pares, F);
        exit(1); 
    }
}
void Liberar(int **m, int **pares, int i)
{   int x;
    if(m != NULL)
    {   for(x = 0; x < i; x++)
        {   if(*(m+x) != NULL)
            free(*(m+x)); 
            printf("Fila liberada\n");
        }
        free(m); 
        printf("Liberada la matriz de apuntadores\n");
    } 
    if(pares != NULL) 
    {   free(*pares); 
        printf("Liberada la matriz de pares\n");
    }
}
void Cargar(int **m)
{   int i, j;
    printf("Escriba valores enteros de una matriz 10x10\n");
    for(i = 0; i < F; ++i)
    {   for(j = 0; j < C; ++j)
            scanf("%d", *(m+i)+j);
    }
}
void Imprimir(int **m, int *pares)
{   int i,j;
    for(i = 0; i < F; ++i)
    {   for(j = 0; j < C; ++j)
            printf("%-5d", *(*(m+i)+j));
        printf("%5d\n", *(pares+i));
    }
}
void Proceso(int **m, int *pares)
{   int i, j, c;
    for(i = 0; i < F; ++i)
    {   c = 0; // Comienza en 0 pares para contar
        for(j = 0; j < C; ++j)
        {   if((*(*(m+i)+j)%2) == 0)
            c++;
        }
        *(pares+i) = c;
    } 
} // Elaboro Garcia Resendis Itztli Kaban