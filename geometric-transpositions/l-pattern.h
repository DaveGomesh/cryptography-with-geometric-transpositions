#include <string.h>
#include <math.h>

void lPattern(char text[]){
    int lengthText = strlen(text);
    char auxText[lengthText];

    int linesCount, columnsCount;

    int squareRootLengthText = (int)sqrt(lengthText);

    linesCount = columnsCount = squareRootLengthText;
    while(columnsCount * linesCount < lengthText){
        columnsCount++;
    }

    char matrix[linesCount][columnsCount];

    for(int i=0; i<linesCount; i++){
        for(int j=0; j<columnsCount; j++){
            matrix[i][j] = '-';
        }
    }

    int i=0, j=0, k=0;
    char state = 'd'; //u = up, r = right, d = down, l = left


    int inputVerticalLimit = linesCount-1;
    int inputHorizontalLimit = 0;

    while (k<lengthText){
        switch (state){
            case 'd':
                while(i<=inputVerticalLimit && k<lengthText){
                    matrix[i++][j] = text[k++];
                }

                i--;
                j++;
                state = 'R';
                inputHorizontalLimit++;
                break;

            case 'R':
                while (j<=columnsCount-1 && k<lengthText){
                    matrix[i][j++] = text[k++];
                }
                
                j--;
                i--;
                state = 'u';
                inputVerticalLimit--;
                break;
            
            case 'u':
                matrix[i][j--] = text[k++];
                state = 'l';
                break;

            case 'l':
                while (j>=inputHorizontalLimit && k<lengthText){
                    matrix[i][j--] = text[k++];
                }

                j++;
                i--;
                state = 'U'; 
                inputVerticalLimit--;              
                break;

            case 'U':
                while (i>=0 && k<lengthText){
                    matrix[i--][j] = text[k++];
                }

                i++;
                j++;
                state = 'r';
                inputHorizontalLimit++;             
                break;

            case 'r':
                matrix[i++][j] = text[k++];
                state = 'd';
                break;
        }
    }

    i = 0;
    j = 0;
    k = 0;
    state = 'r'; //u = up, r = right, d = down, l = left

    // The first position is the limit in the up, and the second position is the limit in the bottom
    int outputVerticalLimit[2] = {1, linesCount-1};
    // The first position is the limit in the left, and the second position is the limit in the right
    int outputHorizontalLimit[2] = {0, columnsCount-1};
    
    while(k<lengthText){
        switch(state){
            case 'r':
                while(j<=outputHorizontalLimit[1] && k<lengthText){
                    if(matrix[i][j] != '-'){
                        auxText[k++] = matrix[i][j++];
                    }
                    else{
                        j++;
                    }
                }
                j--;
                i++;
                outputHorizontalLimit[1]--;
                state = 'd';
                break;
            
            case 'd':
                while(i<=outputVerticalLimit[1] && k<lengthText){
                    if(matrix[i][j] != '-'){
                        auxText[k++] = matrix[i++][j];
                    }
                    else{
                        i++;
                    }
                }
                i--;
                j--;
                outputVerticalLimit[1]--;
                state = 'l';
                break;
            
            case 'l':
                while(j>=outputHorizontalLimit[0] && k<lengthText){
                    if(matrix[i][j] != '-'){
                        auxText[k++] = matrix[i][j--];
                    }
                    else{
                        j--;
                    }
                }
                j++;
                i--;
                outputHorizontalLimit[0]++;
                state = 'u';
                break;

            case 'u':
                while(i>=outputVerticalLimit[0] && k<lengthText){
                    if(matrix[i][j] != '-'){
                        auxText[k++] = matrix[i--][j];
                    }
                    else{
                        i--;
                    }
                }
                i++;
                j++;
                outputVerticalLimit[0]++;
                state = 'r';
                break;
        }
    }

    auxText[k] = '\0';

    strcpy(text, auxText);
}