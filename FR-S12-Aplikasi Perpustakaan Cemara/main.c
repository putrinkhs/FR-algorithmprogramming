#include <stdio.h>
#include <string.h>

#define MAX_BUKU 100

// Struktur data untuk menyimpan informasi buku
struct Buku {
    char judul[100];
    char pengarang[50];
    int tahun_terbit;
    int stok;
};

// Struktur data untuk menyimpan informasi transaksi
struct Transaksi {
    char judul[100];
    char tipe_transaksi[20]; // "Peminjaman" atau "Pengembalian"
};

// Deklarasi array untuk daftar buku dan riwayat transaksi
struct Buku daftar_buku[MAX_BUKU];
struct Transaksi riwayat_transaksi[MAX_BUKU];
int jumlah_buku = 0;
int jumlah_transaksi = 0;

// Fungsi untuk menambahkan buku ke daftar buku
void tambah_buku() {
    if (jumlah_buku < MAX_BUKU) {
        printf("Masukkan judul buku: ");
        scanf("%s", daftar_buku[jumlah_buku].judul);
        printf("Masukkan pengarang buku: ");
        scanf("%s", daftar_buku[jumlah_buku].pengarang);
        printf("Masukkan tahun terbit buku: ");
        scanf("%d", &daftar_buku[jumlah_buku].tahun_terbit);
        printf("Masukkan stok buku: ");
        scanf("%d", &daftar_buku[jumlah_buku].stok);
        jumlah_buku++;
        printf("Selamat, Buku berhasil ditambahkan!\n");
    } else {
        printf("Maaf, kapasitas buku penuh.\n");
    }
}

// Fungsi untuk menampilkan daftar buku
void tampilkan_daftar_buku() {
    printf("Daftar Buku:\n");
    for (int i = 0; i < jumlah_buku; i++) {
        printf("%d. Judul: %s | Pengarang: %s | Tahun Terbit: %d | Stok: %d\n", i + 1, daftar_buku[i].judul, daftar_buku[i].pengarang, daftar_buku[i].tahun_terbit, daftar_buku[i].stok);
    }
}

// Fungsi untuk menghapus buku dari daftar buku
void hapus_buku() {
    int index;
    printf("Masukkan nomor buku yang ingin dihapus: ");
    scanf("%d", &index);
    if (index >= 1 && index <= jumlah_buku) {
        for (int i = index - 1; i < jumlah_buku - 1; i++) {
            strcpy(daftar_buku[i].judul, daftar_buku[i + 1].judul);
            strcpy(daftar_buku[i].pengarang, daftar_buku[i + 1].pengarang);
            daftar_buku[i].tahun_terbit = daftar_buku[i + 1].tahun_terbit;
            daftar_buku[i].stok = daftar_buku[i + 1].stok;
        }
        jumlah_buku--;
        printf("Selamat, Buku berhasil dihapus!\n");
    } else {
        printf("Maaf, Nomor buku tidak valid.\n");
    }
}

// Fungsi untuk menambahkan transaksi (peminjaman atau pengembalian)
void tambah_transaksi() {
    char judul[100];
    printf("Masukkan judul buku yang ingin dipinjam atau dikembalikan: ");
    scanf("%s", judul);

    int stok_terbaru = -1;
    for (int i = 0; i < jumlah_buku; i++) {
        if (strcmp(daftar_buku[i].judul, judul) == 0) {
            printf("Pilih tipe transaksi (Peminjaman/Pengembalian): ");
            scanf("%s", riwayat_transaksi[jumlah_transaksi].tipe_transaksi);
            if (strcmp(riwayat_transaksi[jumlah_transaksi].tipe_transaksi, "Peminjaman") == 0) {
                printf("Masukkan jumlah buku yang ingin dipinjam: ");
                scanf("%d", &stok_terbaru);
                if (stok_terbaru <= daftar_buku[i].stok) {
                    daftar_buku[i].stok -= stok_terbaru;
                    strcpy(riwayat_transaksi[jumlah_transaksi].judul, judul);
                    jumlah_transaksi++;
                    printf("Selamat, Transaksi Peminjaman berhasil!\n");
                } else {
                    printf("Maaf, Stok tidak mencukupi.\n");
                }
            } else if (strcmp(riwayat_transaksi[jumlah_transaksi].tipe_transaksi, "Pengembalian") == 0) {
                printf("Masukkan jumlah buku yang dikembalikan: ");
                scanf("%d", &stok_terbaru);
                daftar_buku[i].stok += stok_terbaru;
                strcpy(riwayat_transaksi[jumlah_transaksi].judul, judul);
                jumlah_transaksi++;
                printf("Selamat, Transaksi Pengembalian berhasil!\n");
            } else {
                printf("Maaf, Tipe transaksi tidak valid.\n");
            }
            return;
        }
    }
    printf("Maaf, Buku dengan judul tersebut tidak ditemukan.\n");
}

// Fungsi untuk menampilkan riwayat transaksi
void tampilkan_riwayat_transaksi() {
    printf("Riwayat Transaksi:\n");
    for (int i = 0; i < jumlah_transaksi; i++) {
        printf("%d. Judul: %s | Tipe Transaksi: %s\n", i + 1, riwayat_transaksi[i].judul, riwayat_transaksi[i].tipe_transaksi);
    }
}

int main() {
    int pilihan;
    do {

        printf("\nMenu:\n");
        printf("1. Tambah Buku\n");
        printf("2. Tampilkan Daftar Buku\n");
        printf("3. Hapus Buku\n");
        printf("4. Transaksi (Peminjaman/Pengembalian)\n");
        printf("5. Tampilkan Riwayat Transaksi\n");
        printf("6. Keluar\n");
        printf("Pilih menu (1-6): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambah_buku();
                break;
            case 2:
                tampilkan_daftar_buku();
                break;
            case 3:
                hapus_buku();
                break;
            case 4:
                tambah_transaksi();
                break;
            case 5:
                tampilkan_riwayat_transaksi();
                break;
            case 6:
                printf("Terima kasih telah menggunakan Aplikasi Perpustakaan Cemara. Sampai jumpa!\n");
                break;
            default:
                printf("Maaf, Pilihan tidak valid. Silakan pilih menu yang benar.\n");
        }
    } while (pilihan != 6);

    return 0;
}
