#ifndef DECRYPT_COLUMNAR_WITH_NUMERIC_KEY_H_INCLUDED
#define DECRYPT_COLUMNAR_WITH_NUMERIC_KEY_H_INCLUDED

/**
 * ----------------------------------------------------------------
 * WELCOME TO GEOMETRIC TRANSPOSITIONS!
 * ----------------------------------------------------------------
 * Columnar Transposition with Numeric Key Decryptor
 * ----------------------------------------------------------------
 * @author David Gomesh
 * ----------------------------------------------------------------
 * *** This file is in UTF-8 codification! ***
 * ----------------------------------------------------------------
*/

#include <string.h>

void decryptColumnarWithNumericKey(char encryptedText[], char key[]){
    int lengthText = strlen(encryptedText), lengthKey = strlen(key);
    int order[lengthKey];
    char auxiliaryText[lengthText];

    //Number of Columns already defined
    int linesCount, columnsCount = lengthKey;

    //Order
    for(int upper=65, lower=97, value=1; upper<=90 && lower<=122; upper++, lower++){
        for(int i=0; i<lengthKey; i++){
            if(key[i]==upper || key[i]==lower){
                order[i] = value++;
            }
        }
    }

    //Calculate the Number of Lines
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
    int k=0;
    for(int currentPosition=1; currentPosition<=lengthKey; currentPosition++){
        for(int l=0; l<lengthKey; l++){
            if(order[l]==currentPosition){
                for(int i=0, j=l; i<linesCount; i++){
                    if(k < lengthText && matrix[i][j] != '-'){
                        matrix[i][j] = encryptedText[k++];
                    }
                }
                break;
            }
        }
    }

    //Output
    for(int i=0, k=0; i<linesCount; i++){
        for(int j=0; j<columnsCount; j++){
            if(matrix[i][j] != '-'){
                auxiliaryText[k++] = matrix[i][j];
            }
        }
    }
    
    //Return
    auxiliaryText[k] = '\0';
    
    strcpy(encryptedText, auxiliaryText);
}

#endif /* DECRYPT_COLUMNAR_WITH_NUMERIC_KEY_H_INCLUDED */