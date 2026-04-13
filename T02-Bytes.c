#include <stdio.h>
int main() // Valor en bytes de cada tipo de variable en C
{
    char c;
    int i;
    float f;
    double d;
    long l;
    printf("Tipo variable\tTamanio\n");
    printf("char\t\t%lu\n", sizeof(c));
    printf("short\t\t%lu\n", sizeof(i)/2);
    printf("int\t\t%lu\n", sizeof(i));
    printf("long\t\t%lu\n", sizeof(d));
    printf("long long\t%lu\n", sizeof(l)*2);
    printf("float\t\t%lu\n", sizeof(f));
    printf("double\t\t%lu\n", sizeof(d));
    printf("long double\t%lu\n", sizeof(d)*2);
    return 0; // Elaboro Garcia Resendis Itztli Kaban
}