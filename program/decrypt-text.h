#ifndef DECRYPT_TEXT_H_INCLUDED
#define DECRYPT_TEXT_H_INCLUDED

#include "default-inclusions.h"

#include "decryption-inclusions.h"

void decryptText(){
    FILE * f_EncryptedText;
    char encryptedText[MAX_LENGTH_TEXT];
    int option, linesCount;

    do{
        system("cls");

        printf("Cryptography with Geometric Transposition\n\n");

        printf("[DECRYPT]\n\n");

        option = showOptions();

        if(option != 0){
            f_EncryptedText = fopen("encrypted-text.txt", "r");

            if(f_EncryptedText == NULL){
                f_EncryptedText = fopen("encrypted-text.txt", "w");
                fclose(f_EncryptedText);

                printf("\n\nError: the 'encrypted-text.txt' file not found\n");
                printf("An empty file has been created!\n");

                system("pause");
                
                return;
            }

            fgets(encryptedText, MAX_LENGTH_TEXT, f_EncryptedText);

            fclose(f_EncryptedText);
        }

        system("cls");

        printf("Cryptography with Geometric Transposition\n\n");


        switch (option){
            case 1:
                printf("[DECRYPT][SIMPLE COLUMNAR]\n");
                showCurrentText(encryptedText);

                int columnsCount;
                printf("Number of Columns: ");
                scanf("%i", &columnsCount);
                setbuf(stdin, NULL);

                decryptSimpleColumnar(encryptedText, columnsCount);
                break;
            
            case 2:
                printf("[DECRYPT][SIMPLE LINEAR]\n");
                showCurrentText(encryptedText);

                printf("Number of Lines: ");
                scanf("%i", &linesCount);
                setbuf(stdin, NULL);

                decryptSimpleLinear(encryptedText, linesCount);
                break;
            
            case 3:
                printf("[DECRYPT][LINEAR WITH NUMERIC KEY]\n");
                showCurrentText(encryptedText);

                char key[MAX_LENGTH_TEXT];
                printf("Enter the Key: ");
                fgets(key, MAX_LENGTH_TEXT, stdin);

                removeInvalidCharacters(key);
                replaceEquivalentCharacters(key);

                decryptLinearWithNumericKey(encryptedText, key);
                break;
            
            case 4:
                printf("[DECRYPT][BY ITINERARY]\n");
                showCurrentText(encryptedText);

                printf("Number of Lines: ");
                scanf("%i", &linesCount);
                setbuf(stdin, NULL);

                decryptByItinerary(encryptedText, linesCount);
                break;
            
            case 5:
                printf("[DECRYPT][TRIANGULAR]\n");
                showCurrentText(encryptedText);

                decryptTriangular(encryptedText);
                break;
            
            case 6:
                printf("[DECRYPT][EXTERNAL SPIRAL]\n");
                showCurrentText(encryptedText);

                decryptExternalSpiral(encryptedText);
                break;
            
            case 7:
                printf("[DECRYPT][INTERNAL SPIRAL]\n");
                showCurrentText(encryptedText);

                decryptInternalSpiral(encryptedText);
                break;
            
            case 8:
                printf("[DECRYPT][ZIG ZAG]\n");
                showCurrentText(encryptedText);

                decryptZigzag(encryptedText);
                break;
            
            case 9:
                printf("[DECRYPT]['L' PATTERN]\n");
                showCurrentText(encryptedText);

                decryptLPattern(encryptedText);
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
        printf("Result: %s\n\n", encryptedText);

        FILE * f_ResultText = fopen("result-text.txt", "w");
        fprintf(f_ResultText, encryptedText);
        fclose(f_ResultText);

        printf("The Result Text has been saved on 'result-text.txt'!\n\n");
        system("pause");
    }
}

#endif /* DECRYPT_TEXT_H_INCLUDED */