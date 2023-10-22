#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char line[100];  // Maksimum panjang baris
    char *token;

    // Membuka file untuk dibaca
    file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 1;
    }

    // Membaca dan menampilkan setiap baris dalam file
    while (fgets(line, sizeof(line), file)) {
        // Membaca data menggunakan strtok
        token = strtok(line, " ");  // Membaca ID
        printf("ID: %s\n", token);

        token = strtok(NULL, " ");  // Membaca nama depan
        printf("Nama Depan: %s\n", token);

        // Membaca nama belakang (memanfaatkan sisa baris)
        char full_name[50] = "";
        while (token = strtok(NULL, " ")) {
            strcat(full_name, token);
            strcat(full_name, " ");
        }
        printf("Nama Belakang: %s\n", full_name);

        token = strtok(NULL, "\n");  // Membaca jumlah uang
        printf("Jumlah Uang: %s\n", token);
    }

    // Menutup file setelah selesai membacanya
    fclose(file);

    return 0;
}
