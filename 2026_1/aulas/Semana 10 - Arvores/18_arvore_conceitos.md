# Aula 17: Conceitos sobre Árvores

## 1. Introdução e Motivação

Nas aulas anteriores, vimos estruturas lineares, como listas, pilhas e filas. Nessas estruturas, os elementos aparecem em sequência: um depois do outro.

Hoje, vamos estudar uma estrutura não linear: a **árvore**.

Em vez de representar apenas uma sequência, uma árvore representa uma **hierarquia**. Esse tipo de organização aparece em várias situações reais e também serve como base para estruturas de dados eficientes.

### 1.1 Por que estudar árvores?

Árvores são usadas para representar relações hierárquicas. Elas aparecem em praticamente todas as áreas da computação.

Vamos ver alguns exemplos práticos:

* **HTML (Document Object Model)**:  
  Uma página web é estruturada como uma árvore. O elemento `<html>` é a raiz, com dois filhos principais: `<head>` e `<body>`. Dentro deles, temos outros elementos aninhados, como `<div>`, `<p>`, `<h1>` etc.

* **Sistema de arquivos**:  
  O sistema de pastas do computador também pode ser visto como uma árvore. Uma pasta pode conter arquivos ou outras pastas. O diretório raiz (`/` no Linux, `C:\` no Windows) é a raiz da árvore.

* **Árvores de decisão e o Akinator**:  
  Em jogos e algoritmos de decisão, cada nó pode representar uma pergunta, e cada resposta leva a outra pergunta ou a uma decisão final. As respostas finais ficam nas folhas da árvore.

E por que isso importa em Estrutura de Dados?

Além dessas aplicações visuais e lógicas, árvores são a base de estruturas eficientes que veremos nas próximas aulas:

* **Árvores Binárias de Busca (BST)**: permitem organizar dados para facilitar buscas;
* **Árvores AVL, Rubro-Negras e B**: mantêm a árvore balanceada para garantir bom desempenho;
* **Heaps**: organizam prioridades de forma eficiente.

Todas essas estruturas dependem do entendimento que vamos construir hoje.

## 2. Terminologia e Conceitos Fundamentais

Agora que entendemos por que árvores são importantes, vamos estudar como essa estrutura é formada e quais são seus conceitos básicos.

Imagine a seguinte árvore:

```mathematica
        A
      /   \
     B     C
    / \     \
   D   E     F
````

Essa estrutura representa uma árvore com vários nós ligados de forma hierárquica.

### 2.1 Termos fundamentais

* **Nó (node)**:
  Unidade básica da árvore. Cada nó armazena um valor e pode ter ligações para outros nós.
  Exemplo: `A`, `B`, `C`, `D`, `E` e `F` são nós.

* **Aresta (edge)**:
  Ligação entre dois nós. Em uma árvore, uma aresta conecta um nó ao seu filho.

* **Raiz (root)**:
  É o nó mais alto da hierarquia. É o único nó que não possui pai.
  Exemplo: no exemplo acima, `A` é a raiz.

* **Filho (child)**:
  Um nó diretamente ligado abaixo de outro.
  Exemplo: `B` e `C` são filhos de `A`.

* **Pai (parent)**:
  Um nó diretamente ligado acima de outro.
  Exemplo: `A` é pai de `B` e `C`.

* **Irmãos (siblings)**:
  Nós que compartilham o mesmo pai.
  Exemplo: `B` e `C` são irmãos; `D` e `E` também.

* **Folha (leaf)**:
  Nó que não possui filhos.
  Exemplo: `D`, `E` e `F` são folhas.

* **Subárvore (subtree)**:
  Qualquer nó da árvore, junto com todos os seus descendentes, forma uma subárvore.
  Exemplo: a subárvore com raiz em `B` inclui os nós `B`, `D` e `E`.

### 2.2 Conceitos estruturais

* **Profundidade de um nó**:
  Número de arestas da raiz até esse nó.

  Exemplo:

  ```mathematica
          A
        /   \
       B     C
      / \     \
     D   E     F
  ```

  A profundidade de `D` é 2, pois o caminho da raiz até `D` é:

  ```text
  A → B → D
  ```

* **Altura de um nó**:
  Número de arestas no caminho mais longo entre esse nó e uma de suas folhas.

  Exemplo:

  ```mathematica
          A
        /   \
       B     C
      / \     \
     D   E     F
  ```

  A altura de `B` é 1, pois o maior caminho de `B` até uma folha é:

  ```text
  B → D
  ```

  ou

  ```text
  B → E
  ```

* **Altura da árvore**:
  A altura da árvore é a altura da raiz.

  No exemplo acima, a altura da árvore é 2.

### 2.3 Exercício

Considere a árvore abaixo:

```mathematica
        A
      /   \
     B     C
    /     / \
   D     E   F
  / \
 G   H
```

Dada a árvore acima, identifique para cada nó:

* Valor;
* Pai;
* Filho da esquerda;
* Filho da direita;
* Altura;
* Profundidade.

Além disso, responda:

* Quem é a raiz?
* Quais são os nós folhas?
* Quais são os irmãos de `B`?
* Quais são os irmãos de `E`?
* Quais são os irmãos de `G`?

## 3. Tipos Especiais de Árvores

Até agora, vimos a estrutura geral de uma árvore.

Mas, assim como nas listas encadeadas temos listas simples, duplamente encadeadas e circulares, nas árvores também há variações com propriedades específicas.

### 3.1 Árvores n-árias e árvores binárias

Em teoria, um nó pode ter qualquer número de filhos.

Quando limitamos esse número a no máximo **n filhos por nó**, chamamos de **árvore n-ária**.

Por exemplo:

* uma árvore com no máximo 3 filhos por nó é uma árvore ternária;
* uma árvore com no máximo 4 filhos por nó é uma árvore 4-ária;
* uma árvore com no máximo 2 filhos por nó é uma árvore binária.

Na prática, uma das estruturas mais importantes é a **árvore binária**.

### 3.2 Árvore binária

Uma **árvore binária** é uma árvore em que cada nó tem no máximo dois filhos:

* filho à esquerda;
* filho à direita.

Exemplo:

```mathematica
      A
     / \
    B   C
   /     \
  D       E
```

Árvores binárias são a base para várias estruturas de dados importantes, como:

* Árvores Binárias de Busca;
* Árvores AVL;
* Heaps.

### 3.3 Árvore estritamente binária

Uma árvore é **estritamente binária** quando cada nó tem exatamente 0 ou 2 filhos.

Ou seja, nenhum nó possui apenas um filho.

Exemplo:

```mathematica
       A
      / \
     B   C
    / \
   D   E
```

Nesse exemplo:

* `A` tem 2 filhos;
* `B` tem 2 filhos;
* `C`, `D` e `E` têm 0 filhos.

Esse tipo de árvore aparece em algumas aplicações, como árvores de expressão e árvores de decisão.

### 3.4 Árvore perfeita

Uma árvore binária é **perfeita** quando:

* todos os nós internos têm exatamente dois filhos;
* todas as folhas estão no mesmo nível;
* todos os níveis estão completamente preenchidos.

Exemplo:

```mathematica
        A
      /   \
     B     C
    / \   / \
   D   E F   G
```

Esse é um exemplo ideal de árvore bem distribuída.

### 3.5 Árvore balanceada: noção informal

Uma árvore é considerada **balanceada**, de forma informal, quando suas subárvores têm alturas parecidas.

A ideia é evitar que um lado cresça muito mais que o outro.

Exemplo:

```mathematica
        A
      /   \
     B     C
    / \     \
   D   E     F
```

Uma árvore balanceada não precisa ser perfeita. Ela só precisa evitar um desequilíbrio grande demais.

Estruturas como AVL, Rubro-Negra e B usam regras específicas para manter a árvore balanceada.

### 3.6 Árvore degenerada

Uma árvore é **degenerada** quando cada nó tem apenas um filho.

Nesse caso, a árvore se comporta praticamente como uma lista encadeada.

Exemplo:

```mathematica
A
 \
  B
   \
    C
     \
      D
```

Esse caso é importante porque mostra que uma árvore nem sempre é eficiente.

Se a árvore estiver muito desequilibrada, operações como busca e inserção podem ficar tão ruins quanto em uma lista.

## 4. Número de Nós em Função da Altura

Quando trabalhamos com árvores binárias, uma pergunta natural é:

> Dada uma altura `h`, qual é o mínimo e o máximo número de nós que uma árvore binária pode ter?

Antes de responder, lembre-se:

* a altura `h` é o número de arestas do caminho mais longo da raiz até uma folha;
* uma árvore com um único nó tem altura `h = 0`.

Exemplo:

```mathematica
A
```

Altura: `0`
Número de nós: `1`

### 4.1 Máximo de nós

O número máximo de nós ocorre quando todos os níveis da árvore estão completamente preenchidos.

Em uma árvore binária:

* nível 0 pode ter até 1 nó;
* nível 1 pode ter até 2 nós;
* nível 2 pode ter até 4 nós;
* nível 3 pode ter até 8 nós;
* nível `i` pode ter até `2^i` nós.

Somando todos os níveis de `0` até `h`, temos:

$$
N_{max}= 2^0 + 2^1 + 2^2 + \dots + 2^h
$$

Logo:

$$
N_{max}=2^{h+1}-1
$$

#### Exemplo com altura `h = 2`

Como a altura é 2, a árvore possui os níveis 0, 1 e 2.

```mathematica
        A
      /   \
     B     C
    / \   / \
   D   E F   G
```

Nível 0: 1 nó
Nível 1: 2 nós
Nível 2: 4 nós

Total:

$$
N_{max} = 1 + 2 + 4 = 7
$$

Pela fórmula:

$$
N_{max}=2^{h+1}-1 = 2^{2+1}-1 = 2^3-1 = 7
$$

#### Exemplo com altura `h = 3`

Como a altura é 3, a árvore possui os níveis 0, 1, 2 e 3.

```mathematica
          A
       /     \
      B       C
    /  \     /  \
   D    E   F    G
  / \  / \ / \  / \
 H  I J  K L M  N  O
```

Nível 0: 1 nó
Nível 1: 2 nós
Nível 2: 4 nós
Nível 3: 8 nós

Total:

$$
N_{max}=1+2+4+8=15
$$

Pela fórmula:

$$
N_{max}=2^{h+1}-1 = 2^{3+1}-1 = 2^4-1 = 15
$$

### 4.2 Mínimo de nós

O número mínimo de nós ocorre quando a árvore é degenerada.

Nesse caso, cada nó possui apenas um filho, e a árvore se comporta como uma lista encadeada.

Se a altura é `h`, o número mínimo de nós é:

$$
N_{min}=h+1
$$

#### Exemplo com altura `h = 3`

```mathematica
A
 \
  B
   \
    C
     \
      D
```

Altura: `3`
Número de nós: `4`

Pela fórmula:

$$
N_{min}=h+1=3+1=4
$$

### 4.3 Por que a altura importa?

A altura é importante porque muitas operações em árvores dependem da altura.

Em uma árvore degenerada, a altura pode crescer proporcionalmente ao número de nós.

Em uma árvore bem distribuída, a altura cresce muito mais lentamente.

Essa ideia será fundamental nas próximas aulas, quando estudarmos Árvores Binárias de Busca e árvores balanceadas.

## 5. Representação de Árvores

### 5.1 Representação com nós

A forma mais comum e flexível de representar árvores binárias é usando estruturas encadeadas.

Nesse modelo, cada nó guarda:

* o valor armazenado no nó;
* um ponteiro para o filho à esquerda;
* um ponteiro para o filho à direita.

Em C++, podemos representar um nó assim:

```cpp
struct Node {
    int value;
    Node* left;
    Node* right;
};
```

Nesse exemplo:

* `value` guarda o valor do nó;
* `left` aponta para o filho da esquerda;
* `right` aponta para o filho da direita.

Se um nó não possui filho à esquerda ou à direita, o ponteiro correspondente será `nullptr`.

### 5.2 Criando um nó

Podemos criar uma função auxiliar para criar um novo nó:

```cpp
Node* createNode(int value) {
    Node* node = new Node;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
```

Essa função:

1. aloca um novo nó na memória;
2. armazena o valor recebido;
3. inicializa os filhos como `nullptr`;
4. retorna o ponteiro para o nó criado.

### 5.3 Construindo uma árvore manualmente

Imagine que queremos construir a seguinte árvore:

```mathematica
      10
     /  \
    5    15
   / \
  3   7
```

Em C++, poderíamos escrever:

```cpp
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* node = new Node;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int main() {
    Node* root = createNode(10);

    root->left = createNode(5);
    root->right = createNode(15);

    root->left->left = createNode(3);
    root->left->right = createNode(7);

    // A árvore foi construída.
    // Nas próximas seções, veremos como percorrê-la.

    return 0;
}
```

Essa árvore fica organizada assim:

```mathematica
      10
     /  \
    5    15
   / \
  3   7
```

### 5.4 Observação sobre outras representações

Existem outras formas de representar árvores, como usando vetores.

Essa representação funciona especialmente bem em árvores completas, como veremos mais adiante ao estudar heaps.

Por enquanto, vamos focar na representação encadeada com ponteiros.

## 6. Travessias em Árvores

Uma árvore pode ser percorrida de várias formas.

Percorrer uma árvore significa visitar seus nós em alguma ordem.

Isso é útil para várias tarefas, como:

* imprimir os valores da árvore;
* buscar informações;
* liberar memória;
* copiar uma árvore;
* avaliar expressões;
* processar todos os elementos armazenados.

Existem duas abordagens principais:

* **DFS (Depth-First Search)**: busca em profundidade;
* **BFS (Breadth-First Search)**: busca em largura.

Nesta aula, vamos estudar as duas, mas daremos mais atenção à DFS, pois ela se conecta diretamente com recursão.

Para os exemplos, usaremos a árvore abaixo:

```mathematica
      10
     /  \
    5    15
   / \
  3   7
```

## 6.1 DFS: Depth-First Search

A DFS percorre a árvore descendo pelos ramos.

Em árvores binárias, há três formas clássicas de DFS:

* pré-ordem;
* em-ordem;
* pós-ordem.

A diferença entre elas está no momento em que processamos a raiz.

### 6.1.1 Pré-ordem

Na pré-ordem, processamos primeiro o nó atual e depois suas subárvores.

Ordem:

```text
Raiz → Esquerda → Direita
```

Para a árvore:

```mathematica
      10
     /  \
    5    15
   / \
  3   7
```

A ordem de visita é:

```text
10 → 5 → 3 → 7 → 15
```

Implementação:

```cpp
void preOrder(Node* node) {
    if (node != nullptr) {
        cout << node->value << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}
```

A ideia é:

1. visitar o nó atual;
2. percorrer a subárvore esquerda;
3. percorrer a subárvore direita.

### 6.1.2 Em-ordem

Na em-ordem, processamos o nó atual entre a subárvore esquerda e a subárvore direita.

Ordem:

```text
Esquerda → Raiz → Direita
```

Para a árvore:

```mathematica
      10
     /  \
    5    15
   / \
  3   7
```

A ordem de visita é:

```text
3 → 5 → 7 → 10 → 15
```

Implementação:

```cpp
void inOrder(Node* node) {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->value << " ";
        inOrder(node->right);
    }
}
```

A ideia é:

1. percorrer a subárvore esquerda;
2. visitar o nó atual;
3. percorrer a subárvore direita.

Observação importante:

Em uma **Árvore Binária de Busca**, o percurso em-ordem visita os valores em ordem crescente.

Em uma árvore binária comum, isso não é necessariamente verdade.

### 6.1.3 Pós-ordem

Na pós-ordem, processamos o nó atual depois de processar suas subárvores.

Ordem:

```text
Esquerda → Direita → Raiz
```

Para a árvore:

```mathematica
      10
     /  \
    5    15
   / \
  3   7
```

A ordem de visita é:

```text
3 → 7 → 5 → 15 → 10
```

Implementação:

```cpp
void postOrder(Node* node) {
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->value << " ";
    }
}
```

A ideia é:

1. percorrer a subárvore esquerda;
2. percorrer a subárvore direita;
3. visitar o nó atual.

Esse percurso é útil, por exemplo, para liberar memória, pois processamos os filhos antes de processar o pai.

### 6.1.4 Comparação entre as travessias DFS

Usando a árvore:

```mathematica
      10
     /  \
    5    15
   / \
  3   7
```

Temos:

| Travessia | Ordem                     | Resultado             |
| --------- | ------------------------- | --------------------- |
| Pré-ordem | Raiz → Esquerda → Direita | `10 → 5 → 3 → 7 → 15` |
| Em-ordem  | Esquerda → Raiz → Direita | `3 → 5 → 7 → 10 → 15` |
| Pós-ordem | Esquerda → Direita → Raiz | `3 → 7 → 5 → 15 → 10` |

## 6.2 BFS: Breadth-First Search

A BFS percorre a árvore por níveis.

Ou seja, primeiro visitamos a raiz, depois os filhos da raiz, depois os netos, e assim por diante.

Para a árvore:

```mathematica
      10
     /  \
    5    15
   / \
  3   7
```

A visita por níveis é:

```yaml
Nível 0: 10
Nível 1: 5, 15
Nível 2: 3, 7
```

Ordem visitada:

```text
10 → 5 → 15 → 3 → 7
```

Diferentemente da DFS, a BFS normalmente é implementada usando uma **fila**.

A ideia é:

1. colocar a raiz na fila;
2. enquanto a fila não estiver vazia:

   * remover o primeiro nó da fila;
   * visitar esse nó;
   * inserir seus filhos na fila.

Em C++, podemos usar `std::queue` para representar essa fila:

```cpp
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

void bfs(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->value << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}
```

Nesse código:

* `queue<Node*> q;` cria uma fila de ponteiros para nós;
* `q.push(root);` insere a raiz na fila;
* `q.front();` acessa o primeiro elemento da fila;
* `q.pop();` remove o primeiro elemento da fila;
* os filhos do nó atual são inseridos no final da fila.

Assim, os nós são visitados nível por nível.

Observação:

Neste exemplo, usamos `std::queue` para simplificar a implementação.
A ideia importante é que a BFS depende de uma fila.
Em trabalhos ou provas em que a STL não estiver permitida, a fila teria que ser implementada manualmente ou substituída por uma estrutura própria.

### 6.3 Comparação geral entre DFS e BFS

| Tipo de travessia | Ideia principal                                            | Estrutura auxiliar |
| ----------------- | ---------------------------------------------------------- | ------------------ |
| DFS               | Explora profundamente uma subárvore antes de ir para outra | Recursão ou pilha  |
| BFS               | Explora a árvore nível por nível                           | Fila               |

Exemplo:

```mathematica
      10
     /  \
    5    15
   / \
  3   7
```

| Travessia | Resultado             |
| --------- | --------------------- |
| Pré-ordem | `10 → 5 → 3 → 7 → 15` |
| Em-ordem  | `3 → 5 → 7 → 10 → 15` |
| Pós-ordem | `3 → 7 → 5 → 15 → 10` |
| BFS       | `10 → 5 → 15 → 3 → 7` |

## 7. Exercícios Rápidos

Considere a árvore abaixo:

```mathematica
        A
      /   \
     B     C
    / \     \
   D   E     F
      /
     G
```

Responda:

1. Qual é a raiz?
2. Quais são as folhas?
3. Qual é a profundidade de `G`?
4. Qual é a altura de `B`?
5. Qual é a altura da árvore?
6. Qual é a ordem do percurso em pré-ordem?
7. Qual é a ordem do percurso em em-ordem?
8. Qual é a ordem do percurso em pós-ordem?
9. Qual é a ordem do percurso em largura?
