# Aula 14: Recursão

## 1. Motivação

Até agora no curso, trabalhamos principalmente com manipulações sobre **estruturas lineares**, como arrays, listas encadeadas, pilhas e filas.

Nesses casos, muitas operações podem ser descritas naturalmente com laços de repetição.
Por exemplo, para percorrer um array ou uma lista, normalmente usamos um `for` ou um `while`.

No entanto, na próxima parte do curso, começaremos a estudar algoritmos e estruturas em que essa forma de pensar nem sempre é a mais natural.
Veremos algoritmos de ordenação mais avançados, como **merge sort** e **quick sort**, além de estruturas que não são simplesmente lineares.

Nesses casos, a recursão passa a ser uma ferramenta importante, pois permite resolver problemas dividindo-os em versões menores do mesmo problema.

A ideia central desta aula é entender como pensar recursivamente, e não apenas decorar a sintaxe de uma função que chama a si mesma.



## 2. Recursão

Recursão é uma técnica em que uma função é definida em termos dela mesma.

De forma geral, uma função recursiva tem uma estrutura parecida com esta:

```cpp
func(n) = func(n - 1) + algum_processamento
````

A ideia principal é resolver um problema a partir de versões menores desse mesmo problema.

Por exemplo, em vez de tentar resolver diretamente o problema para um valor `n`, tentamos resolver primeiro o problema para `n - 1`, `n - 2`, ou alguma outra versão menor. Depois, usamos essa solução menor para construir a solução do problema original.

No entanto, é importante destacar:

> Recursão não é mágica. Ela apenas organiza a solução de um problema que pode ser naturalmente dividido em problemas menores.

Para usar recursão corretamente, precisamos responder três perguntas:

1. Qual problema essa função resolve?
2. Qual é o menor caso possível, que pode ser resolvido diretamente?
3. Como a solução de um caso menor ajuda a resolver o caso atual?



## 3. Estrutura de uma função recursiva

Uma função recursiva normalmente possui duas partes principais: o **caso base** e o **passo recursivo**.

### Caso base

O caso base é a situação mais simples do problema, em que não precisamos fazer uma nova chamada recursiva.

Ele serve como condição de parada da recursão.

Sem um caso base, a função continuaria chamando a si mesma indefinidamente, até causar um erro de execução, como estouro da pilha de chamadas.

Exemplo conceitual:

```cpp
if (n == 0) {
    return algum_valor_simples;
}
```

### Passo recursivo

O passo recursivo é a parte da função em que chamamos a própria função novamente, mas com uma entrada menor ou mais simples.

A chamada precisa caminhar em direção ao caso base.

Exemplo conceitual:

```cpp
return alguma_coisa + func(n - 1);
```

Se a chamada recursiva não reduzir o problema, a recursão não termina.



## 4. Pensando recursivamente

Ao escrever uma função recursiva, não devemos tentar imaginar todas as chamadas ao mesmo tempo.

Uma forma melhor de pensar é definir claramente o que a função faz.

Por exemplo:

```cpp
soma(arr, n)
```

pode ser entendida como:

> A função `soma(arr, n)` retorna a soma dos primeiros `n` elementos do array `arr`.

Depois de definir esse contrato, podemos pensar:

Se `soma(arr, n - 1)` já sabe somar os primeiros `n - 1` elementos, então para somar os primeiros `n` elementos basta adicionar o elemento que ficou faltando.

Ou seja:

```cpp
soma(arr, n) = soma(arr, n - 1) + arr[n - 1]
```

Esse raciocínio é parecido com uma prova por indução:

* resolvemos um caso simples;
* assumimos que conseguimos resolver um caso menor;
* usamos a solução menor para resolver o caso atual.

Essa é uma das ideias mais importantes da recursão.



## 5. Modelo mental: pilha de chamadas

Quando uma função chama outra função, o programa precisa guardar:
* onde a execução parou
* e quais eram os valores das variáveis naquele momento

Isso também acontece em chamadas recursivas.

Mesmo que seja **a mesma função sendo chamada várias vezes**, cada chamada possui seus próprios dados.

O código da função existe apenas uma vez na memória, mas **cada chamada cria um novo “contexto de execução”**, contendo:
* os parâmetros da função
* as variáveis locais
* o ponto para onde o programa deve voltar após terminar

Esses contextos são armazenados na **pilha de chamadas**.

A chamada mais recente fica no topo da pilha e é a que está sendo executada no momento.

As chamadas anteriores ficam “pausadas”, esperando o resultado da chamada atual para continuar.

Exemplo conceitual:

```text
f(3)
    espera f(2)
        espera f(1)
            espera f(0)
                retorna valor base
            retorna resultado de f(1)
        retorna resultado de f(2)
    retorna resultado de f(3)
