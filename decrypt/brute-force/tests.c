#include <stdio.h>

int main(){
    int number = 6;
    double fact=1;

    for(int i=1; i<=number; i++){
        fact *= i;
    }

    printf("Factorial %lf\n", fact);

    return 0;
}