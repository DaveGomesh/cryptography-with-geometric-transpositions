#ifndef SHOW_TEXTS_H_INCLUDED
#define SHOW_TEXTS_H_INCLUDED

#include "default-inclusions.h"

#include <string.h>

void showTexts(){
    FILE * f_OriginalText;
    FILE * f_EncryptedText;
    FILE * f_ResultText;

    char originalText[MAX_LENGTH_TEXT];
    char encryptedText[MAX_LENGTH_TEXT];
    char resultText[MAX_LENGTH_TEXT];


    f_OriginalText = fopen("original-text.txt", "r");
    if(f_OriginalText!=NULL){
        fgets(originalText, MAX_LENGTH_TEXT, f_OriginalText);
    }
    else{
        strcpy(originalText, "file not found");
    }
    

    f_EncryptedText = fopen("encrypted-text.txt", "r");
    if(f_EncryptedText!=NULL){
        fgets(encryptedText, MAX_LENGTH_TEXT, f_EncryptedText);
    }
    else{
        strcpy(encryptedText, "file not found");
    }


    f_ResultText = fopen("result-text.txt", "r");
    if(f_ResultText!=NULL){
        fgets(resultText, MAX_LENGTH_TEXT, f_ResultText);
    }
    else{
        strcpy(resultText, "file not found");
    }


    system("cls");

    printf("Cryptography with Geometric Transposition\n\n");

    printf("[SHOWING ALL TEXTS FROM THE FILES]\n\n");

    printf("'original-text.txt'  = %s\n", originalText);
    printf("'encrypted-text.txt' = %s\n", encryptedText);
    printf("'result-text.txt'    = %s\n", resultText);

    printf("\n");

    system("pause");
}

#endif /* SHOW_TEXTS_H_INCLUDED */