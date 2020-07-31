#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../string-processings/remove-invalid-characters.h"

void generatePreString(char text[], char preString[], int position);

void getAnagrams(char text[], char preString[]);

void removePreStringFromText(char text[], char preString[], char postString[]);

void mergePreStringWithCharacter(char current[], char preString[], char character);

int verifyAnagram(char anagram[], char originalText[]);

int option, actionOption, coutAnagrams=0;
char OriginalText[100000];

int main(){
    char encryptedText[100000], originalText[100000];;
    char preString[2];

    FILE * f_EncryptedText;
    FILE * f_OriginalText;

    printf("Decrypt using Brute Force with Anagrams\n\n");

    printf("1 - Type Texts\n");
    printf("2 - Use the Files\n");

    printf("OPTION: ");
    scanf("%i", &option);
    setbuf(stdin, NULL);

    switch (option){
        case 1:
            printf("\nEnter the Encrypted Text: ");
            fgets(encryptedText, 100000, stdin);

            printf("\nAction:\n");
            printf("1 - Show All Anagrams\n");
            printf("2 - Find the Original Text\n");

            printf("OPTION: ");
            scanf("%i", &actionOption);
            setbuf(stdin, NULL);

            switch (actionOption){
                    case 1:
                        break;

                    case 2:
                        printf("\nEnter the Original Text: ");
                        fgets(originalText, 100000, stdin);
                        break;
                }

            break;
        
        case 2:
            f_EncryptedText = fopen("encrypted-text.txt", "r");
            f_OriginalText = fopen("original-text.txt", "r");

            if(f_EncryptedText == NULL){
                f_EncryptedText = fopen("encrypted-text.txt", "w");
                fclose(f_EncryptedText);

                printf("The 'encrypted-text.txt' file not found!\n");
                printf("An empty file was created!\n");
                system("pause");
                exit(0);
            }

            if(f_OriginalText == NULL){
                f_OriginalText = fopen("original-text.txt", "w");
                fclose(f_OriginalText);

                printf("The 'original-text.txt' file not found!\n");
                printf("An empty file was created!\n");
                system("pause");
                exit(0);
            }

            fgets(encryptedText, 100000, f_EncryptedText);
            fgets(originalText, 100000, f_OriginalText);

            fclose(f_EncryptedText);
            break;
    }
    
    if(actionOption == 1){
        printf("\nShowing...\n\n");
    }

    if(option == 2 || actionOption == 2){
        printf("\nDecrypting...\n\n");
    }

    strcpy(OriginalText, originalText);

    removeInvalidCharacters(encryptedText);
    removeInvalidCharacters(OriginalText);

    for(int i=0; encryptedText[i]!='\0'; i++){
        generatePreString(encryptedText, preString, i);
        getAnagrams(encryptedText, preString);
    }
}

void generatePreString(char text[], char preString[], int position){
    preString[0] = text[position];
    preString[1] = '\0';
}

void getAnagrams(char text[], char preString[]){
    int lengthText = strlen(text);
    char postString[lengthText];

    removePreStringFromText(text, preString, postString);

    for(int i=0; postString[i]!='\0'; i++){
        char currentAnagram[lengthText];
        
        mergePreStringWithCharacter(currentAnagram, preString, postString[i]);

        if(strlen(currentAnagram) == lengthText){
            coutAnagrams++;

            if(actionOption == 1){
                printf("ANAGRAM %i: %s\n", coutAnagrams, currentAnagram);
            }

            if(option == 2 || actionOption == 2){
                if(verifyAnagram(currentAnagram, OriginalText)==1){
                    FILE * f_ResultDecrypting = fopen("result-decrypting.txt", "w");

                    fprintf(f_ResultDecrypting, currentAnagram);

                    fclose(f_ResultDecrypting);

                    printf("RESULT: %s\n", currentAnagram);
                    printf("Count Tests: %i\n", coutAnagrams);
                    printf("The result was saved in the file: 'result-decrypting.txt'!\n");
                    exit(0);
                }
            }
        }

        getAnagrams(text, currentAnagram);
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

    removeInvalidCharacters(postString);
}

void mergePreStringWithCharacter(char current[], char preString[], char character){
    int lengthPreString = strlen(preString);

    strcpy(current, preString);

    current[lengthPreString] = character;

    current[lengthPreString+1] = '\0';
}

int verifyAnagram(char anagram[], char originalText[]){
    if(strcmp(anagram, originalText)==0){
        return 1;
    }

    return 0;
}

//SILVA, Luiz Paulo Moreira. "O que é anagrama?"; Brasil Escola. Disponível em: https://brasilescola.uol.com.br/o-que-e/matematica/o-que-e-anagrama.htm. Acesso em 27 de julho de 2020.