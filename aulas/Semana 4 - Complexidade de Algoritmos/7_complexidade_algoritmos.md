# Aula 7: Complexidade de Algoritmos

Até agora, em disciplinas anteriores, nosso foco principal tem sido entender como uma linguagem de programação funciona e como desenvolver algoritmos corretos para resolver problemas específicos.
No entanto, além da corretude e da legibilidade do código, há outro fator essencial a ser considerado: **a eficiência do algoritmo**.

## 1. Introdução

Em termos práticos, a complexidade de um algoritmo é uma forma de estimarmos quanta **memória** e quanto **tempo** ele demanda para executar uma tarefa.

Projetar algoritmos eficientes é fundamental, pois um código funcional, mas ineficiente, pode ser inviável na prática, especialmente quando lidamos com grandes volumes de dados.

### Exemplo

Considere dois algoritmos para resolver o mesmo problema de busca em uma lista:

1. **Busca Sequêncial**: Percorre a lista elemento por elemento até encontrar o valor desejado.
2. **Busca Binária**: Assume que a lista está ordenada e reduz a busca pela metade a cada iteração.

A busca linear pode ser viável para listas pequenas, mas, conforme o tamanho da lista cresce, a busca binária se torna muito mais eficiente.
Essa eficiência pode ser a diferença entre um código que roda em segundos e outro que leva minutos ou até horas para processar a mesma quantidade de dados.

Por isso, ao desenvolver um algoritmo, é sempre importante refletir sobre alternativas mais eficientes. No caso acima, manter a lista ordenada desde o início pode permitir buscas significativamente mais rápidas.

## 2. Complexidade de Algoritmos

De maneira formal, a **complexidade de um algoritmo** descreve a relação entre o tamanho do problema e o consumo de recursos computacionais necessários para resolvê-lo.

### 2.1 Tipos de Complexidade

Os dois principais tipos de complexidade são:
* **Complexidade Espacial**: Mede a quantidade de memória necessária para resolver o problema.
* **Complexidade Temporal**: Mede a quantidade de tempo (ou número de operações) que o algoritmo executa para processar a entrada.

### 2.2 Medida de Complexidade

O **tamanho do problema** geralmente é representado por um parâmetro **N**, que indica a quantidade de elementos a serem processados.
Como veremos adiante, a complexidade de um algoritmo é expressa por funções matemáticas que dependem de **N**.

> **Observação:** Em alguns casos, mais de um parâmetro pode influenciar a complexidade, como ocorre com grafos ou matrizes.

### 1.3 Complexidade de Espaço
A complexidade espacial mede a quantidade de memória necessária para armazenar dados durante a execução do algoritmo.

#### Exemplo
Considere o seguinte código que calcula a média dos valores em um array:

```c
float media(float arr[], int n) {
    float total = 0;
    for(int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total / n;
}
```

Além dos parâmetros de entrada, esse algoritmo utiliza apenas duas variáveis adicionais: `total` e `i`.
Como a quantidade de memória necessária não varia com o tamanho do array, dizemos que essa função possui complexidade espacial `constante O(1)`.

### 1.4 Complexidade de Tempo

A complexidade temporal mede o número de operações realizadas pelo algoritmo em função de `N`.

#### Exemplo
Consideremos novamente a função que calcula a média de um array:

```c
float media(float arr[], int n) {
    float total = 0;
    for(int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total / n;
}
```

O número de iterações do loop cresce linearmente com `N`.
Ou seja, se o tamanho da lista dobrar, o número de operações também dobrará.
Esse comportamento caracteriza um algoritmo de complexidade temporal `linear`, representado por `O(N)`.

## 2. Fundamentos

Embora a complexidade espacial seja importante, na grande maioria dos problemas a memória utilizada acaba sendo `constante` ou `linear` em relação ao tamanho da entrada.
Dessa forma, a complexidade de tempo tem maior impacto na eficiência de um algoritmo e, por esse motivo, será o foco principal desta aula.

### 2.1 Análise de Desempenho

