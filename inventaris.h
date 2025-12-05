#ifndef INVENTARIS_H 
#define INVENTARIS_H 

// Definisi struktur Barang
typedef struct {
    char Nama[20];
    int Stok;
    int Harga;
} Barang;

// Definisi struktur Gudang yang berisi daftar Barang dan jumlahnya
typedef struct {
    Barang Daftar[100];
    int jum;
} Gudang;

void InisialisasiGudang(Gudang *g); // Inisialisasi gudang dengan jumlah barang awal 0
void CariBarang(Gudang *g, char NamaBarang[]); // Mencari barang berdasarkan nama
void TampilkanList(Gudang g); // Menampilkan daftar barang di gudang
void Update(Gudang *g); // Memperbarui stok atau harga barang
void Tambah(Gudang *g); // Menambahkan barang baru ke gudang
void Hapus(Gudang *g); // Menghapus barang dari gudang dengan menggeser data

#endif