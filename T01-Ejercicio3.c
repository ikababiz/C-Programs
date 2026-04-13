#include <stdio.h>
#define C 25
int main()
{
    char oso[C];
    int i;
    for(i=1 ; i <=5 ; ++i)
    {
        printf("Escribe una frase o palabra: ");
        gets(oso);
        fflush(stdin);
    }
    printf("La ultima cadena del arreglo fue: ");
    puts(oso) ; 
    return 0;
}