Existem diferentes formas de medir o tempo de execução de um algoritmo. Podemos considerar, por exemplo:
* **Tempo de CPU**: O tempo de execução do algoritmo no processador.
* **Tempo Total de Execução**: O tempo total de execução do algoritmo, incluindo possíveis interrupções.
* **Contagem de Instruções**: O número de instruções executadas durante a execução do algoritmo.

Uma maneira de medir o tempo de execução de um algoritmo é utilizando ferramentas como a biblioteca `time.h` no C ou o comando `time` no Linux.
```c
#include <stdio.h>
#include <time.h>

float media(float arr[], int n) {
    float total = 0;
    for(int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total / n;
}

int main() {
    int n = 1000000;
    float arr[n];

    for(int i = 0; i < n; i++) {
        arr[i] = 2.0 * i;
    }

    clock_t inicio, fim;
    double tempoGasto;

    inicio = clock(); // Marca o tempo de início
    float resultado = media(arr, n);
    fim = clock(); // Marca o tempo de fim

    // Calcula o tempo gasto em segundos
    tempoGasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Média calculada: %f\n", resultado);
    printf("Tempo de execução: %f segundos\n", tempoGasto);

    return 0;
}
```

#### Limitações dessa abordagem:

* O tempo real de execução pode ser influenciado por diversos fatores externos, como a velocidade do processador, o sistema operacional, e outras tarefas em execução no sistema.
* Objetivo da análise de complexidade: O principal objetivo não é medir o tempo de execução em segundos, mas entender como o algoritmo se comporta à medida que o tamanho da entrada cresce.

Assim, ao analisarmos a complexidade de tempo, consideraremos o **número de operações** realizadas, desconsiderando as condições específicas de execução como o hardware e o sistema operacional.

### 2.2 Como calcular o custo computacional

O cálculo da complexidade de tempo de um algoritmo envolve contar o número de operações relevantes que o algoritmo realiza.
Algumas considerações importantes:
* **Operações**: Incluem leituras e escritas, operações matemáticas, e atribuições de variáveis, todas com custo **1**.
* **Loops**: Para cada iteração de um loop, somamos o custo da operação dentro do loop.
* **Condicionais**: Quando um algoritmo contém condições (como **if**), as duas possibilidades são consideradas, e o foco é na execução da opção de maior custo.

#### Exemplo

Consideremos o código para calcular a média de um vetor.

```c
float media(float arr[], int n) {
    float total = 0;               // 1
    for(int i = 0; i < n; i++) {   // n -> executamos n vezes uma operação de custo 1
        total += arr[i];           // 1
    }
    return total / n;              // 1
}
```

Agora, vamos calcular a complexidade:
* A operação `float total = 0`; ocorre uma vez, então tem complexidade `O(1)`.
* O loop `for(int i = 0; i < n; i++)` executa `n` vezes, e dentro dele temos a operação `total += arr[i];`, que é realizada `n` vezes também, cada uma com complexidade `O(1)`.
* O retorno `return total / n`; ocorre uma vez e também tem complexidade `O(1)`.

Portanto, a complexidade total do algoritmo é:
$$T(n) = 1 + \sum_{i=1}^{n} 1 + 1 = n + 2$$

### 2.3 Análise Assintótica

O cálculo anterior é uma possível solução para o problema de calcular a média de um conjunto de números.
No entanto, diferentes programadores podem criar soluções distintas para o mesmo problema.

O que pode levar diferentes custos computacionais, como:
  - Algoritmo 1: $T_1(N) = 10N + 5000$
  - Algoritmo 2: $T_2(N) = 2N^2 + 10$
  - Algoritmo 3: $T_3(N) = N^2 + 5N + 2$

Para valores pequenos de **N**, o **Algoritmo 1** pode ser mais lento devido à constante **5000**.
Porém, à medida que **N** cresce, os **algoritmos 2 e 3** se tornam significativamente mais lentos devido ao termo **$N^2$**.

