#include <string.h>
#include <stdio.h>

void simpleColumnar(char text[], int columnCount){
    int lengthText = strlen(text);
    char auxText[lengthText];
    int lineCount;

    if(lengthText % columnCount == 0){
        lineCount = lengthText / columnCount;
    }
    else{
        lineCount = lengthText / columnCount + 1;
    }

    printf("Size matrix: %i %i\n", lineCount, columnCount);
    char matriz[lineCount][columnCount];

    for(int i=0, k=0; i<lineCount; i++){
        for(int j=0; j<columnCount; j++){
            if(k < lengthText){
                matriz[i][j] = text[k++];
            }else{
                matriz[i][j] = '-';
            }
        }
    }

    for(int j=0, k=0; j<columnCount; j++){
        for(int i=0; i<lineCount; i++){
            if(matriz[i][j] != '-'){
                auxText[k++] = matriz[i][j];
            }
        }
    }

    // strcpy(text, "");
    strcpy(text, auxText);

    // Show Simple Columnar
    for(int i=0; i<lineCount; i++){
        for(int j=0; j<columnCount; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }

}