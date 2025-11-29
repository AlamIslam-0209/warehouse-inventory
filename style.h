#ifndef STYLE_H
#define STYLE_H


// Kode warna
// Warna Teks Standar
#define ANSI_COLOR_BLACK   "\x1B[30m"
#define ANSI_COLOR_RED     "\x1B[31m" 
#define ANSI_COLOR_GREEN   "\x1B[32m" 
#define ANSI_COLOR_YELLOW  "\x1B[33m"
#define ANSI_COLOR_BLUE    "\x1B[34m"
#define ANSI_COLOR_MAGENTA "\x1B[35m"
#define ANSI_COLOR_CYAN    "\x1B[36m"
#define ANSI_COLOR_WHITE   "\x1B[37m"

// Warna Teks Terang (Bright)
#define ANSI_BRIGHT_BLACK   "\x1B[90m" 
#define ANSI_BRIGHT_RED     "\x1B[91m"
#define ANSI_BRIGHT_GREEN   "\x1B[92m"
#define ANSI_BRIGHT_YELLOW  "\x1B[93m"
#define ANSI_BRIGHT_BLUE    "\x1B[94m"
#define ANSI_BRIGHT_MAGENTA "\x1B[95m"
#define ANSI_BRIGHT_CYAN    "\x1B[96m"
#define ANSI_BRIGHT_WHITE   "\x1B[97m"

// Latar Belakang Standar
#define ANSI_BG_BLACK   "\x1B[40m"
#define ANSI_BG_RED     "\x1B[41m"
#define ANSI_BG_GREEN   "\x1B[42m"
#define ANSI_BG_YELLOW  "\x1B[43m"
#define ANSI_BG_BLUE    "\x1B[44m"
#define ANSI_BG_MAGENTA "\x1B[45m"
#define ANSI_BG_CYAN    "\x1B[46m"
#define ANSI_BG_WHITE   "\x1B[47m"

// Latar Belakang Terang (Bright)
#define ANSI_BRIGHT_BG_BLACK   "\x1B[100m" 
#define ANSI_BRIGHT_BG_RED     "\x1B[101m"
#define ANSI_BRIGHT_BG_GREEN   "\x1B[102m"
#define ANSI_BRIGHT_BG_YELLOW  "\x1B[103m"
#define ANSI_BRIGHT_BG_BLUE    "\x1B[104m"
#define ANSI_BRIGHT_BG_MAGENTA "\x1B[105m"
#define ANSI_BRIGHT_BG_CYAN    "\x1B[106m"
#define ANSI_BRIGHT_BG_WHITE   "\x1B[107m"

#define ANSI_RESET      "\x1B[0m"  // Reset
#define ANSI_BOLD       "\x1B[1m"  // Teks Tebal
#define ANSI_UNDERLINE  "\x1B[4m"  // Garis bawah
#define ANSI_REVERSE    "\x1B[7m"  // Membalik warna teks dan latar


//Fungs-fungsi
void aktifkanModeVirtualTerminal(void);
void clearScreen(void);                 // Untuk membersihkan layar
void moveCursor(int baris, int kolom);  // Untuk pindah ke baris/kolom
void hideCursor(void);                  // (Opsional) Menghilangkan kursor
void showCursor(void);                  // (Opsional) Memunculkan kursor

int getConsoleWidth(void);


#endif 