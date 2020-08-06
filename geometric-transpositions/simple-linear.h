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

void simpleLinear(char text[], int linesCount){
    int lengthText = strlen(text);
    char auxiliaryText[lengthText];
    int columnsCount;

    //Calculate Matrix Size
    if(lengthText % linesCount == 0){
        columnsCount = lengthText / linesCount;
    }else{
        columnsCount = lengthText / linesCount + 1;
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