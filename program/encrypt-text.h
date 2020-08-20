#ifndef ENCRYPT_TEXT_H_INCLUDED
#define ENCRYPT_TEXT_H_INCLUDED

#include "default-inclusions.h"

#include "encryption-inclusions.h"

void encryptText(){
    FILE * f_OriginalText;
    char originalText[MAX_LENGTH_TEXT];
    int option, linesCount;

    do{
        system("cls");

        printf("Cryptography with Geometric Transposition\n\n");

        printf("[ENCRYPT]\n\n");

        option = showOptions();

        if(option != 0){
            f_OriginalText = fopen("original-text.txt", "r");

            if(f_OriginalText == NULL){
                f_OriginalText = fopen("original-text.txt", "w");
                fclose(f_OriginalText);

                printf("\n\nError: the 'original-text.txt' file not found\n");
                printf("An empty file has been created!\n");

                system("pause");
                
                return;
            }

            fgets(originalText, MAX_LENGTH_TEXT, f_OriginalText);

            fclose(f_OriginalText);
        }

        system("cls");

        printf("Cryptography with Geometric Transposition\n\n");

        switch (option){
            case 1:
                printf("[ENCRYPT][SIMPLE COLUMNAR]\n");
                showCurrentText(originalText);

                int columnsCount;
                printf("Number of Columns: ");
                scanf("%i", &columnsCount);
                setbuf(stdin, NULL);

                simpleColumnar(originalText, columnsCount);
                break;
            
            case 2:
                printf("[ENCRYPT][SIMPLE LINEAR]\n");
                showCurrentText(originalText);

                printf("Number of Lines: ");
                scanf("%i", &linesCount);
                setbuf(stdin, NULL);

                simpleLinear(originalText, linesCount);
                break;
            
            case 3:
                printf("[ENCRYPT][LINEAR WITH NUMERIC KEY]\n");
                showCurrentText(originalText);

                char key[MAX_LENGTH_TEXT];
                printf("Enter the Key: ");
                fgets(key, MAX_LENGTH_TEXT, stdin);

                removeInvalidCharacters(key);
                replaceEquivalentCharacters(key);

                linearWithNumericKey(originalText, key);
                break;
            
            case 4:
                printf("[ENCRYPT][BY ITINERARY]\n");
                showCurrentText(originalText);

                printf("Number of Lines: ");
                scanf("%i", &linesCount);
                setbuf(stdin, NULL);

                byItinerary(originalText, linesCount);
                break;
            
            case 5:
                printf("[ENCRYPT][TRIANGULAR]\n");
                showCurrentText(originalText);

                triangular(originalText);
                break;
            
            case 6:
                printf("[ENCRYPT][EXTERNAL SPIRAL]\n");
                showCurrentText(originalText);

                externalSpiral(originalText);
                break;
            
            case 7:
                printf("[ENCRYPT][INTERNAL SPIRAL]\n");
                showCurrentText(originalText);

                internalSpiral(originalText);
                break;
            
            case 8:
                printf("[ENCRYPT][ZIG ZAG]\n");
                showCurrentText(originalText);

                zigzag(originalText);
                break;
            
            case 9:
                printf("[ENCRYPT]['L' PATTERN]\n");
                showCurrentText(originalText);

                lPattern(originalText);
                break;
            
            case 0:
                break;
                
            default:
                printf("\n\nInvalid option!\n\n");
                system("pause");
                break;
        }

    }while(option < 0 || option > 9);

    if(option != 0){
        printf("Result: %s\n\n", originalText);

        FILE * f_EncryptedText = fopen("encrypted-text.txt", "w");
        fprintf(f_EncryptedText, originalText);
        fclose(f_EncryptedText);

        printf("The Result Text has been saved on 'encrypted-text.txt'!\n\n");
        system("pause");
    }
}

#endif /* ENCRYPT_TEXT_H_INCLUDED */