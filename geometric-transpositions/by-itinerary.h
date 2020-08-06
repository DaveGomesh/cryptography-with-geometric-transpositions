#ifndef BY_ITINERARY_H_INCLUDED
#define BY_ITINERARY_H_INCLUDED

/**
 * ----------------------------------------------------------------
 * WELCOME TO GEOMETRIC TRANSPOSITIONS!
 * ----------------------------------------------------------------
 * Transposition by Itinerary
 * ----------------------------------------------------------------
 * @author David Gomesh
 * ----------------------------------------------------------------
 * *** This file is in UTF-8 codification! ***
 * ----------------------------------------------------------------
*/

#include <string.h>

void byItinerary(char text[], int linesCount){
    int lengthText = strlen(text);
    int columnsCount = lengthText;
    char auxiliaryText[lengthText];
    char matrix[linesCount][columnsCount];
    
    char state = 'd'; //u = up and d = down
    for(int i=0, j=0; j<lengthText; j++){
        matrix[i][j] = text[j];

        for(int k=0; k<linesCount; k++){
            if(k != i){
                matrix[k][j] = '-';
            }
        }

        if(state == 'd'){
            if(i == linesCount-1){
                state = 'u';
                i--;
                continue;
            }else{
                i++;
            }
        }

        if(state == 'u'){
            if(i == 0){
                state = 'd';
                i++;
                continue;
            }
            else{
                i--;
            }
        }
    }

    int k=0;
    for(int i=0; i<linesCount; i++){
        for(int j=0; j<columnsCount; j++){
            if(matrix[i][j] != '-'){
                auxiliaryText[k++] = matrix[i][j];
            }
        }
    }

    auxiliaryText[k] = '\0';
    
    strcpy(text, auxiliaryText);
}

#endif /* BY_ITINERARY_H_INCLUDED */