```

As chamadas descem até o caso base. Depois disso, os retornos acontecem no sentido inverso: da chamada mais profunda para a chamada inicial.

Por isso, é comum dizer que a recursão tem dois momentos:

```text
1. A ida: as chamadas recursivas vão sendo feitas.
2. A volta: os resultados vão sendo combinados.
```

Esse comportamento será importante em diversos algoritmos, especialmente quando quisermos processar algo antes ou depois da chamada recursiva.

Considere o exemplo:

```cpp
void exemplo(int n) {
    if (n == 0) return;

    cout << "Antes: " << n << endl;
    exemplo(n - 1);
    cout << "Depois: " << n << endl;
}
```

Ao chamar:

```cpp
exemplo(3);
```

a saída será:

```text
Antes: 3
Antes: 2
Antes: 1
Depois: 1
Depois: 2
Depois: 3
```

Isso acontece porque o código antes da chamada recursiva é executado durante a ida. Já o código depois da chamada recursiva é executado durante a volta.



## 6. Exemplos

### Exemplo 1: Fatorial

A função fatorial é um exemplo clássico de recursão.

A definição matemática é:

```text
n! = n * (n - 1)!
0! = 1
```

Ou seja, para calcular `n!`, podemos calcular primeiro `(n - 1)!` e depois multiplicar o resultado por `n`.

#### Versão iterativa

```cpp
int fatorial(int n) {
    int resultado = 1;

    for (int i = 1; i <= n; i++) {
        resultado = resultado * i;
    }

    return resultado;
}
```

#### Versão recursiva

```cpp
int fatorial(int n) {
    if (n == 0) {
        return 1;
    }

    return n * fatorial(n - 1);
}
```

Nesse caso:

```cpp
fatorial(n)
```

significa:

> Retornar o fatorial de `n`.

O caso base é `n == 0`, pois sabemos diretamente que `0! = 1`.

O passo recursivo é:

```cpp
return n * fatorial(n - 1);
```

Aqui, assumimos que `fatorial(n - 1)` sabe calcular corretamente o fatorial de `n - 1`. Então, multiplicamos esse resultado por `n`.



### Exemplo 2: Soma dos elementos de um array

#### Problema

Dado um array, queremos somar seus elementos.

Podemos definir a função da seguinte forma:

```cpp
soma(arr, n)
```

Significado:

> Retorna a soma dos primeiros `n` elementos do array `arr`.

Se `n == 0`, não há elementos para somar. Portanto, a soma é `0`.

Se `n > 0`, podemos somar os primeiros `n - 1` elementos e depois adicionar o último elemento considerado, que está na posição `n - 1`.

#### Implementação

```cpp
int soma(int arr[], int n) {
    if (n == 0) {
        return 0;
    }

    return soma(arr, n - 1) + arr[n - 1];
}
```

Exemplo:

```cpp
int arr[] = {4, 7, 2};

