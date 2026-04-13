#include <stdio.h> 
#define F 10
void Leer(int *);
void Quicksort(int *, int, int);
void Imprimir(int *, int *);
int main()
{   // Mayor paso x referencia Quicksort
    int arr[F]={0}, c = 0;
    Leer(arr);
    Imprimir(arr, &c); // Original
    Quicksort(arr, 0, F-1);// Para que quicksort sepa que comienza desde el primero(0) hasta T-1
    Imprimir(arr, &c); // Reordenado
    return 0;
}
void Leer(int *arr)
{   int i = 0;
    printf("Escriba 10 numeros enteros\n");
    for (i = 0; i < F; ++i)
    {   printf("#%d:", i+1);
        scanf("%d", arr + i);
    }
}   
void Imprimir(int *arr, int *c)
{   int i = 0;
    if(*c == 0) // c actua como bandera
    {   *c = *c + 1;
        printf("El arreglo original es:{"); // {}Para que parezca "conjunto"
    }
    else
    printf("El arreglo reordenado es:{");
    for (i = 0; i < F; ++i)
    {   printf("%d", *(arr + i));
        if(i < F - 1)
        printf(", ");
        else
        printf("}\n");
    }
}
void Quicksort(int *arr, int low, int high)
{   int piv = 0, i = 0, j = 0, temp = 0, i_piv = 0;
    if (low < high) 
    {   
        piv = *(arr + high); // Ultimo elemento como pivote
        i = (low - 1); // Indice del elemento más pequenio
        for (j = low; j <= high - 1; ++j) // Partición (acomodar menores a la izquierda y mayores a la derecha)
        {   if (*(arr + j) < piv) 
            {   i++; // o ++i;
                temp = *(arr + i); // Intercambio usando punteros
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
        temp = *(arr + i + 1); // i+1 porque i llega hasta 8
        *(arr + i + 1) = *(arr + high); // Intercambio para indice pivote
        *(arr + high) = temp;
        i_piv = i + 1;                  // Recursividad (la funcion se llama a si misma)
        Quicksort(arr, low, i_piv - 1); // Mitad inferior
        Quicksort(arr, i_piv + 1, high); // Mitad superior
    }
} // Elboro Garcia Resendis Itzlti Kaban