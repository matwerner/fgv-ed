# Aula 23: Lista de Exercícios sobre Árvores Rubro-Negras

## Questão 1
Mostre as árvores rubro-negras que resultam após a inserção sucessiva das chaves `41, 38, 31, 12, 19, 8` em uma árvore rubro-negra inicialmente vazia.  

Além disso, como ficaria a árvore se inseríssemos os mesmos valores, na mesma ordem, em:

- uma árvore AVL?
- uma árvore binária de busca (BST)?

## Questão 2
Insira as chaves `9, 8, 7, 6, 1, 2, 3, 4, 5` (nesta ordem) em uma árvore rubro-negra, desenhando a árvore após **cada inserção**.

## Questão 3
Insira as chaves `4, 7, 12, 15, 3, 5, 14, 18` (nesta ordem) em uma árvore rubro-negra.  

Desenhe a árvore **apenas após cada rotação ou troca de cores**.

## Questão 4
Demonstre com contra-exemplos que as afirmações abaixo são **falsas**:

A. Toda árvore AVL é uma árvore rubro-negra.  
B. Toda árvore rubro-negra é uma árvore AVL.

> Para cada item, mostre um exemplo concreto de árvore que satisfaz uma estrutura mas não a outra.

## Questão 5
Suponha que a **altura preta** de cada uma das subárvores `α, β, γ, d`, nas Figuras 13.5 e 13.6 (na seção de inserção da aula passada), seja `k`.  

Identifique cada nó em cada figura com sua altura preta e **verifique se a transformação indicada preserva a Propriedade 4** da árvore rubro-negra.

## Questão 6
O professor Teach está preocupado que a função `fixInsert` possa atribuir `T->NIL` com a cor **vermelha**, caso em que o `while` não terminaria quando `z` fosse a raiz.  

Mostre que a preocupação do professor é **infundada**, demonstrando que a função `fixInsert` **nunca** atribui a cor vermelha a `T.nil`.

## Questão 7
Desenvolva um **algoritmo** que receba uma árvore rubro-negra e retorne a **quantidade de nós pretos** da árvore.

## Questão 8
Desenvolva um **algoritmo** que receba uma árvore rubro-negra e retorne a **quantidade de nós vermelhos** da árvore.

## Questão 9
Desenvolva um **algoritmo** que, dada uma árvore rubro-negra e uma inserção já realizada, **verifique se todas as propriedades da estrutura ainda são válidas**.

> Propriedades a verificar:
> - Todo nó é vermelho ou preto.
> - A raiz e todas as folhas (NIL) são pretas.
> - Um nó vermelho não pode ter filhos vermelhos.
> - Todo caminho de um nó até suas folhas descendentes nulas contém o mesmo número de nós pretos.
