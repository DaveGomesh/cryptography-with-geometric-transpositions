#ifndef L_PATTERN_H_INCLUDED
#define L_PATTERN_H_INCLUDED

/**
 * ----------------------------------------------------------------
 * WELCOME TO GEOMETRIC TRANSPOSITIONS!
 * ----------------------------------------------------------------
 * Transposition with 'L' Pattern Decryptor
 * ----------------------------------------------------------------
 * @author David Gomesh
 * ----------------------------------------------------------------
 * *** This file is in UTF-8 codification! ***
 * ----------------------------------------------------------------
*/

#include <string.h>
#include <math.h>

void decryptLPattern(char encryptedText[]){
    int lengthText = strlen(encryptedText);
    char auxiliaryText[lengthText];

    int linesCount, columnsCount;

    //Calculate Matrix Sizes
    int squareRootLengthText = (int)sqrt(lengthText);

    linesCount = columnsCount = squareRootLengthText;
    while(columnsCount * linesCount < lengthText){
        columnsCount++;
    }

    char matrix[linesCount][columnsCount];

    //Checks Possible Fields
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
                while(i<=inputVerticalLimit && k++<lengthText){
                    matrix[i++][j] = '@';
                }

                i--;
                j++;
                state = 'R';
                inputHorizontalLimit++;
                break;

            case 'R':
                while (j<=columnsCount-1 && k++<lengthText){
                    matrix[i][j++] = '@';
                }
                
                j--;
                i--;
                state = 'u';
                inputVerticalLimit--;
                break;
            
            case 'u':
                matrix[i][j--] = '@';
                state = 'l';
                k++;
                break;

            case 'l':
                while (j>=inputHorizontalLimit && k++<lengthText){
                    matrix[i][j--] = '@';
                }

                j++;
                i--;
                state = 'U'; 
                inputVerticalLimit--;              
                break;

            case 'U':
                while (i>=0 && k++<lengthText){
                    matrix[i--][j] = '@';
                }

                i++;
                j++;
                state = 'r';
                inputHorizontalLimit++;             
                break;

            case 'r':
                matrix[i++][j] = '@';
                state = 'd';
                k++;
                break;
        }
    }

    //Input
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
                        matrix[i][j++] = encryptedText[k++];
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
                        matrix[i++][j] = encryptedText[k++];
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
                        matrix[i][j--] = encryptedText[k++];
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
                        matrix[i--][j] = encryptedText[k++];
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

    //Output
    i=0;
    j=0;
    k=0;
    state = 'd';

    inputVerticalLimit = linesCount-1;
    inputHorizontalLimit = 0;

    while (k<lengthText){
        switch (state){
            case 'd':
                while(i<=inputVerticalLimit && k<lengthText){
                    auxiliaryText[k++] = matrix[i++][j];
                }

                i--;
                j++;
                state = 'R';
                inputHorizontalLimit++;
                break;

            case 'R':
                while (j<=columnsCount-1 && k<lengthText){
                    auxiliaryText[k++] = matrix[i][j++];
                }
                
                j--;
                i--;
                state = 'u';
                inputVerticalLimit--;
                break;
            
            case 'u':
                auxiliaryText[k++] = matrix[i][j--];
                state = 'l';
                break;

            case 'l':
                while (j>=inputHorizontalLimit && k<lengthText){
                    auxiliaryText[k++] = matrix[i][j--];
                }

                j++;
                i--;
                state = 'U'; 
                inputVerticalLimit--;              
                break;

            case 'U':
                while (i>=0 && k<lengthText){
                    auxiliaryText[k++] = matrix[i--][j];
                }

                i++;
                j++;
                state = 'r';
                inputHorizontalLimit++;             
                break;

            case 'r':
                auxiliaryText[k++] = matrix[i++][j];
                state = 'd';
                break;
        }
    }

    //Return
    auxiliaryText[k] = '\0';

    strcpy(encryptedText, auxiliaryText);
}

#endif /* L_PATTERN_H_INCLUDED */