#include <stdio.h>
#include <string.h>

// Mendefinisikan struktur untuk mahasiswa
struct Mahasiswa {
    char nama[50];
    int umur;
};

int main() {
    // Deklarasi dan inisialisasi variabel bertipe struct Mahasiswa
    struct Mahasiswa mhs1;
    strcpy(mhs1.nama, "Putri");
    mhs1.umur = 19;

    // Menampilkan informasi mahasiswa
    printf("Nama: %s\n", mhs1.nama);
    printf("Umur: %d tahun\n", mhs1.umur);

    return 0;
}
