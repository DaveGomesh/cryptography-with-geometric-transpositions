# Criptografia com Transposições Geométricas

## Características do Projeto

- Linguagem: **C**
- Compilador: **MinGW (GCC)**
- Sistema Operacional: **Windows 10**
- Editor: **VS Code**
- Outros programas: **Photoshop CC 2019**
- [***Referências***](#referências-bibliográficas)

## O que é Transposição Geométrica?

Significa dispor um texto em uma matriz formando alguma forma geométrica. Por exemplo:

| ![Transposição Triangular](https://user-images.githubusercontent.com/65545355/89712988-d87c3180-d96a-11ea-8293-ff7198196bfd.jpg? "Transposição Triangular") |
|-|
| *Transposição Triangular* |

## Quais transposições existem no Projeto?

- [Colunar Simples](#columnar-simples)
- [Linear Simples](#linear-simples)
- [Linear com Chave Numérica](#linear-com-chave-numérica)
- [Transposição por Itinerário](#transposição-por-itinerário)
- [Triangular](#triangular)
- [Espiral Externo](#espiral-externo)
- [Espiral Interno](#espiral-interno)
- [Zigue-Zague](#ziguezague)
- [Padrão 'L'](#padrão-'l')

## Alguns padrões a serem seguidos

- *Strings* **DEVEM** conter "`\0`" na última posição (em C, isso representa o final de uma *string*);
- **Evitar** usar caracteres especiais no texto, como: "`!` `@` `#` `$` `%` `&`" e *quebras de linha* ("`\n`"). O motivo é bem simples: como as transposições irão apenas bagunçar o texto, esses caracteres podem ajudar descobrir o texto original.
  - **Obs.:** a remoção é opcional para todos os caracteres, exceto para o "`-`", pois esse caractere é removido automaticamente pelas funções que bagunçam o texto.

## Colunar Simples

[Veja com mais detalhes essa transposição](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/documentation/simple-columnar.md "Transposição Colunar Simples")

| ![Demostração do Funcionamento da Transposição Colunar Simples](https://user-images.githubusercontent.com/65545355/89732053-58190780-da22-11ea-8ba9-827ee28a5e42.gif "Demostração do Funcionamento da Transposição Colunar Simples") |
|-|
| *Demostração do Funcionamento da Transposição Colunar Simples* |

## Linear Simples

[Veja com mais detalhes essa transposição](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/documentation/simple-linear.md "Transposição Linear Simples")

| ![Demostração do Funcionamento da Transposição Linear Simples](https://user-images.githubusercontent.com/65545355/89734284-95d15c80-da31-11ea-91f6-e4808b260d9d.gif "Demostração do Funcionamento da Transposição Linear Simples") |
|-|
| *Demostração do Funcionamento da Transposição Linear Simples* |

## Linear com Chave Numérica

[Veja com mais detalhes essa transposição](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/documentation/linear-with-numeric-key.md "Transposição Linear com Chave Numérica")

| ![Demostração do Funcionamento da Transposição Linear com Chave Numérica](https://user-images.githubusercontent.com/65545355/89735086-548f7b80-da36-11ea-9d00-4f2126c0c4c0.gif "Demostração do Funcionamento da Transposição Linear com Chave Numérica") |
|-|
| *Demostração do Funcionamento da Transposição Linear com Chave Numérica.* |

## Transposição por Itinerário

[Veja com mais detalhes essa transposição](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/documentation/by-itinerary.md "Transposição por Itinerário")

| ![Demostração do Funcionamento da Transposição Colunar Simples](https://user-images.githubusercontent.com/65545355/89744536-4a946980-da84-11ea-85a0-4128e983399d.gif "Demostração do Funcionamento da Transposição Colunar Simples") |
|-|
| *Demostração do Funcionamento da Transposição por Itinerário* |

## Triangular

[Veja com mais detalhes essa transposição](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/documentation/triangular.md "Transposição Triangular")

| ![Demostração do Funcionamento da Transposição Triangular](https://user-images.githubusercontent.com/65545355/89746761-dd87d080-da91-11ea-94eb-65598fb3df3d.gif "Demostração do Funcionamento da Transposição Triangular") |
|-|
| *Demostração do Funcionamento da Transposição Triangular* |

## Espiral Externo

[Veja com mais detalhes essa transposição](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/documentation/external-spiral.md "Transposição por Espiral Externo")

| ![Demostração do Funcionamento da Transposição por Espiral Externa](https://user-images.githubusercontent.com/65545355/89795522-e19e0780-dafe-11ea-9699-4f95762fe629.gif "Demostração do Funcionamento da Transposição por Espiral Externa") |
|-|
| *Demostração do Funcionamento da Transposição por Espiral Externa* |

## Espiral Interno

[Veja com mais detalhes essa transposição](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/documentation/internal-spiral.md "Transposição por Espiral Interno")

| ![Demostração do Funcionamento da Transposição por Espiral Interna](https://user-images.githubusercontent.com/65545355/89905003-fdb5ad80-dbbf-11ea-8e38-9213735e9890.gif "Demostração do Funcionamento da Transposição por Espiral Interna") |
|-|
| *Demostração do Funcionamento da Transposição por Espiral Interna* |

## Ziguezague

[Veja com mais detalhes essa transposição](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/documentation/zigzag.md "Transposição em Ziguezague")

| ![Demostração do Funcionamento da Transposição em Ziguezague](https://user-images.githubusercontent.com/65545355/89907234-ca285280-dbc2-11ea-8cf6-d19cd6c1e6f8.gif "Demostração do Funcionamento da Transposição em Ziguezague") |
|-|
| *Demostração do Funcionamento da Transposição em Ziguezague* |

## Padrão 'L'

[Veja com mais detalhes essa transposição](https://github.com/DavidGomesh/cryptography-with-geometric-transpositions/blob/master/documentation/l-pattern.md "Transposição com o Padrão 'L'")

| ![Demostração do Funcionamento da Transposição com o padrão "L"](https://user-images.githubusercontent.com/65545355/89947215-7a657d80-dbfa-11ea-8e7b-430d05d611c5.gif "Demostração do Funcionamento da Transposição com o padrão 'L'") |
|-|
| *Demostração do Funcionamento da Transposição com o padrão "L"* |

## Referências Bibliográficas

FERREIRA, Marcelo Zochio. Introdução à Criptografia. 1ª edição. São Paulo, SP. Novatec, 2016.

SILVA, Luiz Paulo Moreira. "O que é anagrama?"; Brasil Escola. Disponível em: https://brasilescola.uol.com.br/o-que-e/matematica/o-que-e-anagrama.htm. Acesso em 27 de julho de 2020.

YouTube. "Anagram Solving Algorithm". Disponível em: (https://youtu.be/lVGNs-DAzfc?list=LLrOluNfP46HBUYbbucTNcPQ)

Wikipedia. "Frequência de letras". Disponível em: (https://pt.wikipedia.org/wiki/Frequ%C3%AAncia_de_letras)

Aldeia Numaboa. "Frequência de ocorrência de letras no Português". Dispoível em: (http://www.numaboa.com.br/criptografia/criptoanalise/310-Frequencia-no-Portugues)