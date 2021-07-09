#include <stdio.h>
#include <string.h>
#include "string-processings/remove-invalid-characters.h"
#include <stdlib.h>
#include <stdbool.h>

double quantAnagrams=0;

void generatePreString(char text[], char preString[], int position);

void getAnagrams(char text[], char preString[], int level);

void removePreStringFromText(char text[], char preString[], char postString[]);

void mergePreStringWithCharacter(char current[], char preString[], char character);

int main(){
    char text[550];
    char preString[2];

    printf("Enter the text: ");
    fgets(text, 550, stdin);
    removeInvalidCharacters(text);

    for(int i=0; text[i]!='\0'; i++){
        generatePreString(text, preString, i);
        getAnagrams(text, preString, 1);
    }

    printf("Count Tests: %.0lf\n", quantAnagrams);

    return 0;
}

void generatePreString(char text[], char preString[], int position){
    preString[0] = text[position];
    preString[1] = '\0';
}

void getAnagrams(char text[], char preString[], int level){
    int lengthText = strlen(text);
    char postString[lengthText];

    removePreStringFromText(text, preString, postString);


    for(int i=0; postString[i]!='\0'; i++){
        char current[lengthText];
        mergePreStringWithCharacter(current, preString, postString[i]);
        if(strlen(current) == lengthText){
        //     // printf("Level:            %i\n", level);
        //     // printf("String:           %s\n", text);
        //     // printf("Pre String:       %s\n", preString);
        //     // printf("Posterior String: %s\n", postString);
            printf("ANAGRAM (%.0lf): %s\n-------------------\n", ++quantAnagrams, current);
        }
        getAnagrams(text, current, level+1);
    }
}

void removePreStringFromText(char text[], char preString[], char postString[]){
    strcpy(postString, text);

    for(int i=0; preString[i]!='\0'; i++){
        for(int j=0; text[j]!='\0'; j++){
            if(preString[i]==postString[j]){
                postString[j] = '-';
                break;
            }
        }
    }

    // printf("\n**********\nPosterior String: %sEND\n**********\n", postString);
    // system("pause");

    removeInvalidCharacters(postString);
}

void mergePreStringWithCharacter(char current[], char preString[], char character){
    int lengthPreString = strlen(preString);

    strcpy(current, preString);

    current[lengthPreString] = character;

    current[lengthPreString+1] = '\0';
    // printf("Length Pre String: %i\n", lengthPreString);
    // printf("I received the character: %c\n", character);
    // printf("The new word is: %s\n", current);
}


//SILVA, Luiz Paulo Moreira. "O que é anagrama?"; Brasil Escola. Disponível em: https://brasilescola.uol.com.br/o-que-e/matematica/o-que-e-anagrama.htm. Acesso em 27 de julho de 2020.