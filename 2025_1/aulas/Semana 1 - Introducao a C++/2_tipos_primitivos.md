# Aula 2: Introdução à Linguagem C++

## 1. Tipos Primitivos

Em C++, ao contrário de Python, as variáveis possuem tipos definidos em tempo de compilação. Os principais tipos primitivos são:

- `int` (inteiro)
- `float` (ponto flutuante de precisão simples)
- `double` (ponto flutuante de precisão dupla)
- `char` (um único caractere)
- `bool` (booleano)
- `long` (inteiro de maior capacidade)

Sendo assim, após inicializar uma variável com um determinado tipo, não é possível altera-la.

```cpp
int x = 10;
float x = 1.7; // Erro: declaração conflitante ‘float x’
```

### Definição e Atributição

Em C++, podemos separar o momento em que reservamos um espaço na memória para uma variável do momento em que atribuímos um valor a ela.

* Chamamos de `definição` (ou `declaração`) o ato de reservar um espaço na memória para a variável.
* Chamamos de `atribuição` quando associamos um valor a esse espaço de memória.
* Quando fazemos ambos ao mesmo tempo, chamamos de `inicialização`.

```cpp
int c;     // Definição (memória reservada, mas sem valor atribuído)
c = 0;     // Atribuição (valor associado à variável)

int x = 3; // Definição e Inicialização (memória reservada e valor atribuído)
```

**Aviso**:
Variáveis não inicializadas podem conter qualquer valor aleatório na memória (chamado de lixo).
Embora alguns compiladores inicializem variáveis com zero, isso não é garantido.
Usar variáveis não inicializadas pode levar a comportamentos imprevisíveis e erros difíceis de depurar.

### Representação em Memória e Comparação com Python
Em Python, os tipos são dinâmicos e podem ocupar espaço variável na memória. Já em C++, os tipos são estaticamente alocados com tamanhos fixos, geralmente:

| Tipo      | Tamanho (bytes) | Valor Mínimo                      | Valor Máximo                         |
|-----------|----------------|------------------------------------|--------------------------------------|
| `char`    | 1              | -128                               | 127                                  |
| `bool`    | 1              | 0 (false)                          | 1 (true)                             |
| `int`     | 4              | -2,147,483,648 (2^32)              | 2,147,483,647 (2^32 - 1)             |
| `float`   | 4              | 1.2E-38                            | 3.4E+38                              |
| `double`  | 8              | 2.2E-308                           | 1.8E+308                             |
| `long`    | 8              | -9,223,372,036,854,775,808 (-2^63) | 9,223,372,036,854,775,807 (2^63 - 1) |

**Diclaimer**: Tamanho de alguns tipos de variável podem mudar dependendo do compilador e arquitetura (e.g.: 32 vs 64 bits).

Podemos verificar o tamanho dos tipos usando `sizeof`:

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

Podemos verificar os valores através do seguinte bloco de código:

```cpp
#include <iostream>
#include <limits>

int main() {
    std::cout << "int min: " << std::numeric_limits<int>::min() << '\n';
    std::cout << "int max: " << std::numeric_limits<int>::max() << '\n';
    std::cout << "long min: " << std::numeric_limits<long>::min() << '\n';
    std::cout << "long max: " << std::numeric_limits<long>::max() << '\n';
    return 0;
}
```

Observação: Python abstrai esses detalhes, tratando inteiros como objetos de precisão arbitrária e floats como IEEE-754.

### Endereçamento

Cada variável armazenada na memória possui um endereço, que pode ser acessado utilizando o operador `&`.
Diferente de Python, onde as variáveis são referências para objetos na memória gerenciados automaticamente, em C++ podemos visualizar diretamente os endereços de memória.

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

### Palavra-chava `const`

A palavra-chave `const` em C++ serve para definir variáveis ou parâmetros que não podem ser modificados após a inicialização.
Isso é útil para garantir a integridade dos dados e evitar alterações acidentais.

```cpp
const int tamanho = 100;
tamanho = 200; // Erro: variável constante não pode ser modificada
```

### Palavra-chava `unsigned`

A palavra-chave `unsigned` em C++ é usada para indicar que um número inteiro não pode ter valores negativos, apenas valores positivos e zero.
Isso pode ser útil quando temos certeza de que a variável nunca precisará armazenar números negativos, como contagens e índices.

```cpp
unsigned int quantidade = 10;
quantidade = 2147483647 + 1;
```

<!-- Seria interessante aprensentar aqui uma ilustração sobre como fica na memória. Tambem seria interessante falar aqui sobre endereçamento -->

## 2. Entrada e Saída

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

### Concatenando Valores com `cout`
Diferente do Python, onde usamos `+` para concatenar strings, em C++ usamos `<<`:

```cpp
string nome = "Joao";
int idade = 25;
cout << "Nome: " << nome << ", Idade: " << idade << endl;
```

