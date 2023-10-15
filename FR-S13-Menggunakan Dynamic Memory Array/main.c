#include <stdio.h>
#include <stdlib.h>

int main() {
    int SIZE = 9;
    int* data = NULL;
    int choice;

    printf("Pilih jenis alokasi memori:\n");
    printf("1. Alokasi Memori Statis (Kode A)\n");
    printf("2. Alokasi Memori Dinamis (Kode B)\n");
    printf("Masukkan pilihan (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Alokasi memori statis (Kode A)
        int data_static[SIZE];
        data = data_static;

        // Entry data
        for (int i = 0; i < SIZE; i++) {
            data[i] = i * 10; // Isi data sesuai dengan kebutuhan
        }
    } else if (choice == 2) {
        // Alokasi memori dinamis (Kode B)
        data = (int*)malloc(SIZE * sizeof(int));

        if (data == NULL) {
            printf("Maaf, Alokasi memori gagal. Program berhenti.\n");
            return 1;
        }

        // Entry data
        for (int i = 0; i < SIZE; i++) {
            data[i] = i * 10; // Isi data sesuai dengan kebutuhan
        }
    } else {
        printf("Maaf, Pilihan tidak valid. Program berhenti.\n");
        return 1;
    }

    // Search data
    // Kode lengkap ...

    // Print all
    printf("Data:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d\t", data[i]);
    }

    // Free allocated memory (jika alokasi memori dinamis)
    if (choice == 2) {
        free(data);
    }

    return 0;
}
