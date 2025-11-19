#ifndef INVENTARIS_H
#define INVENTARIS_H

typedef struct {
    char Nama[20];
    int Stok;
    int Harga;
} Inventaris;

void CariBarang(Inventaris *inv, char NamaBarang[]);
void Tampilkan();
void Update();
void Tambah();
void Hapus();

#endif