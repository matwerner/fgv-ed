# Aula 28: Orientação a Objetos em C++

## 1. Introdução

Nesta última semana de aula, voltamos a trabalhar com C++ com um foco na aplicação dos conceitos de orientação a objetos (OO) no contexto da implementação de estruturas de dados.

Embora os conceitos de OO já tenham sido trabalhados em Python na disciplina de Linguagens de Programação, agora veremos como eles se aplicam em C++, uma linguagem que demanda mais cuidado com tipagem, memória e controle de recursos.

Falaremos breevemente sobre:

1. Classes em C++
   * Construtores, destrutores
   * Métodos, `this`, operadores (`.`, `->`)
   * Encapsulamento (`public`, `private`, `protected`)
2. Herança
3. Polimorfismo e métodos virtuais

   * Sobrescrita
   * Sobrecarga de funções e operadores
4. Templates (Tópico novo)

## 2. Orientação a Objetos

Antes de entrarmos na sintaxe específica do C++, vamos relembrar brevemente o que é **orientação a objetos (OO)**.

A orientação a objetos é um paradigma de programação onde os programas são estruturados em torno de **classes** e **objetos**, que representam entidades com **estado** (atributos) e **comportamento** (métodos).
A ideia central é organizar o código de forma mais próxima da realidade do problema, facilitando o reuso, a modularidade e a manutenção.

Uma **classe** funciona como um modelo ou definição de uma entidade.
Por exemplo, a classe `Produto` pode representar algo com um `título`, `preço` e `descrição`.
Já um **objeto** é uma instância concreta dessa classe, como um determinado celular ou remédio.

Além de armazenar dados, as classes também definem **ações** possíveis sobre esses dados por meio de métodos.
Por exemplo, a classe `Produto` pode ter um método `aplicar_cupom()` que reduz o preço com base em um desconto, respeitando regras como não permitir valor negativo ou limites de percentual.

Esse estilo de programação é especialmente útil em estruturas de dados, pois permite representar elementos (como nós de uma lista ou árvore) como objetos que carregam dados e se relacionam com outros objetos por meio de ponteiros ou referências.

## 3. Representação

Em C++, as classes têm uma sintaxe muito semelhante às `structs`. Ambas podem conter atributos e métodos. A principal diferença é que, por padrão:

* os membros de uma `struct` são `public`;
* os membros de uma `class` são `private`.

A grande vantagem das classes em C++ é permitir organizar tanto os dados quanto os comportamentos associados (métodos) em uma única estrutura, promovendo encapsulamento, reutilização e clareza de responsabilidades.

Nesta seção, usaremos como exemplo uma estrutura de lista encadeada com as classes `Node` (nó da lista) e `LinkedList` (lista em si).

```cpp
#include <iostream>
using namespace std;

class Node {
private:
    int key;
    Node* next;

public:
    Node(int k) {
        key = k;
        next = nullptr;
        cout << "Criando nó com chave " << key << endl;
    }

    ~Node() {
        cout << "Destruindo nó com chave " << key << endl;
    }

    void setNext(Node* n) {
        this->next = n;
    }

    Node* getNext() {
        return this->next;
    }

    int getKey() const {
        return this->key;
    }
};

class LinkedList {
protected:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int k) {
        Node* novo = new Node(k);
        novo->setNext(head);
        head = novo;
    }

    void print() const {
        Node* atual = head;
        while (atual != nullptr) {
            cout << atual->getKey() << " -> ";
            atual = atual->getNext();
        }
        cout << "NULL" << endl;
    }
};
```

### 3.1 Construtores e Destrutores

Construtores e destrutores são métodos especiais em C++:

* **Construtor**: executado automaticamente na criação do objeto. Serve para inicializar atributos e alocar recursos.
* **Destrutor**: executado automaticamente na destruição do objeto. Serve para liberar recursos (memória, arquivos, conexões, etc).

No nosso exemplo:

* `Node(int k)` é o construtor da classe `Node`, que inicializa os campos `key` e `next`, e imprime uma mensagem.
* `~Node()` é o destrutor, que imprime uma mensagem ao ser chamado.

A classe `LinkedList` também possui um construtor que inicializa `head` como `nullptr`.

### 3.2 Métodos, `this` e Operadores (`.`, `->`)

Métodos são funções associadas a uma classe e que operam sobre os atributos do objeto.

* O ponteiro `this` é um ponteiro implícito para o objeto atual. Ele é equivalente ao `self` em Python, embora explícito apenas quando necessário.
* O operador `.` é usado para acessar membros de um **objeto**.
* O operador `->` é usado para acessar membros de um **ponteiro para objeto**.

