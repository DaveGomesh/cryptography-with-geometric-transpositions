#include <stdio.h>
#include "process-strings.h"
#include "simple-columnar.h"

int main(){
    char text[250];
    printf("Insert a text: ");
    fgets(text, 250, stdin);
    printf("Initial text: %s", text);
    removeInvalidCharacters(text);
    simpleColumnar(text, 6);
    printf("Final text: %s\n", text);
    return 0;
}