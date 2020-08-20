#include <stdio.h>

#include "geometric-transpositions/simple-linear.h"
#include "geometric-transpositions/simple-columnar.h"
#include "geometric-transpositions/linear-with-numeric-key.h"
#include "geometric-transpositions/by-itinerary.h"
#include "geometric-transpositions/triangular.h"
#include "geometric-transpositions/external-spiral.h"
#include "geometric-transpositions/internal-spiral.h"
#include "geometric-transpositions/zigzag.h"
#include "geometric-transpositions/l-pattern.h"

#include "string-processings/remove-invalid-characters.h"
#include "string-processings/replace-equivalent-characters.h"
#include "string-processings/to-lowercase.h"
#include "string-processings/to-uppercase.h"

#include <stdlib.h>
#include <stdarg.h> 

void variableArgs(int num, ...){
    va_list args;
    va_start(args, num);
    int j;
    for(int i=0; i<9; i++){
        j = va_arg(args, int);
        printf("%i\n", j);
    }
    va_end(args);
}

int main(){
    int option, error;
    int linesCount, columnsCount;
    char text[100000], textForEncrypt[100000], key[550];

    do{
        error = 0;
        system("cls");

        printf("Cryptography with Geometric Transposition\n\n");

        printf("1 - Type the Text\n");
        printf("2 - Use the File\n");
        
        printf("OPTION: ");
        scanf("%i", &option);
        setbuf(stdin, NULL);

        switch (option){
            case 1:
                printf("Insert the text: ");
                fgets(text, 100000, stdin);
                break;
            
            case 2:;
                FILE * f_OriginalText = fopen("original-text.txt", "r");

                if(f_OriginalText == NULL){
                    f_OriginalText = fopen("original-text.txt", "w");
                    fclose(f_OriginalText);

                    printf("\nThe 'original-text.txt' file not found!\n");
                    printf("An empty file has been created!\n\n");

                    error = 1;
                    system("pause");
                    break;
                }

                fgets(text, 100000, f_OriginalText);

                fclose(f_OriginalText);
                break;
            
            default:
                error = 1;
                printf("Invalid Option!\n\n");
                system("pause");
                break;
        }

        if(error == 0){
            removeInvalidCharacters(text);
            replaceEquivalentCharacters(text);
            // toLowercase(text);
            // toUppercase(text);

            strcpy(textForEncrypt, text);

            printf("Text: %s\n", textForEncrypt);

            printf("\nChoose encryption:\n");
            printf("1 - Simple Columnar\n");
            printf("2 - Simple Linear\n");
            printf("3 - Columnar with Numeric Key\n");
            printf("4 - by Itinerary\n");
            printf("5 - Triangular\n");
            printf("6 - External Spiral\n");
            printf("7 - Internal Spiral\n");
            printf("8 - Zigzag\n");
            printf("9 - 'L' Pattern\n");
            printf("0 - Exit\n");
            printf("OPTION: ");
            scanf("%i", &option);
            setbuf(stdin, NULL);

            printf("\n");

            switch (option){
                case 1:
                    printf("Simple Columnar\n");
                    printf("Number of columns: ");
                    scanf("%i", &columnsCount);
                    simpleColumnar(textForEncrypt, columnsCount);
                    break;
                
                case 2:
                    printf("Simple Linear\n");
                    printf("Number of lines: ");
                    scanf("%i", &linesCount);
                    simpleLinear(textForEncrypt, linesCount);
                    break;

                case 3:
                    printf("Columnar with Numeric Key\n");
                    printf("Enter the key: ");
                    fgets(key, 550, stdin);
                    removeInvalidCharacters(key);
                    columnarWithNumericKey(textForEncrypt, key);
                    break;

                case 4:
                    printf("by Itinerary\n");
                    printf("Number of lines: ");
                    scanf("%i", &linesCount);
                    byItinerary(textForEncrypt,linesCount);
                    break;

                case 5:
                    printf("Triangular\n");
                    triangular(textForEncrypt);
                    break;

                case 6:
                    printf("External Spiral\n");
                    externalSpiral(textForEncrypt);
                    break;

                case 7:
                    printf("Internal Spiral\n");
                    internalSpiral(textForEncrypt);
                    break;
                
                case 8:
                    printf("Zigzag\n");
                    zigzag(textForEncrypt);
                    break;
                
                case 9:
                    printf("'L' Pattern\n");
                    lPattern(textForEncrypt);
                    break;

                case 0:
                    printf("Exiting...\n");
                    break;

                default:
                    printf("Invalid option!!!\n");
                    break;
            }

            setbuf(stdin, NULL);

            printf("Result: %s\n\n", textForEncrypt);

            FILE * f_ResultEncryption = fopen("result-ecryption.txt", "w");

            fprintf(f_ResultEncryption, textForEncrypt);

            fclose(f_ResultEncryption);


            system("pause");
        }

    }while(option != 0 || error == 1);

    return 0;
}

