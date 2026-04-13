#include <stdio.h> // Matriz traspuesta
#include <stdlib.h> // Ejemplo de liberacion segura de memoria
#define F 3
void CreaMA(int ***, int ***); // Crea ambas matrices de apuntadores
void CreaR(int **, int **); // Crea los renglones de ambas matrices
void Cargar(int **); // Carga la primer matriz
void Proceso(int **, int **); // Traspone las matrices
void Imprimir(int **, int **); // Imprime ambas matrices
void Liberar(int **, int **, int, int); // Verifica si los apuntadores cambiaron de NULL y de ser el caso libera memoria
int main()
{   int **m1 = NULL, **m2 = NULL; // Inicializados con NULL
    CreaMA(&m1, &m2); // Manda ** y **
    CreaR(m1, m2); // Manda * y *
    Cargar(m1); // Manda *
    Proceso(m1, m2); // Manda * y *
    Imprimir(m1, m2); // Manda * y *
    Liberar(m1, m2, F, F); // Manda * y * y enteros de filas(3) y columnas(3)
    return 0;
}
void CreaMA(int ***m1, int ***m2) // "Cacha" con *** y ***
{   int t = sizeof(int*) * F; // Tamanio en de 3 apuntadores a entero
    *m1 = (int **)malloc(t); // Memoria dinamica bidimensional (espacio para arreglo de enteros de 3x3)
    if(*m1 == NULL) // En caso de fallo, NULL no se modifica
    {   printf("Error, no se pudo reservar memoria\n");
        exit(1); // Error generico
    }
    *m2 = (int **)malloc(t);
    if(*m2 == NULL)
    {   printf("Error, no se pudo reservar memoria\n");
        Liberar(*m1, NULL, 0, 0); // *m1 y *m2 porque en esta funcion son tipo int *** 0 y 0 porque no se logro generar ningun renglon
        exit(1); // Error generico
    }
}
void CreaR(int **m1, int **m2)
{   int i = 0, j = 0, t = sizeof(int) * F; // Tamanio de 3 enteros
    for(i = 0; i < F; ++i) // Renglones de la primera, controlados por i
    {   // *********************************
        //if(i < 2) // Sirve para simular que malloc falle
        *(m1+i) = (int*)malloc(t);
        //else
        //*(m1+i) = NULL;
        if(*(m1+i) == NULL) // En caso de falta de memoria se liberan las previas y finaliza el programa
        {   printf("Error, no se pudo reservar memoria\n");
            Liberar(m1, m2, i++, j); // Importante inicializar i y j iguales a cero
            exit(1); // Error generico
        }
    }
    for(j = 0; j < F; ++j) // Renglones de la segunda, controlados por j
    {
        *(m2+j) = (int*)malloc(t);
        if(*(m2+j) == NULL) // En caso de falta de memoria se liberan las previas y finaliza el programa
        {   printf("Error, no se pudo reservar memoria\n");
            Liberar(m1, m2, i, j++); // i y j ayudan a identificar en que puntos ya no se pudo reservar memoria
            exit(1); // Error generico
        }
    }
}
void Cargar(int **m1)
{   int i, j;
    printf("Escriba los elementos enteros de una matriz 3x3\n");
    for(i = 0; i < F; ++i)
    {
        for(j = 0; j < F; ++j)
        {   printf("Elemento %d%d:", i+1, j+1);
            scanf("%d", (*(m1+i)+j));
        }
    }
}
void Proceso(int **m1, int **m2)
{   int i, j;
    for(i = 0; i < F; ++i)
    {
        for(j = 0; j < F; ++j)
        {
            *(*(m2+j)+i) = *(*(m1+i)+j); // Cambio de fila a columna
        }
    }
}
void Imprimir(int **m1, int **m2)
{   int i, j;
    printf("Matriz original:\n");
    for(i = 0; i < F; ++i)
    {
        for(j = 0; j < F; ++j)
        {
            printf("%3d", *(*(m1+i)+j));
        }
        putchar('\n');
    }
    printf("Matriz traspuesta:\n");
    for(i = 0; i < F; ++i)
    {
        for(j = 0; j < F; ++j)
        {
            printf("%3d", *(*(m2+i)+j));
        }
        putchar('\n');
    }
}
void Liberar(int **m1, int **m2, int x, int y) // "Cacha" ** y **, junto con los enteros
{   int i;
    if(m1 != NULL) // En caso de ser NULL significa que malloc fallo
    {
        {   // Estre proceso solo ocurre si es distinto de NULL, lo que implica que malloc reservo memoria 
            for(i = 0; i < x; ++i)
            {
                if(*(m1+i) != NULL)
                free(*(m1+i)); // Se liberan los renglones generados de la primer matriz, hasta x
                printf("Renglon %d de la primer matriz liberado\n", i+1);
            }  
            free(m1); // Se libera la primer matriz de apuntadores
            printf("Primer matriz liberada\n");
        }
    }
    if(m2 != NULL) // Usar free incluso en caso de que malloc falle no es peligroso en el estandar de C
    {              // Pero es buena practica no usar free(puntero), 
        {          // ya que en caso de que puntero no este inicializado con NULL, puede causar un Segmentation Fault
            for(i = 0; i < y; ++i)
            {
                if(*(m2+i) != NULL)
                free(*(m2+i)); // Se liberan los renglones generados  de la segunda matriz, hasta y
                printf("Renglon %d de la segunda matriz liberado\n", i+1);
            }
            free(m2); // Se libera la segunda matriz de apuntadores
            printf("Segunda matriz liberada\n");
        }
    }
}