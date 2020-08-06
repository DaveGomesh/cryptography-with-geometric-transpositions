#ifndef SIMPLE_COLUMNAR_H_INCLUDED
#define SIMPLE_COLUMNAR_H_INCLUDED

/**
 * ----------------------------------------------------------------
 * WELCOME TO GEOMETRIC TRANSPOSITIONS!
 * ----------------------------------------------------------------
 * Simple Columnar Transposition
 * ----------------------------------------------------------------
 * @author David Gomesh
 * ----------------------------------------------------------------
 * *** This file is in UTF-8 codification! ***
 * ----------------------------------------------------------------
*/

#include <string.h>

void simpleColumnar(char text[], int columnsCount){
    int lengthText = strlen(text);
    char auxiliaryText[lengthText];
    int linesCount;

    //Calculate the Matrix Size
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
    for(int j=0; j<columnsCount; j++){
        for(int i=0; i<linesCount; i++){
            if(matrix[i][j] != '-'){
                auxiliaryText[k++] = matrix[i][j];                
            }
        }
    }
    
    //Return
    auxiliaryText[k] = '\0';

    strcpy(text, auxiliaryText);
}

#endif /* SIMPLE_COLUMNAR_H_INCLUDED */