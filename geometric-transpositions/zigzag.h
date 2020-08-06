#ifndef ZIGZAG_H_INCLUDED
#define ZIGZAG_H_INCLUDED

/**
 * ----------------------------------------------------------------
 * WELCOME TO GEOMETRIC TRANSPOSITIONS!
 * ----------------------------------------------------------------
 * Transposition with Zigzag
 * ----------------------------------------------------------------
 * @author David Gomesh
 * ----------------------------------------------------------------
 * *** This file is in UTF-8 codification! ***
 * ----------------------------------------------------------------
*/

#include <string.h>
#include <math.h>

void zigzag(char text[]){
    int lengthText = strlen(text);
    char auxiliaryText[lengthText];

    int linesCount, columnsCount;

    int squareRootLengthText = (int)sqrt(lengthText);

    linesCount = columnsCount = squareRootLengthText;
    while(columnsCount * linesCount < lengthText){
        linesCount++;
    }

    char matrix[linesCount][columnsCount];

    char state = 'r'; //r = rigth, l = left
    for(int i=0, k=0; i<linesCount; i++){
        if(state == 'r'){
            for(int j=0; j<columnsCount; j++){
                if(k < lengthText){
                    matrix[i][j] = text[k++];
                }
                else{
                    matrix[i][j] = '-';
                }
            }

            state = 'l';
        }
        else{
            for(int j=columnsCount-1; j>=0; j--){
                if(k < lengthText){
                    matrix[i][j] = text[k++];
                }
                else{
                    matrix[i][j] = '-';
                }
            }

            state = 'r';
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

#endif /* ZIGZAG_H_INCLUDED */