soma(arr, 3);
```

A execução conceitual seria:

```text
soma(arr, 3) = soma(arr, 2) + arr[2]
soma(arr, 2) = soma(arr, 1) + arr[1]
soma(arr, 1) = soma(arr, 0) + arr[0]
soma(arr, 0) = 0
```

Na volta:

```text
soma(arr, 1) = 0 + 4 = 4
soma(arr, 2) = 4 + 7 = 11
soma(arr, 3) = 11 + 2 = 13
```



### Exemplo 3: Percorrendo uma lista encadeada

Recursão também pode ser usada para percorrer listas encadeadas.

Considere uma lista simplesmente encadeada:

```cpp
struct Node {
    int value;
    Node* next;
};
```

Queremos imprimir os elementos da lista na ordem normal.

Podemos definir a função:

```cpp
printList(node)
```

Significado:

> Imprime todos os elementos da lista a partir do nó `node`.

Se `node == nullptr`, a lista acabou. Esse é o caso base.

Caso contrário, imprimimos o valor do nó atual e depois imprimimos o restante da lista.

```cpp
void printList(Node* node) {
    if (node == nullptr) {
        return;
    }

    cout << node->value << endl;
    printList(node->next);
}
```

Nesse caso, o processamento acontece antes da chamada recursiva. Por isso, os elementos são impressos na ordem normal.



#### Imprimindo a lista em ordem reversa

Agora, suponha que queremos imprimir a lista ao contrário.

Com laços, essa tarefa não é tão direta em uma lista simplesmente encadeada, pois cada nó só aponta para o próximo. Não temos acesso direto ao nó anterior.

Com recursão, podemos usar a pilha de chamadas a nosso favor.

A ideia é:

> Primeiro percorremos até o final da lista. Depois, imprimimos os valores na volta da recursão.

```cpp
void printReverse(Node* node) {
    if (node == nullptr) {
        return;
    }

    printReverse(node->next);
    cout << node->value << endl;
}
```

Observe a diferença em relação à função anterior.

Na impressão normal:

```cpp
cout << node->value << endl;
printList(node->next);
```

Na impressão reversa:

```cpp
printReverse(node->next);
cout << node->value << endl;
```

Ou seja, a posição da chamada recursiva altera a ordem em que o processamento acontece.

Se o processamento vem antes da chamada recursiva, ele acontece na ida.

Se o processamento vem depois da chamada recursiva, ele acontece na volta.



### Exemplo 4: Busca binária

A busca binária é um exemplo de algoritmo que pode ser implementado tanto de forma iterativa quanto recursiva.

Ela funciona sobre um array ordenado.

A cada passo, olhamos para o elemento do meio:
* se o elemento do meio é o alvo, encontramos a resposta;
* se o alvo é maior que o elemento do meio, buscamos na metade direita;
* se o alvo é menor que o elemento do meio, buscamos na metade esquerda.

### Versão iterativa

```cpp
int binarySearchIterative(int arr[], int n, int target) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int middle = start + (end - start) / 2;

        if (arr[middle] == target) {
            return middle;
        }
        else if (arr[middle] < target) {
            start = middle + 1;
        }
        else {
            end = middle - 1;
        }
    }

    return -1;
}
```

### Versão recursiva

Podemos definir:

```cpp
binarySearchRecursive(arr, start, end, target)
```

Significado:

> Procura `target` no trecho do array entre as posições `start` e `end`. Se encontrar, retorna o índice. Caso contrário, retorna `-1`.

O caso base acontece quando o intervalo fica vazio:

```cpp
if (start > end) return -1;
```

A implementação fica:

```cpp
int binarySearchRecursive(
    int arr[],
    int start,
    int end,
    int target
) {
    if (start > end) {
        return -1;
    }

    int middle = start + (end - start) / 2;

    if (arr[middle] == target) {
        return middle;
    }
    else if (arr[middle] < target) {
        return binarySearchRecursive(arr, middle + 1, end, target);
    }
    else {
        return binarySearchRecursive(arr, start, middle - 1, target);
    }
}
```

A busca binária é um bom exemplo para observar que a recursão nem sempre é obrigatória.

Nesse caso, a versão iterativa é bastante simples e normalmente mais econômica em memória.

Mesmo assim, a versão recursiva ajuda a enxergar a ideia de reduzir o problema para uma metade do intervalo original.



## 7. Iteração vs recursão

Nem todo problema deve ser resolvido com recursão.

Em muitos casos, uma solução iterativa é mais simples, mais eficiente e mais fácil de controlar.

A recursão costuma ser mais adequada quando o problema possui uma estrutura naturalmente recursiva ou quando a estratégia consiste em dividir o problema em partes menores.

| Iteração                                             | Recursão                                               |
| ---------------------------------------------------- | ------------------------------------------------------ |
| Usa laços de repetição                               | Usa chamadas de função                                 |
| Geralmente consome menos memória                     | Usa a pilha de chamadas                                |
| Boa para percursos lineares simples                  | Boa para problemas definidos em termos de subproblemas |
| Normalmente mais direta para arrays e listas simples | Mais natural em divisão e conquista                    |

O ponto principal não é escolher recursão sempre.

O ponto principal é saber reconhecer quando a recursão torna a solução mais clara.



## 8. Custo e cuidados

### Tempo de execução

O tempo de execução de uma função recursiva depende de:

* quantas chamadas recursivas são feitas;
* quanto trabalho é feito em cada chamada;
* se existem chamadas repetidas para os mesmos subproblemas.

Por exemplo, uma função como fatorial faz apenas uma chamada recursiva por nível:

```cpp
fatorial(n) chama fatorial(n - 1)
```

Nesse caso, o número de chamadas cresce linearmente com `n`.

Logo, o tempo é:

```text
O(n)
```

Já em problemas que fazem mais de uma chamada recursiva por nível, o custo pode crescer mais rapidamente.

Um exemplo clássico é a implementação ingênua de Fibonacci:

```cpp
int fib(int n) {
    if (n <= 1) {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}
```

Essa implementação repete muitos cálculos.
Por isso, apesar de parecer simples, ela é ineficiente.

### Memória

Cada chamada recursiva ocupa espaço na pilha de chamadas.

Por isso, uma recursão muito profunda pode causar estouro de pilha.

Isso é chamado de:

```text
stack overflow
```

Por exemplo, se uma função chama a si mesma milhares ou milhões de vezes antes de chegar ao caso base, o programa pode não ter memória suficiente na pilha para armazenar todas essas chamadas.

Portanto, ao usar recursão, devemos sempre verificar:

* se existe caso base;
* se o passo recursivo caminha em direção ao caso base;
* qual é a profundidade máxima da recursão;
* se há repetição desnecessária de chamadas.



## 9. Exercícios

### Q1. Tamanho de uma lista encadeada

Implemente uma função recursiva:

```cpp
int list_size(Node* head);
````

A função deve retornar o número de elementos de uma lista simplesmente encadeada.

#### Dicas

* Qual é o tamanho de uma lista vazia?
* Como o tamanho da lista se relaciona com o próximo nó (`head->next`)?

#### Exemplos

```
Caso 1
Entrada: 1 -> 2 -> 3 -> 4 -> NULL
Saída: 4

Caso 2
Entrada: NULL
Saída: 0
```

### Q2. Remover todos os elementos com valor X

Implemente uma função recursiva:

```cpp
Node* remove_all(Node* head, int x);
```

Dada a cabeça (`head`) de uma lista, remova todos os nós cujo valor seja igual a `x`.

A função deve retornar a nova cabeça da lista.

#### Dicas

* Resolva primeiro o problema para o restante da lista (`head->next`)
* Depois decida o que fazer com o nó atual:

  * Se `head->val == x`, o nó deve ser removido
  * Caso contrário, ele deve permanecer na lista
* Pense com cuidado no que deve ser retornado em cada caso

#### Exemplos

```
Caso 1
Entrada:
    Lista: 1 -> 2 -> 3 -> 2 -> 4 -> NULL
    x = 2
Saída:
    1 -> 3 -> 4 -> NULL

Caso 2
Entrada:
    Lista: 2 -> 2 -> 2 -> NULL
    x = 2
Saída:
    NULL

Caso 3
Entrada:
    Lista: 1 -> 3 -> 5 -> NULL
    x = 2
Saída:
    1 -> 3 -> 5 -> NULL
```

#### Observações

* Sempre trate o caso base (`head == NULL`)
* Cuidado ao remover o primeiro elemento da lista
* Nunca acesse `head->next` sem garantir que `head != NULL`
