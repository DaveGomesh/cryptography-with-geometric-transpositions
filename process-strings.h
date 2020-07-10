#include <string.h>
#include <ctype.h>

void removeInvalidCharacters(char text[]){
    int lengthText = strlen(text);
    char auxText[lengthText];
    
    int j=0;
    for(int i=0; i<lengthText; i++){
        if(isalnum(text[i])){
            auxText[j++] = text[i];
        }
    }

    strcpy(text, "");
    auxText[j] = '\0';

    strcpy(text, auxText);
}