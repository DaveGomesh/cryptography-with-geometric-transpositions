# Transposição com o Padrão "L"

## Definição da Função

Ao chamar a função, deve se passar o texto original já processado.

***Obs.:*** o texto deve conter no mínimo 4 caracteres para ser criptografado.

```c
void lPattern(char text[]);
```

[Acesse o código completo](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/geometric-transpositions/l-pattern.h)

## Cálculo do Tamanho da Matriz

É necessário criar uma matriz capaz de armazenar o texto, e que suas dimensões sejam iguais ou o mais próximo possível disso.

1. Se calcula a raiz quadrada do tamanho do texto;
1. O valor obtido é atribuído a quantidade de colunas, temporariamente, também é atribuido a quantidade de linhas;
1. Então é testado se a matriz atual é capaz de armazenar o texto:
    1. Caso a matriz for capaz, essa será a matriz utilizada.
    1. Caso não, aumenta em 1 a quantidade de linhas, e o passo 3 é repetido até encontrar a matriz ideal.

## Código fonte do cálculo

```c
int squareRootLengthText = (int)sqrt(lengthText);

linesCount = columnsCount = squareRootLengthText;
while(columnsCount * linesCount < lengthText){
    columnsCount++;
}
```

## Entrada

Iniciando pelo canto superior esquerdo, desce até a última linha e continua na mesma até o seu limite, formando assim um "L". Em seguida, faz o processo contrário, isto é, começando pela penúltima linha e indo até a segunda coluna, formando novamente um "L", menor dessa vez.

| ![Entrada da Transposição com o Padrão "L"](https://user-images.githubusercontent.com/65545355/89946561-813fc080-dbf9-11ea-8381-ce94dd95ac33.jpg "Entrada da Transposição com o Padrão 'L'") |
|-|
| *Entrada da Transposição com o Padrão "L"* |

## Saída

A saída começa pelo canto inferior esquerdo, e vai lendo as diagonais até o canto superior direito.

| ![Saída da Transposição com o Padrão "L"](https://user-images.githubusercontent.com/65545355/89946894-fdd29f00-dbf9-11ea-80fd-6ee188036dc2.jpg "Saída da Transposição com o Padrão 'L'") |
|-|
| *Saída da Transposição com o Padrão "L"* |

## Demonstração

Estado | Texto
 -: | :-
**Original** | O objetivo da guerra é ter a paz
**Processado** | oobjetivodaguerraeterapaz
**Criptografado** | ejtbuioegvortaoreedapraaz

## Exibição do Funcionamento

| ![Demostração do Funcionamento da Transposição com o padrão "L"](https://user-images.githubusercontent.com/65545355/89947215-7a657d80-dbfa-11ea-8e7b-430d05d611c5.gif "Demostração do Funcionamento da Transposição com o padrão 'L'") |
|-|
| *Demostração do Funcionamento da Transposição com o padrão "L"* |
