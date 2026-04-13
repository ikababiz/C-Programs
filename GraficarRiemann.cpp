#include <graphics.h>
#include <stdio.h> // Proyecto Suma de Riemann
#include <math.h>
#include <stdlib.h>
double Funcion(double, int);
void GraficarRiemann(double, double,long int, int);
int main()
{
    long int n, k = 1;
    int opc = 0;
    double a, b;
    double delta_t = 0;                    // Delta_t en la particion regular Pn
    double s_Superior = 0, s_Inferior = 0; // La suma de superior e inferior
    double tk_1 = 0, tk = 0;               // Para el k-esimo rectangulo
    const char *nombreFuncion;
    printf("Proyecto: Suma de Riemann\nIntegrantes:\nGarcia Resendis Iztli Kaban\nMendoza Guerrero Diego\n");
    while (opc != 7)
    {
        printf("*****MENU*****\nElija el tipo de funcion:\n1. Potencias\n2. Trigonometricas\n3. Raices\n4. Logaritmicas\n5. Exponenciales\n6. Otro\n7. Finalizar Programa\n");
        do
        {
            scanf("%d", &opc);
            if (opc < 1 || opc > 7)
                printf("Error, elija una opcion valida\n");
        } while (opc < 1 || opc > 7);
        switch (opc) // Esta parte tambien se cambia *****************************************
        {
        case 1:
            nombreFuncion = "x^3+1";
            break;
        case 2:
            nombreFuncion = "sin(x)";
            break;
        case 3:
            nombreFuncion = "sqrt(x)";
            break;
        case 4:
            nombreFuncion = "ln(x)";
            break;
        case 5:
            nombreFuncion = "e^x";
            break;
        case 6:
            nombreFuncion = "x";
            break;
        default:
            exit(1);
        }
        printf("Este programa calcula la integral de f(x) = %s\n", nombreFuncion);
        printf("Escriba el valor inicial del intervalo: ");
        scanf("%lf", &a);
        do
        {
            printf("Escriba el valor final del intervalo: ");
            scanf("%lf", &b);
            if (a > b || a == b)
            {
                if (a > b)
                    printf("Error, el valor final debe ser mayor al inicial, vuelva a intentar\n");
                else
                    printf("Error, el valor final no puede concidir con el del inicial, vuelva a intentar\n");
            }
        } while (a > b || a == b);
        printf("Sea Pn una particion regular,\n");
        do
        {
            printf("escriba el numero de puntos en la particion: ");
            scanf("%ld", &n);
            if (n < 2)
                printf("Error, el valor de los puntos en la particion debe ser mayor a 2, vuelva a intentar\n");
        } while (n < 2);
        if (opc == 3 && a < 0) 
        printf("¡Aviso! Las funciones irracionales no estan definidas para negativos.\n");
        if (opc == 4 && a <= 0) 
        printf("¡Aviso! las funciones logaritmicas no estan definida para valores menores o iguales a 0.\n");
        delta_t = (b - a) / n;
        s_Inferior = 0;
        s_Superior = 0;
        for (k = 1; k <= n; ++k)
        {
            tk = a + k * (delta_t);                       // Rectangulos circunscritos
            tk_1 = a + (k - 1) * (delta_t);               // Rectangulos inscritos
            s_Superior += (Funcion(tk, opc) * delta_t);   // Suma de (k=1) hasta n
            s_Inferior += (Funcion(tk_1, opc) * delta_t); // Suma de (k=1) hasta n
        }
        printf("Suma superior con n = %ld, de f(x) = %s en el intervalo [%.1f,%.1f] es = %.8f\n", n, nombreFuncion, a, b, s_Superior);
        printf("Suma inferior con n = %ld, de f(x) = %s en el intervalo [%.1f,%.1f] es = %.8f\n", n, nombreFuncion, a, b, s_Inferior);
        GraficarRiemann(a, b, n, opc);
    }
    return 0;
}
double Funcion(double x, int opc)
{
    double y;
    switch (opc) // Aqui se pueden cambiar las funciones de ser necesario
    {
    case 1: // Potencias
        y = pow(x, 3) + 1;
        break;
    case 2: // Trigonometricas
        y = sin(x);
        break;
    case 3:          // Raices
        y = sqrt(x); // falta validacion
        break;
    case 4:         // Logaritmicas
        y = log(x); // falta validacion
        break;
    case 5: // Exponenciales
        y = exp(x);
        break;
    case 6: // Otros *****
        y = x;
    }
    return (y);
}
void GraficarRiemann(double a, double b,long int n, int opc) 
{   int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    int ALTO = 480;
    int ANCHO = 640;
    double escalaX = 40.0; // Ajustar según el intervalo [a, b]
    double escalaY = 40.0; // Ajustar según el valor de f(x)
    double delta_t = (b - a) / n;
    setcolor(WHITE);// 1. Dibujar Ejes
    line(0, ALTO - 50, ANCHO, ALTO - 50); // Eje X
    line(50, 0, 50, ALTO);                // Eje Y
    setcolor(YELLOW);// 2. Dibujar la Curva (f(x))
    for (double x = a; x <= b; x += 0.01) 
    {   int px = 50 + (x - a) * escalaX;
        int py = (ALTO - 50) - Funcion(x, opc) * escalaY;
        putpixel(px, py, YELLOW);
    }
    // 3. Dibujar Rectángulos (Suma Inferior/Izquierda)
    setcolor(LIGHTCYAN);
    for (int k = 0; k < n; k++) 
    {   double x_izq = a + k * delta_t;
        double h = Funcion(x_izq, opc);
        int x1 = 50 + (x_izq - a) * escalaX;
        int y1 = (ALTO - 50); // Base en el eje X
        int x2 = 50 + (x_izq + delta_t - a) * escalaX;
        int y2 = (ALTO - 50) - (h * escalaY); // Altura de la función
        rectangle(x1, y1, x2, y2);
        if(n <= 100)
        delay(1000 / n); // Efecto visual: esperar un poco entre rectángulos, colo con n pequenio
        else
        delay(10007100);
    }
    outtextxy(200, 20, (char*)"Presiona cualquier tecla para volver al menu...");
    getch();
    closegraph();
}