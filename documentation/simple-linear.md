# Transposição Linear Simples

## Definição da Função

Ao chamar a função, deve se passar o texto original já processado, e a quantidade de linhas desejada.

***Obs.:*** deve ser passado um valor para a quantidade de linhas que seja menor que o tamanho do texto. Caso o valor passado seja igual ou superior, a função simplesmente não irá criptografar o texto.

```c
void simpleLinear(char text[], int linesCount);
```

[Acesse o código completo](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/geometric-transpositions/simple-columnar.h)

## Cálculo do Tamanho da Matriz

1. Obtém o tamanho do texto;
1. Calcula o resto da divisão do tamanho do texto pela quantidade linhas desejada:
    1. se `resto = 0`, a quantidade de colunas é: `tamanhoDoTexto / quantLinhas`;
    1. se `resto != 0`, a quantidade de colunas é: `(tamanhoDoTexto / quantLinhas) + 1`.

### Código fonte do cálculo

```c
//Calculate Matrix Size
if(lengthText % linesCount == 0){
    columnsCount = lengthText / linesCount;
}else{
    columnsCount = lengthText / linesCount + 1;
}

//Matrix Statement
char matrix[linesCount][columnsCount];
```

## Entrada

Coloca cada letra na horizontal, seguindo a ordem das linhas.

| ![Entrada da Transposição Linear Simples](https://user-images.githubusercontent.com/65545355/89734164-ce246b00-da30-11ea-8a44-a9a89d9e87e1.jpg "Entrada da Transposição Linear Simples") |
|-|
| *Entrada da Transposição Linear Simples* |

## Saída

Lê cada letra verticalmente, seguindo a ordem das colunas.

| ![Saída da Transposição Linear Simples](https://user-images.githubusercontent.com/65545355/89734207-1b084180-da31-11ea-804c-95800e0b3758.jpg "Saída da Transposição Linear Simples") |
|-|
| *Saída da Transposição Linear Simples* |

## Demonstração

Estado | Texto
 -: | :-
**Original** | Minha terra tem palmeiras
**Processado** | minhaterratempalmeiras
**Criptografado** | mttlaieemsnrmehrpiaaar

***Obs.:*** no exemplo foi usado **5** linhas.

## Exibição do Funcionamento

| ![Demostração do Funcionamento da Transposição Linear Simples](https://user-images.githubusercontent.com/65545355/89734284-95d15c80-da31-11ea-91f6-e4808b260d9d.gif "Demostração do Funcionamento da Transposição Linear Simples") |
|-|
| *Demostração do Funcionamento da Transposição Linear Simples* |
