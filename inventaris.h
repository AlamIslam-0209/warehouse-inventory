#ifndef INVENTARIS_H
#define INVENTARIS_H

typedef struct {
    char Nama[20];
    int Stok;
    int Harga;
} Barang;

typedef struct {
    Barang Daftar[100];
    int jum;
} Gudang;

void InisialisasiGudang(Gudang *g);
void CariBarang(Gudang *g, char NamaBarang[]);
void TampilkanList(Gudang g);
void Update(Gudang *g);
void Tambah(Gudang *g);
void Hapus(Gudang *g);

#endif