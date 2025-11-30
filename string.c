#include <stdio.h>
#include "string.h"

int BandingkanString(char str1[], char str2[]) {
    while(*str1 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1-*str2;
}

void SalinString(char Asal[], char Tujuan[]) {
    int i = 0;
    while (Asal[i] != '\0'){
        Tujuan[i] = Asal[i];
        i++;
    }
    Tujuan[i] = '\0';
}

