# Aula 24: Lista de Exercícios sobre Heaps

## Q1. Inserções em uma Max-Heap

Considere uma max-heap inicialmente vazia.

Insira os elementos na seguinte ordem:

```text
100 → 50 → 190 → 10 → 280 → 180 → 40 → 165 → 175
```

Mostre a configuração da heap após cada inserção em sua **representação em forma de árvore (heap completa) e array**, indicando as trocas realizadas pelo procedimento de subida (*heapifyUp*), quando ocorrerem.

## Q2. Remoções em uma Max-Heap

Considere a seguinte max-heap:

```cpp
[280, 190, 180, 175, 100, 50, 40, 10, 165]
```

Execute duas operações consecutivas de:

```cpp
extractMax()
```

Para cada remoção, mostre a configuração final da heap em sua **representação em forma de árvore (heap completa) e array** e indique os principais passos do *heapifyDown*.

## Q3. Verificação de Heap

Considere os arrays abaixo:

```cpp
A = [40, 30, 35, 10, 20, 25, 5]
B = [40, 30, 35, 10, 50, 25, 5]
```

Para cada caso:

* Verifique se o array representa uma max-heap
* Justifique analisando as relações pai–filho
* Caso não seja heap, indique a primeira violação encontrada

## Q4. Propriedades do menor elemento em uma Max-Heap

Considere uma max-heap com elementos distintos.

Responda:

* Em que posições o menor elemento pode aparecer?
* Ele pode ser raiz?
* Ele pode estar em um nó interno?

Justifique com base na propriedade de max-heap.

## Q5. Construção Bottom-Up

Dado o array:

```cpp
[5, 3, 17, 10, 84, 19, 6, 22, 9]
```

Construa uma max-heap utilizando o algoritmo bottom-up.

Mostre:

* O estado do array a cada etapa relevante do algoritmo
* A heap final em sua **representação em forma de árvore (heap completa)**

## Q6. HeapSort

Considere o array:

```cpp
[5, 13, 2, 25, 7, 17, 20, 8, 4]
```

Execute o algoritmo HeapSort.

Mostre:

* A max-heap inicial construída
* O estado do array após cada iteração da fase de ordenação
* O resultado final ordenado

## Q7. Implementação de HeapifyDown

Considere a estrutura:

```cpp
struct Heap {
    int* data;
    int capacity;
    int size;
};
```

Implemente a função:

```cpp
void heapifyDown(int data[], int pos, int size);
```

responsável por restaurar a propriedade de max-heap após a remoção da raiz.

## Q8. Construção de Max-Heap

Implemente a função:

```cpp
void buildMaxHeap(int data[], int size);
```

utilizando abordagem bottom-up.

Explique por que essa construção possui complexidade **O(n)**, mesmo utilizando `heapifyDown` repetidamente.

## Q9. Aplicação: Top-K elementos

Você precisa manter os **k maiores elementos** de uma sequência de milhões de números que:

* são processados uma única vez
* não podem ser armazenados integralmente em memória

Responda:

* Como uma heap pode ser usada para resolver esse problema?
* Qual tipo de heap deve ser utilizada?
* Qual a complexidade por elemento processado?
* Qual a vantagem dessa abordagem em relação à ordenação completa?
