#include <stdio.h>

int main() {
    // Jumlah Mata Kuliah yang saya ambil
    int N = 2;

    // Array untuk kode mata kuliah
    char* kode[] = {"COMP6112036", "MATH6184036"};

    // Array untuk nama mata kuliah (matkul)
    char* matkul[] = {"Algorithm and Programming", "Discrete Mathematics and Linear Algebra"};

    // Array untuk jumlah SKS
    int sks[] = {4, 6};

    // Array untuk grade
    char grade[] = {'A', 'A'};

    // Menampilkan data mata kuliah
    printf("==============================\n");
    printf("= Program Daftar Mata Kuliah = \n");
    printf("==============================\n");
    for (int i = 0; i < N; i++) {
        printf("Kode        : %s\n", kode[i]);
        printf("Mata Kuliah : %s\n", matkul[i]);
        printf("SKS         : %d\n", sks[i]);
        printf("Grade       : %c\n", grade[i]);
        printf("------------------------------\n");
    }

    return 0;
}

