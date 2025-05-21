# Aula 21: Lista de Exercícios sobre Árvores AVL

## Q1. Modificações em uma AVL

Considere a seguinte árvore AVL:

```mathematica
       20
     /    \
    10     35
   /     /    \
  5     23     57
              /  \
             42   60
```

Mostre como a árvore ficaria se:

A. Inserção do nó `1`;  
B. Inserção do nó `65`;  
C. Inserção do nó `37`;  
D. Remoção do nó `10`.

> Para cada item, desenhe a árvore resultante após os reequilíbrios necessários, indicando claramente quais rotações foram realizadas.

## Q2. Fator de Balanceamento

Considere a rotação dupla à esquerda-direita usada para corrigir o desbalanceamento de uma árvore AVL:

Antes:
```mathematica
          a (bf=2)
         / \
       T1   c (bf=-1)
           / \
   (bf=1) b   T4
         / \
        T2  T3
```

Depois:
```mathematica
            b
         /     \
        a       c
       / \     / \
      T1  T2  T3 T4
```

Determine os fatores de balanceamento finais dos nós `a`, `b` e `c` após a rotação.
Explique como esses valores podem ser calculados a partir da configuração inicial.

## Q3. Verificação de AVL
Implemente uma função que receba a raiz de uma árvore binária e verifique se ela é uma árvore AVL.
A função deve garantir que, para cada nó:
* A diferença entre as alturas das subárvores esquerda e direita não ultrapasse $1$.
* A chave obedeça à propriedade da BST: maior que as chaves à esquerda e menor que as da direita.

## Q4. Rotações e atualização de metadados

Suponha uma implementação de AVL com a representação a seguir:

```cpp
struct Node {
    int key;
    int value;
    int height;
    Node* left;
    Node* right;
};
```

(a) Implemente a operação de rotacao a direita convencional:
```cpp
Node* rotateRight(Node *n)
```
(b) Suponha agora que acrescentamos um campo `int numNodes` à struct `Node`, representando o número de nós na subárvore enraizada naquele nó.
 Modifique sua implementação da rotação à direita para atualizar corretamente os valores de `numNodes`.

> Lembre-se de atualizar também os campos de `height` após a rotação.