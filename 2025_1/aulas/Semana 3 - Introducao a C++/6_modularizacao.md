# Aula: Modularização em C/C++

---

## 0. Prótipos de função

O que acontece se tentarmos executar uma função antes de defini-la?
```cpp
#include <iostream>

using namespace std;

void exibeSoma(int a, int b) {
    cout << soma(a, b) << endl;
}

int soma(int a, int b) {
    return a + b;
}

int main() {
    exibeSoma(1, 2);
    return 0;   
}
```

O código falhará! O motivo é simples: em C e C++, toda função deve ser declarada antes de ser utilizada.

Quando o compilador encontra uma chamada de função, ele precisa saber sua `assinatura` (tipo de retorno, nome e parâmetros) para gerar o código correto.
Se a função ainda não foi definida, ocorre um erro de compilação.

Para corrigir esse problema, temos duas opções:
1. Mover a definição da função para antes de sua primeira utilização.
2. Utilizar `protótipos de função`.

Os `protótipos de função` são declarações que informam ao compilador quais funções existem e como elas devem ser chamadas, sem precisar fornecer a implementação naquele momento.

Essa abordagem melhora a organização do código, permitindo que possamos estruturar as funções de forma mais intuitiva e modular.
Além disso, como veremos a seguir, essa prática é essencial para a modularização do código em arquivos separados.

### 0.1 Exemplo

```cpp
#include <iostream>

using namespace std;

// Protótipos da funções
int soma(int a, int b);
void exibeSoma(int a, int b);

// Implementação da funções
void exibeSoma(int a, int b) {
    cout << soma(a, b) << endl;
}

int soma(int a, int b) {
    return a + b;
}

int main() {
    exibeSoma(1, 2);
    return 0;   
}
```


## 1. Modularização: Separando `.h` e `.cpp`

Em C e C++, é uma prática comum dividir o código em arquivos distintos para melhorar a organização e facilitar a reutilização.
Normalmente, um **arquivo de cabeçalho (`.h`)** contém declarações de funções e classes, enquanto um **arquivo de implementação (`.cpp`)** contém suas definições.
Essa separação permite que diferentes partes do código utilizem as mesmas funções sem duplicação desnecessária.

### 1.1 Motivação para a Separação

Diferente de linguagens interpretadas, onde todo o código-fonte é carregado e executado diretamente, em C e C++ a compilação acontece em etapas.
Os programas costumam ser divididos em `múltiplos arquivos`, que são compilados separadamente e depois vinculados (`linkados`).

Isso traz várias vantagens:
* **Reutilização**: O código pode ser usado em vários projetos sem modificação.
* **Organização**: A lógica do programa é distribuída de forma clara e modular.
* **Compilação eficiente**: Apenas os arquivos modificados precisam ser recompilados.

Essa separação acontece porque, em projetos grandes, **compilar o código inteiro do zero a cada alteração seria extremamente ineficiente**.
Em vez disso, compilamos apenas os arquivos modificados e, posteriormente, o vinculador (`linker`) junta os arquivos compilados para formar o programa final.

O problema dessa abordagem é que, durante a compilação de um arquivo `.cpp`, o compilador **não tem acesso às funções definidas em outros arquivos**.
Por isso, usamos os arquivos de cabeçalho (`.h`) para declarar as funções e torná-las acessíveis a diferentes partes do código.

### 1.2 Exemplo:

#### Arquivo `operacoes.h`

```cpp
#ifndef OPERACOES_H
#define OPERACOES_H

// Declaração das funções
int soma(int a, int b);
int subtracao(int a, int b);

#endif
```

#### Arquivo `operacoes.cpp`

```cpp
#include "operacoes.h"

// Implementação das funções
int soma(int a, int b) {
    return a + b;
}

int subtracao(int a, int b) {
    return a - b;
}
```

#### Arquivo `main.cpp`

```cpp
#include <iostream>
#include "operacoes.h"

int main() {
    std::cout << "Soma: " << soma(3, 2) << std::endl;
    std::cout << "Subtracao: " << subtracao(5, 1) << std::endl;
    return 0;
}
```

#### Compilando...

```sh
>>> g++ main.cpp operacoes.cpp -o programa
./programa
```

---

## 2. Diretivas de Pré-Processador

Os arquivos de cabeçalho usam **#ifndef, #define e #endif** para evitar inclusão múltipla do mesmo arquivo:

```cpp
#ifndef NOME_DO_ARQUIVO_H
#define NOME_DO_ARQUIVO_H

// Declaração de funções

#endif
```

Explicação:
- `#ifndef NOME_DO_ARQUIVO_H`: Verifica se o identificador não foi definido anteriormente.
- `#define NOME_DO_ARQUIVO_H`: Define o identificador para evitar múltiplas inclusões.
- `#endif`: Fecha a verificação do pré-processador.

Isso garante que o compilador não tente incluir o mesmo arquivo mais de uma vez, evitando erros de redefinição.

---

## 3. Namespaces

Em C++, `namespace` permite organizar o código e evitar conflitos de nomes.

### 3.1 Exemplo:

#### Arquivo `operacoes.h`

```cpp
#ifndef OPERACOES_H
#define OPERACOES_H

namespace Matematica {

// Declaração das funções
int soma(int a, int b);
int subtracao(int a, int b);

}

#endif
```

