#ifndef TRIANGULAR_H_INCLUDED
#define TRIANGULAR_H_INCLUDED

/**
 * ----------------------------------------------------------------
 * WELCOME TO GEOMETRIC TRANSPOSITIONS!
 * ----------------------------------------------------------------
 * Triangular Transposition
 * ----------------------------------------------------------------
 * @author David Gomesh
 * ----------------------------------------------------------------
 * *** This file is in UTF-8 codification! ***
 * ----------------------------------------------------------------
*/

#include <string.h>

void triangular(char text[]){
    int lengthText = strlen(text);
    char auxiliaryText[lengthText];

    int linesCount=1, columnsCount;

    int maxCharMatrix=1;
    int maxCharLastLine=1;

    while(maxCharMatrix < lengthText){
        maxCharLastLine+=2;
        maxCharMatrix+=maxCharLastLine;
        linesCount++;
    }

    columnsCount = maxCharLastLine;

    char matrix[linesCount][columnsCount];

    /*
        i = Matrix Line Index
        j = Valid Matrix Column Index
        l = Matrix Column Index
        k = String Index
    */
    int maxCharCurrentLine = 1;
    for(int i=0, k=0; i<linesCount; i++, maxCharCurrentLine+=2){
        for(int j=(columnsCount/2)-i, l=0, quant=0; l<columnsCount; l++){
            if(l!=j || k>=lengthText){
                matrix[i][l] = '-';
            }else{
                matrix[i][j++] = text[k++];
                quant++;
                if(quant>=maxCharCurrentLine){
                    j=-1;
                }
            }
        }
    }

    int k=0;
    for(int j=0; j<columnsCount; j++){
        for(int i=0; i<linesCount; i++){
            if(matrix[i][j] != '-'){
                auxiliaryText[k++] = matrix[i][j];                
            }
        }
    }

    auxiliaryText[k] = '\0';

    strcpy(text, auxiliaryText);
}

#endif /* TRIANGULAR_H_INCLUDED */