#ifndef TO_UPPERCASE_H_INCLUDED
#define TO_UPPERCASE_H_INCLUDED

/**
 * ----------------------------------------------------
 * Convert to Lowercase:
 * -> Leaves all lowercase letters.
 * ----------------------------------------------------
 * @author: David Gomesh
 * ----------------------------------------------------
 * *** The file is in UTF-8 codification! ***
 * ----------------------------------------------------
*/

#include <string.h>

void toUppercase(char text[]){
    int lengthText = strlen(text);
    char auxiliaryText[lengthText];

    strcpy(auxiliaryText, text);

    for(int i=0; i<lengthText; i++){
        int character = text[i];

        if(character >= 97 && character <= 122){
            auxiliaryText[i] = character - 32;
            continue;
        }

        switch (character){
            //A Family
            case -124:
                auxiliaryText[i] = -114;
                break;
            
            case -122:
                auxiliaryText[i] = -113;
                break;
            
            case -96:
                auxiliaryText[i] = -75;
                break;
            
            case -125:
                auxiliaryText[i] = -74;
                break;
            
            case -123:
                auxiliaryText[i] = -73;
                break;
            
            case -58:
                auxiliaryText[i] = -57;
                break;
            //

            //C Family
            case -121:
                auxiliaryText[i] = -128;
                break;
            //

            //E Family
            case -126:
                auxiliaryText[i] = -112;
                break;
            
            case -120:
                auxiliaryText[i] = -46;
                break;
            
            case -119:
                auxiliaryText[i] = -45;
                break;
            
            case -118:
                auxiliaryText[i] = -44;
                break;
            //

            //I family
            case -95:
                auxiliaryText[i] = -42;
                break;
            
            case -116:
                auxiliaryText[i] = -41;
                break;
            
            case -117:
                auxiliaryText[i] = -40;
                break;
            
            case -115:
                auxiliaryText[i] = -34;
                break;
            
            case -43:
                auxiliaryText[i] = 73;//Normal I
                break;
            //

            //N Family
            case -92:
                auxiliaryText[i] = -91;
                break;
            //

            //O Family
            case -108:
                auxiliaryText[i] = -103;
                break;
            
            case -94:
                auxiliaryText[i] = -32;
                break;
            
            case -109:
                auxiliaryText[i] = -30;
                break;
            
            case -107:
                auxiliaryText[i] = -29;
                break;
            
            case -28:
                auxiliaryText[i] = -27;
                break;
            //

            //U Family
            case -127:
                auxiliaryText[i] = -102;
                break;
            
            case -93:
                auxiliaryText[i] = -23;
                break;
            
            case -106:
                auxiliaryText[i] = -22;
                break;
            
            case -105:
                auxiliaryText[i] = -21;
                break;
            //

            //Y Family
            case -20:
                auxiliaryText[i] = -19;
                break;
            
            case -104:
                auxiliaryText[i] = 89;//Normal Y
                break;
            //      
        }

    }

    strcpy(text, auxiliaryText);
}

#endif