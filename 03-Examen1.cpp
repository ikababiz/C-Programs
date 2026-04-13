#include <stdio.h> // Programa 3 Examen
//#include <string.h>
#define T 45
#define C 4
typedef struct alumno 
{   char nombre[T];
    int boleta;
    float cals[C];
    double may;
} sinon; 
void Cargar(sinon *);
void Proceso(sinon *, int *);
void Imprimir(sinon, char **, int);
int main()
{   int mes = 0;
    char *cad[T] = {"Enero", "Febrero", "Marzo", "Abril"};
    sinon x, *px = NULL; 
    px = &x;
    Cargar(px);
    Proceso(&x, &mes);
    Imprimir(x, cad, mes);
    return 0;
}
void Cargar(sinon *x) 
{   int i;
    printf("Nombre: ");
    fgets(x->nombre, T, stdin);
    //(x->nombre)[strcspn(x->nombre, "\n")] = '\0'; Para evitar el salto de linea
    printf("Matricula: ");
    scanf("%d", &x->boleta);
    for(i = 0; i < C; ++i)
    {   do
        {   printf("Calificaciones: ");
            scanf("%f", &x->cals[i]);
            if(x->cals[i] <= 0 || x->cals[i] > 10)
            printf("Error, calificaciones validas son de 0 a 10, vuelva a intentar\n");
        } while (x->cals[i] <= 0 || x->cals[i] > 10);
    }  
}
void Proceso(sinon *x, int *mes) 
{   int i;
    double mayor = x->cals[0];
    for(i = 0; i < C; ++i)
    if(mayor < x->cals[i])
    {   mayor = x->cals[i];
        *mes = i;
    }
    x->may = mayor;
} 
void Imprimir(sinon x, char *cad[T], int mes) 
{   int i;
    printf("Nombre: %sMatricula: %d ", x.nombre, x.boleta);
    printf("Calificaciones: ");
    for(i = 0; i < C; ++i) 
        printf("%3.1f ", x.cals[i]);
    printf("\nCalificacion Mayor = %.1f, ", x.may);
    printf("En el mes de = %s\n", cad[mes]);
} // Elaboro Garcia Resendis Itztli Kaban