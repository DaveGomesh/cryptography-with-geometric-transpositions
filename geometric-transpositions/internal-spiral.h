#include <string.h>
#include <math.h>

void internalSpiral(char text[]){
    int lengthText = strlen(text);
    char auxText[lengthText];
    
    int linesCount, columnsCount;

    int squareRootLengthText = (int)sqrt(lengthText);

    linesCount = columnsCount = squareRootLengthText;
    while(columnsCount * linesCount < lengthText){
        linesCount++;
    }

    if(linesCount < columnsCount){
        linesCount = columnsCount;
    }
    else if(columnsCount < linesCount){
        columnsCount = linesCount;
    }

    if(linesCount%2==0){
        linesCount++;
        columnsCount++;
    }

    if((linesCount - 2)*(columnsCount-2) >= lengthText){
        linesCount -= 2;
        columnsCount -= 2;
    }

    char matrix[linesCount][columnsCount];

    for(int i=0; i<linesCount; i++){
        for(int j=0; j<columnsCount; j++){
            matrix[i][j] = '-';
        }
    }

    int verticalMiddle = (linesCount - 1) / 2;
    int horizontalMiddle = (columnsCount - 1) / 2;

    int i=verticalMiddle, j=horizontalMiddle, k=0;
    char state = 'r'; //u = up, r = right, d = down, l = left

    //The first position is the limit in the up, and the second position is the limit in the bottom
    int verticalLimit[2] = {verticalMiddle-1, verticalMiddle+1};
    //The first position is the limit in the left, and the second position is the limit in the right
    int horizontalLimit[2] = {horizontalMiddle-1, horizontalMiddle+1};

    while(k<lengthText){
        switch(state){
            case 'r':
                while(j<=horizontalLimit[1] && k<lengthText){
                    matrix[i][j++] = text[k++];
                }

                i++;
                j--;
                horizontalLimit[1]++;
                state = 'd';
                break;

            case 'd':
                while(i<=verticalLimit[1] && k<lengthText){
                    matrix[i++][j] = text[k++];
                }

                i--;
                j--;
                verticalLimit[1]++;
                state = 'l';
                break;

            case 'l':
                while(j>=horizontalLimit[0] && k<lengthText){
                    matrix[i][j--] = text[k++];
                }

                j++;
                i--;
                horizontalLimit[0]--;
                state = 'u';
                break;

            case 'u':
                while(i>=verticalLimit[0] && k<lengthText){
                    matrix[i--][j] = text[k++];
                }

                i++;
                j++;
                verticalLimit[0]--;
                state = 'r';
                break;
        }
    }

    k=0;
    int currentLine = linesCount-1, currentColumn = 1;
    while(k<lengthText){
        
        if(currentLine >= 0){
            for(i=currentLine, j=0; i<linesCount && j < columnsCount; i++, j++){
                if(matrix[i][j] != '-'){
                    auxText[k++] = matrix[i][j];
                }
            }
            currentLine--;
        }
        else{
            for(i=0, j=currentColumn; j<columnsCount; i++, j++){
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