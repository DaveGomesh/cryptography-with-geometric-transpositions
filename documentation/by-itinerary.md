# Transposição Colunar Simples

## Definição da Função

Ao chamar a função, deve se passar o texto original já processado, e a quantidade de linhas desejada.

***Obs.:*** deve ser passado um valor para a quantidade de linhas que seja menor que o tamanho do texto. Caso o valor passado seja igual ou superior, a função simplesmente não irá criptografar o texto.

```c
void byItinerary(char text[], int linesCount);
```

[Acesse o código completo](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/geometric-transpositions/by-itinerary.h)

## Cálculo do Tamanho da Matriz

A quantidade de linhas é informada pelo usuário, e quantidade de colunas é igual ao tamanho do texto.

## Entrada

Segue um padrão fixo em ziguezague.

| ![Entrada da Transposição por Itinerário](https://user-images.githubusercontent.com/65545355/89744302-f1c3d180-da81-11ea-8c73-153e0e818adb.jpg "Entrada da Transposição por Itinerário") |
|-|
| *Entrada da Transposição por Itinerário* |

## Saída

Lê cada letra horizontalmente, seguindo a ordem das linhas.

| ![Saída da Transposição por Itinerário](https://user-images.githubusercontent.com/65545355/89744393-bece0d80-da82-11ea-92b2-35dd36511ef9.jpg "Saída da Transposição por Itinerário") |
|-|
| *Saída da Transposição por Itinerário* |

## Demonstração

### Exemplo 1

Estado | Texto
 -: | :-
**Original** | Olá, tudo bem?
**Processado** | olatudobem
**Criptografado** | oauoeltdbm

***Obs.:*** nesse exemplo foi usado **2** linhas.

---

### Exemplo 2

Estado | Texto
 -: | :-
**Original** | Olá, tudo bem?
**Processado** | olatudobem
**Criptografado** | oueltdbmao

***Obs.:*** no exemplo foi usado **3** linhas.

---

### Comparação

Resultados | Quantidade de Linhas
-:|:-:
oauoeltdbm | **2**
oueltdbmao | **3**

## Exibição do Funcionamento

| ![Demostração do Funcionamento da Transposição Colunar Simples](https://user-images.githubusercontent.com/65545355/89744536-4a946980-da84-11ea-85a0-4128e983399d.gif "Demostração do Funcionamento da Transposição Colunar Simples") |
|-|
| *Demostração do Funcionamento da Transposição por Itinerário* |
