#include <stdio.h>
#include <stdlib.h>

#include "../../string-processings/remove-invalid-characters.h"
#include "../../string-processings/to-uppercase.h"

// #include "../../geometric-transpositions/simple-columnar.h"
// #include "../../geometric-transpositions/simple-linear.h"

#include "D:\\David Gomesh\\GitHub\\cryptography-with-geometric-transpositions\\decrypt\\decryptor-algorithm\\decrypt-simple-columnar.h"
#include "D:\\David Gomesh\\GitHub\\cryptography-with-geometric-transpositions\\decrypt\\decryptor-algorithm\\decrypt-simple-linear.h"
#include "D:\\David Gomesh\\GitHub\\cryptography-with-geometric-transpositions\\decrypt\\decryptor-algorithm\\decrypt-columnar-with-numeric-key.h"
#include "D:\\David Gomesh\\GitHub\\cryptography-with-geometric-transpositions\\decrypt\\decryptor-algorithm\\decrypt-by-itinerary.h"
#include "D:\\David Gomesh\\GitHub\\cryptography-with-geometric-transpositions\\decrypt\\decryptor-algorithm\\decrypt-triangular.h"
#include "D:\\David Gomesh\\GitHub\\cryptography-with-geometric-transpositions\\decrypt\\decryptor-algorithm\\decrypt-external-spiral.h"
#include "D:\\David Gomesh\\GitHub\\cryptography-with-geometric-transpositions\\decrypt\\decryptor-algorithm\\decrypt-internal-spiral.h"
#include "D:\\David Gomesh\\GitHub\\cryptography-with-geometric-transpositions\\decrypt\\decryptor-algorithm\\decrypt-zigzag.h"
#include "D:\\David Gomesh\\GitHub\\cryptography-with-geometric-transpositions\\decrypt\\decryptor-algorithm\\decrypt-l-pattern.h"

int main(){
    int option;
    int columnsCount, linesCount;

    char encryptedText[550], key[550];

    do{
        system("cls");
        printf("Insert the Encrypted text: ");
        fgets(encryptedText, 550, stdin);

        removeInvalidCharacters(encryptedText);
        toUppercase(encryptedText);

        printf("Text: %s\n", encryptedText);

        printf("\nChoose encryption:\n");
        printf("1 - Simple Columnar\n");
        printf("2 - Simple Linear\n");
        printf("3 - Columnar with Numeric Key\n");
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

        printf("\n");

        switch (option){
            case 1:
                printf("Simple Columnar\n");
                printf("Number of columns: ");
                scanf("%i", &columnsCount);
                decryptSimpleColumnar(encryptedText, columnsCount);
                break;
            
            case 2:
                printf("Simple Linear\n");
                printf("Number of lines: ");
                scanf("%i", &linesCount);
                decryptSimpleLinear(encryptedText, linesCount);
                break;

            case 3:
                printf("Columnar with Numeric Key\n");
                printf("Enter the key: ");
                fgets(key, 550, stdin);
                removeInvalidCharacters(key);
                decryptColumnarWithNumericKey(encryptedText, key);
                break;

            case 4:
                printf("by Itinerary\n");
                printf("Number of lines: ");
                scanf("%i", &linesCount);
                decryptByItinerary(encryptedText,linesCount);
                break;

            case 5:
                printf("Triangular\n");
                decryptTriangular(encryptedText);
                break;

            case 6:
                printf("External Spiral\n");
                decryptExternalSpiral(encryptedText);
                break;

            case 7:
                printf("Internal Spiral\n");
                decryptInternalSpiral(encryptedText);
                break;
            
            case 8:
                printf("Zigzag\n");
                decryptZigzag(encryptedText);
                break;
            
            case 9:
                printf("'L' Pattern\n");
                decryptLPattern(encryptedText);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option!!!\n");
                break;
        }

        setbuf(stdin, NULL);

        printf("Result: %s\n\n", encryptedText);

        system("pause");

    }while(option != 0);
    return 0;
}