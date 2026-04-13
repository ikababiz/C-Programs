#include <stdio.h>  // Malloc en arreglos bidimensionales
#include <stdlib.h>
#define F 3
#define C 5
void CreaMA(int ***); // Trabaja con memoria dinamica bidimensional
void CreaR(int **, int **); // Crea la matriz de apuntadores dinamica para la matriz y una memoria dinamica para un arreglo de numeros
void Cargar(int **); 
void Proceso(int **, int *);
void Liberar(int **, int**, int);
void Imprimir(int **, int *);
int main()  
{   int **m = NULL, *mayores = NULL;
    CreaMA(&m);
    CreaR(m, &mayores);
    Cargar(m);
    Proceso(m, mayores);
    Imprimir(m, mayores);
    Liberar(m, &mayores, F); // 3 filas creadas si llega hasta aqui
    return 0;
}
void CreaMA(int ***mp)
{   int t = sizeof(int*) * F; // Tamanio para malloc
    *mp = (int**)malloc(t); 
    if(*mp == NULL)
    {   printf("Error en memoria, no se pudo realizar el proceso\n");
        exit(1); // 1 para fallo generico
    }
}
void CreaR(int **m, int **mayores)
{   int i;
    for(i = 0; i < F; i++)
    {   *(m+i) = (int *)malloc(sizeof(int) * C);
        if(*(m+i) == NULL)
        {   printf("Error en memoria, no se pudo realizar el proceso\n");
            Liberar(m, mayores, i);
            exit(1); // Finaliza el programa
        }
    }
    *mayores = (int*)malloc(sizeof(int) * F); 
    if(*mayores == NULL)
    {   printf("Error en memoria, no se pudo realizar el proceso\n");
        Liberar(m, mayores, F);
        exit(1); // 1 para fallo generico
    }
}
void Liberar(int **m, int **mayores, int i)
{   int x;
    if(m != NULL)
    {
        for(x = 0; x < i; x++)
        {
            if(*(m+x) != NULL)
            free(*(m+x)); // Se liberan las memorias de las filas creadas hasta i
            printf("Liberadas las filas\n");
        }
        free(m); // Se libera memoria del arreglo de apuntadores
        printf("Liberada la matriz de apuntadores\n");
    } 
    if(mayores != NULL) 
    {   free(*mayores); // Se libera memoria del arreglo de mayores
        printf("Liberada la matriz de mayores\n");
    }
}
void Cargar(int **m)
{   int i, j;
    printf("Escriba valores enteros de una matriz 3x5\n");
    for(i = 0; i < F; ++i)
    {   
        for(j = 0; j < C; ++j)
        {
            printf("Valor %d%d: ",i,j);
            scanf("%d", *(m+i)+j);
        }
    }
}
void Imprimir(int **m, int *mayores)
{   int i,j;
    for(i = 0; i < F; ++i)
    {
       for(j = 0; j < C; ++j)
        {
            printf("%-4d", *(*(m+i)+j));
        }
        printf("Mayor de fila = %3d\n", *(mayores+i));
    }
}
void Proceso(int **m, int *mayores)
{   int i, j, may;
    for(i = 0; i < F; ++i)
    {   may = *(*(m+i)+0);
        for(j = 0; j < C; ++j)
        {
            if(may < *(*(m+i)+j))
            may = *(*(m+i)+j);
        }
        *(mayores+i) = may;
    } 
} // Elaboro Garcia Resendis Itztli Kaban