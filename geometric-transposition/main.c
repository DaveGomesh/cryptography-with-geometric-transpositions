#include <stdio.h>
#include "process-strings.h"
#include "simple-columnar.h"
#include "simple-linear.h"
#include "columnar-with-numeric-key.h"
#include "by-itinerary.h"
#include <stdlib.h>
#include <stdarg.h>

void variableArgs(int num, ...){
    va_list args;
    va_start(args, num);
    int j;
    for(int i=0; i<9; i++){
        j = va_arg(args, int);
        printf("%i\n", j);
    }
    va_end(args);
}

int main(){
    char text[99550], text2[99550];
    printf("Insert a text: ");
    fgets(text, 99550, stdin);
    removeInvalidCharacters(text);
    strcpy(text2, text);

    printf("Decrypting...\n");

    for (int i=0; 9==9; i++){
        byItinerary(text2, 7);
        if(strcmp(text, text2)==0){
            printf("Result %i: %s\n", i, text2);
            system("pause");
            exit(0);
        }
    }
    
    return 0;
}

//os rapazes sao capazes

// for(int i=0; i<linesCount; i++){
//     for(int j=0; j<columnCount; j++){
//         printf("%c ", matrix[i][j]);
//     }
//     printf("\n");
// }