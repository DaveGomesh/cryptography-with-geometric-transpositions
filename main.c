#include <stdio.h>

#include "geometric-transposition/process-strings.h"
#include "geometric-transposition/simple-columnar.h"
#include "geometric-transposition/simple-linear.h"
#include "geometric-transposition/columnar-with-numeric-key.h"
#include "geometric-transposition/by-itinerary.h"
#include "geometric-transposition/triangular.h"
#include "geometric-transposition/spiral.h"
#include "geometric-transposition/zigzag.h"

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
    int option;
    int linesCount, columnsCount;
    char text[100000], key[550];

    do{
        printf("Cryptography with Geometric Transposition\n\n");

        printf("Insert the text: ");
        fgets(text, 100000, stdin);
        removeInvalidCharacters(text);

        printf("\nChoose encryption:\n");
        printf("1 - Simple Columnar\n");
        printf("2 - Simple Linear\n");
        printf("3 - Columnar with Numeric Key\n");
        printf("4 - by Itinerary\n");
        printf("5 - Triangular\n");
        printf("6 - Spiral\n");
        printf("7 - Zigzag\n");
        printf("0 - Exit\n");
        printf("OPTION: ");
        scanf("%i", &option);
        setbuf(stdin, NULL);

        printf("\n");

        switch (option){
            case 1:
                printf("Simple Columnar\n");
                printf("Number of columns: ");
                scanf("%i", &columnsCount);
                simpleColumnar(text, columnsCount);
                break;
            
            case 2:
                printf("Simple Linear\n");
                printf("Number of lines: ");
                scanf("%i", &linesCount);
                simpleLinear(text, linesCount);
                break;

            case 3:
                printf("Columnar with Numeric Key\n");
                printf("Enter the key: ");
                fgets(key, 550, stdin);
                columnarWithNumericKey(text, key);
                break;

            case 4:
                printf("by Itinerary\n");
                printf("Number of lines: ");
                scanf("%i", &linesCount);
                byItinerary(text,linesCount);
                break;
            case 5:
                printf("Triangular\n");
                triangular(text);
                break;

            case 6:
                printf("Spiral\n");
                spiral(text);
                break;
            
            case 7:
                printf("Zigzag\n");
                zigzag(text);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option!!!\n");
                break;
        }

        setbuf(stdin, NULL);

        printf("Result: %s\n\n", text);
        system("pause");
        system("cls");

    }while(option != 0);

    return 0;
}

//os rapazes sao capazes
//minha terra tem palmeiras onde canta o sabia

// for(int i=0; i<linesCount; i++){
//     for(int j=0; j<columnsCount; j++){
//         printf("%c ", matrix[i][j]);
//     }
//     printf("\n");
// }