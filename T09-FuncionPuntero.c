#include <stdio.h> 
#include <string.h>
#define F 40
void Entrada(char *);
char *Proceso(char *, int *); 
void Salida(char *); // Put(cadena completa)
void Imprimir(char *, int); // Caracter por caracter invertido
int main()
{   // Funcion retorna punteros
    char cad[F], *t = NULL; 
    int tam = 0;
    printf("Direccion de cad[] es = %p\n", &cad[F]);
    Entrada(cad);
    t = Proceso(cad, &tam);
    Salida(cad);
    Imprimir(t, tam);
    return 0;
}
void Entrada(char *cad)
{   printf("Direccion del puntero *cad es = %p\n", cad);
    fgets(cad, F, stdin);
}
char *Proceso(char *cad, int *t)
{   char *var = cad;  
    while (*var != '\0')
    {
        ++var; 
        ++(*t);
    }
    cad = var - 1;
    printf("Direccion de var es = %p\n", var);
    printf("Direccion de cad al retornar es = %p\n", cad);
    return(cad);    
}
void Salida(char *cad)
{
    puts(cad);
}
void Imprimir(char *pcad, int t)
{   
    printf("Cadena invertida = ");
    for (--t; t >= 0; --t)
    {
        printf("%c", *pcad--);
    }
} // Elboro Garcia Resendis Itzlti Kaban