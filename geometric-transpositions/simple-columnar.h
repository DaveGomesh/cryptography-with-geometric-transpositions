#ifndef SIMPLE_LINEAR_H_INCLUDED
#define SIMPLE_LINEAR_H_INCLUDED

/**
 * ----------------------------------------------------------------
 * WELCOME TO GEOMETRIC TRANSPOSITIONS!
 * ----------------------------------------------------------------
 * Simple Linear Transposition
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

    //Calculate Matrix Size
    if(lengthText % columnsCount == 0){
        linesCount = lengthText / columnsCount;
    }else{
        linesCount = lengthText / columnsCount + 1;
    }

    char matrix[linesCount][columnsCount];

    //Input
    for(int j=0, k=0; j<columnsCount; j++){
        for(int i=0; i<linesCount; i++){
            if(k < lengthText){
                matrix[i][j] = text[k++];
            }else{
                matrix[i][j] = '-';
            }
        }
    }

    //Output
    int k=0;
    for(int i=0; i<linesCount; i++){
        for(int j=0; j<columnsCount; j++){
            if(matrix[i][j] != '-'){
                auxiliaryText[k++] = matrix[i][j];
            }
        }
    }

    //Return
    auxiliaryText[k] = '\0';

    strcpy(text, auxiliaryText);
}

#endif /* SIMPLE_LINEAR_H_INCLUDED */