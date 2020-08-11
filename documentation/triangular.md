# Transposição Triangular

## Definição da Função

Ao chamar a função, deve se passar o texto original já processado.

```c
void triangular(char text[]);
```

[Acesse o código completo](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/geometric-transpositions/triangular.h)

## Cálculo do Tamanho da Matriz

É necessário encontrar uma matriz que seja capaz de armazenar uma pirâmide que por sua vez, seja capaz de armazenar o texto todo. A pirâmide pode ter uma capacidade superior, mas, nunca inferior.

Uma matriz 1x1 só consegue armazenar 1 caractere. A primeira matriz capaz de armazenar uma pirâmide é a 2x3. E a próxima, é a 3x5. Em seguida, vem a 4x7. Depois a 5x9... E assim em diante:

![Matrizes possíveis](https://user-images.githubusercontent.com/65545355/89745814-8cc1a900-da8c-11ea-8404-dd65c6176c56.jpg "Matrizes possíveis")

Para encontrar a matriz ideal, basta testar a capacidade das pirâmides. Começando com a 1x1, com capacidade de armazenar 1 caractere. Caso não seja essa, aumenta-se 1 linha e 2 colunas. A capacidade nova será a capacidade atual somado com a quantidade nova de colunas. E então, é testado novamente.<br>Esse ciclo continua até que uma das pirâmides seja capaz de armazenar o texto.

### Código fonte do cálculo

***Obs.:*** a variável ```maxCharLastLine``` foi usada para facilitar a compreensão do código.

```c
int linesCount=1, columnsCount;

int maxCharPyramid=1;
int maxCharLastLine=1;

while(maxCharPyramid < lengthText){
    maxCharLastLine+=2;
    maxCharPyramid+=maxCharLastLine;
    linesCount++;
}

columnsCount = maxCharLastLine;
```

## Entrada

Coloca cada letra na horizontal, seguindo a ordem das linhas e formando a pirâmide.

| ![Entrada da Transposição Triangular](https://user-images.githubusercontent.com/65545355/89746568-cdbbbc80-da90-11ea-9ecf-eeeba30d7cf7.jpg "Entrada da Transposição Triangular") |
|-|
| *Entrada da Transposição Triangular* |

## Saída

Lê cada letra verticalmente, seguindo a ordem das colunas.

| ![Saída da Transposição Triangular](https://user-images.githubusercontent.com/65545355/89746612-0a87b380-da91-11ea-89f2-ee02a2ebab0d.jpg "Saída da Transposição Triangular") |
|-|
| *Saída da Transposição Triangular* |

## Demonstração

Estado | Texto
 -: | :-
**Original** | Motivo para sonhar
**Processado** | motivoparasonhar
**Criptografado** | avsooomtpniahrar

## Exibição do Funcionamento

| ![Demostração do Funcionamento da Transposição Triangular](https://user-images.githubusercontent.com/65545355/89746761-dd87d080-da91-11ea-94eb-65598fb3df3d.gif "Demostração do Funcionamento da Transposição Triangular") |
|-|
| *Demostração do Funcionamento da Transposição Triangular* |
