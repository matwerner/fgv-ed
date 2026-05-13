# Aula 18: Lista de Exercícios sobre Árvores Binárias

Nesta lista, vamos praticar operações fundamentais sobre árvores binárias: percursos, busca, altura, profundidade, relações entre nós e comparação entre árvores.

Sempre que possível, utilize como exemplo a árvore abaixo:

```text
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
              \
               8
```

Uma possível estrutura para representar os nós é:

```cpp
class Node {

public:
    int value;
    Node* left;
    Node* right;

	Node(int value) {
		this->value = value;
		this->left = nullptr;
		this->right = nullptr;
	}
};
```

## Parte 1: Percorrendo a árvore

### Q1. Travessias em árvore

Escreva as sequências correspondentes às três travessias clássicas da árvore:

* Pré-ordem
* In-ordem
* Pós-ordem

### Q2. Reconstrução da árvore

Dadas as seguintes travessias:

```text
Pré-ordem: 10, 5, 2, 7, 6, 20, 30
In-ordem:  2, 5, 6, 7, 10, 20, 30
```

Reconstrua a árvore binária correspondente.

Explique brevemente como você identificou:
* qual é a raiz;
* quais nós pertencem à subárvore esquerda;
* quais nós pertencem à subárvore direita.

### Q3. Contagem de nós

Implemente a função `int countNodes(Node* root)` que retorna o número total de nós de uma árvore binária.

Exemplo:
```text
Entrada: árvore de exemplo
Saída: 8
```

### Q4. Contagem de folhas

Implemente a função `int countLeaves(Node* root)` que retorna o número de folhas de uma árvore binária.

Exemplo:
```text
Entrada: árvore de exemplo
Saída: 4 (as folhas são: 4, 5, 6 e 8)
```

## Parte 2: Altura, profundidade e busca

### Q5. Altura da árvore

Implemente uma função `int height(Node* root)` que calcula a altura de uma árvore binária.

A maior distância da raiz até uma folha é:

```text
Entrada: árvore de exemplo
Saída: 3 (Caminho mais longo: 1 -> 3 -> 7 -> 8)
```

### Q6. Verificar se um valor existe na árvore

Implemente a função `bool contains(Node* root, int value)` que verifica se um valor existe na árvore.

Exemplos:
```cpp
contains(root, 5);  // true
contains(root, 10); // false
```

### Q7. Profundidade de um valor específico

Implemente a função `int depth(Node* root, int value)` que retorna a profundidade de um valor específico na árvore.

Exemplos:

```text
depth(root, 1) = 0
depth(root, 2) = 1
depth(root, 4) = 2
depth(root, 8) = 3
```

Caso o valor não exista na árvore, retorne `-1`.

### Q8. Encontrar e retornar o ponteiro para um nó

Implemente uma função `Node* find(Node* root, int value)` que encontra um valor na árvore e retorna o ponteiro para o nó correspondente.

Exemplos:
```cpp
Node* node = find(root, 7);
```

Se o valor existir, a função deve retornar o endereço do nó correspondente.

Se o valor não existir, a função deve retornar `nullptr`.

## Parte 3: Relações entre nós

### Q9. Pai de um nó

Implemente a função `Node* parent(Node* root, int value)` que retorna o pai de um nó com determinado valor.

Exemplos:
```text
parent(root, 2) = nó com valor 1
parent(root, 4) = nó com valor 2
parent(root, 8) = nó com valor 7
```

Caso o valor esteja na raiz, a função deve retornar `nullptr`, pois a raiz não possui pai.

Caso o valor não exista na árvore, a função também deve retornar `nullptr`.

### Q10. Irmão de um nó

Implemente a função `Node* sibling(Node* root, int value)` que retorna o irmão de um nó com determinado valor.

Exemplos:
```text
sibling(root, 2) = nó com valor 3
sibling(root, 4) = nó com valor 5
sibling(root, 6) = nó com valor 7
```

Caso o nó não tenha irmão, retorne `nullptr`.

Caso o valor não exista na árvore, retorne `nullptr`.

### Q11. Tio de um nó

