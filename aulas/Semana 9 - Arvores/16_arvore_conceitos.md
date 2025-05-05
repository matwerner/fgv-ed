# Aula 16: Conceitos sobre Árvore

## 1. Introdução e Motivação

Nas aulas anteriores, vimos listas encadeadas, uma estrutura de dados em que os elementos (nós) se conectam de forma sequencial. Esse modelo é útil para representar sequências lineares de dados, como filas ou pilhas.

Hoje, vamos estudar uma estrutura semelhante em termos de nós e ponteiros, mas com uma organização hierárquica: as árvores.

### 1.1 Por que estudar árvores?

Árvores são usadas para representar relações hierárquicas em diversas situações. Elas aparecem em praticamente todas as áreas da computação.

Vamos ver alguns exemplos práticos:

* **HTML (Document Object Model)**:\
Uma página web é estruturada como uma árvore. O elemento `<html>` é a raiz, com dois filhos principais: `<head>` e `<body>`, e cada um deles contém outros elementos aninhados (como `<div>`, `<p>`, `<h1>` etc.). Isso forma uma hierarquia que pode ser percorrida e manipulada com facilidade por scripts e navegadores.

* **Sistema de Arquivos**:\
    O sistema de pastas do seu computador também é uma árvore. Cada pasta pode conter arquivos (folhas) ou outras pastas (subárvores). O diretório raiz (`/` no Linux, `C:\` no Windows) é a raiz da árvore.

* **Árvores de decisão e o Akinator**:\
    Em jogos e algoritmos de decisão, como o Akinator, a estrutura é uma árvore: cada nó representa uma pergunta (como “Seu personagem é real?”), e as arestas levam a outras perguntas ou a uma resposta. A cada passo, percorremos a árvore até chegar a uma folha com a decisão.

E por que isso importa em estrutura de dados?

Além dessas aplicações visuais e lógicas, as árvores servem como base para estruturas altamente eficientes, que aprenderemos nas próximas aulas:
* **Árvores Binárias de Busca (BST)**: permitem buscas rápidas;
* **Árvores AVL, Rubro-Negras, B**  : mantêm equilíbrio e desempenho garantido.
* **Heaps**: organizam prioridades de forma eficiente.

Todas essas estruturas dependem do entendimento que vamos construir hoje.

## 2. Terminologia e Conceitos Fundamentais

Agora que entendemos por que árvores são importantes e onde elas aparecem, vamos estudar com mais cuidado como essa estrutura é formada e quais são os conceitos básicos envolvidos.

Imagine a seguinte árvore:

```mathematica
        A
      /   \
     B     C
    / \     \
   D   E     F
```

Essa estrutura representa uma árvore com vários nós ligados de forma hierárquica.

### 2.1 Termos fundamentais

* **Nó (node)**:\
    Unidade básica da árvore. Cada nó armazena um valor (ou dado) e ponteiros para seus filhos (outros nós ligados a ele). Ex: `A`, `B`, `C` são nós.

* **Raiz (root)**:\
    É o nó mais alto da hierarquia, o único que não tem pai. Toda árvore tem exatamente uma raiz.
    Ex: no exemplo acima, `A` é a raiz.

* Filho (child)**:\
    Um nó diretamente ligado abaixo de outro. Ex: `B` e `C` são filhos de `A`.

* Pai (parent)**:\
    Um nó diretamente ligado acima de outro. Ex: `A` é pai de `B` e `C`.

* Irmãos (siblings)**:\
    Nós que compartilham o mesmo pai. Ex: `B` e `C` são irmãos; `D` e `E` também.

* **Folha (leaf)**:\
    Nó que não possui filhos. Ex: `D`, `E` e `F` são folhas.

* **Subárvore (subtree)**:\
    Qualquer nó da árvore, junto com seus descendentes. Cada nó define uma subárvore.
    Ex: a subárvore com raiz em B inclui os nós `B`, `D` e `E`.

### 2.2 Conceitos estruturais

* **Profundidade de um nó**:\
    Número de arestas da raiz até esse nó.\
    Ex: Profundidade de `D` é 2 (A → B → D).

* **Altura de um nó**:\
    Número de arestas no caminho mais longo entre esse nó e uma de suas folhas.\
    Ex: Altura de `B` é 1 (B → D ou B → E).\
    A altura da árvore é a altura da raiz. No exemplo, altura da árvore = 2.

### 2.3 Exercício

```mathematica
        A
      /   \
     B     C
    /     /  \
   D     E    F
  / \
 G   H
```

Dado a árvore acima, identifique para cada nó:
* Valor
* O pai
* Filho da esquerda
* Filho da direita
* A altura
* A profundida

Além disso, diga quem é:
* A raiz
* Os nós folhas.
* Os irmãos de um determinado nó.

## 3. Tipos Especiais de Árvores

Até agora, vimos a estrutura geral de uma árvore.
Mas, assim como nas listas encadeadas temos listas simples, duplamente encadeadas e circulares, nas árvores também há variações com propriedades específicas.

### 3.1 Árvores n-árias e Árvores Binárias

Em teoria, um nó pode ter qualquer número de filhos.
Quando limitamos esse número a no máximo **$n$ filhos por nó**, chamamos de **árvore $n$-ária**.

Na prática, a estrutura mais comum é a árvore binária, onde cada nó pode ter no máximo dois filhos:
* Um filho à esquerda.
* Um filho à direita.

A partir das árvores binárias, podemos definir tipos ainda mais específicos:

### 3.2 Árvore Binária

* Cada nó tem no máximo dois filhos.
* Base para estruturas como BST, heaps e AVL.

```mathematica
      A
     / \
    B   C
   /     \
  D       E
```

### 3.3 Árvore Estritamente Binária

* Cada nó tem exatamente 0 ou 2 filhos (nunca apenas 1).
* Ajuda a manter simetria e facilita algumas operações.

```mathematica
       A
      / \
     B   C
    / \
   D  E
```

### 3.4 Árvore Cheia (ou Completa Perfeita)

* Todos os nós internos têm exatamente dois filhos.
* Todas as folhas estão no mesmo nível.
* Exemplo ideal de equilíbrio.

```mathematica
        A
      /   \
     B     C
    / \   / \
   D   E F   G
```

### 3.5 Árvore Balanceada (noção informal)

* Uma árvore que busca manter a altura das subárvores esquerda e direita semelhantes.
* Não exige perfeição, mas evita que um lado cresça muito mais que o outro.
* Variações balanceadas incluem AVL, Rubro-Negra e B.

```mathematica
        A
      /   \
     B     C
    / \     \
   D   E     F
```

### 3.6 Árvore Degenerada

* Caso extremo em que cada nó tem apenas um filho.
* A árvore se torna semelhante a uma lista encadeada.
* Piora drasticamente a eficiência das operações de busca e inserção.

```mathematica
A
 \
  B
   \
    C
     \
      D
```

## 4. Número de Nós em Função da Altura

Quando trabalhamos com árvores binárias, uma pergunta natural é:

    Dada uma altura h, qual o mínimo e o máximo número de nós que uma árvore pode ter?

Antes de responder, lembre-se:
* A altura $h$ é o número de arestas do caminho mais longo da raiz até uma folha.
* Então, uma árvore com um único nó (a raiz) tem altura $h=0$.

### 4.1 Máximo de nós:

Ocorre quando a árvore é cheia: todos os níveis estão completamente preenchidos.
* Cada nível $i$ pode conter até $2^i$ nós.
* Somando todos os níveis de $0$ até $h$, temos:

$$N_{max}= 2^0 + 2^1 + 2^2 + \dots + 2^h = 2^{h+1}−1$$

#### Exemplo (altura $h=3$):

```mathematica
        A
      /   \
     B     C
    / \   / \
   D   E F   G
  / \
 H   I
```

Nível 0: 1 nó (A)\
Nível 1: 2 nós (B, C)\
Nível 2: 4 nós (D, E, F, G)\
Nível 3: 8 nós (H, I, ...)\
Total: $2^4−1 = 15$ nós

### 4.2 Mínimo de nós:
Ocorre quando a árvore é completamente degenerada — ou seja, ela se comporta como uma lista encadeada:
cada nó tem apenas um filho.

$$N_{min}=h+1$$

#### Exemplo (altura h=3h=3):

```mathematica
A
 \
  B
   \
    C
     \
      D
```

Altura = 3\
Total de nós = 4

## 5.  Representação de Árvores

### 5.1 Representação com Nós (Estrutura Encadeada)

A forma mais comum e flexível de representar árvores é usando estruturas encadeadas, em que cada nó guarda:
* O valor do nó
* Um ponteiro para o filho à esquerda
* Um ponteiro para o filho à direita

#### Estrutura de um nó em C

```cpp
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};
```

### 5.2 Construindo a árvore

Imagine que queremos construir a árvore:
```mathematica
      10
     /  \
    5    15
   / \
  3   7
