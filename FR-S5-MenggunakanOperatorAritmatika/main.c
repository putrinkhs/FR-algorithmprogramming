#include <stdio.h>

int main() {
    int a = 10;
    int x1, x2, x3, x4;

    for (x1 = 1; x1 <= 20; x1++) {
    for (x2 = 1; x2 <= 20; x2++) {
    for (x3 = 1; x3 <= 20; x3++) {
    for (x4 = 1; x4 <= 20; x4++) {
    
    a -= 4;
    a += x1;
    a *= x2;
    a /= x3;
    a %= x4;

    if (a == 10) {
    
    printf("Nilai akhir a akan menjadi 10 apabila: \n");
    printf("x1 = %d, x2 = %d, x3 = %d, x4 = %d\n", x1, x2, x3, x4);
    
    return 0;
    }

    a = 10;
    }
    }
    }
    }

    printf("Tidak ditemukan solusi yang tepat untuk membuat nilai akhir a menjadi 10\n");
    return 0;
}
