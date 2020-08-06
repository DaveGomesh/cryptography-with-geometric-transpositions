#ifndef DECRYPT_BY_ITINERARY_H_INCLUDED
#define DECRYPT_BY_ITINERARY_H_INCLUDED

/**
 * ----------------------------------------------------------------
 * WELCOME TO GEOMETRIC TRANSPOSITIONS!
 * ----------------------------------------------------------------
 * Transposition by Itinerary Decryptor
 * ----------------------------------------------------------------
 * @author David Gomesh
 * ----------------------------------------------------------------
 * *** This file is in UTF-8 codification! ***
 * ----------------------------------------------------------------
*/

#include <string.h>

void decryptByItinerary(char encryptedText[], int linesCount){
    int lengthText = strlen(encryptedText);
    int columnsCount = lengthText;
    char auxiliaryText[lengthText];

    char matrix[linesCount][columnsCount];

    //Checks Possible Fields
    char state = 'd'; //u = up and d = down
    for(int i=0, j=0; j<lengthText; j++){
        matrix[i][j] = '@';

        for(int k=0; k<linesCount; k++){
            if(k != i){
                matrix[k][j] = '-';
            }
        }

        if(state == 'd'){
            if(i == linesCount-1){
                state = 'u';
                i--;
                continue;
            }else{
                i++;
            }
        }

        if(state == 'u'){
            if(i == 0){
                state = 'd';
                i++;
                continue;
            }
            else{
                i--;
            }
        }
    }

    //Input
    for(int i=0, k=0; i<linesCount; i++){
        for(int j=0; j<columnsCount; j++){
            if(k < lengthText && matrix[i][j] != '-'){
                matrix[i][j] = encryptedText[k++];
            }
        }
    }

    //Output
    state = 'd';
    int j=0; //u = up and d = down
    for(int i=0; j<lengthText; j++){
        auxiliaryText[j] = matrix[i][j];

        if(state == 'd'){
            if(i == linesCount-1){
                state = 'u';
                i--;
                continue;
            }else{
                i++;
            }
        }

        if(state == 'u'){
            if(i == 0){
                state = 'd';
                i++;
                continue;
            }
            else{
                i--;
            }
        }
    }

    //Return
    auxiliaryText[j] = '\0';
    
    strcpy(encryptedText, auxiliaryText);
}

#endif /* DECRYPT_BY_ITINERARY_H_INCLUDED */