# Trabalho A2: Índice Invertido e Análise Comparativa de Estruturas de Dados

## 1. Objetivo

O objetivo deste projeto é implementar um [**índice invertido**](https://www.geeksforgeeks.org/inverted-index/) para um conjunto de documentos, utilizando **três estruturas de dados diferentes**:

1. Árvore Binária de Busca (BST)
2. Árvore AVL (AVL)
3. Árvore Rubro-Negra (RBT)

Vocês deverão implementar essas estruturas em **C ou C++ (sem utilizar orientação a objetos)** e comparar seu desempenho nas operações de **inserção** e **busca**, considerando diferentes quantidades de documentos processados.

### 1.1 Introdução: O que é um Índice Invertido?

Um **índice invertido** associa **palavras** a uma lista de **documentos** nos quais elas aparecem.
É uma estrutura fundamental em sistemas de busca, como o Google, pois permite localizar rapidamente quais documentos contêm uma determinada palavra.

#### Exemplo:

Suponha que temos os seguintes documentos:

- **Documento 1**: "o cachorro correu para casa"
- **Documento 2**: "a casa azul é bonita"
- **Documento 3**: "o cachorro e o gato dormem na casa azul"

Após o processamento (remoção de pontuação, conversão para minúsculas, etc.), o índice invertido resultante será:

| Palavra   | Documentos      |
|-----------|-----------------|
| a         | 2               |
| azul      | 2, 3            |
| bonita    | 2               |
| cachorro  | 1, 3            |
| casa      | 1, 2, 3         |
| correu    | 1               |
| dormem    | 3               |
| e         | 3               |
| gato      | 3               |
| na        | 3               |
| o         | 1, 3            |
| para      | 1               |

Cada palavra é armazenada como um "nó" na estrutura de dados (por exemplo, uma árvore), e esse nó contém uma lista (ou vetor) com os IDs dos documentos nos quais a palavra aparece.

## 2. Divisão de Grupos e Tarefas

* O trabalho deve ser feito em grupos de 4 a 5 alunos.
* O relatório final deve explicitar a divisão de tarefas realizada entre os integrantes.

## 3. Entrega e Utilização do GitHub

* Todo o desenvolvimento deve ocorrer em um repositório no GitHub, que será usado como forma de entrega.
* Envie o link do repositório por e-mail ao professor até **18/06 às 23h59** (sem prorrogação).
* O uso do Git será avaliado: commits relevantes, frequentes e com mensagens claras são obrigatórios.
* Commits feitos após o prazo acarretarão desconto mínimo de 2 pontos.

### 3.1 Entregáveis

1. **Entregáveis Parciais**
    * **Entrega 0**: Enviar e-mail com os integrantes do grupo
    * **Entrega 1**: Implementação da BST + leitura dos dados + CLI (Busca)
    * **Entrega 2**: Implementação da AVL + CLI (Estatísticas)

2. **Entrega Final:**
    * Código-fonte no GitHub:
       - Projeto organizado por pastas
       - Instruções de compilação e execução no `README.md`

    * Relatório em PDF ou Markdown
       - Explicação da estrutura de cada implementação
       - Gráficos comparando o desempenho
       - Análise dos resultados: vantagens e desvantagens observadas
       - Dificuldades encontradas

### 3.2 Cronograma de Entregas

| Entrega           | Conteúdo                                            | Data  |
| ----------------- | --------------------------------------------------- | ----- |
| **Entrega 0**     | Envio dos integrantes do grupo (por e-mail)         | 23/05 |
| **Entrega 1**     | BST funcional + leitura dos dados + CLI (Busca)     | 04/06 |
| **Entrega 2**     | AVL funcional + CLI (Estatísticas)                  | 11/06 |
| **Entrega Final** | Projeto completo + relatório + scripts e instruções | 18/06 |

**Aviso**:
* Atrasos nas entregas parciais acarretarão desconto de pelo menos 1 ponto por Entregável. 
* Trabalhos entregues após a data da Entrega Final (18/06 às 23h59) não serão avaliados.

## 4. Critérios de Avaliação

- [] **Correto funcionamento das estruturas implementadas**: A lógica de inserção, busca e organização dos dados deve estar correta e validada com testes.
- [] **Qualidade da análise comparativa entre estruturas**: Coerência e profundidade na análise das estatísticas obtidas (tempo, altura, número de comparações etc.).
- [] **Clareza e organização do código-fonte**: Uso adequado de funções, modularização, comentários e nomenclatura significativa.
- [] **Reprodutibilidade do projeto**: Código funcional via CLI e instruções claras para indexar a base de dados e realizar buscas.
- [] **Documentação e relatório final**: Relatório bem estruturado, com gráficos e discussões relevantes sobre os resultados observados.
- [] **Uso adequado do Git e organização do repositório**: Histórico de commits coerente, README informativo e estrutura de pastas compatível com o proposto.
- [] **Criatividade e aprofundamento opcional**: Explorações extras como análise de memória, ordenação alternativa ou visualizações adicionais.

## 5. Instruções do Trabalho
O objetivo do projeto é implementar um índice invertido utilizando três diferentes estruturas de dados (BST, AVL e RBT) e realizar uma análise comparativa de desempenho entre elas.

O desenvolvimento deve seguir as etapas abaixo:

1. Indexação a partir de um Corpus Real
    * Você receberá uma base de aproximadamente $10.000$ documentos de texto.
    * Seu programa deverá:
        * Ler automaticamente todos os arquivos `.txt` de um diretório especificado por argumento de linha de comando.
        * Construir o índice invertido utilizando as três estruturas mencionadas, coletando estatísticas de desempenho durante o processo.

2. Estruturas de Dados e Implementações
    * As estruturas devem ser implementadas do zero, em C ou C++ (sem orientação a objetos)
    * É permitido o uso das seguintes bibliotecas da STL:
        * `std::vector` para armazenar os IDs dos documentos.
        * `std::string` para armazenar as palavras.
        * `chrono` para cálculo de tempo.
        * `iostream` para escrita na stdout.
        * `fstream` para leitura dos arquivos.
    * As funções mínimas obrigatórias para cada estrutura estão descritas na seção de “Funcionalidades Mínimas”.

3. Interface por Linha de Comando (CLI)
    * O programa deverá permitir execução via terminal com comandos claros e argumentos bem definidos
    * Comandos esperados:
        ```bash
        ./<arvore> search <n_docs> <diretório>
        ./<arvore> stats <n_docs> <diretório>
        ```
        * `<arvore>`: nome do executável da estrutura (ex: bst, avl, rbt)
        * `search`: comando que permite realizar buscas por palavras
        * `stats`: comando que gera estatísticas de desempenho durante a indexação
        * `<n_docs>`: número de documentos a indexar
        * `<diretório>`: caminho para a pasta contendo os arquivos .txt
    * Essa interface facilita a testagem do projeto e garante sua reprodutibilidade.

    > Ao executar qualquer comando, o programa deve indexar os documentos e então executar a operação solicitada (busca ou geração de estatísticas).

4. Análise Comparativa
    * Após a indexação, o grupo deverá comparar o desempenho das estruturas em termos de:
        * Tempo de inserção (média, total)
        * Tempo de busca de palavras (médio, máximo)
        * Número de comparações por operação
        * Altura da árvore
        * Tamanho dos galhos (menor e maior caminho)
        * Outros critérios que julgarem relevantes
    * Incluam no relatório:
        * Tabelas com os valores brutos coletados pelo programa
        * Gráficos comparativos
        * Interpretação dos resultados: vantagens e limitações de cada estrutura
    > A análise deve ser feita para diferentes tamanhos de entrada (ex: 100, 1.000, 5.000, 10.000 documentos).  

    > A geração dos dados brutos (tempos, comparações etc.) deve ser feita pelo programa em C/C++. 
    > Os gráficos e cálculos estatísticos podem ser feitos em qualquer ferramenta: Python, Excel, etc.

## 5. Instruções do Trabalho

### 5.1 Funcionalidades Mínimas

### A. Estrutura `No` (Presente em todas representações de árvore)

```cpp
struct Node {
    std::string word;
    std::vector<int> documentIds;
    Node* parent;
    Node* left;
    Node* right;
    int height;    // usado na AVL
    int isRed;     // usado na RBT
};

struct BinaryTree {
    Node* root;
    Node* NIL;  // usado na RBT (Opcional)
}
```

### B. Structs auxiliares

```cpp
struct InsertResult {
    int numComparisons;
    double executionTime;
    <Possíveis outras variáveis>
};

struct SearchResult {
    int found;
    std::vector<int> documentIds;
    double executionTime;
    int numComparisons;
    <Possíveis outras variáveis>
};
```

### C. Funções obrigatórias para cada estrutura

#### {bst,avl,rbt}.cpp
* `BinaryTree* create()`
* `InsertResult insert(BinaryTree* tree, const std::string& word, int documentId)`
* `SearchResult search(BinaryTree* tree, const std::string& word)`
* `void destroy(BinaryTree* tree)`

> Usar `BST::`, `AVL::` e `RBT::` como namespaces, conforme a estrutura.

> Este projeto não exige a implementação da operação de remoção em nenhuma das estruturas.
> O foco está exclusivamente nas operações de inserção (para construção do índice invertido) e busca (consulta por palavras).

#### tree_utils.cpp
* `void printIndex(BinaryTree* tree)` 
    ```bash
    1. Algoritmo: 2, 3, 5
    2. Binário: 1, 10
    3. Código: 1, 3, 10
    ...
    ```
* `void printTree(BinaryTree* tree)`
    ```bash
    arvore
    ├── algoritmo
    └── memoria
        ├── lista
        └── vetor
    ```

> Todas as structs (como Node, BinaryTree, InsertResult, SearchResult) devem ser declaradas aqui 

### 5.2 Sugestão de Organização do Código:

Sugere-se a seguinte estrutura de pastas e arquivos:

```
projeto-final/
│
├── src/
│   ├── main_bst.cpp                  # Interface via linha de comando (indexação e busca) da Árvore Binária de Busca
│   ├── main_avl.cpp                  # Interface via linha de comando (indexação e busca) da Árvore AVL
│   ├── main_rbt.cpp                  # Interface via linha de comando (indexação e busca) da Árvore Rubro Negra
│   ├── bst.cpp / bst.h               # Implementação da Árvore Binária de Busca
│   ├── avl.cpp / avl.h               # Implementação da Árvore AVL
│   ├── rbt.cpp / rbt.h               # Implementação da Árvore Rubro-Negra
│   ├── tree_utils.cpp / tree_util.h  # Structs e Funções auxiliares, como Criar Nó, Computar altura, Busca, Exibir Árvore, etc
│   ├── data.cpp / data.h             # Leitura do diretório e carregamento dos arquivos 
│   ├── test_bst.cpp                  # testes unitários e exemplos para implementação da Árvore Binária de Busca
│   ├── test_avl.cpp                  # testes unitários e exemplos para implementação da Árvore AVL
│   ├── test_rbt.cpp                  # testes unitários e exemplos para implementação da Rubro-Negra
│
├── docs/
│   ├── Relatório (PDF ou .md)
│   ├── Gráficos e tabelas
│
├── data/
│   ├── Base de dados de documentos (.txt)
│
├── README.md # Descrição, instruções de compilação e execução do Projeto
```
