# Aula 19: Lista de Exercícios sobre Árvores Binárias de Busca

## Q1. Verificação de ABB (visual)
Verifique quais das árvores abaixo são Árvores Binárias de Busca (ABB). Para cada árvore que **não** for uma ABB, **justifique** sua resposta.

A. 
```mathematica
       15
     /    \
    10     20
   / \    /  \
  5  13  17   22
     / \      /
    11 14    21
```

B. 
```mathematica
      2
     / \
    1   3
       / \
      4   6
       \ 
        5
```

C. 
```mathematica
       12
     /    \
    1      15
     \    /  \
     10  13   30
          \
          14
```

## Q2. Construção e análise de ABBs
Seja o conjunto de chaves ordenadas:
$S = \{s_1, s_2, \dots, s_7\}$, com $s_i < s_{i+1}$ para todo $i < 7$.

A. Desenhe a ABB construída ao inserir as chaves na seguinte ordem:
$s_3, s_7, s_1, s_2, s_6, s_5, s_4$

B. Dê **um exemplo** de ordem de inserção das chaves que leve à **altura máxima** da ABB.

C. Dê **um exemplo** de ordem de inserção das chaves que leve à **altura mínima** da ABB.

## Q3. Busca inconsistente
Suponha que os números de $1$ a $1.000$ estejam armazenados em uma ABB. Estamos buscando o valor **363**.

Indique qual das sequências abaixo **não poderia** representar o caminho de visita dos nós durante essa busca. Justifique.

A. `2, 252, 401, 398, 330, 344, 397, 363`  
B. `924, 220, 911, 244, 898, 248, 362, 363`  
C. `925, 202, 911, 240, 912, 245, 363`  
D. `2, 399, 387, 219, 266, 382, 381, 278, 363`  
E. `935, 278, 347, 621, 299, 392, 358, 363`


## Q4. Modificações em uma ABB

Considere a seguinte ABB (incluir imagem):

```mathematica
       15
     /    \
    10     20
   /     /    \
  5     18     25
       /  \   /  \
      16  19 22   30
             /
            21
```

Mostre como a árvore ficaria se:

A. O nó `16` fosse **removido**  
B. O nó `22` fosse **removido**  
C. O nó `15` fosse **removido**  
D. O nó `9` fosse **inserido**

## Q5. Verificação de ABB (algoritmo)
Implemente uma função que receba a raiz de uma árvore binária e verifique se ela é uma ABB.

## Q6. Caminho de busca
Implemente uma função que, dada uma chave `k` e a raiz de uma ABB, **retorne o caminho** percorrido até encontrar a chave.  
Se a chave não estiver na árvore, retorne o caminho até a falha da busca.

## Q7. Inserção com altura mínima
Dado um vetor ordenado de chaves, escreva uma função que construa uma ABB com **altura mínima**.  

## Q8. Filtragem de maiores valores
Implemente uma função que, dada uma ABB e um valor `x`, **retorne todos os nós com valor maior que `x`**, **sem percorrer nós desnecessários**.
