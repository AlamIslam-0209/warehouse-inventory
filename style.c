#define _WIN32_WINNT 0x0A00 
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

// 2. Include library yang diperlukan
#include <windows.h>
#include <stdio.h>
#include "style.h" // Include header-nya sendiri

// 3. "RESEP" (Definisi) DARI FUNGSI PINDAHKAN KE SINI
void aktifkanModeVirtualTerminal(void) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) {
        return;
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) {
        return;
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode)) {
        return;
    }
}

// FUNGSI UNTUK KONTROL TAMPILAN

// Membersihkan seluruh layar dan memindahkan kursor ke pojok kiri atas (baris 1, kolom 1)
void clearScreen(void) {
    printf("\x1B[2J\x1B[1;1H");
    fflush(stdout); // Memaksa terminal untuk langsung membersihkan
}

// Memindahkan kursor ke barSingle-Line
void moveCursor(int baris, int kolom) {
    printf("\x1B[%d;%dH", baris, kolom);
}

// Menghilangkan kursor agar animasi terlihat bersih
void hideCursor(void) {
    printf("\x1B[?25l");
}

// Menampilkan kursor kembali (WAJIB dipanggil di akhir program)
void showCursor(void) {
    printf("\x1B[?25h");
}


// FUNGSI BARU UNTUK DAPAT LEBAR LAYAR
int getConsoleWidth(void) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    
    // Kita gunakan lebar buffer, bukan cuma jendela yang terlihat
    return csbi.dwSize.X;
}