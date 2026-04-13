#include <stdio.h>
#include <string.h>
#include <strings.h>
#define F 5
#define C 20
int main() // Reordenamiento de un arreglo bidimensional de caracteres
{
    int i, j, id = 0, s = 0;
    char nombres[F][C], temp[C];
    for(i = 0; i < F; ++i)
    {
        printf("Escriba el nombre completo #%d: ", i+1);
        fgets(nombres[i],C,stdin);
    }
    printf("Los nombres son:\n");
    s = sizeof(nombres)/sizeof(nombres[1]);
    for(i = 0; i < s; ++i)
    {
        printf("#%d. ",i + 1);
        puts(nombres[i]); //putchar('\n'); ya lo tiene puts
    }
    for (i = 0; i < F - 1; ++i) // Reordenamiento
    {
        for (j = 0; j < F - i - 1; ++j)
        {   // string case compare compara letra por letra manejandolas como minusculas
            id = strcasecmp(nombres[j], nombres[j+1]);
            if(id > 0)
            {   //swap o cambio
                strcpy(temp, nombres[j]);
                strcpy(nombres[j], nombres[j+1]);
                strcpy(nombres[j+1], temp);
            }
        }
    } printf("Los nombres en orden alfabetico son:\n");
    for(i = 0; i < s; ++i)
    {   
        printf("#%d. ",i + 1);
        puts(nombres[i]); //putchar('\n'); ya lo tiene puts
    }
    return 0; // Elaboro Garcia Resendis Itztli Kaban
}