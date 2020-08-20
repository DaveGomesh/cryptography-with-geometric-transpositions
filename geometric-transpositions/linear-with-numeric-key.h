#ifndef COLUMNAR_WITH_NUMERIC_KEY_H_INCLUDED
#define COLUMNAR_WITH_NUMERIC_KEY_H_INCLUDED

/**
 * ----------------------------------------------------------------
 * WELCOME TO GEOMETRIC TRANSPOSITIONS!
 * ----------------------------------------------------------------
 * Columnar Transposition with Numeric Key
 * ----------------------------------------------------------------
 * @author David Gomesh
 * ----------------------------------------------------------------
 * *** This file is in UTF-8 codification! ***
 * ----------------------------------------------------------------
*/

#include <string.h>

void linearWithNumericKey(char text[], char key[]){
    int lengthText = strlen(text), lengthKey = strlen(key);
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

    //Input
    for(int i=0, k=0; i<linesCount; i++){
        for(int j=0; j<columnsCount; j++){
            if(k < lengthText){
                matrix[i][j] = text[k++];
            }else{
                matrix[i][j] = '-';
            }
        }
    }

    //Output
    int k=0;
    for(int currentPosition=1; currentPosition<=lengthKey; currentPosition++){
        for(int l=0; l<lengthKey; l++){
            if(order[l]==currentPosition){
                for(int i=0, j=l; i<linesCount; i++){
                    if(matrix[i][j] != '-'){
                        auxiliaryText[k++] = matrix[i][j];
                    }
                }
                break;
            }
        }
    }

    //Return
    auxiliaryText[k] = '\0';
    
    strcpy(text, auxiliaryText);
}

#endif /* COLUMNAR_WITH_NUMERIC_KEY_H_INCLUDED */