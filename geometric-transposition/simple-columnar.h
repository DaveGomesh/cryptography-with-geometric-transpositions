#include <string.h>

void simpleColumnar(char text[], int columnsCount){
    int lengthText = strlen(text);
    char auxText[lengthText];
    int linesCount;

    if(lengthText % columnsCount == 0){
        linesCount = lengthText / columnsCount;
    }else{
        linesCount = lengthText / columnsCount + 1;
    }

    char matrix[linesCount][columnsCount];

    for(int i=0, k=0; i<linesCount; i++){
        for(int j=0; j<columnsCount; j++){
            if(k < lengthText){
                matrix[i][j] = text[k++];
            }else{
                matrix[i][j] = '-';
            }
        }
    }

    int k=0;
    for(int j=0; j<columnsCount; j++){
        for(int i=0; i<linesCount; i++){
            if(matrix[i][j] != '-'){
                auxText[k++] = matrix[i][j];                
            }
        }
    }

    auxText[k] = '\0';

    strcpy(text, auxText);
}