# Aula 4: Memória, Arrays e Ponteiros

## 1. Endereços de Memória

Cada variável em um programa ocupa um espaço na memória. Esse espaço tem um endereço único, que pode ser acessado utilizando o operador `&`.

```cpp
int x = 10;
cout << "Endereço de x: " << &x << endl;
```
  
Isso imprime o endereço da variável `x` na memória.

#### Tabela de Variáveis na Memória

| Variável  | Endereço  | Valor  |
|-----------|-----------|--------|
| `x`       | 0x1000    | 10     |

---

## 2. Referências (&)

As referências em C++ são uma maneira de criar um alias ("apelido") para uma variável existente.

- Declaração:
  ```cpp
  int x = 10;
  int& ref = x;  // ref agora se comporta como x
  ```
- Modificar a referência também modifica a variável original.
  ```cpp
  ref = 20;
  cout << x;  // Exibe 20
  ```
- Referências devem ser inicializadas na declaração e não podem ser alteradas para referenciar outra variável.

| Variável  | Endereço  | Valor  |
|-----------|-----------|--------|
| `x`       | 0x1000    | 10     |
| `ref`     | 0x1000    | 20     |

---

## 3. Arrays em C++

Os arrays em C++ funcionam de maneira semelhante aos de Python, mas têm tamanho fixo e precisam ser declarados explicitamente.

### 3.1 Variaveis independentes vs Arrays

#### Independentes

```cpp
int x = 10;
int y = 20;
int z = 30;
```

| Variável  | Endereço  | Valor  |
|-----------|-----------|--------|
| `x`       | 0x1000    | 10     |
|           | 0x1004    |        |
|           | 0x1008    |        |
|           | 0x100C    |        |
| `y`       | 0x1008    | 20     |
|           | 0x1010    |        |
|           | 0x1014    |        |
| `z`       | 0x1018    | 30     |
|           | 0x101C    |        |
|           | 0x1020    |        |

#### Array

```cpp
int a[3];
int a[0] = 10;
int a[1] = 20;
int a[2] = 30;
```

| Variável  | Endereço  | Valor  |
|-----------|-----------|--------|
|           | 0x1000    |        |
|           | 0x1004    |        |
| a[0]      | 0x1008    | 10     |
| a[1]      | 0x100C    | 20     |
| a[2]      | 0x1008    | 30     |
|           | 0x1010    |        |
|           | 0x1014    |        |
|           | 0x1018    |        |
|           | 0x101C    |        |
|           | 0x1020    |        |

### 3.2 Arrays Unidimensionais

```cpp
// OpçãO 1:

// Declaração
int numeros[5];
// Inicialização
for (int i = 0; i < 5; i++) {
    numeros[i] = i;
}

// OpçãO 2:

// Declaração e InicializaçãO
int numeros[5] = {1, 2, 3, 4, 5}; 
```

### 3.3 Arrays Bidimensionais

```cpp
// OpçãO 1:

// Declaração
int matriz[3][3];
// Inicialização
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        matriz[i][j] = i*j + j;
    }
}

// OpçãO 2:

// Declaração e InicializaçãO
int matriz[3][3] = {{0, 1, 2}, 
                    {3, 4, 5},
                    {6, 7, 8}};
```

### 3.4 Observações

* Junto com o array n-dimensional, é essencial manter variaveis auxiliares que guardem o tamanho de cada dimensão do array
  ```cpp
  #include <iostream>

  using namespace std;

  int main() {
      int a[5] = {1, 2, 3, 4, 5};
      int n = 5;

      int total = 0;
      for (int i = 0; i < n; i++) {
          total += a[i];
      }
      cout << total << endl;

      return 0;
  }
  ```

* Em C++, nada impede que acessar espaços indevidos da memória que vão alem do espaço alocado a um array
  ```cpp
  #include <iostream>

  using namespace std;

  int main() {
      int a[5] = {1, 2, 3, 4, 5};

      for (int i = 0; i < 5; i++) {
          cout << a[i] << endl;
      }
      cout << a[5] << endl;

      return 0;
  }
  ```

