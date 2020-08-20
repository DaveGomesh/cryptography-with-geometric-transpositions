#ifndef SET_TEXTS_H_INCLUDED
#define SET_TEXTS_H_INCLUDED

#include "default-inclusions.h"

void setTexts(){
    int option;
    char originalText[MAX_LENGTH_TEXT];

    do{
        system("cls");

        printf("Cryptography with Geometric Transposition\n\n");

        printf("[SET TEXTS]\n\n");

        printf("Choose a file\n\n");

        printf("1 - Original Text ('original-text.txt')\n");
        printf("2 - Encrypted Text ('encrypted-text.txt')\n");
        printf("3 - Result Text ('result-text.txt')\n");
        printf("0 - Back\n\n");

        printf("OPTION: ");
        scanf("%i", &option);
        setbuf(stdin, NULL);

        switch (option){
            case 1:;
                FILE * f_OriginalText = fopen("original-text.txt", "w");
                char originalText[MAX_LENGTH_TEXT];

                printf("\nEnter the Original Text: ");
                fgets(originalText, MAX_LENGTH_TEXT, stdin);

                removeInvalidCharacters(originalText);
                replaceEquivalentCharacters(originalText);

                fprintf(f_OriginalText, originalText);
                
                fclose(f_OriginalText);

                printf("\nSaved successfully!\n\n");
                break;
            
            case 2:;
                FILE * f_EncryptedText = fopen("encrypted-text.txt", "w");
                char encryptedText[MAX_LENGTH_TEXT];

                printf("\nEnter the Encrypted Text: ");
                fgets(encryptedText, MAX_LENGTH_TEXT, stdin);

                removeInvalidCharacters(encryptedText);
                replaceEquivalentCharacters(encryptedText);

                fprintf(f_EncryptedText, encryptedText);
                
                fclose(f_EncryptedText);

                printf("\nSaved successfully!\n\n");
                break;
            
            case 3:;
                FILE * f_ResultText = fopen("result-text.txt", "w");
                char resultText[MAX_LENGTH_TEXT];

                printf("\nEnter the Result Text: ");
                fgets(resultText, MAX_LENGTH_TEXT, stdin);

                removeInvalidCharacters(resultText);
                replaceEquivalentCharacters(resultText);

                fprintf(f_ResultText, resultText);
                
                fclose(f_ResultText);

                printf("\nSaved successfully!\n\n");
                break;

            case 0:
                break;
            
            default:
                printf("\n\nInvalid option!\n\n");
                break;
        }

    }while(option < 0 || option > 2);

    if(option != 0){
        system("pause");
    }
}

#endif /* SET_TEXTS_H_INCLUDED */