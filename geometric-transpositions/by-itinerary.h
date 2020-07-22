#include <string.h>

void byItinerary(char text[], int linesCount){
    int lengthText = strlen(text);
    int columnCount = lengthText;
    char auxText[lengthText];
    char matrix[linesCount][columnCount];
    
    
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
        for(int j=0; j<columnCount; j++){
            if(matrix[i][j] != '-'){
                auxText[k++] = matrix[i][j];
            }
        }
    }

    auxText[k] = '\0';
    
    strcpy(text, auxText);
}