```

Em C ficaria:

```cpp
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

// Função auxiliar para criar um novo nó
Node* createNode(int value) {
    Node* no = new Node();
    no->value = value;
    no->left = nullptr;
    no->right = nullptr;
    return no;
}

int main() {
    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);

    // A árvore está montada. Podemos agora fazer travessias, buscas, etc.

    return 0;
}
```

### 5.3 Observação

Existem outras formas de representar árvores, como usando vetores, que funcionam bem em árvores completas (por exemplo, em heaps).
Mas esse tipo de representação será discutido mais adiante na disciplina.

## 6. Travessia

Uma árvore binária pode ser percorrida de várias formas, dependendo da ordem desejada para acessar seus nós.
Isso é essencial para diversas tarefas como:
* Impressão estruturada dos dados
* Serialização e deserialização
* Avaliação de expressões
* Liberação de memória
* Busca por padrões
* Ordenação (em BSTs)

Existem duas abordagens principais:

- **BFS (Breadth-First Search)** — percorre a árvore por nível
- **DFS (Depth-First Search)** — percorre profundamente pelos ramos

**Observação**:

Exemplo visual a ser utilizado abaixo:
```mathematica
      10
     /  \
    5    15
   / \
  3   7
```

### 6.1 BFS: Breadth-First Search (Busca em Largura ou por Níveis)

Aqui, percorremos a árvore nível por nível, da esquerda para a direita:

```yaml
Nível 0: 10  
Nível 1: 5, 15  
Nível 2: 3, 7
```

Ordem visitada: `10 → 5 → 15 → 3 → 7`

Usos comuns:
* Verificar estrutura por níveis
* Buscar caminhos mais curtos em algumas variantes
* Aplicações em AI (como jogos ou grafos com pesos iguais)

Implementação (requer o uso de uma fila):
```cpp
void bfs(Node* root) {
    if (raiz == NULL) return;

    Queue* q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        printf("%d ", current->value);
        if (current->left) enqueue(q, current->left);
        if (current->right) enqueue(q, current->right);
    }
}
```

### 6.2 DFS – Depth-First Search (Busca em Profundidade)

Três formas clássicas de percorrer uma árvore profundamente são:

#### Pré-Ordem (raiz → esquerda → direita)

Ordem visitada: `10 → 5 → 3 → 7 → 15`

Usos comuns:
* Serialização / clonagem da árvore
* Impressão da estrutura em forma de diretório

Implementação:
```cpp
void preOrder(Node* n) {
    if (n != NULL) {
        printf("%d ", n->value);
        preOrder(n->left);
        preOrder(n->right);
    }
}
```

#### In-Ordem (esquerda → raiz → direita)

Ordem visitada: `3 → 5 → 7 → 10 → 15`

Usos comuns:
* Em BSTs, imprime os valores em ordem crescente

Implementação:
```cpp
void inOrder(Node* n) {
    if (n != NULL) {
        inOrder(n->left);
        printf("%d ", n->value);
        inOrder(n->right);
    }
}
```

#### Pós-Ordem (esquerda → direita → raiz)

Ordem visitada: `3 → 7 → 5 → 15 → 10`

Usos comuns:
* Liberação de memória (deleta os filhos antes do pai)
* Avaliação de expressões aritméticas em árvores de expressão

Implementação:
```cpp
void postOrder(Node* n) {
    if (n != NULL) {
        postOrder(n->left);
        postOrder(n->right);
        printf("%d ", n->value);
    }
}
```
