# Transposição Linear com Chave Numérica

## Definição da Função

Ao chamar a função, deve se passar o texto original e a chave, ambos já processados.

***Obs.:*** o tamanho da chave definirá a quantidade de colunas que a matriz terá. Portanto, deve se passar um chave que seja menor que o texto a ser criptografado.

```c
void columnarWithNumericKey(char text[], char key[]);
```

[Acesse o código completo](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/geometric-transpositions/linear-with-numeric-key.h)

## Definindo a Chave Numérica

As letras da chave são numeradas em ordem alfabética. Caso haja letras repetidas, essas serão numeradas em sequência da esquerda para a direita.

| ![Chave Numérica sendo gerada](https://user-images.githubusercontent.com/65545355/89734626-a4207800-da33-11ea-9842-d8570b4626e9.jpg "Chave Numérica sendo gerada") |
|-|
| *Chave Numérica sendo gerada.* |

## Cálculo do Tamanho da Matriz

1. Obtém o tamanho do texto;
1. Calcula o resto da divisão do tamanho do texto pela quantidade colunas:
    1. se `resto = 0`, a quantidade de linhas é: `tamanhoDoTexto / quantColunas`;
    1. se `resto != 0`, a quantidade de linhas é: `(tamanhoDoTexto / quantColunas) + 1`.

### Código fonte do cálculo

```c
int linesCount, columnsCount = lengthKey;

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

Coloca cada letra na horizontal, seguindo a ordem das linhas.

| ![Entrada da Transposição Linear com Chave Numérica](https://user-images.githubusercontent.com/65545355/89734779-9f0ff880-da34-11ea-90c1-5cd1a4807ee3.jpg "Entrada da Transposição Linear com Chave Numérica") |
|-|
| *Entrada da Transposição Linear com Chave Numérica.* |

## Saída

A saída é baseada na Chave Numérica gerada, isto é, a Chave define a ordem das colunas a serem lidas.

| ![Entrada da Transposição Linear com Chave Numérica](https://user-images.githubusercontent.com/65545355/89734969-8c49f380-da35-11ea-865f-52fedc41bf83.jpg "Entrada da Transposição Linear com Chave Numérica") |
|-|
| *Entrada da Transposição Linear com Chave Numérica.* |

## Demonstração

Estado | Texto
 -: | :-
**Original** | A música está tocando
**Processado** | amusicaestatocando
**Criptografado** | itamatdacanueoossc

***Obs.:*** no exemplo foi usado a chave "***pizza***".

## Exibição do Funcionamento

| ![Demostração do Funcionamento da Transposição Linear com Chave Numérica](https://user-images.githubusercontent.com/65545355/89735086-548f7b80-da36-11ea-9d00-4f2126c0c4c0.gif "Demostração do Funcionamento da Transposição Linear com Chave Numérica") |
|-|
| *Demostração do Funcionamento da Transposição Linear com Chave Numérica.* |
