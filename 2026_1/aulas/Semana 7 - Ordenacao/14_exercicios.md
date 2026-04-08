# Aula 14: Exercícios sobre Busca e Ordenação

## Questão 1
a) Como encontrar o índice da primeira ocorrência do valor $x$ em uma lista ordenada? Implemente um algoritmo eficiente para resolver esse problema. Justifique a escolha do seu método e analise sua complexidade.

b) Como encontrar o índice da última ocorrência do valor $x$ em uma lista ordenada? Implemente um algoritmo eficiente para resolver esse problema. Justifique a escolha do seu método e analise sua complexidade.

c) Com base nas soluções das questões anteriores, implemente um algoritmo que determine quantos elementos estão dentro do intervalo $[x, y]$ em uma lista ordenada. Qual é a complexidade da sua solução?

## Questão 2
Implemente o algoritmo de ordenação por inserção (Insertion Sort). Analise sua complexidade no pior e no melhor caso.

## Questão 3
Implemente o algoritmo de ordenação por bolha (Bubble Sort) utilizando:

a) Arrays. Analise a complexidade de pior caso do algoritmo implementado.

b) Listas simplesmente encadeadas. Compare a eficiência e a dificuldade de implementação em relação à versão com arrays.

## Questão 4
   Dada uma lista de tuplas $(x, y)$, implemente um algoritmo que ordene a lista primeiramente pelo valor de $x$ e, em caso de empate, pelo valor de $y$. Explique como sua abordagem garante a ordenação correta e analise a complexidade do seu algoritmo.

## Questão 5

Dado um array de $n$ elementos e um inteiro $k$, com $1 \leq k \leq n$, deseja-se encontrar o $k$-ésimo menor elemento do array.
Modifique o algoritmo de ordenação por seleção (*Selection Sort*) para que ele pare assim que for possível determinar esse elemento, sem necessariamente ordenar todo o array.
Apresente a ideia da solução, justifique sua abordagem e analise a complexidade de tempo no pior caso.

## Questão 6

Considere duas listas (arrays ou listas encadeadas) $A$ e $B$, cada uma contendo $n$ e $m$ elementos inteiros, respectivamente.
Deseja-se calcular a **interseção** entre $A$ e $B$, isto é, um conjunto contendo apenas os elementos que aparecem em ambas as listas.
Responda:

a) Suponha que as listas $A$ e $B$ **não estão ordenadas**. Descreva uma forma de calcular a interseção entre elas.
Analise a complexidade de tempo da sua solução em função de $n$ e $m$.

b)  Agora suponha que as listas $A$ e $B$ estão **ordenadas em ordem crescente**.
Descreva uma forma mais eficiente de calcular a interseção nesse caso.

c) Analise a complexidade de tempo da solução do item (b) e compare com a do item (a).

d) Explique por que a ordenação pode tornar o problema mais eficiente, mesmo considerando o custo para ordenar as listas (caso necessário).
