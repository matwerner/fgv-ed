# Aula 3: Controle de Fluxo em C++

## 1. Estruturas Condicionais

### If/Else
O `if` e o `else` são usados para tomar decisões com base em condições.
Se a condição dentro do `if` for verdadeira, o bloco correspondente será executado.
Caso contrário, o programa pode executar um bloco alternativo com `else`.

```cpp
#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "Digite um número: ";
    cin >> numero;
    
    if (numero > 0) {
        cout << "O número é positivo." << endl;
    } else if (numero < 0) {
        cout << "O número é negativo." << endl;
    } else {
        cout << "O número é zero." << endl;
    }
    
    return 0;
}
```

### Switch-Case
O `switch-case` é útil quando há múltiplas opções fixas para um valor específico.
Ele é mais eficiente do que uma sequência de `if-else` quando há muitas comparações de igualdade.

Use switch quando:
* Há um conjunto fixo de valores possíveis.
* O código dentro de cada caso é relativamente simples.
* Deseja-se melhorar a legibilidade ao invés de usar múltiplos if-else.

É importante ressaltar que o `switch-case` só funciona com variáveis **inteiras** (ou seja, nada de strings).

```cpp
#include <iostream>
using namespace std;

int main() {
    int opcao;
    cout << "Escolha uma opção (1-3): ";
    cin >> opcao;

    switch (opcao) {
        case 1:
            cout << "Opção 1 escolhida." << endl;
            break;
        case 2:
            cout << "Opção 2 escolhida." << endl;
            break;
        case 3:
            cout << "Opção 3 escolhida." << endl;
            break;
        default:
            cout << "Opção inválida." << endl;
    }
    return 0;
}
```

**Curiosidade**: essa funcionalidade se encontra presente no python a partir da versão [3.10](https://peps.python.org/pep-0634/).

---

## 2. Estruturas de Repetição

### Laço `for`
Use o `for` quando souber exatamente quantas iterações precisa executar.

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 5; i++) {
        cout << "Iteração: " << i << endl;
    }
    return 0;
}
```

### Laço `while`
Use `while` quando o número de iterações não for conhecido de antemão e depender de uma condição externa.

```cpp
#include <iostream>
using namespace std;

int main() {
    int contador = 1;
    while (contador <= 5) {
        cout << "Contador: " << contador << endl;
        contador++;
    }
    return 0;
}
```

### Laço `do-while`
O `do-while` **sempre executa pelo menos uma vez**, pois a condição é verificada após a execução do bloco.

Use `do-while` quando:
* Você quer garantir que o bloco será executado pelo menos uma vez.
* A condição de saída depende da entrada do usuário.

```cpp
#include <iostream>
using namespace std;

int main() {
    int numero;
    do {
        cout << "Digite um número positivo: ";
        cin >> numero;
    } while (numero <= 0);
    
    cout << "Número válido: " << numero << endl;
    return 0;
}
```

---

## 3. Introdução a Arrays

Os arrays são estruturas que armazenam múltiplos valores do mesmo tipo em uma única variável.
No C++, o tamanho do array é fixo e deve ser definido no momento da declaração.

```cpp
#include <iostream>
using namespace std;

int main() {
    int numeros[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        cout << "Número: " << numeros[i] << endl;
    }
    return 0;
}
```

Esse comportamento é diferente das listas em Python, que podem aumentar e diminuir de tamanho dinamicamente com base nas operações de inserção e remoção.
Além disso, em Python, listas são objetos de uma classe, o que lhes confere métodos para manipulação de dados, como `append()`, `remove()`, etc.
Já em C++, um array é apenas um conjunto sequencial de valores do mesmo tipo e com tamanho fixo.

### Para criar um array em C++

* Declarar e depois atribuir:
    ```cpp
    int arr1[5];  // Declara o array com 5 elementos
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    arr1[3] = 4;
    arr1[4] = 5;
    ```

* Declarar e atribuir ao mesmo tempo:
    ```cpp
    int arr2[3] = {1, 2, 3};  // Declara e atribui os valores ao array
    ```

### Endereço de cada elemento

Como mencionamos anteriormente, um array é uma sequenência de valores em memória.
Isso pode ser visto, verificando o endereço de cada elemento do array.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[3] = {1, 2, 3};
    cout << "Endereço arr[0]: " << &arr[0] << endl;
    cout << "Endereço arr[1]: " << &arr[1] << endl;
    cout << "Endereço arr[2]: " << &arr[2] << endl;
    return 0;
}
```

---

## 4. Introdução a Funções

Em C++, as funções são blocos de código reutilizáveis que podem ser invocados em diferentes partes do programa.
Elas são uma forma de modularizar o código e evitar duplicação.
Cada função em C++ deve declarar o tipo de retorno e os tipos dos parâmetros (caso existam), o que torna o código fortemente tipado.

* Tipo de retorno: A função deve retornar um valor de um tipo específico, como int, float, bool, etc.
* Parâmetros de entrada: Caso a função precise de dados de entrada, os parâmetros são declarados com seus tipos.

### Exemplo de função que soma dois números

```cpp
int soma(int a, int b) {
    return a + b;
}
```
Neste exemplo, a função `soma` retorna um valor do tipo `int` e recebe dois parâmetros do tipo `int`.

Caso a função não precise retornar nenhum valor, usamos o tipo especial void para indicar que a função não retorna nada.

### Exemplo de função que exibe elementos de um array:

Caso a função não precise retornar nenhum valor, usamos o tipo especial `void` para indicar que a função não retorna nada.

```cpp
#include <iostream>
using namespace std;

void exibir(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
```

Aqui, a função `exibir` recebe um array de inteiros e o tamanho do array e exibe seus elementos.
Como ela não precisa retornar nenhum valor, o tipo `void` é utilizado.

### Passagem de Parâmetros

A passagem de parâmetros em C++ pode ser feita de três maneiras principais:
* Por valor
* Por referência (próxima aula);
* Por ponteiro (próxima aula).

#### Passagem por Valor (cópia da variável)

Quando passamos um parâmetro por valor, uma cópia da variável é enviada para a função.
Isso significa que a variável original não é modificada pela função.

```cpp
#include <iostream>
using namespace std;

void dobrar(int numero) {
    numero *= 2;
    cout << "Dentro da função: " << numero << endl;
}

int main() {
    int numero = 10;
    dobrar(numero);
    cout << "Dentro da main: " << numero << endl;
}
```

Aqui, o valor de `numero` dentro da função será duplicado, mas o valor original da variável fora da função não será alterado.

---

## 5. Exercícios

**Exercício 1:**
Escreva uma função que receba um número inteiro e imprima se ele é **positivo**, **negativo** ou **zero**.


**Exercício 2:**
Escreva uma função que receba um array de inteiros e o tamanho do array, e retorne a soma de todos os elementos do array.

**Exercício 3:**
Escreva uma função que receba um número inteiro e retorne `true` se o número for **primo** e `false` caso contrário.
