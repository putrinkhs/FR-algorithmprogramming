#include <stdio.h>
#include <string.h>

// Fungsi untuk menukar dua elemen dalam array
void swap(char arr[10][20], int a, int b) {
    char temp[20];
    strcpy(temp, arr[a]);
    strcpy(arr[a], arr[b]);
    strcpy(arr[b], temp);
}

// Fungsi untuk membagi array dan mengembalikan indeks pivot
int partition(char arr[10][20], int low, int high) {
    char pivot[20];
    strcpy(pivot, arr[high]);
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1);
}

// Fungsi Quick Sort
void quickSort(char arr[10][20], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    char nama[10][20] = {
        "Fahmi Harahap",
        "Icha Nurlisa",
        "Agus Gumilang",
        "Zelda Zuraida",
        "Felix Halim",
        "Deddy Corbuizer",
        "Hassan Makmur",
        "Makmun Sukur",
        "Bella Christie",
        "Chelshe Love"
    };

    printf("Array sebelum diurutkan:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s\n", nama[i]);
    }

    quickSort(nama, 0, 9);

    printf("\nArray setelah diurutkan secara ascending:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s\n", nama[i]);
    }

    return 0;
}