#### Arquivo `operacoes.cpp`

```cpp
#include "operacoes.h"

namespace Matematica {

// Implementação das funções
int soma(int a, int b) {
    return a + b;
}

int subtracao(int a, int b) {
    return a - b;
}

}
```

#### Arquivo `main.cpp`

```cpp
#include <iostream>
#include "operacoes.h"

int main() {
    std::cout << "Soma: " << Matematica::soma(3, 2) << std::endl;
    std::cout << "Subtracao: " << Matematica::subtracao(5, 1) << std::endl;
    return 0;
}
```

O `namespace` evita conflitos entre funções de diferentes módulos e facilita a organização do código.

---

## 4. Documentação de Funções em C/C++

Para documentar funções em C/C++, é comum usar comentários no estilo Doxygen:

```cpp
/**
 * @brief Calcula a soma de dois inteiros.
 * @param a Primeiro número.
 * @param b Segundo número.
 * @return Soma de a e b.
 */
int soma(int a, int b) {
    return a + b;
}
```

Anotações comuns:
* `@brief`: Descrição curta da função.
* `@param`: Descreve os parâmetros da função.
* `@return`: Explica o valor retornado pela função.

Essa documentação pode ser processada por ferramentas como o Doxygen para gerar documentação automática.

---

## 5. Compilação Separada e Makefile

Códigos em C e C++ podem ser compilados separadamente para melhorar a organização e a eficiência da compilação.

### 5.1 Compilando manualmente:

```sh
>>> g++ -c operacoes.cpp -o operacoes.o
>>> g++ -c main.cpp -o main.o
>>> g++ operacoes.o main.o -o programa
./programa
```

### 5.2 Comando `Make`:

Para facilitar esse processo, utilizamos ferramentas de automação, como o `Make` e seu arquivo de configuração, o `Makefile`.

#### Por que usar compilação separada?

Em projetos grandes, recompilar todo o código a cada modificação seria muito demorado.
Ao dividir o código em arquivos separados (`.cpp` e `.h`), podemos recompilar apenas os arquivos que foram alterados.
O compilador gera arquivos objeto (`.o`), que são posteriormente combinados pelo linker para formar o programa final.

#### Criando um `Makefile`

O `Makefile` é um arquivo que define regras para automatizar a compilação de um projeto, evitando a necessidade de compilar manualmente cada arquivo.
Com ele, podemos definir quais arquivos precisam ser recompilados e como vinculá-los para formar o executável final.

##### Estrutura básica do `Makefile`

A estrutura de um `Makefile` segue a seguinte sintaxe:
* **alvo**: O nome do que será gerado, como um executável ou um arquivo objeto.
* **dependências**: Arquivos necessários para criar o alvo. Se algum desses arquivos for modificado, o make recompilará automaticamente.
* **comando**: O comando a ser executado para criar o alvo. Importante: o comando deve ser indentado com um tab (não espaços).

    ```Makefile
    alvo: dependências
        comando
    ```

#### Exemplo

```Makefile
all: programa

programa: main.o operacoes.o
	g++ main.o operacoes.o -o programa

main.o: main.cpp operacoes.h
	g++ -c main.cpp -o main.o

operacoes.o: operacoes.cpp operacoes.h
	g++ -c operacoes.cpp -o operacoes.o

clean:
	rm -f *.o programa
```

Explicação passo a passo:
1. `all: programa`: Define que o alvo principal a ser construído é `programa`.
2. `programa: main.o operacoes.o`: Especifica que `programa` depende dos arquivos `main.o` e `operacoes.o`.
3. `g++ main.o operacoes.o -o programa`: Liga os arquivos objeto e gera o executável.
4. `main.o: main.cpp operacoes.h`: Diz que `main.o` depende de `main.cpp` e `operacoes.h`, e compila `main.cpp`.
5. `operacoes.o: operacoes.cpp operacoes.h`: Diz que `operacoes.o` depende de `operacoes.cpp` e `operacoes.h`, e compila `operacoes.cpp`.
6. `clean`: Remove arquivos objeto e o executável para uma nova compilação limpa.

#### Uso do Makefile:

- Para compilar: `make`
- Para limpar arquivos gerados: `make clean`

---

## 6. Bibliotecas Padrão

C e C++ possuem bibliotecas padrão amplamente utilizadas:

- **stdio.h** (C) / **iostream** (C++): Entrada e saída.
- **math.h** / **cmath**: Funções matemáticas.
- **stdlib.h** / **cstdlib**: Alocação de memória e conversão de tipos.
- **string.h** / **string**: Manipulação de strings.

Exemplo:

```cpp
#include <cmath>
#include <iostream>

int main() {
    std::cout << "Raiz quadrada de 25: " << sqrt(25) << std::endl;
    return 0;
}
```

---

## 7. Exercício

**Objetivo:** Criar um programa modularizado que implemente um sistema simples de conversão de temperatura (Celsius para Fahrenheit e vice-versa).

### Requisitos:

1. Criar um arquivo `conversao.h` com a declaração das funções.
2. Criar um arquivo `conversao.cpp` com a implementação das funções.
3. Criar um `main.cpp` para testar as conversões.
4. Criar um `Makefile` para compilar os arquivos separadamente.
