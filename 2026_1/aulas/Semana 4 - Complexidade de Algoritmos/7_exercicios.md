## **Questão 1**

Considere os algoritmos:

* $T_1(n) = 1000n$
* $T_2(n) = n^2$
* $T_3(n) = n \log n$

**Perguntas:**

1. Classifique cada algoritmo em termos de complexidade assintótica.
2. Ordene os algoritmos por eficiência para valores grandes de $n$.
3. Para $n = 10$, $n = 1000$ e $n = 10^6$, qual algoritmo é mais eficiente?
4. Explique por que constantes importam para valores pequenos de $n$, mas não para grandes.

## **Questão 2**

Dadas as funções:

* $T_1(n) = n^2 + 3n + 10$
* $T_2(n) = 5n \log n + n$
* $T_3(n) = 2^n + n^3$
* $T_4(n) = n \log n + \log n$

**Perguntas:**

1. Determine a complexidade de cada função.
2. Ordene da menor para a maior.
3. Justifique cada simplificação feita.

## **Questão 3**

```cpp
void f(int n) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            cout << k << " ";
        }
        cout << endl;

        for (int j = 1; j * j < n; j++) {
            cout << j << " ";
        }
    }
}
````

1. Calcule o custo computacional.
2. Justifique sua resposta.

## **Questão 4**

```cpp
void f(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << i << ", " << j << endl;
        }
    }
}
```

1. Calcule o custo computacional no pior caso.
2. Justifique por meio de um somatório ou raciocínio equivalente.

## **Questão 5**

```cpp
void f(int n) {
    for (int i = 1; i < n; i = i * 2) {
        cout << i << endl;
    }
}
```

1. Calcule o custo computacional.
2. Explique por que esse loop tem crescimento logarítmico.

## **Questão 6**

```cpp
bool isSorted(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}
```

1. Melhor caso?
2. Pior caso?
3. Caso médio (explique informalmente)?
4. Por que a notação Big-O normalmente enfatiza o pior caso?

## **Questão 7**

Considere duas formas de verificar valores duplicados em um array:

### Algoritmo A

```cpp
bool has_duplicates(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}
```

### Algoritmo B

* Ordena o vetor em ordem crescente
* Percorre o vetor verificando se `arr[i] == arr[i+1]`

**Perguntas:**

1. Qual a complexidade de cada algoritmo?
2. Qual é melhor? Depende?
3. Em que cenário o Algoritmo A pode ser preferível?

## **Questão 8**

```c
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        cout << i + j << endl;
    }
}
```

1. Qual a complexidade em termos de $n$ e $m$?
2. Qual a complexidade se $m = n$?
