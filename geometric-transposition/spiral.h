#include <string.h>
#include <math.h>

#include <stdio.h>

void spiral(char text[]){
    int lengthText = strlen(text);
    char auxText[lengthText];

    int linesCount, columnsCount;

    int squareRootLengthText = (int)sqrt(lengthText);

    linesCount = columnsCount = squareRootLengthText;
    while(columnsCount * linesCount < lengthText){
        linesCount++;
    }

    char matrix[linesCount][columnsCount];

    for(int i=0; i<linesCount; i++){
        for(int j=0; j<columnsCount; j++){
            matrix[i][j] = '-';
        }
    }

    int i=0, j=0, k=0;
    char state = 'r'; //u = up, r = right, d = down, l = left

    // The first position is the limit in the up, and the second position is the limit in the bottom
    int verticalLimit[2]={1, linesCount-1};
    // The first position is the limit in the left, and the second position is the limit in the right
    int horizontalLimit[2]={0, columnsCount-1};
    while(k<lengthText){
        switch(state){
            case 'r':
                while(j<=horizontalLimit[1] && k<lengthText){
                    matrix[i][j++] = text[k++];
                }
                j--;
                i++;
                horizontalLimit[1]--;
                state = 'd';
                break;
            
            case 'd':
                while(i<=verticalLimit[1] && k<lengthText){
                    matrix[i++][j] = text[k++];
                }
                i--;
                j--;
                verticalLimit[1]--;
                state = 'l';
                break;
            
            case 'l':
                while(j>=horizontalLimit[0] && k<lengthText){
                    matrix[i][j--] = text[k++];
                }
                j++;
                i--;
                horizontalLimit[0]++;
                state = 'u';
                break;

            case 'u':
                while(i>=verticalLimit[0] && k<lengthText){
                    matrix[i--][j] = text[k++];
                }
                i++;
                j++;
                verticalLimit[0]++;
                state = 'r';
                break;
        }
    }

    k=0;
    int currentLine = 0, currentColumn = 1;
    while(k<lengthText){
        
        if(currentLine < linesCount){
            for(i=currentLine, j=0; i>=0 && j < columnsCount; i--, j++){
                if(matrix[i][j] != '-'){
                    auxText[k++] = matrix[i][j];
                }
            }
            currentLine++;
        }
        else{
            for(i=currentLine-1, j=currentColumn; j<columnsCount; i--, j++){
                if(matrix[i][j] != '-'){
                    auxText[k++] = matrix[i][j];
                }
            }
            currentColumn++;
        }
    }

    auxText[k] = '\0';

    strcpy(text, auxText);
}