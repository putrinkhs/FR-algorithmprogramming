#include <stdio.h>

// Fungsi iteratif untuk menghitung Fibonacci
unsigned long long fibonacciIterative(int n) {
    if (n <= 0) {
        printf("Input harus lebih besar dari 0.\n");
        return 0;
    }
    if (n <= 2) {
        return 1;
    }

    unsigned long long prev1 = 1, prev2 = 1, result = 0;
    for (int i = 3; i <= n; i++) {
        result = prev1 + prev2;
        prev1 = prev2;
        prev2 = result;
    }
    return result;
}

// Fungsi rekursif untuk menghitung Fibonacci
unsigned long long fibonacciRecursive(int n) {
    if (n <= 0) {
        printf("Input harus lebih besar dari 0.\n");
        return 0;
    }
    if (n <= 2) {
        return 1;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    int n;

    printf("=============================================\n");
    printf("=== Program Menghitung Bilangan Fibonacci ===\n");
    printf("=============================================\n");
    printf("\nMasukkan n untuk menghitung Fibonacci ke-n: ");
    
    if (scanf("%d", &n) != 1) {
        printf("Maaf, input tidak valid. Harap input bilangan bulat!\n");
        printf("\n=============================================\n");
        return 1;
    }

    printf("\nHasil menggunakan Fungsi Iteratif:\n");
    printf("Fibonacci ke-%d = %llu\n", n, fibonacciIterative(n));

    printf("\nHasil menggunakan Fungsi Rekursif:\n");
    printf("Fibonacci ke-%d = %llu\n", n, fibonacciRecursive(n));
    printf("\n=============================================\n");

    return 0;
}

