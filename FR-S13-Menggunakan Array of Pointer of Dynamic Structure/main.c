#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan struktur untuk data mahasiswa
struct Mahasiswa {
    int ID;
    char NAMA[50];
    char PRODI[50];
    float GPA;
};

int main() {
    int n; // Jumlah mahasiswa
    printf("========================================\n");
    printf("==  PROGRAM MANAJEMEN DATA MAHASISWA  ==\n");
    printf("========================================\n");

    printf("Masukkan jumlah mahasiswa   : ");
    scanf("%d", &n);

    // Membuat array of pointer ke struktur Mahasiswa
    struct Mahasiswa *mahasiswa[n];

    // Mengisi data mahasiswa
    for (int i = 0; i < n; i++) {
        mahasiswa[i] = (struct Mahasiswa *)malloc(sizeof(struct Mahasiswa));
        printf("\nMasukkan data mahasiswa ke-%d:\n", i + 1);
        printf("ID      : ");
        scanf("%d", &mahasiswa[i]->ID);
        printf("Nama    : ");
        scanf(" %[^\n]", mahasiswa[i]->NAMA);
        printf("Prodi   : ");
        scanf(" %[^\n]", mahasiswa[i]->PRODI);
        printf("GPA     : ");
        scanf("%f", &mahasiswa[i]->GPA);
    }

    // Menampilkan data mahasiswa
    printf("========================================\n");
    printf("==        DATA MAHASISWA CEMARA       ==\n");
    printf("========================================\n");
    printf("ID\tNAMA\t\tPRODI\t\tGPA\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%s\t\t%.2f\n", mahasiswa[i]->ID, mahasiswa[i]->NAMA, mahasiswa[i]->PRODI, mahasiswa[i]->GPA);
    }

    // Membebaskan memori
    for (int i = 0; i < n; i++) {
        free(mahasiswa[i]);
    }

    return 0;
}
