#include <stdio.h> // Multicadena con memoria dinamica
#include <stdlib.h>
#include <string.h>
#define F 3 // Número de cadenas
#define C 51 // Cantidad máxima de caracteres por cadena
void CreaMA(char ***, char ***); // Trabaja de manera muy similar, solo cambia de int a char
void CreaR(char **, char **); 
void Cargar(char **); 
void Proceso(char **, char **); 
void Imprimir(char **, char **); 
void Liberar(char **, char **, int, int); 
int main() 
{   char **m1 = NULL, **m2 = NULL; 
    CreaMA(&m1, &m2); 
    CreaR(m1, m2); 
    Cargar(m1); 
    Proceso(m1, m2); 
    Imprimir(m1, m2); 
    Liberar(m1, m2, F, F); 
    return 0;
}
void CreaMA(char ***m1, char ***m2) 
{   int t = sizeof(char*) * F; // Importante porque char* es distinto dependiendo el Sistema Operativo
    *m1 = (char **)malloc(t); 
    if(*m1 == NULL) {
        printf("Error, no se pudo reservar memoria para m1\n");
        exit(1);
    }
    *m2 = (char **)malloc(t);
    if(*m2 == NULL) {
        printf("Error, no se pudo reservar memoria para m2\n");
        Liberar(*m1, NULL, 0, 0); // Mandar NULL o *m2 seria lo mismo
        exit(1);
    }
}
void CreaR(char **m1, char **m2)
{   int i = 0, j = 0; // hacer int t = sizeof(char) * C seria t = 1 * C
    for(i = 0; i < F; ++i) 
    {   *(m1 + i) = (char*)malloc(C); // En este caso se puede usar directamente el numero de columnas
        if(*(m1 + i) == NULL) 
        {   Liberar(m1, m2, i, j);
            exit(1);
        }
    }
    for(j = 0; j < F; ++j) 
    {   *(m2 + j) = (char*)malloc(C);
        if(*(m2 + j) == NULL) 
        {   Liberar(m1, m2, i, j);
            exit(1);
        }
    }
}
void Cargar(char **m1)
{   int i;
    printf("Escriba %d cadenas/frases (maximo de %d letras):\n", F, C - 1); // 50 caracteres maximo, revervando el espacio del nulo
    for(i = 0; i < F; ++i)
    {   printf("Frase %d: ", i + 1);
        fgets(*(m1 + i), C, stdin);
        (*(m1+i))[strcspn(*(m1+i), "\n")] = '\0'; // fgets al dar "enter" guarda '\n' antes del nulo \0
    } // strcspn=string complement span, es opcional, sirve para remplazar el salto de linea que guarda fgets por el nulo
} // Solo es para mejor formato sin saltos de linea no deseados
void Proceso(char **m1, char **m2)
{   int i, j, l;
    for(i = 0; i < F; ++i)
    {   l = strlen(*(m1 + i)); // Para saber el largo de cada cadena
        for(j = 0; j < l; ++j)
            *(*(m2+i) + (j)) = *(*(m1+i) + (l-1 - j)); // largo de la cadena menos 1 porque comienza contando desde la posicion 0 y luego menos j que va aumentando
        *(*(m2+i) + l) = '\0'; // Agregar nulo al final de la cadena
    }
}
void Imprimir(char **m1, char **m2)
{   int i;
    for(i = 0; i < F; ++i)
        printf("Original: %-20s | Invertida: %-20s\n", *(m1+i), *(m2+i)); // Tambien se puede hacer caracter por caracter
} // Usar puts agrega un salto de linea no deseado
void Liberar(char **m1, char **m2, int x, int y) 
{   int i;
    if(m1 != NULL) 
    {   for(i = 0; i < x; ++i) 
        {   if(*(m1 + i) != NULL) 
            free(*(m1 + i));
        }
        free(m1);
        printf("Memoria m1 liberada\n");
    }
    if(m2 != NULL) 
    {   for(i = 0; i < y; ++i) 
        {   if(*(m2 + i) != NULL) 
            free(*(m2 + i));
        }
        free(m2);
        printf("Memoria m2 liberada\n");
    }
}