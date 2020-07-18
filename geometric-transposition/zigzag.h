#include <string.h>
#include <math.h>

#include <stdio.h>

void zigzag(char text[]){
    int lengthText = strlen(text);
    char auxText[lengthText];

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
                auxText[k++] = matrix[i][j];                
            }
        }
    }

    auxText[k] = '\0';

    strcpy(text, auxText);
}