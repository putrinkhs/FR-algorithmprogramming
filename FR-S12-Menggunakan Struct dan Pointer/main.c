#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struktur untuk data kontak
struct Contact {
    char name[50];
    char phoneNumber[15];
    char officeNumber[15];
    char email[50];
    char companyName[50];
    struct Contact* next;
};

// Fungsi untuk membuat kontak baru
struct Contact* createContact() {
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
    if (newContact == NULL) {
        printf("Maaf, Gagal membuat kontak baru. Memori tidak cukup!\n");
        exit(1);
    }

    printf("Masukkan nama: ");
    scanf("%s", newContact->name);
    printf("Masukkan nomor HP: ");
    scanf("%s", newContact->phoneNumber);
    printf("Masukkan nomor kantor: ");
    scanf("%s", newContact->officeNumber);
    printf("Masukkan email: ");
    scanf("%s", newContact->email);
    printf("Masukkan nama perusahaan: ");
    scanf("%s", newContact->companyName);

    newContact->next = NULL;
    return newContact;
}

// Fungsi untuk menampilkan daftar kontak
void displayContacts(struct Contact* head) {
    struct Contact* current = head;
    printf("Daftar Kontak:\n");

    while (current != NULL) {
        printf("Nama: %s\n", current->name);
        printf("Nomor HP: %s\n", current->phoneNumber);
        printf("Nomor kantor: %s\n", current->officeNumber);
        printf("Email: %s\n", current->email);
        printf("Nama perusahaan: %s\n\n", current->companyName);
        current = current->next;
    }
}

// Fungsi untuk menghapus kontak
void deleteContact(struct Contact** head, char* nameToDelete) {
    struct Contact* current = *head;
    struct Contact* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, nameToDelete) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Selamat, Kontak '%s' berhasil dihapus.\n", nameToDelete);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Maaf, Kontak dengan nama '%s' tidak ditemukan.\n", nameToDelete);
}

// Fungsi untuk membebaskan memori dari daftar kontak
void freeContacts(struct Contact* head) {
    struct Contact* current = head;
    while (current != NULL) {
        struct Contact* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Contact* head = NULL;
    int choice;
    char nameToDelete[50];

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Kontak\n");
        printf("2. Tampilkan Kontak\n");
        printf("3. Hapus Kontak\n");
        printf("4. Keluar\n");
        printf("Pilih tindakan (1/2/3/4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Tambah kontak baru
                if (head == NULL) {
                    head = createContact();
                } else {
                    struct Contact* newContact = createContact();
                    newContact->next = head;
                    head = newContact;
                }
                break;
            case 2:
                // Tampilkan daftar kontak
                displayContacts(head);
                break;
            case 3:
                // Hapus kontak berdasarkan nama
                printf("Masukkan nama kontak yang ingin dihapus: ");
                scanf("%s", nameToDelete);
                deleteContact(&head, nameToDelete);
                break;
            case 4:
                // Keluar dari program
                freeContacts(head);
                exit(0);
            default:
                printf("Maaf, Pilihan tidak valid. Silakan coba lagi!\n");
        }
    } while (choice != 4);

    return 0;
}
