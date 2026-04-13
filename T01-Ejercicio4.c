#include <stdio.h>
#define C 40 // Tamanio del arreglo
int main()
{
    char oso[C], var;
    int cta=0, x;
    // Pide una cadena mientras el carácter sea diferente del enter (‘\n’)
    printf("Escriba una cadena de caracteres: ");
    for(x=0 ; (var = getchar()) != '\n' && x < C-1 ; ++x)
    { 
        oso[x] = var; // Almacena el carácter en el arreglo oso
        ++cta; // Cohtador de caracteres
    }
    oso[x]='\0'; // La ultima posicion del arreglo, cuando el bucle termina
    printf("La cadena es = ");
    puts(oso); // Imprime toda la cadena hasta llegar al (‘\0’) y salta
    return 0;
}