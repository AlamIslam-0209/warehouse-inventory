#include "inventaris.h"
#include "style.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main () {

    bool StatusMenu = true;
    int pilihan;
    Gudang penyimpanan;
    char nama[20];
    int harga, stok;
    
    InisialisasiGudang(&penyimpanan);

    while (StatusMenu) {

        system("cls");

        printf("Hai, aku asisten pintar Gudang mu!\n");
        printf("mau apa?\n");
        printf("1. Cari Barang\n");
        printf("2. Tampilkan Barang\n");
        printf("3. Update Barang\n");
        printf("4. Tambah Barang\n");
        printf("5. Hapus Barang\n");
        printf("6. Keluar\n");

        printf("pilihan : ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Barang apa yang mau kamu cari?");
                scanf("%s", nama);
                CariBarang(&penyimpanan, nama);
                break;
            case 2:
                TampilkanList(penyimpanan);
                break;
            case 3:
                break;
            case 4:
                Tambah(&penyimpanan);
                break;
            case 5:
                break;
            case 6:
                printf("Terimakasih Telah menggunakan program ini, have a good day~\n");
                StatusMenu = false;
                break;
            default :
                printf("Perintah yang anda masukkan tidak valid, silahlah kembali terlebih dahulu~\n");
                break;

        }

        if (pilihan != 6) {
        printf("\n\nTekan Enter Untuk Kembali...");
        getchar();
        getchar(); //katanya cari aman buat dua, mana tau beda compiler beda output
    }


    }

}
