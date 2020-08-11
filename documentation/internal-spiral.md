# Transposição por Espiral Interno

## Definição da Função

Ao chamar a função, deve se passar o texto original já processado.

***Obs.:*** o texto deve conter no mínimo 3 caracteres para ser criptografado.

```c
void internalSpiral(char text[]);
```

[Acesse o código completo](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/geometric-transpositions/internal-spiral.h)

## Cálculo do Tamanho da Matriz

É necessário criar uma matriz capaz de armazenar o texto, e que tenha dimensões iguais e ímpares para que o espiral possa ficar exatamente no meio da matriz.

1. Se calcula a raiz quadrada do tamanho do texto;
1. O valor obtido é atribuído a quantidade de colunas, temporariamente, também é atribuido a quantidade de linhas;
1. Então é testado se a matriz atual é capaz de armazenar o texto:
    1. Caso a matriz for capaz, essa será a matriz utilizada.
    1. Caso não, aumenta em 1 a quantidade de linhas, e o passo 3 é repetido até encontrar a matriz ideal.
1. Agora, é necessário verificar:
    1. Se a quantidade de linhas é menor que a de colunas:
        1. Se sim, a quantidade de linhas deve ser igualada a quantidade de colunas.
    1. Ou se quantidade de colunas é menor que a de linhas:
        1. Se sim, a quantidade de colunas deve ser igualada a quantidade de linhas.
1. Se as dimensões tiverem números pares, deve se aumentar 1 para ficarem ímpares.
1. Por fim, verifica se uma matriz com as dimensões atuais - 2 podem suportar o texto:
    1. Caso sim, diminui-se 2 das dimensões atuais, para usarmos essa matriz.

### Código fonte do cálculo

```c
int squareRootLengthText = (int)sqrt(lengthText);

linesCount = columnsCount = squareRootLengthText;
while(columnsCount * linesCount < lengthText){
    linesCount++;
}

if(linesCount < columnsCount){
    linesCount = columnsCount;
}
else if(columnsCount < linesCount){
    columnsCount = linesCount;
}

if(linesCount%2==0){
    linesCount++;
    columnsCount++;
}

if((linesCount - 2)*(columnsCount-2) >= lengthText){
    linesCount -= 2;
    columnsCount -= 2;
}
```

## Entrada

Começando exatamente pelo meio, o texto é inserido formando um espiral. Primeiro vai para a direita, depois para baixo, depois esquerda, e por fim para cima.

| ![Entrada da Transposição por Espiral Interna](https://user-images.githubusercontent.com/65545355/89904262-14a7d000-dbbf-11ea-8e69-92c618481257.jpg "Entrada da Transposição por Espiral Interna") |
|-|
| *Entrada da Transposição por Espiral Interna* |

## Saída

A saída começa pelo canto inferior esquerdo, e vai lendo as diagonais até o canto superior direito.

| ![Saída da Transposição por Espiral Interna](https://user-images.githubusercontent.com/65545355/89904671-9861bc80-dbbf-11ea-9ef6-8317f57b07e2.jpg "Saída da Transposição por Espiral Interna") |
|-|
| *Saída da Transposição por Espiral Interna* |

## Demonstração

Estado | Texto
 -: | :-
**Original** | Atacar os doces pelos flancos
**Processado** | atacarosdocespelosflancos
**Criptografado** | oslfaelrcpaoaasnstecdcoos

## Exibição do Funcionamento

| ![Demostração do Funcionamento da Transposição por Espiral Interna](https://user-images.githubusercontent.com/65545355/89905003-fdb5ad80-dbbf-11ea-8e38-9213735e9890.gif "Demostração do Funcionamento da Transposição por Espiral Interna") |
|-|
| *Demostração do Funcionamento da Transposição por Espiral Interna* |
