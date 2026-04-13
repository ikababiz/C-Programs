#include <stdio.h>
#define F 60
#define H 24
int Leer(void);
int Horas(int);
int Minutos(int);
int Segundos(int);
void Imprimir(int, int, int);
int main() // Funciones 
{   int d, h = 0, m = 0, s = 0;
    printf("Dias: ");
    d = Leer();
    h = Horas(d);
    m = Minutos(h);
    s = Segundos(m);
    Imprimir(h, m, s);
    return 0;
}
int Leer(void)
{   int x;
    scanf("%d",&x);
    return(x);
}
int Horas(int d)
{   int h = 0;
    h = d * H;
    return(h);
}
int Minutos(int h)
{   int m = 0;
    m = h * F;
    return(m);
}
int Segundos(int m)
{   int s = 0;
    s = m * F;
    return(s);
}
void Imprimir(int h, int m, int s)
{       
    printf("Horas: %d\nMinutos: %d\nSegundos: %d",h, m, s);
} // Elaboro Garcia Resendis Itztli Kaban