* Copia entre arrays não segue a mesma lógica de cópia entre variavéis. 
  ```cpp
  // Errado
  int a[5] = {1,2,3,4,5};
  int b[5] = a;

  // Correto
  int a[5] = {1,2,3,4,5};
  int b[5];
  for (int i = 0; i < 5; i++) {
      b[i] = a[i];
  }
  ```
---

## 4. Ponteiros

Um ponteiro é uma variável que armazena o endereço de outra variável.

### 4.1 Exemplo

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;   // Variável comum
    int* p = &a;  // Ponteiro para um endereço contendo um inteiro

    cout << "Valor de a: " << a << endl;
    cout << "Endereço de a (&a): " << &a << endl;
    cout << "Valor de p (endereço armazenado): " << p << endl;
    cout << "Valor apontado por p (*p): " << *p << endl;

    return 0;
}
```

Esse código apresenta uma variável `a`, um ponteiro `p` que recebe o endereço de `a` e a exibição desses valores.
* `p` armazena o endereço de `a`. Isso significa que `p` não contém o valor `10`, mas sim um endereço de memória onde `10` está armazenado.
* `*p` desreferencia o ponteiro, acessando o valor armazenado no endereço que `p` aponta, ou seja, `10`.

A saída esperada desse programa será algo semelhante a:

```less
Valor de a: 10  
Endereço de a (&a): 0x61ff08  (pode variar)  
Valor de p (endereço armazenado): 0x61ff08  
Valor apontado por p (*p): 10  
```

### 4.2 Operadores `*` (Desreferência) e `&` (Endereço de Memória)

O funcionamento do programa acima é baseado no uso dos operadores `&` e `*`, que desempenham papéis distintos.

#### Operador & (Endereço de Memória)

O operador `&` retorna o endereço de uma variável.

```cpp
int a = 42;
cout << &a;  // Exibe o endereço de 'a'
```

O endereço retornado depende da alocação da variável na memória, mas pode ser algo como `0x7ffdfc3e9a4c`.

#### Operador * (Desreferência)

O operador `*` acessa o valor armazenado no endereço apontado pelo ponteiro.

```cpp
int a = 42;
int* p = &a;
cout << *p;  // Exibe 42
```

No exemplo inicial, `*p` acessa o valor armazenado em `p`, que é `10`. Se `p` apontasse para outra variável, `*p` passaria a representar o valor armazenado nessa nova variável.

### 4.3 Ilustração

Para ilustrar como os ponteiros funcionam, imagine o seguinte:

```scss
    x  -> [10]   (Armazena o valor 10)
    ptr -> [0x1008]   (Armazena o endereço de x)
```

Aqui:
* A variável `x` armazena o valor `10`.
* O ponteiro `ptr` armazena o endereço de memória de `x` (por exemplo, `0x1008`).

Quando usamos o operador de desreferência `*`, obtemos o valor armazenado no endereço para o qual o ponteiro `ptr` aponta.
Assim, ao escrever `*ptr`, estamos acessando o valor de `x`, que é `10`.

#### Explicação Visual: Diagrama de Ponteiros

A relação entre as variáveis e ponteiros pode ser melhor compreendida com o diagrama a seguir:

```lua
+------------+       +--------+
|   x        | ----> |  10    |
+------------+       +--------+
         ^
         |
    +------------+
    |   ptr      |
    +------------+

```

Neste diagrama:
* `x` contém o valor 10.
* `ptr` contém o endereço de x.


#### Explicação Visual: Memória

Podemos representar a alocação de memória de forma mais detalhada para entender como a memória é organizada.
Imagine que as variáveis `x` e `ptr` estão localizadas em diferentes endereços 

| Variável  | Endereço  | Valor  |
|-----------|-----------|--------|
|           | 0x1000    |        |
|           | 0x1004    |        |
| `x`       | 0x1008    | 10     |
|           | 0x100C    |        |
|           | 0x1008    |        |
|           | 0x1010    |        |
| `ptr`     | 0x1014    | 0x1008 |
|           | 0x1018    |        |
|           | 0x101C    |        |
|           | 0x1020    |        |

Neste diagrama de memória:
* A variável `x` está armazenada no endereço `0x1008` e contém o valor `10`.
* O ponteiro `ptr` está armazenado no endereço `0x1014`, e contém o valor `0x1008`, que é o endereço de `x`.

### 4.4 Ponteiros Não Inicializados: `nullptr`

Quando um ponteiro não é inicializado, ele pode conter um lixo de memória, o que pode levar a comportamento indefinido.
Para evitar isso, usamos `nullptr`, que representa um ponteiro nulo.

```cpp
int* p = nullptr;  // Inicializa um ponteiro nulo
```

#### Exemplo de uso de nullptr para evitar acessos inválidos:

```cpp
#include <iostream>
using namespace std;

