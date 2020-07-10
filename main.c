#include <stdio.h>
#include "process-strings.h"
#include "simple-columnar.h"
#include "simple-linear.h"

int main(){
    char text[550];
    char text2[550];
    printf("Insert a text: ");
    fgets(text, 550, stdin);
    removeInvalidCharacters(text);

    for(int i=1; i<20; i++){
        strcpy(text2, text);
        simpleColumnar(text2, i);
        printf("%i - %s\n", i, text2);
    }

    // char textSC[550];
    // strcpy(textSC, text);
    // simpleColumnar(textSC, 4);
    // printf("Simple Columnar: %s\n", textSC);

    // char textSL[550];
    // strcpy(textSL, text);
    // simpleLinear(textSL, 6);
    // printf("Simple Columnar: %s\n", textSL); 


    return 0;
}