# Transposição por Espiral Externa

## Definição da Função

Ao chamar a função, deve se passar o texto original já processado.

***Obs.:*** o texto deve conter no mínimo 4 caracteres para ser criptografado.

```c
void externalSpiral(char text[]);
```

[Acesse o código completo](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/geometric-transpositions/external-spiral.h)

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

As letras são colocas acompanhando as as extremidades da matriz, formando assim um espiral.

| ![Entrada da Transposição por Espiral Externa](https://user-images.githubusercontent.com/65545355/89794336-4d7f7080-dafd-11ea-819e-03a9bb4341bb.jpg "Entrada da Transposição por Espiral Externa") |
|-|
| *Entrada da Transposição por Espiral Externa* |

## Saída

A saída começa pelo canto superir esquerdo, e vai lendo as diagonais até o canto inferior direito.

| ![Saída da Transposição por Espiral Externa](https://user-images.githubusercontent.com/65545355/89794955-283f3200-dafe-11ea-9a7a-127b38ce24b9.jpg "Saída da Transposição por Espiral Externa") |
|-|
| *Saída da Transposição por Espiral Externa* |

## Demonstração

Estado | Texto
 -: | :-
**Original** | Pátria Amada, Brasil!
**Processado** | patriaamadabrasil
**Criptografado** | paarstbiralidaaam

## Exibição do Funcionamento

| ![Demostração do Funcionamento da Transposição por Espiral Externa](https://user-images.githubusercontent.com/65545355/89795522-e19e0780-dafe-11ea-9699-4f95762fe629.gif "Demostração do Funcionamento da Transposição por Espiral Externa") |
|-|
| *Demostração do Funcionamento da Transposição por Espiral Externa* |
