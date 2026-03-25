# Aula 10: Exercícios sobre Tipos Abstratos de Dados (TAD)

## Questão 1

Dada a estrutura de pilha, ilustre o estado da pilha após a execução sequencial das seguintes operações:
(**OBS**: O estado B leva em conta as operações feitas no estado A)

(a) push(10) -> push(70) -> push(25) -> push(-50);\
(b) pop() -> pop();\
(c) push(13) -> pop() -> pop() -> push(10).

## Questão 2

Dada a estrutura de fila, ilustre o estado da fila após a execução sequencial das seguintes operações:
(**OBS**: O estado B leva em conta as operações feitas no estado A)

(a) enqueue(10) -> enqueue(70) -> enqueue(25) -> enqueue(-50);\
(b) dequeue() -> dequeue();\
(c) enqueue(13) -> dequeue() -> dequeue() -> enqueue(10).

## Questão 3

Dada a estrutura de fila implementada com um array de tamanho `4`, ilustre o estado do array após a execução sequencial das seguintes operações:
(**OBS**: O estado B leva em conta as operações feitas no estado A)

(a) enqueue(10) -> enqueue(70) -> enqueue(25) -> enqueue(-50);\
(b) dequeue() -> dequeue();\
(c) enqueue(13) -> dequeue() -> dequeue() -> enqueue(10).

Explique brevemente qual problema pode ocorrer nessa implementação após várias operações.

## Questão 4

Considere a seguinte classe:

```cpp
class FilaArray {
private:
    int capacity;  // Tamanho do array
    int* data;     // Array de dados 
    int size;      // Número de posições atualmente ocupadas

public:
    FilaArray(int capacity);
    ~FilaArray();
    bool enqueue(int value);
    bool dequeue(int& value);
    bool isEmpty();

    void reverse(); // <-- método a ser implementado
};
```

Implemente o método `reverse()` que inverte a ordem dos elementos armazenados no array `data`.

**Exemplo:**

Antes:
`[10, 20, 30, 40]`

Depois:
`[40, 30, 20, 10]`

**Observações:**

* Considere que os demais métodos e atributos estão corretamente implementados;
* Você pode acessar diretamente os elementos do array `data` por índice;
* A inversão deve ser feita **in-place** (ou seja, modificando o próprio array);
* Não é permitido criar uma nova fila auxiliar.

## Questão 5

Agora considere também a seguinte classe:

```cpp
class PilhaArray {
public:
    PilhaArray(int capacity);
    ~PilhaArray();
    bool push(int value);
    bool pop(int& value);
    bool isEmpty();
};
```

Implemente novamente o método `reverse()` da classe `FilaArray`, porém agora **sem acessar diretamente o array `data`**.

**Restrições:**

* A inversão deve ser feita utilizando uma pilha (`PilhaArray`);
* Você deve utilizar apenas as operações públicas da fila (`enqueue`, `dequeue`, `isEmpty`);
* Não é permitido acessar diretamente os atributos internos da fila (`data`, `size`, etc.);
* A fila deve ser modificada ao final da operação (in-place).

## Questão 6

Implemente uma classe `DynamicArray` com os seguintes atributos:

* `int* data`
* `int size`
* `int capacity`

e com, pelo menos, os seguintes métodos:

```cpp
class DynamicArray {
public:
    DynamicArray(int capacity);
    ~DynamicArray();
    bool pushBack(int value);
    int get(int index);
    void concat(const DynamicArray& other);
};
```

O método `concat` deve concatenar os elementos de `other` ao final do array atual.

Responda:

(a) O que deve ser feito caso não haja capacidade suficiente?\
(b) Qual o custo da operação de concatenação?

## Questão 7

Enquanto uma TAD pilha permite inserção e remoção de elementos apenas em uma extremidade e uma TAD fila permite inserção em uma extremidade e remoção na outra, uma TAD deque (double-ended queue) permite inserção e remoção em ambas as extremidades.

Implemente uma classe `DequeArray` com operações de tempo $O(1)$ para:

* Inserir no início
* Inserir no fim
* Remover do início
* Remover do fim

**OBS:** Utilize um array circular.

## Questão 8

Mostre como implementar uma fila utilizando duas pilhas.

Analise o tempo de execução das operações.

## Questão 9

Implemente uma classe `StackMin` que represente uma pilha de inteiros e suporte as seguintes operações:

* `push(int value)`
* `pop(int& value)`
* `getMinValue(int& value)`
* `isEmpty()`

### Estrutura base:

```cpp
class StackMin {
private:
    int* data;
    int size;
    int capacity;

    // Estruturas adicionais, se necessário

public:
    StackMin(int capacity);
    ~StackMin();

    bool push(int value);
    bool pop(int& value);
    bool getMinValue(int& value);
    bool isEmpty();
};
```

### (a)

Implemente o método `getMinValue` com complexidade $O(n)$.

**Observação:**

* O método deve retornar `true` se a operação for bem-sucedida e armazenar o menor valor em `value`;
* Caso a pilha esteja vazia, deve retornar `false`.

### (b)

Proponha uma modificação na classe `StackMin` para que o método `getMinValue` opere em tempo $O(1)$.

Responda:

* Quais estruturas adicionais seriam necessárias?
* Como essas estruturas seriam atualizadas durante `push` e `pop`?

**Observação:**
A solução deve garantir que todas as operações (`push`, `pop` e `getMinValue`) permaneçam com custo $O(1)$.

## Questão 10

Agora, dada uma fila, implemente a operação `getMinValue`, que retorna o menor valor na fila:

(a) Implemente a função com complexidade $O(n)$\
(b) Proponha uma estratégia para melhorar o desempenho dessa operação e discuta suas limitações.

## Questão 11

Você precisa implementar um sistema de atendimento em um restaurante com as seguintes características:

* pedidos chegam continuamente;
* pedidos são preparados na ordem de chegada;
* pedidos podem ser cancelados antes de serem preparados.

Responda:

(a) Qual estrutura de dados você utilizaria?\
(b) Justifique sua escolha com base no comportamento esperado;\
(c) Quais operações são necessárias;\
(d) Quais limitações essa escolha possui?

## Questão 12

Você precisa implementar um sistema para gerenciar as abas abertas de um navegador.

O sistema deve permitir:

* abrir uma nova aba;
* fechar qualquer aba a partir de sua posição;
* avançar para a próxima aba;
* voltar para a aba anterior;
* exibir a aba atualmente ativa.

Responda:

(a) Qual estrutura de dados você utilizaria?\
(b) Justifique sua escolha;\
(c) Quais operações seriam necessárias;\
(d) Explique por que outras estruturas vistas na disciplina seriam menos adequadas.
