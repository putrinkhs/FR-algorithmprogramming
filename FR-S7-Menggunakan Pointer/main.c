#include <stdio.h>

// Deklarasi fungsi swap dengan pass-by-value
void swapByValue(int a, int b);

// Deklarasi fungsi swap dengan pass-by-address
void swapByAddress(int *a, int *b);

int main() {
    int num1, num2;
    int inputCheck;

    do {
        printf("== Nilai Awal ==\n");
        printf("Input Nilai num1: ");
        inputCheck = scanf("%d", &num1);

        if (inputCheck != 1) {
            printf("Input tidak valid. Harap masukkan nilai yang valid!\n");
            while (getchar() != '\n'); // Membersihkan buffer input
        }
    } while (inputCheck != 1);

    do {
        printf("Input Nilai num2: ");
        inputCheck = scanf("%d", &num2);

        if (inputCheck != 1) {
            printf("Input tidak valid. Harap masukkan nilai yang valid!.\n");
            while (getchar() != '\n'); // Membersihkan buffer input
        }
    } while (inputCheck != 1);

    printf("\n== Pass by Value ==\n");
    printf("Sebelum Pemanggilan fungsi Pass by Value: \n");
    printf("Nilai num1 = %d\n", num1);
    printf("Nilai num2 = %d\n", num2);

    // Memanggil fungsi swapByValue dengan pass-by-value
    swapByValue(num1, num2);

    printf("Setelah Pemanggilan fungsi Pass by Value: \n");
    printf("Nilai num1 = %d\n", num1);
    printf("Nilai num2 = %d\n", num2);

    // Mengembalikan nilai awal
    num1, num2;

    printf("\n== Pass by Address ==\n");
    printf("Sebelum Pemanggilan fungsi Pass by Address: \n");
    printf("Nilai num1 = %d\n", num1);
    printf("Nilai num2 = %d\n", num2);

    // Memanggil fungsi swapByAddress dengan pass-by-address
    swapByAddress(&num1, &num2);

    printf("Setelah Pemanggilan fungsi Pass by Address: \n");
    printf("Nilai num1 = %d\n", num1);
    printf("Nilai num2 = %d\n", num2);

    return 0;
}

// Implementasi fungsi swapByValue
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// Implementasi fungsi swapByAddress
void swapByAddress(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
