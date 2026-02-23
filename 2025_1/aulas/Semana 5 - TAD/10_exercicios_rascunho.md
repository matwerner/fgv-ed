# Aula 10: Rascunho de algumas das soluções dos exercícios discutidos em aula

## Questão 4

```cpp
// Considerar que existem funções createQueue, deleteQueue, enqueue, dequeue
struct Queue {
    int* data;
    int size;
    int maxSize;
}

// Considerar que existem funções createStack, deleteStack, push, pop
struct Stack {
    int* data;
    int size;
    int maxSize;
}

Queue* reverse(Queue* l) {
    Stack* s = createStack(l->maxSize);
    while(l.size > 0) {
        push(s, dequeue(l));
    }

    Queue* r = createQueue(l->maxSize);
    while(s.size > 0) {
        enqueue(r, pop(s));
    }

    deleteStack(s);
    return r;
}
```

## Questão 5

Considerando que temos duas pilhas `A` e `B` e o array tem tamanho `n`:
* A pilha `A` cresce a partir do indice `0` em direção ao meio do array, ocupando os indices `{0, 1, 2, ...}`;
* A pilha `B` cresce a partir do indice `n-1` em direção ao meio do array, ocupando os indices `{n-1, n-2, n-3, ...}`;
* Não haverá conflitos entre as pilhas enquanto $A.size +  B.size \le n$.

## Questão 6

## Questão 7

Basta utilizar a implementação da fila com array circular, visto em aula.
A partir dela, as funções `Inserir no fim` (originalmente, `enqueue`) e `Remover do início` (originalmente, `dequeue`) já estão implementadas de forma eficiente.
Restam apenas implementar `Inserir no início` e `Remover do fim`, as quais também podem ser feitas eficientemente, baseando-se nas duas funções anteriores.

* **Inserir no início**:
Podemos fazer isso movendo o índice `head` para a posição anterior: `data[head - 1] = x`.
* **Remover do fim**:
Da mesma forma, ao remover do fim, basta ajustar `tail` para a posição anterior: `x = data[tail - 1]`.

**Obs**: Lembrar de atualizar as posições do `head` e `tail` levando em conta os limites do array.

## Questão 8

## Questão 9

## Questão 10

(a)
Basta percorrer internamente os elementos válidos da fila para encontrar o menor valor.

(b) 
Se soubéssemos que os valores inseridos sempre pertencem ao intervalo $[1,10]$, poderíamos manter um array `frequencies` de tamanho 11, onde `frequencies[i]` armazenaria a quantidade de ocorrências do valor $i$ na fila.

* Inserção (enqueue): Ao adicionar um elemento $x$, incrementamos `frequencies[x]`.
* Remoção (dequeue): Ao remover um elemento, decrementamos `frequencies[data[head]]`.
* Consulta (getMinValue): Percorremos `frequencies` a partir do índice $0$ até encontrar a primeira posição com valor maior que zero, pois ela representa o menor número presente na fila.

Essa abordagem garante que getMinValue seja `O(1)`, pois sempre verificamos no máximo $10$ posições, independentemente do tamanho da fila.