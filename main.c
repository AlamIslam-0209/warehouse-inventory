#include "inventaris.h"
#include "style.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main () {
    
    aktifkanModeVirtualTerminal(); // Mengaktifkan mode virtual terminal
    bool StatusMenu = true; // Status  awal untuk menjalankan menu utama
    int pilihan; 
    Gudang penyimpanan; // Deklarasi variabel gudang
    char nama[20];
    int harga, stok;
    
    InisialisasiGudang(&penyimpanan); // Inisialisasi gudang sebelum digunakan

    // Main Loop Menu
    while (StatusMenu) {

        system("cls"); // Membersihkan layar sebelum menampilkan menu utama

        // Tampilan menu utama
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

        //logika pemilihan menu dengan switch case
        switch (pilihan) {

            case 1: // jika pengguna memilih cari Barang
                printf("Barang apa yang mau kamu cari? ");
                scanf("%s", nama);
                CariBarang(&penyimpanan, nama);
                break;

            case 2: // jika pengguna memilih tampilkan barang
                TampilkanList(penyimpanan);
                break;

            case 3: // jika pengguna memilih update barang
                Update(&penyimpanan);
                break;

            case 4: // jika pengguna memilih tambah barang
                Tambah(&penyimpanan);
                break;

            case 5: // jika pengguna memilih hapus barang
                Hapus(&penyimpanan);
                break;

            case 6: // jika pengguna memilih keluar dari program
                printf("Terimakasih Telah menggunakan program ini, have a good day~\n");
                StatusMenu = false; // Mengubah status menu menjadi false untuk keluar dari loop
                break;

            default : // jika pengguna memasukkan perintah yang tidak valid
                printf("Perintah yang anda masukkan tidak valid, silahlah kembali terlebih dahulu~\n");
                break;

        }

        if (pilihan != 6) { //pause sementara
        printf("\n\nTekan Enter Untuk Kembali...");
        getchar(); //membersikan buffer
        getchar(); //menunggu input enter
    }


    }

}
