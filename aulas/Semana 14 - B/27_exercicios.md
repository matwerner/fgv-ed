# Aula 27: Lista de Exercícios sobre Árvores B

## Questão 1

Descreva a estrutura de dados que resultaria se cada nó **preto** em uma Árvore Rubro-Negra **fosse fundido com seus filhos vermelhos**, e os filhos dos nós vermelhos passassem a ser filhos diretos desse nó preto.

- Qual seria a forma resultante?
- Essa estrutura é semelhante a que outro tipo de árvore?
- Como essa transformação ajuda a visualizar a relação entre Árvores Rubro-Negras e Árvores B?

## Questão 2

Mostre **todas as B-árvores válidas de grau mínimo 2** (ou seja, grau $t = 2$) que representam o conjunto de chaves:

$$
\{1, 2, 3, 4, 5\}
$$

- Considere diferentes ordens de inserção, se aplicável.
- Lembre-se que cada nó (exceto a raiz) deve conter pelo menos $t-1 = 1$ chave e no máximo $2t - 1 = 3$ chaves.

## Questão 3

Explique:
1. Como encontrar a **chave mínima** armazenada em uma B-árvore?
2. Como encontrar o **predecessor** de uma determinada chave armazenada em uma B-árvore?

Dê exemplos e descreva o percurso necessário na estrutura da árvore para realizar essas operações.

## Questão 4

Mostre os resultados da inserção das chaves, em ordem:

$$
6,\ 19,\ 17,\ 11,\ 3,\ 12,\ 8,\ 20,\ 22,\ 23,\ 13,\ 18,\ 14,\ 16,\ 1,\ 2,\ 24,\ 25,\ 4,\ 26,\ 5
$$

em uma **B-árvore vazia** com grau mínimo $t = 2$.

- **Desenhe apenas** as configurações da árvore **imediatamente antes de algum nó ser repartido**.
- Mostre também a **configuração final** da árvore depois de todas as inserções.

## Questão 5

Mostre os resultados da **remoção das chaves 3, 16 e 22**, nesta ordem, da árvore abaixo:

```
      |5,     12,     16,     20,      24|
   /       /       /       \        \       \
|1 3|  |10 11| |14 15| |17 18 19| |21 22| |25 26|
```

- Mostre o estado da árvore após **cada remoção**.
- Caso ocorra **fusão ou redistribuição**, destaque as mudanças ocorridas.