#ifndef DECRYPT_TRIANGULAR_H_INCLUDED
#define DECRYPT_TRIANGULAR_H_INCLUDED

/**
 * ----------------------------------------------------------------
 * WELCOME TO GEOMETRIC TRANSPOSITIONS!
 * ----------------------------------------------------------------
 * Triangular Transposition Decryptor
 * ----------------------------------------------------------------
 * @author David Gomesh
 * ----------------------------------------------------------------
 * *** This file is in UTF-8 codification! ***
 * ----------------------------------------------------------------
*/

#include <string.h>

void decryptTriangular(char encryptedText[]){
    int lengthText = strlen(encryptedText);
    char auxiliaryText[lengthText];

    int linesCount=1, columnsCount;

    //Calculate Matrix Sizes
    int maxCharMatrix=1;
    int maxCharLastLine=1;

    while(maxCharMatrix < lengthText){
        maxCharLastLine+=2;
        maxCharMatrix+=maxCharLastLine;
        linesCount++;
    }

    columnsCount = maxCharLastLine;

    char matrix[linesCount][columnsCount];

    //Checks Possible Fields
    /*
        i = Matrix Line Index
        j = Valid Matrix Column Index
        l = Matrix Column Index
        k = String Index
    */
    int maxCharCurrentLine = 1;
    for(int i=0, k=0; i<linesCount; i++, maxCharCurrentLine+=2){
        for(int j=(columnsCount/2)-i, l=0, quant=0; l<columnsCount; l++){
            if(l!=j || k++>=lengthText){
                matrix[i][l] = '-';
            }else{
                matrix[i][j++] = '@';
                quant++;
                if(quant>=maxCharCurrentLine){
                    j=-1;
                }
            }
        }
    }
    
    //Input
    int k=0;
    for(int j=0; j<columnsCount; j++){
        for(int i=0; i<linesCount; i++){
            if(matrix[i][j] != '-'){
                matrix[i][j] = encryptedText[k++];
            }
        }
    }

    //Output
    maxCharCurrentLine = 1;
    for(int i=0, k=0; i<linesCount; i++, maxCharCurrentLine+=2){
        for(int j=(columnsCount/2)-i, l=0, quant=0; l<columnsCount; l++){
            if(!(l!=j || k>=lengthText)){
                auxiliaryText[k++] = matrix[i][j++];
                quant++;
                if(quant>=maxCharCurrentLine){
                    j=-1;
                }
            }
        }
    }

    //Return
    auxiliaryText[k] = '\0';

    strcpy(encryptedText, auxiliaryText);
}

#endif /* DECRYPT_TRIANGULAR_H_INCLUDED */