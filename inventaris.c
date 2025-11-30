#include "inventaris.h"
#include "style.h"
#include "string.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void InisialisasiGudang(Gudang *g) {
    g->jum = 0;
}


void CariBarang(Gudang *g,char NamaBarang[]) {
    bool ketemu = false;

    for (int i = 0; i < g->jum; i++) {
        if (BandingkanString(g->Daftar[i].Nama, NamaBarang) == 0) {
            printf("\nBerhasil Barang '%s' Ditemukan di no ke-%d!\n", NamaBarang, i + 1);
            printf("Stok: %d | Harga: %d\n", g->Daftar[i].Stok, g->Daftar[i].Harga);

            ketemu = true;
            break;
        }
    }
    if (!ketemu) {
        printf("Maaf barang %s Tidak Ditemukan di gudang\n", NamaBarang);
    }
}



void TampilkanList(Gudang g) {
    system("cls");
    printf("=============================================");
    moveCursor(2, 0);  printf("No");
    moveCursor(2, 6);  printf("Nama");
    moveCursor(2, 30); printf("stok");
    moveCursor(2, 40); printf("Harga");
    moveCursor(3, 0);
    
    if (g.jum == 0) {
        moveCursor(4, 0);
        printf("           ------Data Kosong------");
    }
    
    else {
        printf("---------------------------------------------");
        for (int i = 0; i < g.jum; i++) {
            int baris = i+4;
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
    system("cls");
    int pilih, i;
    char nama[20];
    int nilaiBaru, stokBaru;
    bool ketemu = false;

    printf("Masukkan barang yang mau di update : ");
    scanf("%s", nama);

    for (i = 0; i < g->jum; i++) {
        if (BandingkanString(g->Daftar[i].Nama, nama) == 0) {
            printf("\nBarang %s ketemu!\n", nama);
            printf("\nStok: %d | Harga: %d\n", g->Daftar[i].Stok, g->Daftar[i].Harga);


            ketemu = true;
            break;
        }
    }
    
    if (!ketemu) {
        printf("Maaf barang yang tidak ada di gudang tidak dapat diperbarui");
    }

    else {
        printf("\nMau update apa?\n");
        printf("1. Stok barang\n");
        printf("2. Harga barang\n");
        printf("3. Batal\n");
        printf("Pilihan : ");
        scanf("%d", &pilih);
        
        if (pilih == 1) {
            printf("Masukkan jumlah stok baru : ");
            scanf("%d", &nilaiBaru);
            
            g->Daftar[i].Stok = nilaiBaru; 
            printf("\nStok berhasil diubah menjadi %d.\n", nilaiBaru);
        } 
        else if (pilih == 2) {
            printf("Masukkan harga baru : ");
            scanf("%d", &nilaiBaru);
            
            g->Daftar[i].Harga = nilaiBaru;
            printf("\nHarga berhasil diubah menjadi %d.\n", nilaiBaru);
        } 
        else if (pilih == 3) {
            printf("Update dibatalkan.\n");
        }
        else {
            printf("Pilihan tidak valid.\n");
        }
            
    }
}



void Tambah(Gudang *g) {
    Barang *b = &g->Daftar[g->jum];
    bool ketemu = false;
    char NamaBarang[20];
    int HargaBarang, StokBarang;

    if (g->jum >= 100) {
        printf("Gudang sudah penuh, tidak bisa diisi lagi");
    }
    
    printf("\nMasukkan nama barang : ");
    scanf(" %[^\n]", NamaBarang);

    for (int i = 0; i < g->jum; i++) {
        if (BandingkanString(g->Daftar[i].Nama, NamaBarang) == 0) {
            printf("\nBarang %s sudah ada di gudang!\n", NamaBarang);

            ketemu = true;
            break;
        }
    }

    if (!ketemu) {
        printf("Masukkan harga barang : ");
        scanf("%d", &HargaBarang);
        printf("Masukkan stok barang : ");
        scanf("%d", &StokBarang);

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

    // Proses penghapusan
    for (int i = 0; i < g->jum; i++) {
        if (BandingkanString(g->Daftar[i].Nama, cari) == 0) {
            ditemukan = true;

            // Geser data
            for (int j = i; j < g->jum - 1; j++) {
                g->Daftar[j] = g->Daftar[j + 1];
            }

            g->jum--;
            printf("\nData barang berhasil dihapus!\n");
            break;
        }
    }
    if (!ditemukan) {
        printf("\nBarang tidak ditemukan.\n");
    }    
}
