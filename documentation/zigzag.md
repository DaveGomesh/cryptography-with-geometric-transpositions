# Transposição em Ziguezague

## Definição da Função

Ao chamar a função, deve se passar o texto original já processado.

***Obs.:*** o texto deve conter no mínimo 4 caracteres para ser criptografado.

```c
void zigzag(char text[]);
```

[Acesse o código completo](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/geometric-transpositions/zigzag.h)

## Cálculo do Tamanho da Matriz

É necessário criar uma matriz capaz de armazenar o texto, e que suas dimensões sejam iguais ou o mais próximo possível disso.

1. Se calcula a raiz quadrada do tamanho do texto;
1. O valor obtido é atribuído a quantidade de colunas, temporariamente, também é atribuido a quantidade de linhas;
1. Então é testado se a matriz atual é capaz de armazenar o texto:
    1. Caso a matriz for capaz, essa será a matriz utilizada.
    1. Caso não, aumenta em 1 a quantidade de linhas, e o passo 3 é repetido até encontrar a matriz ideal.

### Código fonte do cálculo

```c
//Square Root
int squareRootLengthText = (int)sqrt(lengthText);

linesCount = columnsCount = squareRootLengthText;
while(columnsCount * linesCount < lengthText){
    linesCount++;
}

char matrix[linesCount][columnsCount];
```

## Entrada

Coloca cada letra horizontalmente, seguindo, inicialmente, da esquerda para a direita. Na próxima linha a direção muda, da direita para a esquerda. E assim continua, fazendo um ziguezague até o final da matriz.

| ![Entrada da Transposição em Ziguezague](https://user-images.githubusercontent.com/65545355/89906659-09a26f00-dbc2-11ea-9f23-f55ba570d8d7.jpg "Entrada da Transposição em Ziguezague") |
|-|
| *Entrada da Transposição em Ziguezague* |

## Saída

Lê cada letra verticalmente, seguindo a ordem das colunas.

| ![Saída da Transposição em Ziguezague](https://user-images.githubusercontent.com/65545355/89906889-5128fb00-dbc2-11ea-9a6d-ffe93de0f826.jpg "Saída da Transposição em Ziguezague") |
|-|
| *Saída da Transposição em Ziguezague* |

## Demonstração

Estado | Texto
 -: | :-
**Original** | O campeão dos campeões
**Processado** | ocampeaodoscampeoes
**Criptografado** | oodeocaopeaesmsmpca

## Exibição do Funcionamento

| ![Demostração do Funcionamento da Transposição em Ziguezague](https://user-images.githubusercontent.com/65545355/89907234-ca285280-dbc2-11ea-8cf6-d19cd6c1e6f8.gif "Demostração do Funcionamento da Transposição em Ziguezague") |
|-|
| *Demostração do Funcionamento da Transposição em Ziguezague* |
