#include <stdio.h> // Estructuras y ->
#include <string.h>
#define T 50
typedef struct Registro
{
    char nom[T];
    int cant;
    float pre;
    float imp;
} reg;
void Entrada(reg *);
int Palabras(reg);
void Importe(reg *);
float Descuento(reg);
void Imprimir(reg, int, float);
int main()
{   int pal = 0;
    float des = 0.f;
    reg a, *ap = NULL;
    ap = &a;
    Entrada(ap); // metodo 1
    pal = Palabras(a);
    Importe(&a); // metodo 2
    des = Descuento(a);
    Imprimir(a, pal, des);
    return 0;
}
void Entrada(reg *x)
{   
    printf("Escriba el nombre del articulo: ");
    fgets(x->nom, T, stdin);
    (x->nom)[strcspn(x->nom, "\n")] = '\0';
    do
    {   printf("Escriba la cantidad de articulos vendidos: ");
        scanf("%d", &x->cant);
        if(x->cant <= 0)
        printf("Error, escriba una cantidad valida\n");
    } while (x->cant <= 0);
    do
    {   printf("Escriba el precio del articulo: ");
        scanf("%f", &x->pre);
        if(x->pre <= 0)
        printf("Error, escriba una cantidad valida\n");
    } while (x->pre <= 0);
}
int Palabras(reg x)
{   int pal = 0, i = 0, bandera = 0, letras = 0; // Uso de una bandera para saber si esta en una palabra
    while (x.nom[i] != '\0')
    {
        if(x.nom[i] != ' ') // Para contar letras se puede usar strlen
        { // Para contar letras sin espacios no se usa la bandera
            letras++;
            if(bandera == 0) // implica que no estamos en una palabra
            {
                pal++;
                bandera = 1;
            }
        }
        else
            bandera = 0; // Salimos de la palabra
        i++;
    }
    printf("Letras = %d\n", letras);
    return (pal);
}
void Importe(reg *x)
{   
    x->imp = x->pre * x->cant;
}
float Descuento(reg x)
{   float des = 0;
    if(x.imp >= 5000 && x.imp <= 10000)
    des = 0.10; // El 10%
    else
        if(x.imp > 10000 && x.imp <= 20000)
        des = 0.20; // El 20%
        else
            if(x.imp > 20000)
            des = 0.25; // El 25%
            else
                des = 0; // El 0%
    return (des);
}
void Imprimir(reg x, int p, float d)
{
    printf("Nombre del articulo = %s\n", x.nom);
    printf("Precio del articulo = $%.2f\n", x.pre);
    printf("Cantidad vendida = %d\n", x.cant);
    printf("Importe a pagar = $%.2f\n", x.imp);
    printf("Palabras en el nombre del articulo = %d\n", p);
    printf("Porcentaje de descuento = %%%.0f\n", d*100);
} // Elboro Garcia Resendis Itzlti Kaban