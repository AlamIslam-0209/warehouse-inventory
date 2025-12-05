#include "inventaris.h" 
#include "style.h" // Untuk fungsi clearScreen dan moveCursor
#include "string.h" // Untuk fungsi BandingkanString dan SalinString    
#include <stdio.h> 
#include <stdbool.h> // Untuk tipe data boolean
#include <stdlib.h> 


void InisialisasiGudang(Gudang *g) { // Inisialisasi gudang dengan jumlah barang awal 0
    g->jum = 0;
}


void CariBarang(Gudang *g,char NamaBarang[]) {
    bool ketemu = false; // Untuk menandai apakah barang ditemukan

    for (int i = 0; i < g->jum; i++) { // Loop melalui semua barang di gudang untuk mencari barang yang diinginkan
        if (BandingkanString(g->Daftar[i].Nama, NamaBarang) == 0) {
            printf("\nBerhasil Barang '%s' Ditemukan di no ke-%d!\n", NamaBarang, i + 1);
            printf("Stok: %d | Harga: %d\n", g->Daftar[i].Stok, g->Daftar[i].Harga);

            ketemu = true; // Set penanda menjadi true jika barang ditemukan
            break;
        }
    }
    //kondisi jika barang tidak ditemukan
    if (!ketemu) {
        printf("Maaf barang %s Tidak Ditemukan di gudang\n", NamaBarang);
    }
}



void TampilkanList(Gudang g) {
    clearScreen(); // Membersihkan layar sebelum menampilkan daftar

    printf("========== Daftar Inventaris Gudang =========\n");
    printf("=============================================");
    // Header tabel
    moveCursor(3, 0);  printf("No");
    moveCursor(3, 6);  printf("Nama");
    moveCursor(3, 30); printf("stok");
    moveCursor(3, 40); printf("Harga");
    moveCursor(4, 0); 
    
    if (g.jum == 0) { // Kondisi jika tidak ada barang di gudang
        moveCursor(5, 0);
        printf("           ------Data Kosong------");
    }
    
    else {  // Menampilkan daftar barang jika ada
        printf("---------------------------------------------");
        for (int i = 0; i < g.jum; i++) {
            int baris = i+5;
            moveCursor(baris, 0);
            printf("%d.", i+1);
            moveCursor(baris, 6);
            printf("%s", g.Daftar[i].Nama);
            moveCursor(baris, 30);
            printf("%d", g.Daftar[i].Stok);
            moveCursor(baris, 40);
            printf("%d", g.Daftar[i].Harga);
        }
        printf("\n---------------------------------------------");
    }
}

void Update(Gudang *g) {
    clearScreen(); // Membersihkan layar sebelum proses update
    
    int pilih, i;
    char nama[20];
    int nilaiBaru, stokBaru;
    bool ketemu = false; // Sebagai penanda apakah barang ditemukan

    printf("Masukkan barang yang mau di update : ");
    scanf("%s", nama);

    for (i = 0; i < g->jum; i++) { // Mencari barang yang akan diupdate
        if (BandingkanString(g->Daftar[i].Nama, nama) == 0) {
            printf("\nBarang %s ketemu!\n", nama);
            printf("\nStok: %d | Harga: %d\n", g->Daftar[i].Stok, g->Daftar[i].Harga);


            ketemu = true;
            break;
        }
    }
    
    if (!ketemu) { // JKondisi jika barang tidak ditemukan
        printf("Maaf barang yang tidak ada di gudang tidak dapat diperbarui");
    }

    else { // Kondisi jika barang ditemukan
        // Menampilkan menu update
        printf("\nMau update apa?\n");
        printf("1. Stok barang\n");
        printf("2. Harga barang\n");
        printf("3. Batal\n");
        printf("Pilihan : ");
        scanf("%d", &pilih);
        
        if (pilih == 1) { // Update stok barang
            printf("Masukkan jumlah stok baru : ");
            scanf("%d", &nilaiBaru);
            
            g->Daftar[i].Stok = nilaiBaru; // Mengganti stok barang dengan nilai baru
            printf("\nStok berhasil diubah menjadi %d.\n", nilaiBaru);
        } 
        else if (pilih == 2) { // Update harga barang
            printf("Masukkan harga baru : ");
            scanf("%d", &nilaiBaru);
            
            g->Daftar[i].Harga = nilaiBaru; // Mengganti harga barang dengan nilai baru
            printf("\nHarga berhasil diubah menjadi %d.\n", nilaiBaru);
        } 
        else if (pilih == 3) { // Batal update
            printf("Update dibatalkan.\n");
        }
        else {
            printf("Pilihan tidak valid.\n");
        }
            
    }
}



void Tambah(Gudang *g) {
    Barang *b = &g->Daftar[g->jum]; // Membuat pointer ke barang baru yang akan ditambahkan
    bool ketemu = false; // Penanda apakah barang sudah ada di gudang
    char NamaBarang[20];
    int HargaBarang, StokBarang;

    if (g->jum >= 100) { // Validasi Pertama, pengecekan apakah gudang sudah penuh
        printf("Gudang sudah penuh, tidak bisa diisi lagi");
    }
    
    printf("\nMasukkan nama barang : ");
    scanf(" %[^\n]", NamaBarang);

    for (int i = 0; i < g->jum; i++) { // Validasi Kedua, pengecekan apakah barang sudah ada di gudang
        if (BandingkanString(g->Daftar[i].Nama, NamaBarang) == 0) {
            printf("\nBarang %s sudah ada di gudang!\n", NamaBarang);

            ketemu = true;
            break; // Menghentikan loop jika barang sudah ditemukan
        }
    }

    if (!ketemu) { // Kondisi jika barang belum ada di gudang maka barang dapat ditambahkan
        // Meminta input harga dan stok barang baru
        printf("Masukkan harga barang : ");
        scanf("%d", &HargaBarang);
        printf("Masukkan stok barang : ");
        scanf("%d", &StokBarang);

        // Menambahkan barang baru ke gudang
        SalinString(NamaBarang, b->Nama);
        b->Stok= StokBarang;
        b->Harga = HargaBarang;
        g->jum++;
    }
}

void Hapus(Gudang *g) {
    char cari[30];
    bool ditemukan = false;
    printf("\nMasukkan nama barang yang ingin dihapus: ");
    scanf(" %[^\n]", cari);

    // perulangan untuk mencari barang yang akan dihapus
    for (int i = 0; i < g->jum; i++) {
        if (BandingkanString(g->Daftar[i].Nama, cari) == 0) {
            ditemukan = true;

            // Proses menggeser data barang setelah barang yang dihapus
            for (int j = i; j < g->jum - 1; j++) {
                g->Daftar[j] = g->Daftar[j + 1];
            }

            g->jum--; // Mengurangi jumlah barang di gudang
            printf("\nData barang berhasil dihapus!\n");
            break; // Keluar dari loop setelah menghapus barang
        }
    }
    if (!ditemukan) { // Kondisi jika barang tidak ditemukan
        printf("\nBarang tidak ditemukan.\n");
    }    
}