A análise assintótica nos ajuda a simplificar essa análise computacional, focando nas operações de maior ordem que dominam o comportamento do algoritmo para entradas grandes ($N \rightarrow \infty$).
Nesse tipo de análise, termos de menor ordem e constantes multiplicativas contribuem pouco para a comparação e, por isso, podem ser ignoradas.

Ou seja, levando em consideração essa nova abordagem, notariamos que:
- Algoritmo 1 cresce com um fator **$N$**;
- Algoritmo 2 cresce com um fator **$N^2$**;
- Algoritmo 3 cresce com um fator **$N^2$**.

Sendo assim, o **Algoritmo 1** é melhor que os demais algoritmos visto que o seu crescimento é linear enquanto os demais é quadrático.

### 2.4 Perspectivas

Pense no algoritmo de busca sequencial abaixo:
```c
float buscaSequencial(int arr[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            return i; // Melhor caso: O(1)
        }
    }
    return -1; // Pior caso: O(n)
}
```

Podemos fazer 3 tipos de analise sob esse algoritmo:
- **Melhor Caso**:
    * O tempo de execução mais rápido possível para uma entrada de tamanho N.
    * No caso acima, o valor `x` ser o primeiro elemento da lista.
- **Pior Caso**:
    * O tempo de execução mais lento possível para uma entrada de tamanho N.
    * No caso acima, o valor `x` ser o ultimo elemento da lista.
- **Caso Médio**:
    * O tempo esperado considerando todas as entradas possíveis de tamanho N.
    * No caso acima, esse valor varia de acordo com a distribuição dos dados.

### 2.5 Análise de Pior Caso (Notação `O`)

Por definição, sejam $f$ e $g$ duas funções de domínio $X$:
> Dizemos que a função $f(n)$ = $O(g(n))$ \
> se existir uma constante $c \in \R_+$ e um valor $n_0 \in X$ \
> tal que $\forall n \ge n_0$, temos $|f(n)| \le c|g(n)|$.

Ilustrando:

<img src="./7_worst_case_analysis.png" width="400"/>

A notação `O` nos dá um **limite superior** assintótico

#### Exemplos

* **$3N + 2 = O(N)$**, pois $3N + 2 \le 4N$ para todo $N \ge 2$;
* **$10N^2 + 5N - 4 = O(N^2)$**, pois $10N^2 + 5N - 4 \le 11N^2$ para todo $N \ge 5$;
* Generalizando... $f(n) = a_m*N^m + a_{m-1}*N^{m-1} + ... + a_0 = O(N^m)$

## 3. Complexidades classicas

Embora tenhamos falado do algoritmo `T(n)` de forma genérica, os custos dos algoritmos tendem a recair sobre um pequeno conjunto de valores.
Abaixo, exploramos algumas das complexidades mais comuns, com exemplos e descrições detalhadas.

### 3.1 Comparando diferentes complexidades

A tabela a seguir mostra diferentes complexidades de algoritmos e exemplos típicos para cada tipo de complexidade:


| **Notação**       | **Descrição**          | **Descrição**                                                                                       | **Exemplos de Algoritmos**                                                     |
|-------------------|------------------------|-----------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------|
| **$O(1)$**        | **Constante**          | O tempo de execução não depende do tamanho da entrada.                                              | - Acesso a um elemento em um vetor ou lista: `arr[i]`.                                                         |
| **$O(log(n))$**   | **Logarítmica**        | O tempo de execução cresce de forma logarítmica em relação ao tamanho da entrada.                   | - Busca binária em um vetor ordenado.                                                                         |
| **$O(n)$**        | **Linear**             | O tempo de execução cresce linearmente com o tamanho da entrada.                                    | - Busca sequencial em um vetor.                                                                               |
| **$O(n log(n))$** | **Linear-Logarítmica** | O tempo de execução cresce mais rápido que O(n), mas menos que O(n^2).                              | - Algoritmos de ordenação eficientes como Merge Sort, Quick Sort.                                       |
| **$O(n^2)$**      | **Quadrática**         | O tempo de execução cresce quadraticamente com o tamanho da entrada.                                | - Ordenação por bolha (Bubble Sort).                                                                    |
| **$O(2^n)$**      | **Exponencial**        | O tempo de execução cresce muito rapidamente com o aumento do tamanho da entrada.                   | - Algoritmo de força bruta para resolver o problema da mochila.                                         |
| **$O(n!)$**       | **Fatorial**           | O tempo de execução cresce ainda mais rapidamente que O(2^n), com uma taxa de crescimento fatorial. | - Algoritmo de força bruta para resolver o problema do caixeiro viajante (Travelling Salesman Problem). |

