#include <stdio.h>
int main()
{
    char dato;
    printf("Introduzca un caracter\n");
    dato = getchar();
    printf("El carácter original fue %c\n",dato);
    if(dato>='A' && dato <= 'Z')
    printf("El character en minúscula es = %c\n", tolower(dato)); // En caso de ser posible
    printf("El valor de dato no se modifico porque no se reasigno, dato = %c\n",dato);
    return 0;
}