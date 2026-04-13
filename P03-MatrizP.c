#include <stdio.h>
#define F 4
#define C 2
void Asigna(float [F][C], float *[F]);
void Cargar(float *[F], char *[F]);
void Imprimir(float *[F], char *[F]);
int main()
{   float mat[F][C]; 
    float *pmat[F]; // Matriz de apuntador a flotante
    char *cad[F] = {"Biologia:","Matematicas:","Historia:","Espanol:"}; // Inicializado
    Asigna(mat, pmat);
    Cargar(pmat, cad);
    Imprimir(pmat, cad);
    return 0;
}
void Asigna(float mat[F][C], float *pmat[F])
{   int i = 0;
    for (i = 0; i < F; ++i)
    *(pmat+i) = *(mat+i);
}
void Cargar(float *pmat[F], char *cad[F])
{   int i = 0, j = 0;
    printf("Escriba calificaiones validas\n");
    for (i = 0; i < F; ++i)
    {
        for (j = 0; j < C; ++j)
        {   do
            {
                printf("Escriba la calificacion #%d de %s", j+1, *(cad+i));
                scanf("%f", *(pmat+i)+j);
                if(*(*(pmat+i)+j) <= 0 || *(*(pmat+i)+j) > 10)
                printf("Error, las calificaciones deben ser entre 0 y 10, vueva a intentar\n");
            } while (*(*(pmat+i)+j) <= 0 || *(*(pmat+i)+j) > 10);
        }
    }
}
void Imprimir(float *pmat[F], char *cad[F])
{   int i = 0, j = 0;
    for (i = 0; i < F; ++i)
    {
        printf("%-15s", *(cad+i));
        for (j = 0; j < C; ++j)
        {
            printf("%-10.1f ", *(*(pmat+i)+j));
        }
        putchar('\n');
    }
} // Elaboro Garcia Resendis Itztli Kaban