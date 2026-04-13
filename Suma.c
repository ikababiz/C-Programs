#include <stdio.h> // La suma de Riemann | Ejemplo
#include <math.h>
int main() // Integral de f(x) = x^2 en un intervalo [0,1]
{   long int n = 1000000001, k = 1; // Con n computacionalmente grande 
    double a = 0, b = 1; 
    double delta_t = (b - a) / n; // Delta_t en la particion canonica Pn
    double sigma = 0; // La suma de Riemann, particularmente la suma superior usando supremos
    double tk = 0; // Para el k-esimo rectangulo circunscrito, f(x) es creciente en el intervalo [0,1]
    printf("Este programa calcula la integral de f(x) = x^2 en el intervalo [0,1] usando sumas de Riemann\n");
    printf("Calculando la suma con un billon de rectangulos, esto puede tardar...\n");
    for(; k <= n; ++k) // Por lo que es mas facil trabajar con suma superior
    {   tk = a + k*(delta_t);
        sigma += pow(tk,2) * delta_t; // Sigma de (k=1) hasta n, es igual a f(tk)*(delta_t)
    } // f(tk) = tk^2
    printf("Suma superior con n = %ld, de f(x) en el intervalo [0,1] es = %f\n", n, sigma);
    //Alternativamente usando epsilon
    printf("Ahora usando epsilon para refinar las particiones\n");
    double suma_anterior = 0, suma_actual = 0; 
    double epsilon = 0.000000001; // Para todo epsilon > 0, en este caso computacionalmente pequenio
    unsigned long long int m = 10; // Empieza con 10 
    double delta_x;
    double dif;
    do 
    {
        suma_anterior = suma_actual;
        suma_actual = 0; // Reinicia la suma para el nuevo refinamiento
        delta_x = (b - a) / m; // Nuevo delta_x refinado cada que m aumenta
        for(k = 1; k <= m; ++k) 
        {   tk = a + k*(delta_x);
            suma_actual += pow(tk,2) * delta_x; // Sigma de (k=1) hasta m que incrementa hasta que las sumas coincidan
        } 
        dif = fabs(suma_actual - suma_anterior);
        printf("m = %10llu | Suma = %f | Diferencia = %0.10lf\n", m, suma_actual, dif);
        if (fabs(suma_actual - suma_anterior) > epsilon)
        m *= 10; // Incrementan las particiones en base 10
    } 
    while (fabs(suma_actual - suma_anterior) > epsilon && m < 1000000000); // Valor absoluto de la resta o diferencia entre las sumas
    // El proceso de "refinamiento" de m ocurre hasta que 
    //la diferencia entre las sumas sea mas pequenia que epsilon
    printf("m = %10llu | Suma = %f | Diferencia = %0.10lf\n", m, suma_actual, dif);
    printf("Suma con m = %ld y epsilon = %0.9lf, de f(x) en el intervalo [0,1] es = %f\n", m, epsilon, suma_actual);
    return 0;
}