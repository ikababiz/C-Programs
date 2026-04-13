#include <stdio.h>
#define F 3
void Leer(float *[F], char*[F]);
float *Proceso(float *[F]); // Funcion que retorna puntero
void Imprimir(float *[F], char*[F], float *);
void Asignar(float [F][F], float *[F]);
int main() // Repaso
{   float arr[F][F], *parr[F]; // Arreglos de punteros
    float *p = NULL; // Puntero simple inizializdo con NULL
    char *cad[F] = {"Programacion:","Algebra:","Calculo:"}; // Arreglos de puntero tipo cadena inicializado
    Asignar(arr, parr); // Vincula el arreglo bidimensional con el arreglo de apuntadores
    Leer(parr, cad); // Cargar calificaciones
    p = Proceso(parr); // Obtener la direccion del arreglo local estatico de la funcion Proceso()
    Imprimir(parr, cad, p); // Mostrar usando profundidad para que se vea alineado
    return 0;
}
void Asignar(float arr[F][F], float *parr[F]) // Vincula los arreglos
{   int i = 0;
    for (i = 0; i < F; ++i)
    *(parr+i) = *(arr+i);
}
void Leer(float *parr[F], char *pcad[F]) // Cargar valores
{   int i = 0, j = 0;
    printf("Escriba calificaciones validas de 0 a 10\n");
        for (i = 0; i < F; ++i)
        {
            for (j = 0;j < F; ++j)
            {
                do // Validacion de calificaciones
                {
                    printf("Calificacion #%d de %s", j+1, *(pcad+i));
                    scanf("%f", (*(parr + i)+j));
                    if((*(*(parr + i)+j)) <= 0 || (*(*(parr + i)+j)) > 10)
                    printf("Error, calificacion invalida, vuelva a intentar\n");
                }
            while ((*(*(parr + i)+j)) <= 0 || (*(*(parr + i)+j)) > 10);
            }
        }
}
void Imprimir(float *parr[F], char *pcad[F], float *p) // Salida 
{   int i = 0, j = 0;
    printf("Las calificaciones son:\n");
    for (i = 0; i < F; ++i)
        {   printf("%-15s", *(pcad+i)); // Uso de profundidad
            for (j = 0;j < F; ++j)
            {
                printf("%10.1f", (*(*(parr + i)+j))); // Uso de profundidad
            }
            putchar('\n');
        }
    printf("Los promedios son:\n");
    for (i = 0; i < F; ++i)
    printf("%-15s%10.1f\n", *(pcad+i), *(p+i)); // Uso de profundidad
}
float *Proceso(float *parr[F]) // Calcular el promedio de cada materia
{   int i = 0, j = 0;
    static float prom[F]; // Static para que no se elimine el arreglo local
    float *p = NULL; 
    p = prom; // Apuntador que guarda la direccion inicial del arreglo
    for (i = 0; i < F; ++i)
        {
            for (j = 0;j < F; ++j)
            {
               *(p+i) += (*(*(parr + i)+j)); // Usando el puntero para desplazarse entre valores
            }
            *(p+i) /= F; // Uso de operaciones de asignacion
        }
        return (p); // Proceso retorna el puntero p que apunta a la direccion del arreglo estatico
} // Elaboro Garcia Resendis Itztli Kaban