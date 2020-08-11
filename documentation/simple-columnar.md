# Transposição Colunar Simples

## Definição da Função

Ao chamar a função, deve se passar o texto original já processado, e a quantidade de colunas desejada.

***Obs.:*** deve ser passado um valor para a quantidade de colunas que seja menor que o tamanho do texto. Caso o valor passado seja igual ou superior, a função simplesmente não irá criptografar o texto.

```c
void simpleColumnar(char text[], int columnsCount);
```

[Acesse o código completo](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/geometric-transpositions/simple-linear.h)

## Cálculo do Tamanho da Matriz

1. Obtém o tamanho do texto;
1. Calcula o resto da divisão do tamanho do texto pela quantidade colunas desejada:
    1. se `resto = 0`, a quantidade de linhas é: `tamanhoDoTexto / quantColunas`;
    1. se `resto != 0`, a quantidade de linhas é: `(tamanhoDoTexto / quantColunas) + 1`.

### Código fonte do cálculo

```c
//Calculate the Matrix Size
if(lengthText % columnsCount == 0){
    linesCount = lengthText / columnsCount;
}else{
    linesCount = lengthText / columnsCount + 1;
}

//Matrix Statement
char matrix[linesCount][columnsCount];
```

## Entrada

Coloca cada letra na vertical, seguindo a ordem das colunas.

| ![Entrada da Transposição Colunar Simples](https://user-images.githubusercontent.com/65545355/89731870-ff953a80-da20-11ea-8675-620fc092a069.jpg "Entrada da Transposição Colunar Simples") |
|-|
| *Entrada da Transposição Colunar Simples* |

## Saída

Lê cada letra horizontalmente, seguindo a ordem das linhas.

| ![Saída da Transposição Colunar Simples](https://user-images.githubusercontent.com/65545355/89731940-88ac7180-da21-11ea-82dc-c284d3df06cd.jpg "Saída da Transposição Colunar Simples") |
|-|
| *Saída da Transposição Colunar Simples* |

## Demonstração

Estado | Texto
 -: | :-
**Original** | A cabana na Floresta Tropical
**Processado** | acabananaflorestatropical
**Criptografado** | anltpcaoaianrtcbaeraafsol

***Obs.:*** no exemplo foi usado **5** colunas.

## Exibição do Funcionamento

| ![Demostração do Funcionamento da Transposição Colunar Simples](https://user-images.githubusercontent.com/65545355/89732053-58190780-da22-11ea-8ba9-827ee28a5e42.gif "Demostração do Funcionamento da Transposição Colunar Simples") |
|-|
| *Demostração do Funcionamento da Transposição Colunar Simples* |