int main() {
    int* p = nullptr;  // Ponteiro nulo
    if (p) {
        cout << *p;  // Não será executado
    } else {
        cout << "Ponteiro nulo, impossível acessar valor!" << endl;
    }
    return 0;
}
```

Por que usar `nullptr`?
* Evita acessar memória inválida;
* Facilita a verificação antes de acessar ponteiros.

---

## 5. Passagem de Parâmetros para Funções

Em C++, podemos passar variáveis para funções de três formas principais:
* **Por valor** (cópia dos dados, não afeta a variável original)
* **Por referência** (&) (passa a variável diretamente, permitindo modificações)
* **Por ponteiro** (*) (passa o endereço da variável, permitindo modificações)

### 6.1 Passagem por Valor

* Quando passamos um parâmetro por valor, a função recebe uma cópia do valor.
* Se a função modificar essa cópia, o valor original não é alterado.
  ```cpp
  void funcao(int a) {
      a = 20; // Modifica apenas a cópia
  }
  ```

### 5.2 Passagem por Referência

* Com a passagem por referência, a função recebe um link direto para a variável original.
* A função pode modificar o valor original diretamente, sem fazer uma cópia.
  ```cpp
  void funcao(int& a) {
      a = 20; // Modifica diretamente o valor de 'a'
  }
  ```

* Se não quisermos que a função modifique o valor, podemos usar const para garantir que a variável não seja alterada:
  ```cpp
  void exibir(const int& a) {
      cout << a; // Apenas exibe o valor, sem modificá-lo
  }
  ```

### 5.3 Passagem por Ponteiro
* Ao passar um ponteiro para a função, passamos o endereço de memória da variável.
* A função pode modificar o valor original, mas só se o ponteiro for válido.
* Para passar um ponteiro, usamos o operador & na chamada da função:

  ```cpp
  void funcao(int* a) {
      *a = 20; // Modifica o valor que 'a' aponta
  }

  int x = 10;
  funcao(&x); // Passa o endereço de 'x'
  ```

* Podemos verificar se o ponteiro é válido, usando nullptr, para evitar acessar áreas de memória inválidas:
  ```cpp
  void processa(int* ptr) {
      if (ptr != nullptr) {
          cout << *ptr; // Acessa o valor se o ponteiro for válido
      }
  }
  ```

### 5.4 Quando Usar Cada Um?

| Modo       | Quando Usar                                                                                                                 |
| ---------- | --------------------------------------------------------------------------------------------------------------------------- |
| Valor      | Quando não precisar modificar a variável original e a eficiência não for uma preocupação.                                   |
| Referência | Quando precisar modificar a variável original e não quiser criar cópias desnecessárias.                                     |
| Ponteiro   | Quando precisar de controle adicional sobre o ponteiro (permitindo nullptr) e for necessário modificar a variável original. |

---

## 6. Relação entre Arrays e Ponteiros

Em C++, arrays e ponteiros estão muito ligados.
Um array é, na prática, um ponteiro para o primeiro elemento.
Isso é importante para entender como arrays e matrizes funcionam em C++.

### 6.1 Um Array é um Ponteiro
Quando declaramos um array, como `int arr[5]`, o nome do array é, na verdade, um ponteiro para o primeiro elemento. Ou seja, `arr` é o mesmo que `&arr[0]`.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    // O nome do array é um ponteiro para o primeiro elemento
    cout << arr << endl;      // Endereço de arr[0]
    cout << &arr[0] << endl;  // Endereço de arr[0]

    return 0;
}
```

