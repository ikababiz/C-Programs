#include <stdio.h>
#include <string.h>
#define F 5
#define C 40
void Entrada(char [F][C], char *[F]);
void Proceso(char *[F]);
void Salida(char *[F], int*);
int main() // Reordenamiento de un arreglo multicadena
{   int b = 0; // Bandera para cambiar de leyenda en Salida
    char nombres[F][C], *pnombres[F];
    Entrada(nombres, pnombres);
    Salida(pnombres, &b);
    Proceso(pnombres);
    Salida(pnombres, &b);
    return 0; 
}
void Entrada(char nombres[F][C], char *pnombres[F])
{   int i = 0;
    for(i = 0; i < F; ++i) // Vincula el arreglo de punteros con el multicadena
    *(pnombres+i) = *(nombres+i);
    for(i = 0; i < F; ++i)
    {
        printf("Escriba el nombre completo #%d: ", i+1);
        fgets(*(pnombres+i),C,stdin);  // Trabaja con el arreglo de punteros
    }   // fgets para evitar desbordamientos
}
void Salida(char *pnombres[F], int *pb)
{   int i = 0;
    if(*pb == 0)
    printf("Los nombres son:\n");
    else
    printf("Los nombres en orden alfabetico son:\n");
    for(i = 0; i < F; ++i)
    {
        printf("#%d. ",i + 1);
        printf("%s", *(pnombres+i)); // Alternativa puts
    }   *pb = 1; // Bandera para cambiar leyenda
}
void Proceso(char *pnombres[F])
{   int i = 0, j = 0;
    char *temp; // Puntero temporal para intercambiar direcciones
    for (i = 0; i < F - 1; ++i) // Reordenamiento
    {   
        for (j = 0; j < F - i - 1; ++j)
        {   
            strlwr(*(pnombres+j)); // Minusculas para la comparacion
            strlwr(*(pnombres+j+1));
            if(strcmp(*(pnombres+j), *(pnombres+j+1)) > 0) // izquierda a derecha j>j+1 verdadero 1 falso 0
            {   // Intercambio, sin el uso de strcpy
                temp = *(pnombres + j);
                *(pnombres + j) = *(pnombres + j + 1);
                *(pnombres + j + 1) = temp;
            }
        }
    } 
} // Elaboro Garcia Resendis Itztli Kaban