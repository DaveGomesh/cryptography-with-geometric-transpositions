#include "encrypt-text.h"
#include "decrypt-text.h"
#include "set-texts.h"
#include "show-texts.h"

int main(){
    int option;

    do{
        system("cls");

        printf("Cryptography with Geometric Transposition\n\n");

        printf("1 - Encrypt Text\n");
        printf("2 - Decrypt Text\n");
        printf("3 - Set texts\n");
        printf("4 - Show Texts in the files\n");
        printf("0 - Exit\n\n");

        printf("OPTION: ");
        scanf("%i", &option);
        setbuf(stdin, NULL);

        switch(option){
            case 1:
                encryptText();
                break;

            case 2:
                decryptText();
                break;

            case 3:
                setTexts();
                break;

            case 4:
                showTexts();
                break;
            
            case 0:
                printf("\n\nExiting...\n\n");
                system("pause");
                break;
            
            default:
                printf("\n\nInvalid option!\n\n");
                system("pause");
                break;
        }

    }while(option < 0 || option > 3 || option != 0);

    return 0;
}