Aqui:
* `arr` e `&arr[0]` mostram o mesmo endereço, que é o endereço do primeiro elemento de `arr`.

### 6.2 Passando um Array para uma Função

Quando passamos um array para uma função, estamos passando o endereço do seu primeiro elemento.
A função vai tratar o array como um ponteiro.

```cpp
#include <iostream>
using namespace std;

void exibirArray(int* p, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << p[i] << " ";  // Acessando os elementos através do ponteiro
    }
    cout << endl;
}

int main() {
    int arr[3] = {10, 20, 30};
    exibirArray(arr, 3);  // Passando o array para a função
    return 0;
}
```

Aqui:
* O array `arr` é passado como um ponteiro para a função `exibirArray()`, e dentro da função podemos acessar os elementos do array com o ponteiro `p`.

### 6.3 Soma de Ponteiros com Arrays

Quando somamos um ponteiro com um valor, ele avança para o próximo elemento do array.
Para um array de `int`, somar `arr + 1` faz o ponteiro ir para o próximo inteiro.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};
    int* ptr = arr;

    cout << "Endereço inicial de arr: " << ptr << endl;
    cout << "Valor de *ptr: " << *ptr << endl;  // Exibe 10

    ptr = ptr + 1;  // Avança o ponteiro para o próximo elemento
    cout << "Endereço após ptr + 1: " << ptr << endl;
    cout << "Valor de *ptr após ptr + 1: " << *ptr << endl;  // Exibe 20

    return 0;
}
```

Aqui:
* O ponteiro `ptr` aponta para o primeiro elemento de `arr`.
* Quando somamos `ptr + 1`, o ponteiro vai para o próximo elemento de `arr`, ou seja, `arr[1]`.

### 6.4. Passando Matrizes 2D para Funções

Quando passamos uma matriz 2D para uma função, passamos o endereço da primeira linha.
O ponteiro precisa ser ajustado para refletir a estrutura da matriz.

```cpp
#include <iostream>
using namespace std;

void exibirMatriz(int (*mat)[3], int linhas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int mat[2][3] = {{1, 2, 3}, {4, 5, 6}};
    exibirMatriz(mat, 2);  // Passando a matriz para a função
    return 0;
}
```

Aqui:
* A matriz `mat` é passada para a função `exibirMatriz()`.
* O ponteiro `mat` é um ponteiro para um array de 3 inteiros, o que permite acessar as linhas da matriz.

### 6.5 Soma de Ponteiros com Matrizes 2D

Quando somamos um ponteiro que aponta para uma linha de uma matriz, ele avança para a próxima linha.

```cpp
#include <iostream>
using namespace std;

int main() {
    int mat[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int (*ptr)[3] = mat;

    cout << "Endereço inicial de mat: " << ptr << endl;
    cout << "Valor de ptr[0][0]: " << ptr[0][0] << endl;  // Exibe 1

    ptr = ptr + 1;  // Avança para a próxima linha da matriz
    cout << "Endereço após ptr + 1: " << ptr << endl;
    cout << "Valor de ptr[0][0] após ptr + 1: " << ptr[0][0] << endl;  // Exibe 4

    return 0;
}
```

Aqui:
* O ponteiro `ptr` aponta para a primeira linha de `mat`.
* Quando somamos `ptr + 1`, o ponteiro vai para a próxima linha da matriz, ou seja, para `mat[1]`.




## 7. Exercício

1. Crie um programa que demonstre a diferença entre passar um parâmetro por valor, referência e ponteiro. O programa deve:
    - Definir uma função para cada tipo de passagem.
    - Mostrar o efeito de cada método no valor original da variável.
2. Implemente uma função que receba dois ponteiros para inteiros e troque os valores das variáveis. No `main`, crie duas variáveis, imprima seus valores antes e depois da troca.
3. Crie uma função que inverta os elementos de um array utilizando ponteiros. No `main`, crie um array, imprima os valores antes e depois da inversão.
4. Implemente uma função que receba duas matrizes `2x2` e calcule a soma delas. No `main`, crie duas matrizes, chame a função para somá-las e imprima a matriz resultante.

