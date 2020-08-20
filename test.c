#include <stdio.h>
#include <stdlib.h>

#include "string-processings/remove-invalid-characters.h"
#include "string-processings/replace-equivalent-characters.h"

#include "geometric-transpositions/l-pattern.h"
#include "decrypt/decryptor-algorithm/decrypt-l-pattern.h"

int main(){
    char text[50];

    fgets(text, 50, stdin);

    removeInvalidCharacters(text);
    replaceEquivalentCharacters(text);

    lPattern(text);

    printf("Encrypted Text: %s\n", text);

    decryptLPattern(text);

    printf("Decrypted Text: %s\n", text);

    return 0;
}