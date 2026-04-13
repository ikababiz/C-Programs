#include <stdio.h>
#include <stdlib.h>
#define F 10
int *Crear1(void); // Empleando ambos metodos
void Crear();
void Cargar(int *); 
void Proceso(int *, int *);
void Imprimir(int *, int *);
int main()
{   int *m = NULL;
    int *n = NULL;
    n = Crear1();
    Crear(&m);
    Cargar(m);
    Proceso(m, n);
    Imprimir(m, n);
    free(m); // Liberar el espacio del primer arreglo
    free(n); // Liberar el espacio del segundo arreglo
    return 0;
}
int *Crear1(void)
{   int *n2 = NULL;
    int t = sizeof(int) * F; // Tamanio para malloc
    
    n2 = (int*)malloc(t); // Crear el priner arreglo
    if(n2 == NULL)
    {
        printf("Error en memoria, no se pudo realizar el proceso\n");
        exit(-1); // -1 para fallo fatal
    }
    return(n2);
}
void Crear(int **m2)
{   int t = sizeof(int) * F; // Tamanio para malloc
    *m2 = (int*)malloc(t); // Crear el segundo arreglo
    if(*m2 == NULL)
    {
        printf("Error en memoria, no se pudo realizar el proceso\n");
        exit(1); // -1 para fallo comun
    }
}
void Cargar(int *p)
{   int i;
    printf("Escriba 10 numeros enteros\n");
    for(i = 0; i < F; ++i)
    {
        printf("Valor #%d: ",i+1);
        scanf("%d", p+i);
    }
}
void Imprimir(int *p, int *q)
{   int i;
    printf("Original Invertido\n");
    for(i = 0; i < F; ++i)
    {
        printf("%6d", *(p+i));
        printf("%6d\n", *(q+i));
    }
}
void Proceso(int *p, int *q)
{   int i, j;
    for(i = 0, j = F-1; i < F; ++i, --j)
    *(q+j) = *(p+i);
} // Elaboro Garcia Resendis Itztli Kaban