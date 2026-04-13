#include <stdio.h>
#define C 7 // Tamanio del arreglo
int main()
{
    char oso[C], aux;
    int cta=0, x;
    printf("Intriduzca una frase o palabra: ");
    gets(oso);
    for(x = 0 ; oso[x]!= '\0' ; ++x)
    {
        aux = tolower(oso[x]); // Convierte la letra en minuscula
        if(oso[x] == 'a') 
            ++cta;
        printf("%c", oso[x]); // También se puede usar putchar(oso[x]);
    }   
    printf("\nLas 'A's mayusculas y minusculas encontradas fueron = %d\n", cta);
    return 0;
}