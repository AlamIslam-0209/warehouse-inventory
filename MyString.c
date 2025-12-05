#include <stdio.h>
#include "mystring.h"

// Fungsi untuk membandingkan dua string
int BandingkanString(char str1[], char str2[]) {
    // Membandingkan dua string
    while(*str1 != '\0' && *str1 == *str2) {
        str1++; // Pindah ke karakter berikutnya di kata pertama
        str2++; // Pindah ke karakter berikutnya di kata kedua
    }
    // Mengembalikan selisih ASCII dari karakter yang berbeda atau 0 jika sama
    return *str1-*str2; 
}

// Fungsi untuk menyalin string dari Asal ke Tujuan
void SalinString(char Asal[], char Tujuan[]) {
    int i = 0;
    // Perulangan untuk menyalin karakter satu per satu
    while (Asal[i] != '\0'){
        Tujuan[i] = Asal[i];
        i++;
    }
    Tujuan[i] = '\0'; // Menambahkan karakter null di akhir string tujuan
}

