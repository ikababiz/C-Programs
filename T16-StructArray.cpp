#include <stdio.h> // Arreglos de estructuras
#include <string.h>
#include <stdlib.h>
#define T 40
#define A 3 // 10
#define C 3 // Calificaciones por alumno
typedef struct nodo
{
    float apr[C];
}sinon;
typedef struct registro
{   char nom[T];
    int bol;
    float cals[C];
    float prom;
    sinon *p;
}reg;
void Cargar(reg *);
void Proceso(reg *);
float* Mayores(reg *);
void Apro(reg *, int *, int *);
void Porcentajes(reg*);
void Imprimir(reg *, float *, char **, int, int);
int main()
{   reg r[A];
    float *may = NULL;
    int a = 0, re = 0;
    char *cad[T] = {"Aprobado", "Reprobado"};
    Cargar(r);
    Proceso(r);
    may = Mayores(r);
    Apro(r, &a, &re);
    Porcentajes(r);
    Imprimir(r, may, cad, a, re);
    free(may);
    for(int i = 0; i < A; i ++)
    free((r+i)->p);
    return 0;
}
void Cargar(reg *r)
{   int i, j;
    printf("Arreglo de registros\n");
    for(i = 0; i < A; ++i)
    {   fflush(stdin);
        printf("Escriba el nombre del alumno %d: ", i+1);
        fgets((r+i)->nom, T, stdin);
        ((r+i)->nom)[strcspn((r+i)->nom, "\n")] = '\0';
        printf("Escriba la boleta del alumno %d: ", i+1);
        scanf("%d", &(r+i)->bol);
        for (j = 0; j < C; ++j)
        {   do
            {   printf("Escriba la calificacion %d del alumno %d: ", j+1, i+1);
                scanf("%f", &(r+i)->cals[j]);
                if((r+i)->cals[j] < 0 || (r+i)->cals[j] > 10)
                printf("Error, escriba una calificaion valida\n");
            } while ((r+i)->cals[j] < 0 || (r+i)->cals[j] > 10);
        }
    }
}
void Proceso(reg *r)
{   int i, j;
    for(i = 0; i < A; ++i)
    {   (r+i)->prom = 0;
        for(j = 0; j < C; ++j)
            (r+i)->prom += (r+i)->cals[j];
        (r+i)->prom /= C;
    }
}
float *Mayores(reg *r)
{   int i, j;
    float *may = NULL, calm;
    may = (float*)malloc(sizeof(float) * A);
    if(may == NULL)
    {   printf("Error en memoria\n");
        exit(1);
    }
    for(i = 0; i < A; ++i)
    {   calm = (r+i)->cals[0];
        for(j = 0; j < C; ++j)
        {
            if(calm < (r+i)->cals[j])
            calm = (r+i)->cals[j];
        }
        *(may+i) = calm;
    }
    return(may);
}
void Apro(reg *r, int *a, int *re)
{   int i,j;
    for(i = 0; i < A; ++i)
    {   
        for(j = 0; j < C; ++j)
        {
            if((r+i)->cals[j] >= 6)
            (*a)++; // ++*
            else
            (*re)++;
        }
    }
}
void Porcentajes(reg *r)
{   int i,j;
    for(i = 0; i < A; i++)
    {
        (r+i)->p = (sinon*)malloc(sizeof(sinon));
        if((r+i)->p == NULL)
        {   printf("Error en memoria\n");
            exit(1);
        }
        for(j = 0; j < C; j++)
            (r+i)->p->apr[j] = 0;
    }
    for(j = 0; j < C; j++) 
    {
        for(i = 0; i < A; i++) 
        {
            if((r+i)->cals[j] >= 6)
            (r+0)->p->apr[j] += 1; 
        }
    }
}
void Imprimir(reg *r, float *may, char **cad, int a, int re)
{   int i, j;
    for(i = 0; i < A; ++i)
    {   printf("%d. Nombre del alumno = %-15s", i+1, (r+i)->nom);
        printf("Boleta = %d\nCalificaciones = |", (r+i)->bol);    
        for(j = 0; j < C; ++j)
           printf("%d\xA7 parcial = %.1f | ", j+1, (r+i)->cals[j]);
        printf("\nPromedio = %.1f\tEstado = ", (r+i)->prom);
        if((r+i)->prom >= 6)
        printf("%s\n", *(cad+0));
        else
        printf("%s\n", *(cad+1));
    }
    printf("Califiaciones aprobatorias = %d\n", a);
    printf("Califiaciones reprobatorias = %d\n", re);
    printf("Porcentajes de aprobacion = ");
    for(i = 0; i < C; i++)
        printf("|%d\xA7 parcial = %%%.0f|", i+1, ((r+0)->p->apr[i]/A)*100);
    putchar('\n');
    for(i = 0; i < A; ++i)
       printf("Alumno = %-15s Mayor calificacion = %.1f\n", (r+i)->nom, *(may+i));
} // Elaboro Garcia Resendis Itztli Kaban