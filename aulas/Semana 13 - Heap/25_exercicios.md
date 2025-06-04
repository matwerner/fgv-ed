# Aula 25: Lista de Exercícios sobre Heaps

## Questão 1

Uma sequência de elementos em ordem crescente é um **min-heap**?

## Questão 2

A sequência abaixo representa um heap?

```python
[23, 17, 14, 6, 13, 10, 1, 5, 7, 12]
```

Ela é um **max-heap**? Justifique sua resposta.

## Questão 3

Em um **heap de máximo**, qual é a **posição possível do menor elemento**, assumindo que todos os elementos são distintos? Justifique sua resposta com base na estrutura do heap.

## Questão 4

Suponha que estamos implementando um **max-heap** usando um **array**, como visto em aula. Sabemos que a ordem de inserção foi:

```python
100 → 50 → 190 → 10 → 280 → 180 → 40 → 165 → 175
```

**(a)** Desenhe a árvore do heap após **cada inserção**.

**(b)** Mostre como ficará o **array final** após todas as inserções.

**(c)** Em seguida, realize **duas remoções sucessivas** do topo (duas extractMax). Mostre como o **array se modifica após cada remoção**.

**(d)** Explique brevemente os passos envolvidos na sua resposta.

## Questão 5

Você precisa manter uma lista com os **k maiores elementos** enquanto percorre uma **sequência com milhões de números**, que é **lida uma única vez** e **não sofre remoções**.

**(a)** Explique como uma **heap** pode ser usada para resolver isso com eficiência.

**(b)** Qual é o custo computacional da sua abordagem?

## Questão 6

Considere a estrutura de dados a seguir que representa uma **max-heap**:

```cpp
struct Heap {
	int* data;    // vetor das prioridades
	int capacity; // tamanho máximo do heap
	int size;     // próxima posição disponível no vetor
};
```

A seguir, temos um esboço da função de remoção do topo:

```cpp
int extractTop(Heap* heap, int* value) {
	if (heap->size == 0) {
		return 0;
	}
	
	int topo = heap->data[0];
	heap->data[0] = heap->data[heap->size - 1];
	heap->size--;
	heapifyDown(heap->data, 0, heap->pos);
	return 1;
}
```

**Implemente a função `heapifyDown` que reorganiza os elementos a partir do topo para restaurar a propriedade do heap.**

## Questão 7

Ilustre o processo de construção (`buildMaxHeap`) da heap utilizando a abordagem bottom-up a partir da seguinte sequência:

```python
[5, 3, 17, 10, 84, 19, 6, 22, 9]
```

Mostre a árvore e o array intermediário conforme os swaps ocorrem.

## Questão 8

Implemente a função `buildMaxHeap` com **complexidade O(n)**.

## Questão 9

Ilustre a execução do algoritmo `HeapSort` sobre a seguinte sequência de inteiros:

```python
[5, 13, 2, 25, 7, 17, 20, 8, 4]
```

Mostre:
- A heap construída inicialmente  
- O array após cada remoção do topo  
- A ordenação final
