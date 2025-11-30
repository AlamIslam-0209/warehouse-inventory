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
            printf("\nBerhasil Barang '%s' Ditemukan di indeks ke-%d!\n", NamaBarang, i + 1);
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
    printf("===================================");
    moveCursor(2, 0);  printf("Nama");
    moveCursor(2, 25); printf("stok");
    moveCursor(2, 35); printf("Harga");
    moveCursor(3, 0);
    
    if (g.jum == 0) {
        moveCursor(4, 0);
        printf("      ------Data Kosong------");
    }
    
    else {
        printf("-----------------------------------");
        for (int i = 0; i < g.jum; i++) {
            int baris = i+4;
            moveCursor(baris, 0);
            printf("%s", g.Daftar[i].Nama);
            moveCursor(baris, 25);
            printf("%d", g.Daftar[i].Stok);
            moveCursor(baris, 35);
            printf("%d", g.Daftar[i].Harga);
        }
        printf("\n-----------------------------------");
    }
}

void Update(Gudang *g) {
    system("cls");
    int pilih;
    char nama[20];
    bool ketemu = false;

    printf("Masukkan barang yang mau di update");
    scanf("%s", nama);

    for (int i = 0; i < g->jum; i++) {
        if (BandingkanString(g->Daftar[i].Nama, nama) == 0) {
            printf("\nBarang '%[^\n]' sudah ada di gudang!\n", nama);

            ketemu = true;
            break;
        }
    }
    
    if (!ketemu) {
        printf("\nmau update apa?");
        printf("1. Stok barang");
        printf("2. Harga barang");
        scanf("%d", &pilih);
        
        

        if (pilih == 1) {
            
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
    printf("Masukkan harga barang : ");
    scanf("%d", &HargaBarang);
    printf("Masukkan stok barang : ");
    scanf("%d", &StokBarang);

    for (int i = 0; i < g->jum; i++) {
        if (BandingkanString(g->Daftar[i].Nama, NamaBarang) == 0) {
            printf("\nBarang '%[^\n]' sudah ada di gudang!\n", NamaBarang);

            ketemu = true;
            break;
        }
    }
    
    if (!ketemu) {
        SalinString(NamaBarang, b->Nama);
        b->Stok= StokBarang;
        b->Harga = HargaBarang;
        g->jum++;
    }
}

void Hapus() {
    int a = 1;
    
}
