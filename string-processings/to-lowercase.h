#ifndef TO_LOWERCASE_H_INCLUDED
#define TO_LOWERCASE_H_INCLUDED

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

void toLowercase(char text[]){
    int lengthText = strlen(text);
    char auxiliaryText[lengthText];

    strcpy(auxiliaryText, text);

    for(int i=0; i<lengthText; i++){
        int character = text[i];

        if(character >= 65 && character <= 90){
            auxiliaryText[i] = character + 32;
            continue;
        }

        switch (character){
            //A Family
            case -114:
                auxiliaryText[i] = -124;
                break;
            
            case -113:
                auxiliaryText[i] = -122;
                break;
            
            case -75:
                auxiliaryText[i] = -96;
                break;
            
            case -74:
                auxiliaryText[i] = -125;
                break;
            
            case -73:
                auxiliaryText[i] = -123;
                break;
            
            case -57:
                auxiliaryText[i] = -58;
                break;
            //

            //C Family
            case -128:
                auxiliaryText[i] = -121;
                break;
            //
            
            //E Family
            case -112:
                auxiliaryText[i] = -126;
                break;
            
            case -46:
                auxiliaryText[i] = -120;
                break;
            
            case -45:
                auxiliaryText[i] = -119;
                break;
            
            case -44:
                auxiliaryText[i] = -118;
                break;
            //

            //I family
            case -42:
                auxiliaryText[i] = -95;
                break;
            
            case -41:
                auxiliaryText[i] = -116;
                break;
            
            case -40:
                auxiliaryText[i] = -117;
                break;
            
            case -34:
                auxiliaryText[i] = -115;
                break;
            //

            //N Family
            case -91:
                auxiliaryText[i] = -92;
                break;
            //

            //O Family
            case -103:
                auxiliaryText[i] = -108;
                break;
            
            case -32:
                auxiliaryText[i] = -94;
                break;
            
            case -30:
                auxiliaryText[i] = -109;
                break;
            
            case -29:
                auxiliaryText[i] = -107;
                break;
            
            case -27:
                auxiliaryText[i] = -28;
                break;
            //

            //U Family
            case -102:
                auxiliaryText[i] = -127;
                break;
            
            case -23:
                auxiliaryText[i] = -93;
                break;
            
            case -22:
                auxiliaryText[i] = -106;
                break;
            
            case -21:
                auxiliaryText[i] = -105;
                break;
            //

            //Y Family
            case -19:
                auxiliaryText[i] = -20;
                break;
            //      
        }

    }

    strcpy(text, auxiliaryText);
}

#endif