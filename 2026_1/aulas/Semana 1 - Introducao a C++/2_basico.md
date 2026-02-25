# C++ Básico

Esta aula tem como objetivo apresentar os principais elementos da linguagem C++ necessários para implementarmos Estruturas de Dados. Não é um curso completo de C++, mas sim o essencial para que possamos modelar e implementar estruturas corretamente.

## 1. Entrada e Saída

Em C++, usamos `cin` para entrada e `cout` para saída:

```cpp
#include <iostream>
using namespace std;

int main() {
    int idade;
    cout << "Digite sua idade: ";
    cin >> idade;
    cout << "Voce tem " << idade << " anos." << endl;
    return 0;
}
```

Para capturar múltiplos valores:

```cpp
int a, b;
cin >> a >> b;
```

## 2. Tipos Primitivos

Em C++, ao contrário de Python, as variáveis possuem tipos definidos em tempo de compilação. Os principais tipos primitivos são:

* `int` (inteiro)
* `float` (ponto flutuante de precisão simples)
* `double` (ponto flutuante de precisão dupla)
* `char` (um único caractere)
* `bool` (booleano)
* `long` (inteiro de maior capacidade)

Sendo assim, após inicializar uma variável com um determinado tipo, não é possível alterá-la.

```cpp
int x = 10;
float x = 1.7; // Erro: declaração conflitante ‘float x’
```

### 2.1 Declaração e Atribuição

Em C++, podemos separar o momento em que reservamos um espaço na memória para uma variável do momento em que atribuímos um valor a ela.

* Chamamos de **declaração** (ou **definição**) o ato de reservar um espaço na memória para a variável.
* Chamamos de **atribuição** quando associamos um valor a esse espaço de memória.
* Quando fazemos ambos ao mesmo tempo, chamamos de **inicialização**.

```cpp
int c;     // Definição (memória reservada, mas sem valor atribuído)
c = 0;     // Atribuição (valor associado à variável)

int x = 3; // Definição e Inicialização (memória reservada e valor atribuído)
```

**Aviso:** variáveis não inicializadas podem conter qualquer valor aleatório na memória (lixo). Alguns compiladores inicializam com zero, mas isso não é garantido. Usar variáveis não inicializadas pode levar a comportamentos imprevisíveis e erros difíceis de depurar.


### 2.2 Representação em Memória e Comparação com Python

Em Python, os tipos são dinâmicos e podem ocupar espaço variável na memória. Já em C++, os tipos são alocados com tamanhos fixos, geralmente:

| Tipo      | Tamanho (bytes) | Valor Mínimo                      | Valor Máximo                         |
|-----------|----------------|------------------------------------|--------------------------------------|
| `char`    | 1              | -128                               | 127                                  |
| `bool`    | 1              | 0 (false)                          | 1 (true)                             |
| `int`     | 4              | -2,147,483,648 (2^32)              | 2,147,483,647 (2^32 - 1)             |
| `float`   | 4              | 1.2E-38                            | 3.4E+38                              |
| `double`  | 8              | 2.2E-308                           | 1.8E+308                             |
| `long`    | 8              | -9,223,372,036,854,775,808 (-2^63) | 9,223,372,036,854,775,807 (2^63 - 1) |

**Disclaimer:** o tamanho de alguns tipos pode mudar dependendo do compilador e arquitetura (e.g.: 32 vs 64 bits).

Podemos verificar o tamanho com `sizeof`:

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Tamanho de int: " << sizeof(int) << " bytes" << endl;
    cout << "Tamanho de char: " << sizeof(char) << " bytes" << endl;
    cout << "Tamanho de double: " << sizeof(double) << " bytes" << endl;
    return 0;
}
```

Em Python, como determinar o espaço ocupado por um objeto na memória? (Dica: `sys.getsizeof()`).


### 2.3 Endereçamento

Cada variável armazenada na memória possui um endereço, que pode ser acessado utilizando o operador `&`.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 42;
    cout << "Valor de a: " << a << endl;
    cout << "Endereço de a: " << &a << endl;
    return 0;
}
```


### 2.4 Palavra-chave `const`

A palavra-chave `const` em C++ serve para definir variáveis ou parâmetros que não podem ser modificados após a inicialização.

```cpp
const int tamanho = 100;
tamanho = 200; // Erro: variável constante não pode ser modificada
```

## 3. Operadores

### 3.1 Operadores Aritméticos

| Operador | Descrição      | Exemplo (`a = 10, b = 3`) | Resultado             |
| -------- | -------------- | ------------------------- | --------------------- |
| `+`      | Adição         | `a + b`                   | `13`                  |
| `-`      | Subtração      | `a - b`                   | `7`                   |
| `*`      | Multiplicação  | `a * b`                   | `30`                  |
| `/`      | Divisão        | `a / b`                   | `3` (divisão inteira) |
| `%`      | Módulo (resto) | `a % b`                   | `1`                   |

**Observação:** em divisão inteira, `10 / 3` resulta em `3`. Para obter um resultado decimal, pelo menos um dos operandos deve ser `float` ou `double`, como `10.0 / 3`.

