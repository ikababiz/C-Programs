#include <stdio.h>
// Función para intercambiar dos elementos
void Swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
// Función de partición
int particion(int arreglo[], int bajo, int alto) {
    int pivote = arreglo[alto]; // Elegimos el último como pivote
    int i = (bajo - 1); // Índice del elemento más pequeño

    for (int j = bajo; j <= alto - 1; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arreglo[j] <= pivote) {
            i++; 
            Swap(&arreglo[i], &arreglo[j]);
        }
    }
    Swap(&arreglo[i + 1], &arreglo[alto]);
    return (i + 1);
}
// Función principal de QuickSort
void quickSort(int arreglo[], int bajo, int alto) {
    if (bajo < alto) {
        // pi es el índice de partición
        int pi = particion(arreglo, bajo, alto);

        // Ordenamos los elementos antes y después de la partición
        quickSort(arreglo, bajo, pi - 1);
        quickSort(arreglo, pi + 1, alto);
    }
}
int main() {
    int datos[10] = {24, 7, 15, 100, 56, 1, 99, 42, 12, 8};
    int n = 10;

    quickSort(datos, 0, n - 1);

    printf("Arreglo ordenado: \n");
    for (int i = 0; i < n; i++) printf("%d ", datos[i]);
    
    return 0;
}