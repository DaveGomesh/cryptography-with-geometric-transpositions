#include <string.h>

void onlyLetters(char text[]){
    int lengthText = strlen(text);
    char auxiliaryText[lengthText];

    strcpy(auxiliaryText, text);

    int k=0;
    for(int i=0; i<lengthText; i++){
        int character = text[i];

        if((character >= 65 && character <= 90) || (character >= 97 && character <= 122)){
            auxiliaryText[k++] = character;
        }
    }

    auxiliaryText[k] = '\0';

    strcpy(text, auxiliaryText);
}