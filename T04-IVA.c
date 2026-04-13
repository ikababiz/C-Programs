#include <stdio.h>
#define IVA 0.16
int Leer(void);
float Bruto(int, float);
float Neto(float, float);
float Iva(float);
void Imprimir(float, float, float);
int main() // Salario con funciones
{   int h;
    float bruto = 0, neto = 0, iv = 0;
    const float p_hora = 100.00f;
    printf("Horas: ");
    h = Leer();
    bruto = Bruto(h, p_hora);
    iv = Iva(bruto);
    neto = Neto(bruto, iv);
    Imprimir(bruto, iv, neto);
    return 0; 
}
int Leer(void)
{   int x;
    scanf("%d", &x);
    return (x);
}
float Bruto(int h, float p_hora)
{   float x = 0;
    x = h * p_hora;
    return(x);
}
float Iva(float bruto)
{   float x = 0;
    x = bruto * (IVA);
    return(x);
}
float Neto(float bruto, float iv)
{   float x = 0;
    x = bruto - iv;
    return(x);
}
void Imprimir(float bruto, float iv, float neto)
{
    printf("Bruto: %10.2f\nIva: %10.2f\nNeto: %10.2f\n", bruto, iv, neto);
} // Elaboro Garcia Resendis Itztli Kaban