//AaÄäÅåÁáÂâÀàÃãBbCcÇçDdEeÉéÊêËëÈèFfGgHhIiÍíÎîÏïÌìıJjKkLlMmNnÑñOoÖöÓóÔôÒòÕõPpQqRrSsTtUuÜüÚúÛûÙùVvWwXxYyÝýÿZz

//os rapazes sao capazes

//minha terra tem palmeiras onde canta o sabia

//estou testando um texto maior para melhor compreensao, ainda maior do que o texto que diz que eu sou o lider

//Revelado pelo Santos, em 2009, Neymar se tornou o principal futebolista em atividade no país. Em 2013, foi vendido ao Barcelona em alta,[13] após ser protagonista da conquista da Copa das Confederações FIFA 2013 pela Seleção Brasileira.[14][15] Ao lado de Messi, Iniesta, Xavi, Daniel Alves e Luis Suárez, conquistou a Liga dos Campeões da UEFA de 2014–15 e se transformou no principal futebolista brasileiro e um dos principais futebolistas do mundo.[16] Em 2015, foi finalista do prêmio Bola de Ouro da FIFA (melhor jogador do mundo).[17] Em 2017, se tornou a transferência mais cara da história do futebol mundial, com sua venda milionária ao Paris Saint-Germain por 222 milhões de euros.[18] Nesse mesmo ano, foi pela segunda vez na carreira um dos três finalistas da premiação da FIFA de melhor jogador do mundo, atualmente nomeada como The Best FIFA Football Awards ou apenas FIFA The Best. Também foi finalista pela revista France Football, responsável pela entrega do Ballon d'Or ou Bola de Ouro.


//printf("Matrix Sizes: %i x %i\n", linesCount, columnsCount);
// printf("Current Indexes: %i x %i\n", i, j);
// printf("Limits: up=%i, right=%i, down=%i, left=%i\n", verticalLimit[0], horizontalLimit[1], verticalLimit[1], horizontalLimit[0]);
// printf("\n");

//Print ASCII Table
// for(int i=0; i<256; i++){
//     printf("Decimal Code: %i\t Character: %c\n", i, i);
// }

/**================================================================
 * ----------------------------------------------------------------
 * WELCOME TO DOCUMENTATION!
 * ----------------------------------------------------------------
 * Simple Columnar Transposition:
 * -> Input: Linear
 * -> Output: Columnar
 * ----------------------------------------------------------------
 * @author David Gomesh
 * GitHub: DavidGomesh
 * Instagram: @david_gomesh
 * E-mail: david.gomes@acad.ifma.edu.br
 * ----------------------------------------------------------------
 * *** The file is in UTF-8 codification! ***
 * ----------------------------------------------------------------
*///===============================================================

// J-------------------------K THE END L-----------------------l //


    // for(int i=0; i<linesCount; i++){
    //     for(int j=0; j<columnsCount; j++){
    //         printf("%c ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }