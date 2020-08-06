/**================================================================
#include <string.h>

void columnarWithNumericKey(char text[], char key[]){
    int lengthText = strlen(text), lengthKey = strlen(key);
    int positions[lengthKey];
    char auxText[lengthText];

    int linesCount, columnsCount = lengthKey;

    for(int upper=65, lower=97, value=1; upper<=90 && lower<=122; upper++, lower++){
        for(int i=0; i<lengthKey; i++){
            if(key[i]==upper || key[i]==lower){
                positions[i] = value++;
            }
        }
    }

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
    for(int value=1; value<=lengthKey; value++){
        for(int l=0; l<lengthKey; l++){
            if(positions[l]==value){
                for(int i=0, j=l; i<linesCount; i++){
                    if(matrix[i][j] != '-'){
                        auxText[k++] = matrix[i][j];
                    }
                }
                break;
            }
        }
    }

    auxText[k] = '\0';
    
    strcpy(text, auxText);
}