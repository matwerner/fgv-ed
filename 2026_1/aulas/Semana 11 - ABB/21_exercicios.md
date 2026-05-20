# Aula 20: Lista de Exercícios sobre Árvores Binárias de Busca

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

Considere a seguinte ABB:

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

Mostre como a árvore ficaria após cada operação abaixo, considerando sempre a árvore original.

Quando a remoção envolver um nó com dois filhos, use o sucessor em ordem.

A. O nó `16` fosse **removido**  
B. O nó `22` fosse **removido**  
C. O nó `15` fosse **removido**  
D. O nó `9` fosse **inserido**

## Q5. Caminho de busca
Implemente uma função que, dada uma chave `k` e a raiz de uma ABB, **exiba no terminal o caminho** percorrido até encontrar a chave.  
Se a chave não estiver na árvore, exiba o caminho até a falha da busca.

## Q6. Verificação de ABB (algoritmo)
Implemente uma função que receba a raiz de uma árvore binária e verifique se ela é uma ABB.
A função deve considerar a propriedade global da ABB, não apenas a relação entre cada nó e seus filhos imediatos.

## Q7. Filtragem de maiores valores
Implemente uma função que, dada uma ABB e um valor `x`, **exiba todos os nós com valor maior que `x`**, **sem percorrer nós desnecessários**.

## Q8. Diferença absoluta mínima

Dada uma árvore binária de busca e um valor-alvo `k`, implemente uma função que **encontre o nó cujo valor tem a menor diferença absoluta** com `k`.

Exemplo:
Se a ABB contém os valores `{10, 22, 14, 26, 5}` e `k = 12`, o nó mais próximo é `10` (diferença de 2) ou `14` (diferença de 2).

## Q9. Construção de ABB com altura mínima
Dado um vetor ordenado de chaves, escreva uma função que construa uma ABB com **altura mínima**.

## Q10. k-ésimo menor elemento

Dada uma árvore binária de busca e um inteiro `k`, implemente uma função que retorne o nó que contém o `k`-ésimo menor valor da árvore.

Por exemplo, se a ABB contém os valores:

`{5, 10, 14, 22, 26}`

então:

- para `k = 1`, a resposta é `5`;
- para `k = 2`, a resposta é `10`;
- para `k = 5`, a resposta é `26`.

Assuma que `1 <= k <= n`, onde `n` é o número de nós da árvore.

A. Implemente a função `kthSmallest(Node* root, int k)`.

B. Existe alguma forma de melhorar o tempo computacional dessa operação? 
Se sim, qual informação adicional poderíamos armazenar em cada nó da árvore? Explique como essa informação ajudaria.