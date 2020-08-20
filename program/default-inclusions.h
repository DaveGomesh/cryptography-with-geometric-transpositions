#ifndef DEFAULT_INCLUSIONS_H_INCLUDED
#define DEFAULT_INCLUSIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "../string-processings/remove-invalid-characters.h"
#include "../string-processings/replace-equivalent-characters.h"

#define MAX_LENGTH_TEXT 99999

int showOptions(){
    int option;

    printf("Choose a option:\n\n");

    printf("1 - Simple Columnar\n");
    printf("2 - Simple Linear\n");
    printf("3 - Linear with Numeric Key\n");
    printf("4 - by Itinerary\n");
    printf("5 - Triangular\n");
    printf("6 - External Spiral\n");
    printf("7 - Internal Spiral\n");
    printf("8 - Zigzag\n");
    printf("9 - 'L' Pattern\n");
    printf("0 - Exit\n");

    printf("OPTION: ");
    scanf("%i", &option);
    setbuf(stdin, NULL);

    return option;
}

void showCurrentText(char currentText[]){
    printf("Original Text: %s\n\n", currentText);
}

#endif /* DEFAULT_INCLUSIONS_H_INCLUDED */