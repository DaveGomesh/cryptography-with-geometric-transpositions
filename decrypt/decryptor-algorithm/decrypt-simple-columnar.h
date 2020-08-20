#ifndef DECRYPT_SIMPLE_COLUMNAR_H_INCLUDED
#define DECRYPT_SIMPLE_COLUMNAR_H_INCLUDED

/**
 * ----------------------------------------------------------------
 * WELCOME TO GEOMETRIC TRANSPOSITIONS!
 * ----------------------------------------------------------------
 * Simple Columnar Transposition Decryptor
 * ----------------------------------------------------------------
 * @author David Gomesh
 * ----------------------------------------------------------------
 * *** This file is in UTF-8 codification! ***
 * ----------------------------------------------------------------
*/

#include <string.h>

void decryptSimpleColumnar(char encryptedText[], int columnsCount){
    int lengthText = strlen(encryptedText);
    char auxiliaryText[lengthText];
    int linesCount;

    //Calculate the Matrix Size
    if(lengthText % columnsCount == 0){
        linesCount = lengthText / columnsCount;
    }else{
        linesCount = lengthText / columnsCount + 1;
    }

    char matrix[linesCount][columnsCount];

    //Checks Possible Fields
    for(int i=0, k=0; i<linesCount; i++){
        for(int j=0; j<columnsCount; j++){
            if(k++ < lengthText){
                matrix[i][j] = '@';
            }else{
                matrix[i][j] = '-';
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

    // for(int j=0; j<columnsCount; j++){
    //     for(int i=0; i<linesCount; i++){
    //         if(k < lengthText && matrix[i][j] != '-'){
    //             matrix[i][j] = encryptedText[k++];
    //         }
    //     }
    // }

    
    //Output
    int k=0;
    for(int j=0; j<columnsCount; j++){
        for(int i=0; i<linesCount; i++){
            if(matrix[i][j] != '-'){
                auxiliaryText[k++] = matrix[i][j];                
            }
        }
    }

    // for(int i=0, k=0; i<linesCount; i++){
    //     for(int j=0; j<columnsCount; j++){
    //         if(matrix[i][j] != '-'){
    //             auxiliaryText[k++] = matrix[i][j];                
    //         }
    //     }
    // }

    //Return
    auxiliaryText[k] = '\0';

    strcpy(encryptedText, auxiliaryText);
}

#endif /* DECRYPT_SIMPLE_COLUMNAR_H_INCLUDED */