Cada uma dessas complexidades representa diferentes formas de como o tempo de execução de um algoritmo se comporta conforme o tamanho da entrada cresce. 
Algumas complexidades, como $O(1)$ e $O(log(n))$, indicam algoritmos muito eficientes em termos de tempo, enquanto outras, como $O(n!)$ e $O(2^n)$, indicam algoritmos que podem se tornar rapidamente inviáveis para entradas grandes.

### 3.2 Comportamento das Complexidades ao Longo do Tamanho `n`

É importante entender como as diferentes complexidades se comportam à medida que o tamanho da entrada $n$ aumenta.
A seguir, temos um gráfico que compara o comportamento de algumas das complexidades mais comuns, mostrando como o tempo de execução aumenta à medida que $n$ cresce.

<img src="./7_complexity_comparison.png" width="600"/>

Aonde,

$$O(1) \lt O(log(n)) \lt O(n) \lt O(n log(n)) \lt O(n^2) \lt O(n^3) \lt O(c^n) \lt O(n!)$$

Como podemos observar, complexidades como $O(1)$ e $O(log(n))$ aumentam muito lentamente com o tamanho da entrada, tornando-os altamente eficientes.
Já algoritmos com complexidades como $O(n^2)$, $O(2^n)$ e $O(n!)$ têm um crescimento muito mais rápido, o que torna esses algoritmos menos práticos para entradas grandes.

### 3.3 Exemplos de Algoritmos

Abaixo, mostramos alguns exemplos de algoritmos em C para diferentes complexidades de tempo: constante, logarítmica, linear, quadrática e exponencial.

#### Complexidade $O(1)$ - Acesso a um Item em um Vetor

O acesso direto a um elemento de um vetor ocorre em tempo constante O(1):

```c
int acessarElemento(int arr[], int index) {
    return arr[index];
}
```

#### Complexidade $O(log(n))$ - Busca Binária

A busca binária reduz pela metade o espaço de busca a cada iteração, resultando em uma complexidade logarítmica O(log(n)):

```c
int buscaBinariaRecursiva(int arr[], int esquerda, int direita, int x) {
    if (esquerda > direita) {
        return -1;  // Elemento não encontrado
    }

    int meio = (esquerda + direita) / 2;

    if (arr[meio] == x) {
        return meio;  // Elemento encontrado
    }

    if (arr[meio] < x) {
        return buscaBinariaRecursiva(arr, meio + 1, direita, x);
    } else {
        return buscaBinariaRecursiva(arr, esquerda, meio - 1, x);
    }
}
```

####  Complexidade $O(n)$ - Busca Sequencial

A busca sequencial percorre todo o vetor até encontrar o elemento desejado, com complexidade linear O(n):

```c
int buscaSequencial(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;  // Elemento encontrado
        }
    }
    return -1;  // Elemento não encontrado
}
```

#### Complexidade $O(n^2)$ - Bubble Sort

O Bubble Sort compara e troca elementos adjacentes em múltiplas passadas pelo vetor, resultando em uma complexidade quadrática O(n²):

```c
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Troca os elementos
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
```

#### Complexidade $O(2^n)$ - Fibonacci Recursivo

O cálculo do Fibonacci recursivo gera duas novas chamadas a cada execução, resultando em uma complexidade exponencial O(2ⁿ):

```c
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```
