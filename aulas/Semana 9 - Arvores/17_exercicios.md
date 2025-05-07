# Aula 17: Lista de Exercícios sobre Árvores Binárias

> Para facilitar, aonde for cabível, utilizar como exemplo a árvore binária abaixo:

```mathematica
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
              \
               8
```

## Q1. Travessias em árvore

Escreva as sequências correspondentes às três travessias clássicas:
- A. Pré-ordem  
- B. Pós-ordem  
- C. In-ordem  

## Q2. Reconstrução da árvore

Dadas as seguintes travessias:

- Pré-ordem: `1, 2, 4, 5, 3, 6, 7`  
- In-ordem: `4, 2, 5, 1, 6, 3, 7`

Reconstrua a árvore binária correspondente.

## Q3. Altura de cada nó

Implemente um algoritmo que calcule a **altura de cada nó** da árvore.  
A altura de um nó é o maior número de arestas até uma folha.  
A solução deve ter complexidade **O(n)**.

## Q4. Profundidade de cada nó

Calcule a **profundidade de cada nó** da árvore.  
A profundidade de um nó é o número de arestas até a raiz.  
A solução deve ter complexidade **O(n)**.

## Q5. Contagem de nós

Escreva uma função que retorne o **número total de nós** de uma árvore binária.

## Q6. Exibição da árvore no terminal

Implemente duas formas diferentes de exibir uma árvore binária no terminal:

- A. **Na horizontal**, com indentação proporcional à profundidade.
	```
		        8
			7
		3
			6
	1
			5
		2
			4
	```
- B. **Estilo diretório**, como no comando `tree`.
	```bash
	1
	├── 2
	│   ├── 4
	│   └── 5
	└── 3
		├── 6
		└── 7
			└── 8
	```

## Q7. Comparação estrutural

Dadas duas árvores binárias, determine se elas são **estruturalmente iguais** (mesma forma e mesmos valores nos mesmos lugares).

## Q8. Clonagem de árvore

Implemente uma função que **clona uma árvore binária**, retornando uma nova árvore com a mesma estrutura e valores.

## Q9. Menor ancestral comum (LCA)

Implemente uma função que, dados dois valores de nós em uma árvore binária, retorne o seu **menor ancestral comum** (*Lowest Common Ancestor* – LCA).

```bash
Entrada: nós 4 e 5  
Saída: LCA = 2

Entrada: nós 4 e 6  
Saída: LCA = 1

Entrada: nós 7 e 8  
Saída: LCA = 7

Entrada: nós 5 e 8  
Saída: LCA = 1
```

## Q10. Caminhos da raiz até folhas

Escreva uma função que **imprima todos os caminhos da raiz até cada folha** da árvore.

```bash
1 -> 2 -> 4
1 -> 2 -> 5
1 -> 3 -> 6
1 -> 3 -> 7 -> 8
```
