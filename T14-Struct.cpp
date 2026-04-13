#include <stdio.h> // Estructuras (tipo derivado)
#include <string.h>
#define T 30 // 30 letras maximo
typedef struct alumno // metodo 1
{   char nombre[T];
    int boleta;
} sinon; // sinonimo
struct calificaciones // metodo 2
{   float cal1;
    float cal2;
    float cal3;
};
typedef struct calificaciones apd; // apodo
void Cargar(sinon &, apd &);
float Proceso(apd);
void Imprimir(alumno, calificaciones, float);
int main()
{   float prom = 0;
    sinon a; // Usand sinonimo 
    apd c1; // Usando apodo
    Cargar(a, c1);
    prom = Proceso(c1);
    Imprimir(a, c1, prom);
    return 0;
}
void Cargar(sinon &pa, apd &pc1) // & solo funciona en C++
{   printf("Escriba el nombre del alumno: ");
    fgets(pa.nombre, T, stdin);
    (pa.nombre)[strcspn(pa.nombre, "\n")] = '\0'; // Para evitar el salto de linea
    printf("Escriba el numero de boleta del alumno: ");
    scanf("%d", &pa.boleta);
    printf("Escriba la calificacion 1 del alumno: ");
    scanf("%f", &pc1.cal1);
    printf("Escriba la calificacion 2 del alumno: ");        
    scanf("%f", &pc1.cal2);
    printf("Escriba la calificacion 3 del alumno: ");
    scanf("%f", &pc1.cal3);
}
float Proceso(apd pc1) // Solo lectura
{   float promedio = 0;
    promedio = pc1.cal1 + pc1.cal2 + pc1.cal3;
    promedio /= 3;
    return (promedio);
} 
void Imprimir(alumno a, calificaciones cals, float p) // Solo lectura
{   printf("Nombre del alumno: %s | Boleta: %d\n", a.nombre, a.boleta);
    printf("Calificaciones: %.1f, %.1f, %.1f\n", cals.cal1, cals.cal2, cals.cal3);
    printf("Promedio = %.1f\n", p);
} // Elboro Garcia Resendis Itzlti Kaban