Implemente a função `Node* uncle(Node* root, int value)` que retorna o tio de um nó com determinado valor.

Exemplos:
```text
uncle(root, 4) = nó com valor 3
uncle(root, 5) = nó com valor 3
uncle(root, 6) = nó com valor 2
uncle(root, 8) = nó com valor 6
```

Caso o nó não tenha tio, retorne `nullptr`.

### Q12. Imprimir todos os valores da subárvore de um nó

Dado um valor, implemente a função `void printSubtree(Node* root, int value)` que encontra o nó correspondente e imprime todos os valores da subárvore enraizada nesse nó.

Exemplo:

```text
printSubtree(root, 3);

Uma saída possível, usando pré-ordem, seria:
3 6 7 8
```

### Q13. Retornar todos os valores da subárvore de um nó

Dado um valor, implemente a função `std::vector<int> valuesInSubtree(Node* root, int value)` que encontra o nó correspondente e retorne todos os valores da subárvore enraizada nesse nó.

Utilize `std::vector<int>` para facilitar.

Exemplo:
```cpp
std::vector<int> values = valuesInSubtree(root, 3);

Resultado esperado, considerando pré-ordem:
[3, 6, 7, 8]
```

Caso o valor não exista na árvore, retorne um vetor vazio.

Dica: você pode separar o problema em duas partes:
1. encontrar o nó com o valor desejado;
2. percorrer a subárvore desse nó e guardar os valores no vetor.

Uma possível função auxiliar seria:
```cpp
void collectValues(Node* root, std::vector<int>& values);
```

## Parte 4: Estrutura da árvore

### Q14. Comparar se duas árvores têm a mesma forma

Dadas duas árvores binárias, implemente a função `bool sameShape(Node* a, Node* b)` que verifica se elas têm a mesma estrutura, ignorando os valores armazenados nos nós.

Exemplo:
```text
Árvore A:

    1
   / \
  2   3

Árvore B:

    10
   /  \
  20   30

As duas árvores têm a mesma forma, mesmo possuindo valores diferentes.

Resultado:
true
```

Agora considere:

```text
Árvore A:

    1
   / \
  2   3

Árvore B:

    10
   /
  20

Resultado:
false
```

### Q15. Comparar se duas árvores são iguais

Dadas duas árvores binárias, implemente a função `bool equals(Node* a, Node* b)` que verifica se elas são iguais.

Duas árvores são iguais quando:
* possuem a mesma estrutura;
* possuem os mesmos valores nas mesmas posições.


Exemplo:

```text
Árvore A:

    1
   / \
  2   3

Árvore B:

    1
   / \
  2   3

Resultado:
true
```

Agora considere:

```text
Árvore A:

    1
   / \
  2   3

Árvore B:

    1
   / \
  2   4

Resultado:
false
```

## Parte 5: Desafios

### Q16. Caminho da raiz até um valor

Dado um valor, implemente a função `bool printPath(Node* root, int value)` que imprime o caminho da raiz até esse valor.

Exemplos:
```text
printPath(root, 8);
Saída: 1 -> 3 -> 7 -> 8
```

Outro exemplo:

```text
printPath(root, 5);
Saída: 1 -> 2 -> 5
```

Caso o valor não exista na árvore, informe que o valor não foi encontrado.

### Q17. Menor ancestral comum

Dados dois valores presentes na árvore, implementa a função `Node* lowestCommonAncestor(Node* root, int value1, int value2)` que encontra o menor ancestral comum entre eles.

O menor ancestral comum, ou LCA, é o nó mais baixo da árvore que ainda é ancestral dos dois valores.

Exemplos:

```text
Entrada: 4 e 5
Saída: 2

Porque:
1 -> 2 -> 4
1 -> 2 -> 5

O último nó em comum nos dois caminhos é `2`.
```

Outro exemplo:

```text
Entrada: 4 e 6
Saída: 1

Porque:
1 -> 2 -> 4
1 -> 3 -> 6

O último nó em comum nos dois caminhos é `1`.
```

Outro exemplo:

```text
Entrada: 7 e 8
Saída: 7

Porque `7` é ancestral de `8`.
```
