#include "inventaris.h"
#include <stdio.h>
#include <stdbool.h>

int main () {

    bool StatusMenu = true;
    int pilihan;

    while (StatusMenu) {
        printf("Hai, aku asisten pintar Gudang mu!\n");
        printf("mau apa?\n");
        printf("1. Cari Barang\n");
        printf("2. Tampilkan Barang\n");
        printf("3. Update Barang\n");
        printf("4. Tambah Barang\n");
        printf("5. Hapus Barang\n");
        printf("6. Keluar\n");

        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf("Terimakasih Telah menggunakan program ini, have a good day~\n");
                StatusMenu = false;
                break;
        }


    }

}