### 3.2 Operadores Relacionais

| Operador | Descrição        |
| -------- | ---------------- |
| `==`     | Igual a          |
| `!=`     | Diferente de     |
| `>`      | Maior que        |
| `<`      | Menor que        |
| `>=`     | Maior ou igual a |
| `<=`     | Menor ou igual a |

### 3.3 Operadores Lógicos

| Operador | Descrição        |
| -------- | ---------------- |
| `&&`     | E lógico (AND)   |
| `\|\|`   | Ou lógico (OR)   |
| `!`      | Não lógico (NOT) |

## 4. Estruturas Condicionais

### 4.1 If/Else

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

### 4.2 Switch-Case

O `switch-case` é útil quando há múltiplas opções fixas para um valor específico. Ele costuma ser mais eficiente do que uma sequência de `if-else` quando há muitas comparações de igualdade.

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

## 5. Estruturas de Repetição

### 5.1 Laço `while`

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

### 5.2 Laço `for`

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

## 6. Introdução a Arrays

Os arrays armazenam múltiplos valores do mesmo tipo em uma única variável.
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

Diferente das listas em Python, arrays em C++ não crescem dinamicamente: são apenas um conjunto sequencial de valores com tamanho fixo.

### 6.1 Para criar um array em C++

* Declarar e depois atribuir:

```cpp
int arr1[5];
arr1[0] = 1;
arr1[1] = 2;
arr1[2] = 3;
arr1[3] = 4;
arr1[4] = 5;
```

* Declarar e atribuir ao mesmo tempo:

```cpp
int arr2[3] = {1, 2, 3};
```

### 6.2 Endereço de cada elemento

Como um array é uma sequência contígua em memória, podemos verificar o endereço de cada elemento:

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


## 7. Introdução a Funções

Em C++, funções são blocos de código reutilizáveis. Cada função deve declarar o tipo de retorno e os tipos dos parâmetros.

### 7.1 Exemplo: função que soma dois números

```cpp
int soma(int a, int b) {
    return a + b;
}
```

Caso a função não retorne nada, usamos `void`.

### 7.2 Exemplo: função que exibe elementos de um array

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

### 7.3 Passagem de Parâmetros

A passagem de parâmetros em C++ pode ser feita de três maneiras principais:

* Por valor
* Por referência (próxima aula)
* Por ponteiro (próxima aula)

#### Passagem por Valor (cópia da variável)

Quando passamos um parâmetro por valor, uma cópia da variável é enviada para a função. Isso significa que a variável original não é modificada.

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


## 8. Exercícios

**Exercício 1:** \
Escreva uma função que receba um número inteiro e imprima se ele é **positivo**, **negativo** ou **zero**.

**Exercício 2:** \
Escreva uma função que receba um array de inteiros e o tamanho do array, e retorne a soma de todos os elementos do array.

**Exercício 3:** \
Escreva uma função que receba um número inteiro e retorne `true` se o número for **primo** e `false` caso contrário.

**Exercício Desafio:** \
Implemente uma função `bool validar_cartao(const int cartao[16]);` para validar números de cartão de crédito com **16 dígitos**, utilizando o **algoritmo de Luhn**.  

1. A função deve receber um array de inteiros representando o número do cartão.  
2. Retornar `True` se o número for válido, `False` caso contrário.  

**Exemplo:**
```c++
>>> int[16] c1 = {4, 5, 3, 2, 0, 1, 5, 1, 1, 2, 8, 3, 0, 3, 6, 6};
>>> std::cout << validar_cartao(c1) << std::endl; // True

>>> int[16] c1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6};
>>> std::cout << validar_cartao(c1) << std::endl; // False
```

**Regras do Algoritmo de Luhn:**

1. **Verificar o tamanho:**
O número deve ter exatamente 16 dígitos.

2. **Começar pela direita:**
Pegue os dígitos do cartão da direita para a esquerda (o último dígito é o dígito verificador).

3. **Dobrar os dígitos alternados:**
A cada segundo dígito (contando a partir do penúltimo), dobre o valor.
    * Se o resultado da multiplicação for maior que 9, subtraia 9 (ou some os dois dígitos).

4. **Somar todos os dígitos:**
Some todos os números obtidos (os dobrados + ajustados e os que não foram alterados).

5. **Checar divisibilidade por 10:**
Se a soma total for divisível por 10, o número do cartão é válido.
Caso contrário, é inválido.

**Exemplo Passo a Passo**

Número de cartão: 4532015112830366

1. Dígitos originais:\
```4  5  3  2  0  1  5  1  1  2  8  3  0  3  6  6```
2. Começando da direita, dobramos a cada segundo dígito:\
```8  5  6  2  0  1  1  1  2  2  7  3  0  3  3  6```
3. Soma dos valores:\
```8 + 5 + 6 + 2 + 0 + 1 + 1 + 1 + 2 + 2 + 7 + 3 + 0 + 3 + 3 + 6 = 50```
4. Verificação:\
```50 % 10 = 0  ✅```