### 3.3 Encapsulamento

Encapsulamento significa proteger os dados internos da classe, permitindo acesso a eles apenas por meio de métodos controlados.

Em C++, isso é feito com modificadores de acesso:

| Modificador | Quem pode acessar                  | Equivalente em Python                    |
| ----------- | ---------------------------------- | ---------------------------------------- |
| `private`   | Somente a própria classe           | `__variavel` (name mangling)             |
| `protected` | A própria classe e suas subclasses | `_variavel` (convenção, não obrigatório) |
| `public`    | Qualquer código pode acessar       | Atributos públicos (sem prefixo)         |

## 4. Herança

A herança é um dos pilares da orientação a objetos e permite criar novas classes a partir de classes existentes, reaproveitando atributos e métodos. Com isso, podemos estender funcionalidades sem reescrever código, promovendo **reutilização** e **abstração**.

Além disso, a herança facilita a criação de múltiplas **implementações concretas** para uma mesma **interface abstrata**. Por exemplo, podemos ter diferentes maneiras de implementar um mapa (`Map`), como:

* Usando uma **lista encadeada** (mais simples de entender e implementar);
* Usando um **vetor ordenado**;
* Usando uma **árvore balanceada** (como AVL ou Rubro-Negra).

### 4.1 Exemplo: Implementando `Map` com Lista Encadeada

```cpp
class Map {
public:
    virtual void insert(int key, int value) = 0;
    virtual bool contains(int key) const = 0;
    virtual int get(int key) const = 0;
    virtual ~Map() {} // Destrutor virtual para herança
};

class MapListaEncadeada : public Map {
private:
    struct Node {
        int key;
        int value;
        Node* next;
        Node(int k, int v) {
            this->key = k;
            this->value = v;
            this->next = nullptr;
        }
    };

    Node* head;

public:
    MapListaEncadeada() {
        this->head = nullptr;
    }

    void insert(int key, int value) override {
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
    }

    bool contains(int key) const override {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) return true;
            current = current->next;
        }
        return false;
    }

    int get(int key) const override {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) return current->value;
            current = current->next;
        }
        throw std::runtime_error("Chave não encontrada");
    }

    ~MapListaEncadeada() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};
```

### 4.2 Sintaxe de Herança e Chamada de Construtores

```cpp
class ClasseFilha : public ClasseBase {
    // ...
};
```

> O modificador `public` garante que os membros públicos e protegidos da base continuem acessíveis com o mesmo nível na classe derivada.

```cpp
class Base {
public:
    Base(int x) { /* ... */ }
};

class Derivada : public Base {
public:
    Derivada(int x) : Base(x) { /* ... */ }
};
```

## 5. Polimorfismo

**Polimorfismo** significa "muitas formas" e, em programação orientada a objetos, permite que objetos de diferentes classes derivadas sejam tratados de forma uniforme através de um ponteiro ou referência para a classe base.

### 5.1 Métodos virtuais

Um método **virtual** é aquele que pode ser sobrescrito (redefinido) por classes derivadas.
Ele permite que, mesmo usando um ponteiro para a **classe base**, o método executado seja o da **classe derivada**.

```cpp
class Map {
public:
    virtual void insert(int key, int value) = 0;
    virtual int get(int key) const = 0;
    virtual ~Map() {}
};
```

Acima, `insert` e `get` são métodos virtuais puros (`= 0`), o que significa que `Map` é uma interface e não pode ser instanciada diretamente.

### 5.2 Sobrescrita e chamada via ponteiro base

Com métodos virtuais, é possível usar um ponteiro para a classe base para armazenar e acessar diferentes implementações derivadas:

```cpp
Map* m = new MapListaEncadeada();
m->insert(10, 42);
cout << m->get(10) << endl;
```

Nesse exemplo, mesmo que `m` seja do tipo `Map*`, o método `get` chamado é o de `MapListaEncadeada`.
Isso é possível graças à ligação dinâmica.

### 5.3 Ligação dinâmica (em tempo de execução)

A ligação dinâmica significa que a versão do método a ser executada é decidida em tempo de execução, e não em tempo de compilação.

Esse comportamento só acontece com métodos marcados como virtual.
Se o método não for virtual, o C++ faz ligação estática e usará o método da classe apontada pelo tipo do ponteiro (ou seja, o método da base, mesmo se um método sobrescrito existir na derivada).
