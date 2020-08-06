#ifndef DECRYPT_ZIGZAG_H_INCLUDED
#define DECRYPT_ZIGZAG_H_INCLUDED

/**
 * ----------------------------------------------------------------
 * WELCOME TO GEOMETRIC TRANSPOSITIONS!
 * ----------------------------------------------------------------
 * Transposition with Zigzag Decryptor
 * ----------------------------------------------------------------
 * @author David Gomesh
 * ----------------------------------------------------------------
 * *** This file is in UTF-8 codification! ***
 * ----------------------------------------------------------------
*/

#include <string.h>
#include <math.h>

void decryptZigzag(char encryptedText[]){
    int lengthText = strlen(encryptedText);
    char auxiliaryText[lengthText];

    int linesCount, columnsCount;

    //Calculate Matrix Sizes
    int squareRootLengthText = (int)sqrt(lengthText);

    linesCount = columnsCount = squareRootLengthText;
    while(columnsCount * linesCount < lengthText){
        linesCount++;
    }

    char matrix[linesCount][columnsCount];

    //Check Possible Fields
    char state = 'r'; //r = rigth, l = left
    for(int i=0, k=0; i<linesCount; i++){
        if(state == 'r'){
            for(int j=0; j<columnsCount; j++){
                if(k++ < lengthText){
                    matrix[i][j] = '@';
                }
                else{
                    matrix[i][j] = '-';
                }
            }

            state = 'l';
        }
        else{
            for(int j=columnsCount-1; j>=0; j--){
                if(k++ < lengthText){
                    matrix[i][j] = '@';
                }
                else{
                    matrix[i][j] = '-';
                }
            }

            state = 'r';
        }
    }

    //Input
    for(int j=0, k=0; j<columnsCount; j++){
        for(int i=0; i<linesCount; i++){
            if(matrix[i][j] != '-'){
                matrix[i][j] = encryptedText[k++];
            }
        }
    }

    //Output
    int k=0;
    state = 'r';
    for(int i=0; i<linesCount; i++){
        if(state == 'r'){
            for(int j=0; j<columnsCount; j++){
                if(k < lengthText && matrix[i][j] != '-'){
                    auxiliaryText[k++] = matrix[i][j];
                }
            }

            state = 'l';
        }
        else{
            for(int j=columnsCount-1; j>=0; j--){
                if(k < lengthText && matrix[i][j] != '-'){
                    auxiliaryText[k++] = matrix[i][j];
                }
            }

            state = 'r';
        }
    }

    //Return
    auxiliaryText[k] = '\0';

    strcpy(encryptedText, auxiliaryText);
}

#endif /* DECRYPT_ZIGZAG_H_INCLUDED */