#include <string.h>

void onlyNumbers(char text[]){
    int lengthText = strlen(text);
    char auxiliaryText[lengthText];

    strcpy(auxiliaryText, text);

    int k=0;
    for(int i=0; i<lengthText; i++){
        int character = text[i];

        if(character >= 48 && character <= 57){
            auxiliaryText[k++] = character;
        }
    }
    
    auxiliaryText[k] = '\0';

    strcpy(text, auxiliaryText);
}