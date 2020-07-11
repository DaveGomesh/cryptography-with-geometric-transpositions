#include <stdio.h>
#include <string.h>

void simpleLinear(char text[], int linesCount){
    int lengthText = strlen(text);
    char auxText[lengthText];
    int columnsCount;

    if(lengthText % linesCount == 0){
        columnsCount = lengthText / linesCount;
    }else{
        columnsCount = lengthText / linesCount + 1;
    }

    char matrix[linesCount][columnsCount];

    for(int j=0, k=0; j<columnsCount; j++){
        for(int i=0; i<linesCount; i++){
            if(k < lengthText){
                matrix[i][j] = text[k++];
            }else{
                matrix[i][j] = '-';
            }
        }
    }

    int k=0;
    for(int i=0; i<linesCount; i++){
        for(int j=0; j<columnsCount; j++){
            if(matrix[i][j] != '-'){
                auxText[k++] = matrix[i][j];
            }
        }
    }

    auxText[k] = '\0';

    strcpy(text, auxText);
}