### Obtendo Vários Valores com `cin`
Podemos capturar múltiplos valores:

```cpp
int a, b;
cin >> a >> b;
```

Para ler uma string com espaços:

```cpp
string nome;
cin.ignore(); // Evita problemas com buffer de entrada. Por exemplo, ignora '\n' deixados devido a uma leitura anterior
getline(cin, nome);
```

## 3. Operadores

### Operadores Aritméticos

São usados para realizar operações matemáticas básicas.

| Operador | Descrição      | Exemplo (`a = 10, b = 3`) | Resultado |
|----------|----------------|---------------------------|-----------|
| `+`      | Adição         | `a + b`                   | `13`      |
| `-`      | Subtração      | `a - b`                   | `7`       |
| `*`      | Multiplicação  | `a * b`                   | `30`      |
| `/`      | Divisão        | `a / b`                   | `3` (divisão inteira) |
| `%`      | Módulo (resto) | `a % b`                   | `1`       |

**Observação:**  
- Em **divisão inteira**, `10 / 3` resulta em `3`, pois os números são inteiros.  
- Para obter um resultado decimal, pelo menos um dos operandos deve ser `float` ou `double`, como `10.0 / 3`.

#### Overflow
Em Python, não temos overflow para inteiros devido à sua implementação dinâmica. Já em C++:

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 2147483647; // Maior int (32 bits)
    cout << x + 1 << endl; // Resultado inesperado devido ao overflow
    return 0;
}
```

### Operadores Relacionais (de Comparação)
Comparam valores e retornam um booleano (`true` ou `false`).

| Operador | Descrição                    | Exemplo (`a = 10, b = 3`) | Resultado |
|----------|------------------------------|---------------------------|-----------|
| `==`     | Igual a                      | `a == b`                  | `false`   |
| `!=`     | Diferente de                 | `a != b`                  | `true`    |
| `>`      | Maior que                    | `a > b`                   | `true`    |
| `<`      | Menor que                    | `a < b`                   | `false`   |
| `>=`     | Maior ou igual a             | `a >= b`                  | `true`    |
| `<=`     | Menor ou igual a             | `a <= b`                  | `false`   |

---

## 3. Operadores Lógicos
Usados para combinar expressões booleanas.

| Operador | Descrição           | Exemplo (`x = true, y = false`) | Resultado |
|----------|---------------------|---------------------------------|-----------|
| `&&`     | E lógico (AND)      | `x && y`                        | `false`   |
| `\|\|`   | Ou lógico (OR)      | `x \|\| y`                      | `true`    |
| `!`      | Não lógico (NOT)    | `!x`                            | `false`   |

**Observações:**  
- `&&` retorna `true` **somente** se ambos os operandos forem `true`.  
- `||` retorna `true` **se pelo menos um** dos operandos for `true`.  
- `!` inverte o valor lógico: `!true` resulta em `false`.


## 4. Conversão de Tipos

Em C++, podemos converter valores de um tipo para outro de duas formas:
conversão implícita (automática) e conversão explícita (forçada pelo programador).

### Conversão Implícita
O C++ realiza conversões automáticas quando necessário, desde que não haja perda de dados significativa.
Isso ocorre, por exemplo, ao atribuir um valor de um tipo menor para um tipo maior:

```cpp
int a = 10;
double b = a; // 'a' (int) é convertido automaticamente para double
```

Em operações entre tipos diferentes, o C++ converte automaticamente para o tipo de maior precisão:

```cpp
int a = 5;
double b = 2.5;
double resultado = a * b; // 'a' (int) será convertido para double automaticamente
```

#### Cuidado com a conversão implícita!

Quando um tipo maior é atribuído a um tipo menor, pode haver perda de precisão ou comportamento inesperado:

```cpp
double valor = 3.9;
int inteiro = valor; // Converte implicitamente para int, truncando para 3
```

### Conversão Explícita
Para evitar ambiguidades e garantir conversões seguras, usamos a conversão explícita com `static_cast<>`:

```cpp
double pi = 3.14159;
int inteiro = static_cast<int>(pi); // Converte double para int, truncando para 3
```

O static_cast<int>(pi) equivale ao int() do Python:

```python
pi = 3.14159
inteiro = int(pi)
```

#### Outras formas de conversão explícita:

Além de `static_cast<>`, existem outras formas de conversão, mas algumas podem ser menos seguras ou legíveis:

```cpp
// Conversão usando coerção de tipo estilo C (não recomendada)
int x = (int)pi;  

// Conversão usando cast em C++ (também não recomendada)
int y = int(pi);  
```

Embora essas formas funcionem, `static_cast<>` é a opção mais segura e recomendada em C++, pois deixa claro que a conversão é intencional.
O `static_cast<>` restringe a conversão a tipos compatíveis e evita erros de conversão entre estruturas mais complexas (e.g: classes).