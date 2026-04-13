#include <stdio.h> 
#include <string.h>
int Proceso(char *); // Contar caracteres
void Salida(char *); // Put(cadena completa)
void Imprimir(char *); // Caracter por caracter
void Invertir(char *); // Voltear la cadena
int main()
{   // Cadenas de caracteres con punteros
    char cad[] = "Hola profesora Tapia"; // Modificable
    printf("Direccion de la cadena = %p\n", cad);
    Salida(cad);
    printf("Longitud de la cadena = %d\n", Proceso(cad));
    Invertir(cad);
    Imprimir(cad);
    return 0;
}
void Salida(char *pcad)
{   printf("Direccion del puntero pcad = %p\nCadena = ", pcad);
    puts(pcad); // printf("%s\n", pcad); es igual
}
int Proceso(char *var)
{   char *p = var;
    int tam = 0;   
    while (*p != '\0')
    {
        ++p; // p++;
        ++tam;
    }
    return(tam);
}
void Invertir(char *pcad)
{   int i = 0, tam = Proceso(pcad);
    char temp;
    for (i = 0; i < tam / 2; ++i)
    {
        temp = *(pcad + i);
        *(pcad + i) = *(pcad +  (tam - 1 - i));
        *(pcad +  (tam - 1 - i)) = temp;
    }
}
void Imprimir(char *pcad)
{   int i = 0, tam = Proceso(pcad);
    printf("Cadena invertida = ");
    for (i = 0; i < tam; i++)
    {
        printf("%c", *pcad++);
    }
} // Elboro Garcia Resendis Itzlti Kaban