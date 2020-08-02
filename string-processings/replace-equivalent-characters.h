#ifndef REPLACE_EQUIVALENT_CHARACTERS_H_INCLUDED
#define REPLACE_EQUIVALENT_CHARACTERS_H_INCLUDED

/**
 * ----------------------------------------------------------------
 * Replace Equivalent Characters:
 * -> Exchange accented characters for non-accented characters.
 * ----------------------------------------------------------------
 * @author: David Gomesh
 * ----------------------------------------------------------------
 * *** The file is in UTF-8 codification! ***
 * ----------------------------------------------------------------
*/

#include <string.h>

void replaceEquivalentCharacters(char text[]){
    int lengthText = strlen(text);
    char auxiliaryText[lengthText];
    
    strcpy(auxiliaryText, text);

    for(int i=0; i<lengthText; i++){
        int character = text[i];
        switch (character){

            case -5:
            case 251:
                auxiliaryText[i] = '1';
                break;

            case -3:
            case 253:
                auxiliaryText[i] = '2';
                break;

            case -4:
            case 252:
                auxiliaryText[i] = '3';
                break;

            case -114:
            case -113:
            case -75:
            case -74:
            case -73:
            case -57:
            case 142:
            case 143:
            case 181:
            case 182:
            case 183:
            case 199:
                auxiliaryText[i] = 'A';
                break;
            
            case -125:
            case -124:
            case -123:
            case -122:
            case -96:
            case -58:
            case 131:
            case 132:
            case 133:
            case 134:
            case 160:
            case 198:
                auxiliaryText[i] = 'a';
                break;

            case -128:
            case 128:
                auxiliaryText[i] = 'C';
                break;

            case -121:
            case 135:
                auxiliaryText[i] = 'c';
                break;

            case -112:
            case -46:
            case -45:
            case -44:
            case 144:
            case 210:
            case 211:
            case 212:
                auxiliaryText[i] = 'E';
                break;

            case -126:
            case -120:
            case -119:
            case -118:
            case 130:
            case 136:
            case 137:
            case 138:
                auxiliaryText[i] = 'e';
                break;

            case -42:
            case -41:
            case -40:
            case -34:
            case 214:
            case 215:
            case 216:
            case 222:
                auxiliaryText[i] = 'I';
                break;

            case -117:
            case -116:
            case -115:
            case -95:
            case -43:
            case 139:
            case 140:
            case 141:
            case 161:
            case 213:
                auxiliaryText[i] = 'i';
                break;

            case -91:
            case 165:
                auxiliaryText[i] = 'N';
                break;

            case -92:
            case 164:
                auxiliaryText[i] = 'n';
                break;

            case -103:
            case -32:
            case -30:
            case -29:
            case -27:
            case 153:
            case 224:
            case 226:
            case 227:
            case 229:
                auxiliaryText[i] = 'O';
                break;

            case -109:
            case -108:
            case -107:
            case -94:
            case -28:
            case 147:
            case 148:
            case 149:
            case 162:
            case 228:
                auxiliaryText[i] = 'o';
                break;

            case -31: 
            case 225:
                auxiliaryText[i] = 's'; //eszett or scharfes S
                break;

            case -102:
            case -23:
            case -22:
            case -21:
            case 154:
            case 233:
            case 234:
            case 235:
                auxiliaryText[i] = 'U';
                break;

            case -127:
            case -106:
            case -105:
            case -93:
            case 129:
            case 150:
            case 151:
            case 163:
                auxiliaryText[i] = 'u';
                break;

            case -19:
            case 237:
                auxiliaryText[i] = 'Y';
                break;

            case -104:
            case -20:
            case 152:
            case 236:
                auxiliaryText[i] = 'y';
                break;
        }
    }

    strcpy(text, auxiliaryText);
}

#endif