#include <stdio.h>
#include <string.h>

int main() {
    // Mendefinisikan variabel name1 sebagai array karakter
    char name1[20];
    // Mengisi name1 dengan string "Brisia Jodie"
    strcpy(name1, "Brisia Jodie");

    // Mendefinisikan variabel name2 sebagai pointer ke karakter
    char *name2;
    // Mengisi name2 dengan alamat memori string "Brisia Jodie"
    name2 = "Brisia Jodie";

    // Mendefinisikan variabel name3 sebagai array dari pointer ke karakter
    char *name3[20];
    // Mengisi name3[0] dengan alamat memori string "Brisia Jodie"
    name3[0] = "Brisia Jodie";

    // Menampilkan isi dari ketiga variabel
    printf("name1: %s\n", name1);
    printf("name2: %s\n", name2);
    printf("name3: %s\n", name3[0]);

    return 0;
}
