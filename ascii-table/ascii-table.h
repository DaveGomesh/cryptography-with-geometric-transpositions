#include <stdio.h>

void showASCIITable(){
    printf("ASCII Table:\n\n");
    for(int i=-256; i<256; i++){
        // printf("Decimal Code: %i\t Character: %c\n", i, i);
        printf("Decimal: %i\t Octa: %o\t Hexa: %x\t Char: %c\n", i, i, i, i);
    }
}