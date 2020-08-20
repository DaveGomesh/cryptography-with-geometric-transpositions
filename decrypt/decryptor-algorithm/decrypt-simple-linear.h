#ifndef DECRYPT_SIMPLE_LINEAR_H_INCLUDED
#define DECRYPT_SIMPLE_LINEAR_H_INCLUDED

/**
 * ----------------------------------------------------------------
 * WELCOME TO GEOMETRIC TRANSPOSITIONS!
 * ----------------------------------------------------------------
 * Simple Linear Transposition Decryptor
 * ----------------------------------------------------------------
 * @author David Gomesh
 * ----------------------------------------------------------------
 * *** This file is in UTF-8 codification! ***
 * ----------------------------------------------------------------
*/

#include <string.h>

void decryptSimpleLinear(char encryptedText[], int linesCount){
    int lengthText = strlen(encryptedText);
    char auxiliaryText[lengthText];
    int columnsCount;

    //Calculate Matrix Size
    if(lengthText % linesCount == 0){
        columnsCount = lengthText / linesCount;
    }else{
        columnsCount = lengthText / linesCount + 1;
    }

    char matrix[linesCount][columnsCount];

    //Checks Possible Fields
    for(int j=0, k=0; j<columnsCount; j++){
        for(int i=0; i<linesCount; i++){
            if(k++ < lengthText){
                matrix[i][j] = '@';
            }else{
                matrix[i][j] = '-';
            }
        }
    }

    //Input
    for(int j=0, k=0; j<columnsCount; j++){
        for(int i=0; i<linesCount; i++){
            if(k < lengthText && matrix[i][j] != '-'){
                matrix[i][j] = encryptedText[k++];
            }
        }
    }

    // for(int i=0; i<linesCount; i++){
    //     for(int j=0; j<columnsCount; j++){
    //         if(k < lengthText && matrix[i][j] != '-'){
    //             matrix[i][j] = encryptedText[k++];
    //         }
    //     }
    // }

    //Output
    int k=0;
    for(int i=0; i<linesCount; i++){
        for(int j=0; j<columnsCount; j++){
            if(matrix[i][j] != '-'){
                auxiliaryText[k++] = matrix[i][j];                
            }
        }
    }

    // for(int j=0, k=0; j<columnsCount; j++){
    //     for(int i=0; i<linesCount; i++){
    //         if(matrix[i][j] != '-'){
    //             auxiliaryText[k++] = matrix[i][j];                
    //         }
    //     }
    // }

    //Return
    auxiliaryText[k] = '\0';

    strcpy(encryptedText, auxiliaryText);
}

#endif /* DECRYPT_SIMPLE_LINEAR_H_INCLUDED */