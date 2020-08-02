#ifndef REMOVE_INVALID_CHARACTERS_H_INCLUDED
#define REMOVE_INVALID_CHARACTERS_H_INCLUDED

/**
 * -------------------------------------------------------------
 * Remove Invalid Characters:
 * -> Remove all characters that aren't letters or numbers.
 * -------------------------------------------------------------
 * @author: David Gomesh
 * -------------------------------------------------------------
 * *** The file is in UTF-8 codification! ***
 * -------------------------------------------------------------
*/

#include <string.h>

void removeInvalidCharacters(char text[]){
    int lengthText = strlen(text);
    char auxiliaryText[lengthText];

    int k=0;
    for(int i=0; i<lengthText; i++){
        int character = text[i];
        if (
            /*Negative side*/
            (character >= -208 && character <= -199)

            || (character >= -191 && character <= -166)

            || (character >= -159 && character <= -134)

            || (character >= -128 && character <= -111)

            || (character >= -109 && character <= -102)

            || (character >= -96 && character <= -91)

            || (character >= -75 && character <= -73)

            || (character >= -58 && character <= -57)

            || (character >= -46 && character <= -40)
            
            || (character == -34)

            || (character == -32)

            || (character == -31) //eszett or scharfes S

            || (character >= -30 && character <= -27)

            || (character >= -23 && character <= -19)

            || (character >= -5 && character <= -3)

            /*Positive side*/
            || (character >= 48 && character <= 57)

            || (character >= 65 && character <= 90)

            || (character >= 97 && character <= 122)
            
            || (character >= 128 && character <= 144)

            || (character >= 147 && character <= 154)

            || (character >= 160 && character <= 165)

            || (character >= 181 && character <= 183)

            || (character >= 198 && character <= 199)

            || (character >= 210 && character <= 216)

            || (character == 222)

            || (character == 224)

            || (character == 225) //eszett or scharfes S

            || (character >= 226 && character <= 229)

            || (character >= 233 && character <= 237)

            || (character >= 251 && character <= 253)
        ){
            auxiliaryText[k++] = character;
        }
    }

    auxiliaryText[k] = '\0';

    strcpy(text, auxiliaryText);
}

#endif