#include <stdio.h>
#include <string.h>
#include "string-processings/remove-invalid-characters.h"

void generatePreString(char text[], char preString[]);
void removePreStringFromWord(char text[], char preString[], char postString[]);

void getAnagrams(char text[], char preString[]);

int lengthPreString(char preString[]);

int main(){
    char text[550], preString[550];

    printf("Enter the text: ");
    fgets(text, 550, stdin);
    removeInvalidCharacters(text);

    generatePreString(text, preString);

    // printf("Text:       %s\n", text);
    // printf("Pre String: %s\n", preString);

    getAnagrams(text, preString);

    return 0;
}

void generatePreString(char text[], char preString[]){
    int lengthText = strlen(text);

    int i=0;
    for(; i<lengthText; i++){
        if(i!=0){
            preString[i] = '-';
        }
        else{
            preString[i] = text[0];
        }
    }

    preString[i] = '\0';
}

void removePreStringFromWord(char text[], char preString[], char postString[]){
    int lengthText = strlen(text);

    int i=0;
    for(; i<lengthText; i++){
        if(preString[i] == '-'){
            postString[i] = text[i];
        }
        else{
            postString[i] = '-';
        }
    }

    postString[i] = '\0';
}

void getAnagrams(char text[], char preString[]){
    int lengthText = strlen(text);
    char postString[lengthText];

    removePreStringFromWord(text, preString, postString);

    printf("\n-----------------\n");
    printf("Text: %s\n", text);
    printf("Pre String: %s\n", preString);
    printf("Post String: %s\n", postString);
}

int lengthPreString(char preString[]){
    return 0;
}