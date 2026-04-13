#include <stdio.h>
int main() // Punteros
{   
    int a = 5, b = 10, c = 0;
    int *pa = NULL, *pb = NULL, *pc = NULL;
    pa = &a; // la variable pa almacena la direccion de a, gracias al simbolo &(indica direccion)
    pb = &b;
    pc = &c;
    // Desreferenciacion (* antes del puntero pa lo desreferencia)
    // Es decir, *pa por ejemplo indica el valor de la direccion a la que apunta el puntero pa
    *pc = *pa + *pb; // es igual a escribir c = a + b;
   
    printf("Valor de a = %d\n", a); // 5
    printf("Valor de b = %d\n", b); // 10
    printf("Valor de c = %d\n", c); // 15
    printf("Direccion de a = %p\n", (void*)pa); // Hexadecimal, lo que almacena el puntero pa
    printf("Direccion de b = %p\n", (void*)pb); // Hexadecimal, lo que almacena el puntero pb
    printf("Direccion de c = %p\n", (void*)pc); // Hexadecimal, lo que almacena el puntero pc
    printf("Valor de pa desreferencido = %d\n", *pa); // Al desreferenciar es 5
    printf("Valor de pb desreferencido = %d\n", *pb); // Al desreferenciar es 10
    printf("Valor de pc desreferencido = %d\n", *pc); // Al desreferenciar es 15
    // Ejemplo de tamanios
    printf("Tamanio de la variable a en bytes = %zu\n", sizeof(a)); // 4 bytes por ser entero
    printf("Tamanio de la variable pa en bytes = %zu\n", sizeof(pa)); // 8 bytes en sistemas x64
    return 0;
} 