#include <stdio.h>

int main() {
    int m, n, p, q;

    printf("===================================\n");
    printf("=   Program Penghitung Matriks   =\n");
    printf("===================================\n\n");

    // Input ukuran matriks pertama (baris x kolom)
    printf("Masukkan jumlah baris matriks pertama   : ");
    scanf("%d", &m);

    printf("Masukkan jumlah kolom matriks pertama   : ");
    scanf("%d", &n);

    // Input ukuran matriks kedua (baris x kolom)
    printf("Masukkan jumlah baris matriks kedua     : ");
    scanf("%d", &p);

    printf("Masukkan jumlah kolom matriks kedua     : ");
    scanf("%d", &q);

    // Periksa apakah perkalian matriks dapat dilakukan
    if (n != p) {
        printf("Perkalian matriks tidak dapat dilakukan. Kolom matriks pertama harus sama dengan baris matriks kedua.\n");
        return 1; // Keluar dengan kode kesalahan
    }

    // Inisialisasi matriks pertama, matriks kedua, dan matriks hasil
    int mat1[m][n], mat2[p][q], hasil[m][q];

    // Memasukkan elemen-elemen matriks pertama
    printf("Masukkan elemen-elemen matriks pertama  : ");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    // Memasukkan elemen-elemen matriks kedua
    printf("Masukkan elemen-elemen matriks kedua    : ");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Menghitung perkalian matriks
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < n; k++) {
                hasil[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Menampilkan hasil perkalian matriks
    printf("\nHasil perkalian matriks   : ");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            printf("%d ", hasil[i][j]);
        }
        printf("\n");
    }

    printf("\nTerima kasih telah menggunakan program penghitung matrix\n");

    return 0;
}
