#include <stdio.h>
#include <string.h>

// Mendefinisikan struktur untuk buku
struct Buku {
    char judul[100];
    char pengarang[50];
    int tahun_terbit;
};

// Membuat typedef untuk tipe data struct Buku
typedef struct Buku Buku;

int main() {
    // Deklarasi dan inisialisasi variabel bertipe Buku
    Buku buku1;
    strcpy(buku1.judul, "Pemrograman C");
    strcpy(buku1.pengarang, "John Doe");
    buku1.tahun_terbit = 2020;

    // Menampilkan informasi buku
    printf("Judul       : %s\n", buku1.judul);
    printf("Pengarang   : %s\n", buku1.pengarang);
    printf("Tahun Terbit: %d\n", buku1.tahun_terbit);

    return 0;
}
