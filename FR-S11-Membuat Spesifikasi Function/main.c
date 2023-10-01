#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function prototype for Design Name/Design Entity Names
void getDesignEntityNames();

// Function prototype for Entity Names (Produce Design Reports)
void produceDesignReports();

// Function prototype for Entity Names (Collate Entities)
void collateEntities();

// Function prototype for Entity Data (Produce Design Reports)
void produceDesignReports();

// Function prototype for Entity Data (Generate Report)
void generateReport();

int main() {
    int choice;
    char input[10];

    do {
        system("clear"); // Membersihkan layar konsol (Linux/Unix)
        // Jika menggunakan Windows, bisa menggunakan "cls" sebagai gantinya

    printf("==================================\n");
    printf("== Aplikasi Layanan Biro Design ==\n");
    printf("==================================\n");

        printf("\nMenu Layanan Biro Design:\n");
        printf("1. Get Design Entity Names\n");
        printf("2. Produce Design Reports\n");
        printf("3. Collate Entities\n");
        printf("4. Generate Report\n");
        printf("5. Keluar\n");

        printf("\nMasukkan pilihan (1-5): ");
        scanf("%s", input);

        // Pemeriksaan apakah input adalah angka
        if (isdigit(input[0])) {
            choice = atoi(input);
            if (choice >= 1 && choice <= 5) {
                switch (choice) {
                    case 1:
                        getDesignEntityNames();
                        break;
                    case 2:
                        produceDesignReports();
                        break;
                    case 3:
                        collateEntities();
                        break;
                    case 4:
                        generateReport();
                        break;
                    case 5:
                        printf("Keluar dari aplikasi.\n");
                        printf("----------------------------------\n");
                        break;
                }
            } else {
                printf("Maaf, pilihan tidak valid. Masukkan angka antara 1-5!\n");
            }
        } else {
            printf("Maaf, pilihan tidak valid. Masukkan angka antara 1-5!\n");
        }
        
        printf("\nTekan Enter untuk melanjutkan...");
        while (getchar() != '\n'); // Membersihkan buffer stdin
        getchar(); // Menunggu sampai pengguna menekan Enter
    } while (choice != 5);

    return 0;
}

// Implementasi fungsi-fungsi (cukup dengan dummy print pesan)
void getDesignEntityNames() {
    printf("Fungsi Get Design Entity Names dipanggil.\n");
    printf("----------------------------------\n");
}

void produceDesignReports() {
    printf("Fungsi Produce Design Reports dipanggil.\n");
    printf("----------------------------------\n");

}

void collateEntities() {
    printf("Fungsi Collate Entities dipanggil.\n");
    printf("----------------------------------\n");

}

void generateReport() {
    printf("Fungsi Generate Report dipanggil.\n");
    printf("----------------------------------\n");

}
