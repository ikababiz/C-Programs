#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 300000 
void Quicksort(int *arr, int low, int high) {
    if (low < high) {
        int piv = *(arr + high), i = (low - 1), temp;
        for (int j = low; j <= high - 1; j++) {
            if (*(arr + j) < piv) {
                i++;
                temp = *(arr + i); *(arr + i) = *(arr + j); *(arr + j) = temp;
            }
        }
        temp = *(arr + i + 1); *(arr + i + 1) = *(arr + high); *(arr + high) = temp;
        int i_piv = i + 1;
        Quicksort(arr, low, i_piv - 1);
        Quicksort(arr, i_piv + 1, high);
    }
}
void BubbleSort(int *arr) {
    int temp;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}
int main() {
    // Reservar memoria en el HEAP para evitar desbordamientos
    int *arr1 = (int *)malloc(N * sizeof(int));
    int *arr2 = (int *)malloc(N * sizeof(int));
    clock_t inicio, fin;

    for (int i = 0; i < N; i++) {
        int num = rand() % 100000;
        arr1[i] = num;
        arr2[i] = num;
    }
    printf("Iniciando QuickSort para %d elementos...\n", N);
    inicio = clock();
    Quicksort(arr2, 0, N - 1);
    fin = clock();
    printf(">> QuickSort termino en: %f segundos\n\n", (double)(fin - inicio) / CLOCKS_PER_SEC);
    printf("Iniciando Bubble Sort para %d elementos... (Ve por un cafe, esto tardara)\n", N);
    inicio = clock();
    BubbleSort(arr1);
    fin = clock();
    printf(">> Bubble Sort termino en: %f segundos\n", (double)(fin - inicio) / CLOCKS_PER_SEC);
    free(arr1); free(arr2);
    return 0;
}