#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../string-processings/remove-invalid-characters.h"
#include "../../string-processings/replace-equivalent-characters.h"
#include "../../string-processings/to-uppercase.h"

int main(){
    char encryptedText[100000];

    printf("Cryptanalysis: Frequency of Letters\n\n");

    FILE * f_EncryptedText = fopen("encrypted-text.txt", "r");

    if(f_EncryptedText == NULL){
        f_EncryptedText = fopen("encrypted-text.txt", "w");
        fclose(f_EncryptedText);

        printf("The 'encrypted-text.txt' file not found!\n");
        printf("An empty file has been created!\n\n");

        system("pause");
    }

    fgets(encryptedText, 100000, f_EncryptedText);

    removeInvalidCharacters(encryptedText);
    replaceEquivalentCharacters(encryptedText);
    toUppercase(encryptedText);

    double lengthText = strlen(encryptedText);

    fclose(f_EncryptedText);

    ////////////////////////////////

    int coutLetters[26];
    // for(int i=0; i<26; i++){
    //     coutLetters[i] = 0;
    // }

    for(int i=0; encryptedText[i]!='\0'; i++){
        int character = encryptedText[i];
        switch (character){
            case 65://A
                coutLetters[0]++;
                break;
                
            case 66://B
                coutLetters[1]++;
                break;
                
            case 67://C
                coutLetters[2]++;
                break;
                
            case 68://D
                coutLetters[3]++;
                break;
                
            case 69://E
                coutLetters[4]++;
                break;
                
            case 70://F
                coutLetters[5]++;
                break;
                
            case 71://G
                coutLetters[6]++;
                break;
                
            case 72://H
                coutLetters[7]++;
                break;
                
            case 73://I
                coutLetters[8]++;
                break;
                
            case 74://J
                coutLetters[9]++;
                break;
                
            case 75://K
                coutLetters[10]++;
                break;
                
            case 76://L
                coutLetters[11]++;
                break;
                
            case 77://M
                coutLetters[12]++;
                break;
                
            case 78://N
                coutLetters[13]++;
                break;
                
            case 79://O
                coutLetters[14]++;
                break;
                
            case 80://P
                coutLetters[15]++;
                break;
                
            case 81://Q
                coutLetters[16]++;
                break;
                
            case 82://R
                coutLetters[17]++;
                break;
                
            case 83://S
                coutLetters[18]++;
                break;
                
            case 84://T
                coutLetters[19]++;
                break;
                
            case 85://U
                coutLetters[20]++;
                break;
                
            case 86://V
                coutLetters[21]++;
                break;
                
            case 87://W
                coutLetters[22]++;
                break;
                
            case 88://X
                coutLetters[23]++;
                break;
                
            case 89://Y
                coutLetters[24]++;
                break;
                
            case 90://Z
                coutLetters[25]++;
                break;
        }
    }

    printf("Count Letters: %i\n\n", lengthText);
    for(int i=0; i<26; i++){        
        printf("Letter %c - Count: %i\n", i+65, coutLetters[i]);
    }

    double probabilityOccurrence[26];

    for(int i=0; i<26; i++){
        if(coutLetters[i]>0){
            probabilityOccurrence[i] = (coutLetters[i] * (coutLetters[i] - 1)) / 
                                           (lengthText * (lengthText - 1));
        }
    }

    printf("\nCoincidence Index:\n");
    for(int i=0; i<26; i++){        
        printf("Letter %c - Index: %.4lf\n", i+65, probabilityOccurrence[i]);
    }

    double kappaIndex=0.0;

    for(int i=0; i<26; i++){
        kappaIndex += probabilityOccurrence[i];
    }

    printf("\nKappa Index:       %.4lf\n", kappaIndex);

    double coincidenceIndex = kappaIndex / 0.0385;

    printf("Coincidence Index: %.4lf\n", coincidenceIndex);

    return 0;
}