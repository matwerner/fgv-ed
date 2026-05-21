# Trabalho 4: Sistema de Autocomplete de Jogos com Trie

## Organização do trabalho

Este trabalho deve ser realizado em duplas.

Caso algum aluno não possua dupla, deverá entrar em contato com o professor o quanto antes para que seja possível organizar os grupos ou, se necessário, autorizar a formação de um trio.

Ambos os alunos da dupla são responsáveis pela implementação, documentação e entrega do projeto.

## Descrição do trabalho

Neste trabalho, os alunos devem implementar um sistema simples de **autocomplete de jogos** utilizando uma estrutura de dados chamada **Trie**.

Uma Trie é uma árvore usada para armazenar strings caractere por caractere. Ela é especialmente útil quando queremos realizar buscas por prefixo, como em sistemas de autocomplete, dicionários, índices de palavras e mecanismos de busca textual.

Neste trabalho, a Trie será utilizada para armazenar um catálogo de jogos. Cada jogo possui:
* um título;
* uma descrição curta;
* uma popularidade.

O sistema deve permitir buscar jogos a partir de um prefixo do título. Dado um prefixo e um número `k`, o sistema deve retornar até `k` jogos cujo título começa com esse prefixo, ordenados por popularidade.

A solução deve ser implementada em **C++**, utilizando **classes e modularização** (`.hpp` e `.cpp`).

## O que é uma Trie?

Uma Trie é uma árvore usada para armazenar strings caractere por caractere.

Cada nó representa um caractere, e cada caminho a partir da raiz representa um prefixo. Quando um caminho corresponde a uma palavra ou título completo, marcamos o último nó como fim de palavra ou, neste trabalho, como fim de título.

Por exemplo, os títulos:

```text
hades
halo
halflife
```

compartilham o prefixo:

```text
ha
```

Na Trie, esse prefixo é armazenado apenas uma vez, como parte comum dos três títulos.

Essa propriedade torna a Trie útil para buscas por prefixo. Para encontrar todos os jogos que começam com `"ha"`, primeiro percorremos a Trie seguindo os caracteres `'h'` e `'a'`. Depois, a partir desse ponto, buscamos os títulos completos que possuem esse prefixo.

## Referências de apoio

Antes de iniciar a implementação, recomenda-se estudar o conceito de Trie e observar exemplos de inserção, busca por palavra e busca por prefixo.

Sugestões de referência:

* Vídeo explicativo sobre Trie:
    * [**Estrutura de Dados - Aula 20 - Árvores N árias; Tries"**](https://www.youtube.com/watch?v=zNNKeMHIq14)
    * [**HackerRank: "Data Structures: Tries"**](https://www.youtube.com/watch?v=zIjfhVPRZCg)
    * [**Jacob Sorber: "The Trie Data Structure (Prefix Tree)"**](https://www.youtube.com/watch?v=3CbFFVHQrk4)

* Página/tutorial sobre Trie:
    * [**Geeks for Geeks: "Trie Data Structure"**](https://www.geeksforgeeks.org/dsa/trie-insert-and-search/)

As referências servem como apoio conceitual. A implementação entregue deve seguir a especificação deste trabalho, especialmente em relação às classes, métodos, critérios de ordenação e uso da Trie para o autocomplete.

## Regras do sistema

Considere as seguintes regras:
* O sistema armazena um catálogo de jogos.
* Cada jogo possui título, descrição curta e popularidade.
* Não é necessário tratar tentativas de inserção de jogos com títulos duplicados.
* A Trie deve utilizar o título do jogo como chave de busca.
* A busca deve ser feita por prefixo.
* A busca deve ser **case-insensitive**, ou seja, não deve diferenciar letras maiúsculas e minúsculas.
* A busca deve **ignorar espaços em branco**.
* Os títulos serão compostos apenas por letras, números e espaços.
* Não haverá acentos, pontuações ou outros símbolos nos títulos usados nos testes.
* O sistema deve retornar até `k` jogos encontrados.
* Se `k <= 0`, o método de autocomplete deve retornar um vetor vazio.
* Os jogos retornados devem estar ordenados por popularidade em ordem decrescente.
* Em caso de empate na popularidade, deve vir primeiro o jogo cuja chave de busca do título venha antes em ordem alfabética.
* A lista inicial de jogos será fornecida diretamente no código-fonte.
* Não é necessário implementar leitura de arquivos.
* Não é necessário implementar menu interativo.
* O programa deve ser executado pela linha de comando no formato:

```bash
./app k prefixo
```

Por exemplo:

```bash
./app 3 ha
```

Caso o prefixo possua espaços, ele deve ser passado entre aspas:

```bash
./app 3 "half l"
```

Como a busca deve ignorar espaços, os prefixos `"halfl"`, `"half l"` e `"Half L"` devem ser tratados de forma equivalente.

## Chave de busca

Antes de inserir ou buscar jogos na Trie, títulos e prefixos devem ser convertidos para uma representação interna usada pela estrutura. Neste enunciado, essa representação será chamada de **chave de busca**.

A classe `Trie` deve possuir um método público:

```cpp
std::string toSearchKey(std::string text);
```

Esse método deve converter um título ou prefixo para a forma utilizada internamente pela Trie.

A implementação desse método faz parte do trabalho. Porém, o comportamento externo deve respeitar as regras do sistema:
* não diferenciar letras maiúsculas e minúsculas;
* ignorar espaços em branco;
* considerar que os títulos possuem apenas letras, números e espaços.

Exemplos de comportamento esperado:

```cpp
toSearchKey("Hades") == toSearchKey("hades")
toSearchKey("HA") == toSearchKey("ha")
toSearchKey("Half Life") == toSearchKey("halflife")
toSearchKey("Portal 2") deve preservar o caractere '2'
```

O conjunto de caracteres utilizado internamente pela Trie forma o alfabeto da implementação. O tamanho desse alfabeto depende da solução adotada pelo grupo.

Para converter um caractere para uma posição do array de filhos, pode ser útil consultar a tabela ASCII.

A estratégia de normalização, o tamanho do alfabeto e o mapeamento de caracteres para índices devem ser explicados no relatório.

## Critério de ordenação das sugestões

O método de autocomplete deve retornar os jogos encontrados seguindo os critérios abaixo:
1. maior popularidade;
2. em caso de empate, ordem alfabética pela chave de busca do título.

Por exemplo, considere os jogos:

```text
[Hades | Roguelike de acao baseado na mitologia grega | 95]
[Halo | FPS futurista com campanha e multiplayer | 85]
[Half Life | FPS classico de ficcao cientifica | 92]
[Harvest Moon | Jogo de fazenda e simulacao | 70]
```

Para a busca:

```bash
./app 3 ha
```

O resultado esperado é:

```text
Hades | Roguelike de acao baseado na mitologia grega | 95
Half Life | FPS classico de ficcao cientifica | 92
Halo | FPS futurista com campanha e multiplayer | 85
```

## Funcionalidades do sistema

O sistema deve permitir:
* inserir jogos na Trie;
* buscar um jogo pelo título exato;
* buscar jogos por prefixo;
* retornar até `k` sugestões de jogos por prefixo;
* ordenar os resultados do autocomplete;
* exibir os resultados encontrados;
* converter títulos e prefixos para a chave de busca utilizada internamente.

## Exemplos de funcionamento

Nos exemplos abaixo, um jogo será representado da seguinte forma:

```text
[titulo | descricao | popularidade]
```

### Exemplo 1: busca por título exato

Estado inicial:
```text
[Hades | Roguelike de acao baseado na mitologia grega | 95]
[Half Life | FPS classico de ficcao cientifica | 92]
[Hollow Knight | Metroidvania de exploracao e combate | 90]
```

Chamadas esperadas:
```cpp
contains("Hades");       // true
contains("hades");       // true
contains("HADES");       // true
contains("Half Life");   // true
contains("halflife");    // true
contains("HALF LIFE");   // true
contains("Minecraft");   // false
```

A busca deve ser case-insensitive e deve ignorar espaços em branco.

### Exemplo 2: autocomplete

Estado inicial:
```text
[Hades | Roguelike de acao baseado na mitologia grega | 95]
[Halo | FPS futurista com campanha e multiplayer | 85]
[Half Life | FPS classico de ficcao cientifica | 92]
[Hollow Knight | Metroidvania de exploracao e combate | 90]
```

Chamadas equivalentes:
```cpp
autocomplete("ha", 3);
autocomplete("HA", 3);
```

Resultado esperado:
```text
[Hades | Roguelike de acao baseado na mitologia grega | 95]
[Half Life | FPS classico de ficcao cientifica | 92]
[Halo | FPS futurista com campanha e multiplayer | 85]
```

As chamadas abaixo também devem ser equivalentes:
```cpp
autocomplete("half", 5);
autocomplete("half l", 5);
autocomplete("HALF L", 5);
```

Resultado esperado:
```text
[Half Life | FPS classico de ficcao cientifica | 92]
```

### Exemplo 3: desempate pela chave de busca

Estado inicial:
```text
[Halo | FPS futurista com campanha e multiplayer | 90]
[Half Life | FPS classico de ficcao cientifica | 90]
[Hades | Roguelike de acao baseado na mitologia grega | 95]
```

Executando:
```cpp
autocomplete("ha", 3);
```

Resultado esperado:
```text
[Hades | Roguelike de acao baseado na mitologia grega | 95]
[Half Life | FPS classico de ficcao cientifica | 90]
[Halo | FPS futurista com campanha e multiplayer | 90]
```

`Half Life` aparece antes de `Halo` porque ambos possuem popularidade `90`, mas a chave de busca `halflife` vem antes de `halo` em ordem alfabética.

### Exemplo 4: uso pela linha de comando

Compilando:
```bash
g++ main.cpp Game.cpp Trie.cpp GamesDatabase.cpp -o app
```

Executando:
```bash
./app 3 ha
```

Saída esperada:
```text
Hades | Roguelike de acao baseado na mitologia grega | 95
Half Life | FPS classico de ficcao cientifica | 92
Halo | FPS futurista com campanha e multiplayer | 85
```

Caso nenhum resultado seja encontrado:
```bash
./app 3 zelda
```

Saída esperada:
```text
No results found
```

## Lista inicial de jogos

A lista inicial de jogos será fornecida diretamente no código-fonte.

Não é necessário implementar leitura de arquivos.

O professor fornecerá os arquivos da base de jogos:
```text
GamesDatabase.hpp
GamesDatabase.cpp
```

O arquivo `GamesDatabase.hpp` conterá apenas as declarações da lista de jogos e da quantidade de jogos.

Exemplo de `GamesDatabase.hpp`:

```cpp
#ifndef GAMES_DATABASE_HPP
#define GAMES_DATABASE_HPP

#include "Game.hpp"

extern Game games[];
extern int numberOfGames;

#endif
```

O arquivo `GamesDatabase.cpp` conterá a definição da lista.

Exemplo de `GamesDatabase.cpp`:

```cpp
#include "GamesDatabase.hpp"

Game games[] = {
    Game("Hades", "Roguelike de acao baseado na mitologia grega", 95),
    Game("Hollow Knight", "Metroidvania de exploracao e combate", 90),
    Game("Halo", "FPS futurista com campanha e multiplayer", 85),
    Game("Half Life", "FPS classico de ficcao cientifica", 92),
    Game("Harvest Moon", "Jogo de fazenda e simulacao", 70),
    Game("Stardew Valley", "Jogo de fazenda, exploracao e relacionamentos", 88),
    Game("Portal 2", "Jogo de puzzle em primeira pessoa", 91),
    Game("Team Fortress 2", "FPS em equipes com classes diferentes", 86),
    Game("Civilization 6", "Jogo de estrategia baseado em turnos", 89),
    Game("Resident Evil 4", "Jogo de acao e survival horror", 93)
};

int numberOfGames = sizeof(games) / sizeof(games[0]);
```

Os alunos devem incluir `GamesDatabase.hpp` no `main.cpp` e compilar o projeto incluindo também `GamesDatabase.cpp`.

A Trie não deve criar novos objetos `Game` dinamicamente. Os jogos já existem no array fornecido em `GamesDatabase.cpp`. Os nós terminais da Trie devem armazenar ponteiros para esses objetos.

Além dos arquivos da base de jogos, serão fornecidos também os arquivos auxiliares:

```text
check_database.cpp
Game.hpp
COMO_TESTAR_BASE.md
```

Esses arquivos auxiliares servem apenas para testar se a base de jogos foi carregada corretamente.

O arquivo `check_database.cpp` contém um programa simples que imprime alguns jogos da base no terminal.

O arquivo `Game.hpp` fornecido nessa pasta é uma versão auxiliar da classe `Game`, usada apenas para compilar esse teste inicial.

O arquivo `COMO_TESTAR_BASE.md` explica como compilar e executar esse teste.

Esses arquivos auxiliares não substituem a implementação final do trabalho. O grupo deve seguir a especificação do enunciado e entregar os arquivos exigidos para o projeto final.

## Estruturas

### Classe `Game`

A classe `Game` representa um jogo do catálogo.

```cpp
class Game {

private:
    std::string title;
    std::string shortDescription;
    int popularity;

public:

    Game();
    Game(std::string title, std::string shortDescription, int popularity);
    ~Game();

    std::string getTitle();
    std::string getShortDescription();
    int getPopularity();
};
```

### Classe `TrieNode`

A classe `TrieNode` representa um nó da Trie.

Cada nó deve possuir:

* ponteiros para os filhos;
* uma indicação de fim de título;
* um ponteiro para um objeto `Game`, caso aquele nó represente o final de um título.

O número de filhos de cada nó depende do conjunto de caracteres utilizado na chave de busca.

Uma possível estrutura para `TrieNode` é:

```cpp
class TrieNode {

public:

    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfTitle;
    Game* game;

    TrieNode();
    ~TrieNode();
};
```

A constante `ALPHABET_SIZE` deve representar o número de caracteres válidos na chave de busca. Seu valor depende da implementação escolhida pelo grupo.

Ao criar um novo `TrieNode`, os filhos devem ser inicializados como `nullptr`, `isEndOfTitle` deve ser inicializado como `false` e `game` deve ser inicializado como `nullptr`.

O atributo `isEndOfTitle` indica se o caminho da raiz até aquele nó representa o título completo de um jogo.

O atributo `game` deve apontar para o jogo associado àquele título. Quando `isEndOfTitle == false`, `game` deve ser `nullptr`. Quando `isEndOfTitle == true`, `game` deve apontar para um objeto `Game`.

### Classe `Trie`

A classe `Trie` é responsável por armazenar os jogos e realizar as buscas por título e por prefixo.

```cpp
class Trie {

private:

    TrieNode* root;

public:

    Trie();
    ~Trie();

    bool insert(Game* game);
    bool contains(std::string title);

    std::vector<Game*> autocomplete(std::string prefix, int k);

    std::string toSearchKey(std::string text);
    void sortResults(std::vector<Game*>& games);

    // Outros métodos auxiliares, se necessário
};
```

A raiz da Trie deve ser criada no construtor.

Os métodos `toSearchKey` e `sortResults` devem ser públicos para permitir testes automatizados.

## Especificação dos métodos

### Método `toSearchKey`

O método:

```cpp
std::string toSearchKey(std::string text);
```

deve converter um título ou prefixo para a forma utilizada internamente como chave na Trie.

Esse método deve respeitar o comportamento esperado da busca:
* não diferenciar maiúsculas/minúsculas;
* ignorar espaços em branco;
* preservar letras e números.

### Método `insert`

O método:

```cpp
bool insert(Game* game);
```

deve inserir um jogo na Trie usando o título do jogo como base para a chave de busca.

O parâmetro `game` é um ponteiro para um objeto `Game` já existente no array fornecido em `GamesDatabase.cpp`.

A Trie não deve criar uma nova cópia dinâmica do jogo.

Caso a inserção seja realizada corretamente, o método deve retornar `true`.

Não é necessário tratar títulos duplicados.

### Método `contains`

O método:

```cpp
bool contains(std::string title);
```

deve verificar se existe um jogo com o título informado, respeitando as regras de busca definidas neste enunciado.

O método deve retornar:

* `true`, caso o título seja encontrado;
* `false`, caso contrário.

### Método `sortResults`

O método:

```cpp
void sortResults(std::vector<Game*>& games);
```

deve ordenar o vetor recebido seguindo os critérios do autocomplete:

1. maior popularidade;
2. em caso de empate, ordem alfabética pela chave de busca do título.

Não é permitido utilizar `std::sort`.

### Método `autocomplete`

O método:

```cpp
std::vector<Game*> autocomplete(std::string prefix, int k);
```

deve retornar até `k` jogos cujo título começa com o prefixo informado, respeitando as regras de busca e ordenação definidas neste enunciado.

Caso nenhum jogo seja encontrado, o método deve retornar um vetor vazio.

Caso `k <= 0`, o método deve retornar um vetor vazio.

A implementação deve utilizar a Trie como estrutura principal de busca.

Após a construção da Trie, o método `autocomplete` não deve percorrer o array original de jogos para encontrar os resultados. A busca deve seguir o prefixo na Trie e explorar a subárvore correspondente.

Soluções que simplesmente percorrerem todos os jogos do catálogo para responder ao autocomplete não serão aceitas.

## Uso de estruturas da STL

Neste trabalho, é permitido utilizar:

* `std::string`;
* `std::vector`, apenas para armazenar e retornar os resultados do autocomplete.

Não é permitido utilizar estruturas prontas que substituam a implementação da Trie, como `map` ou `unordered_map`.

Também não é permitido utilizar `std::sort`.

A Trie deve ser implementada manualmente, utilizando nós e ponteiros.

## Organização dos arquivos

O projeto deve possuir a seguinte organização mínima:

```text
main.cpp
Game.hpp
Game.cpp
Trie.hpp
Trie.cpp
GamesDatabase.cpp
GamesDatabase.hpp
```

Descrição dos arquivos:

* **main.cpp**: arquivo principal responsável por carregar a lista inicial de jogos, inserir os jogos na Trie e executar a busca usando os argumentos da linha de comando.
* **Game.hpp**: declaração da classe `Game`.
* **Game.cpp**: implementação da classe `Game`.
* **Trie.hpp**: declaração das classes `Trie` e `TrieNode`.
* **Trie.cpp**: implementação das classes `Trie` e `TrieNode`.
* **GamesDatabase.hpp**: declaração das variáveis contendo a lista inicial de jogos.
* **GamesDatabase.cpp**: definição da lista inicial de jogos.

É permitido criar arquivos adicionais (`.hpp` e `.cpp`) para melhor organização do código.

Todos os arquivos devem estar no mesmo diretório para garantir a compilação correta com o comando fornecido.

## Funcionamento do `main.cpp`

O programa deve ser executado no seguinte formato:

```bash
./app k prefixo
```

Onde:

* `k` é a quantidade máxima de sugestões desejadas;
* `prefixo` é o prefixo usado na busca.

Exemplo:

```bash
./app 3 ha
```

Caso o prefixo contenha espaços, ele deve ser passado entre aspas:

```bash
./app 3 "half l"
```

O `main.cpp` deve:

1. verificar se os argumentos foram informados corretamente;
2. converter o argumento `k` para inteiro;
3. criar uma `Trie`;
4. inserir todos os jogos da lista inicial na Trie;
5. chamar o método `autocomplete`;
6. exibir os jogos retornados.

A inserção dos jogos deve ser feita passando ponteiros para os objetos existentes no array `games`.

Exemplo:

```cpp
for (int i = 0; i < numberOfGames; i++) {
    trie.insert(&games[i]);
}
```

Caso a quantidade de argumentos esteja incorreta, o programa deve exibir:

```text
Usage: ./app k prefix
```

Caso nenhum resultado seja encontrado, o programa deve exibir:

```text
No results found
```

A saída dos jogos encontrados deve seguir o formato:

```text
Titulo | Descricao | Popularidade
```

## Requisitos

### Implementação

* As funções devem seguir exatamente as assinaturas fornecidas.
* O programa deve compilar corretamente.
* Programas que não compilarem não poderão ser avaliados e receberão nota 0.
* A Trie deve ser implementada manualmente.
* O autocomplete deve utilizar a Trie como estrutura principal de busca.
* O autocomplete deve ser case-insensitive.
* A busca deve ignorar espaços em branco.
* Os títulos utilizados nos testes terão apenas letras, números e espaços.
* Não serão utilizados acentos, pontuações ou outros símbolos nos testes.
* Os resultados do autocomplete devem ser ordenados manualmente.
* O código deve utilizar boas práticas de programação, incluindo modularização, nomes claros e uso adequado de classes.
* A Trie deve armazenar ponteiros para os jogos existentes, e não criar novos objetos `Game` dinamicamente.

### Bibliotecas e funções permitidas

* É permitido utilizar `std::string`.
* É permitido utilizar `std::vector` apenas para armazenar e retornar os resultados do autocomplete.
* Não é permitido utilizar `std::sort` ou outra função pronta de ordenação.
* Não é permitido utilizar estruturas prontas que substituam a Trie, como `map` ou `unordered_map`.

### Entrada e saída

* Não é necessário implementar leitura de arquivos.
* Não é necessário implementar menu interativo.
* O programa deve ser executado no formato:

```bash
./app k prefixo
```

* Caso a quantidade de argumentos esteja incorreta, o programa deve exibir:

```text
Usage: ./app k prefix
```

* Caso nenhum jogo seja encontrado, o programa deve exibir:

```text
No results found
```

* A saída dos jogos encontrados deve seguir o formato:

```text
Titulo | Descricao | Popularidade
```

## Orientações para o relatório

O relatório deve ter aproximadamente 2 páginas e deve focar nas decisões de implementação, no funcionamento geral dos métodos, na análise de custo computacional e na comparação com uma solução ingênua.

O relatório deve conter:
* Representação da Trie
    - qual tamanho de alfabeto foi escolhido;
    - como os caracteres foram mapeados para posições do array de filhos;
    - como títulos e prefixos foram convertidos para chaves de busca.
* Funcionamento dos métodos
    - explique, em alto nível, como funcionam os métodos `insert`, `contains` e `autocomplete`;
    - não é necessário descrever o código linha por linha.
* Análise de custo
    - indique o custo computacional das operações `insert`, `contains` e `autocomplete`;
    - explique brevemente de onde vêm esses custos.
* Comparação e uso de memória
    - compare a solução com Trie com uma solução ingênua que percorre todos os jogos;
    - explique o custo de memória de usar uma Trie em vez de apenas armazenar os jogos em um array;
    - comente como o compartilhamento de prefixos pode reduzir o número de nós;
    - comente como o tamanho do alfabeto afeta o espaço ocupado por cada nó.

Para a análise de custo, devem ser considerados os parâmetros:
* `L`: tamanho do título após conversão para chave de busca;
* `p`: tamanho do prefixo após conversão para chave de busca;
* `s`: número de nós visitados na subárvore do prefixo;
* `r`: número de jogos encontrados para o prefixo buscado.

## Questões

### Questão 1

Implementar as classes básicas do projeto:
* `Game`;
* `TrieNode`;
* `Trie`.

As classes devem seguir as estruturas apresentadas anteriormente e inicializar corretamente seus atributos.

### Questão 2

Implementar o método: `std::string toSearchKey(std::string text);`.

O método deve seguir as regras de busca definidas no enunciado.

### Questão 3

Implementar o método `bool insert(Game* game)`.

O método deve inserir o jogo na Trie, seguindo a especificação apresentada anteriormente.

### Questão 4

Implementar o método `bool contains(std::string title)`.

O método deve verificar se existe um jogo com o título informado, seguindo a especificação apresentada anteriormente.

### Questão 5

Implementar o método `void sortResults(std::vector<Game*>& games)`.

O método deve ordenar os jogos segundo os critérios definidos no enunciado.

Não é permitido utilizar `std::sort`.

### Questão 6

Implementar o método `std::vector<Game*> autocomplete(std::string prefix, int k)`.

O método deve retornar até `k` jogos compatíveis com o prefixo informado, seguindo a especificação apresentada anteriormente.

### Questão 7

Criar um `main.cpp` que permita executar o programa pela linha de comando no formato:

```bash
./app k prefixo
```

O programa deve carregar os jogos fornecidos, inserir os jogos na Trie, executar a busca por prefixo e exibir os resultados.

### Questão 8

Criar um arquivo `README.md` contendo:
* descrição do projeto;
* instruções de compilação;
* instruções de execução;
* breve explicação da organização dos arquivos;
* exemplos de uso pela linha de comando.

### Questão 9

Redigir um relatório em PDF, com aproximadamente 2 páginas, seguindo as orientações apresentadas anteriormente.

## Entrega

O trabalho deve ser entregue através de um repositório no GitHub, e o link enviado por e-mail.

O código deve compilar utilizando:

```bash
g++ main.cpp Game.cpp Trie.cpp GamesDatabase.cpp -o app
```

Enviar o link do repositório para:

```text
matheus.werner@fgv.br
```

até **Terça, 09 de Junho, às 23h59**.

## Considerações finais

* Trabalhos que não compilarem receberão nota 0.
* Trabalhos que implementarem uma solução sem Trie receberão nota 0.
* Trabalhos em que o método `autocomplete` percorra o array original de jogos para encontrar os resultados, em vez de seguir o prefixo na Trie e explorar a subárvore correspondente, receberão nota 0.
* O uso de `std::vector` é permitido apenas para armazenar e retornar os resultados do autocomplete.
* Trabalhos que utilizarem estruturas prontas para substituir a Trie, como `map` ou `unordered_map`, receberão nota 0.
* Trabalhos que utilizarem `std::sort` ou outra função pronta de ordenação receberão nota 0.
* Trabalhos muito semelhantes entre si poderão ser chamados para uma breve explicação do código.
* Caso seja necessário, o aluno poderá ser solicitado a explicar a implementação apresentada.
* Política de atraso:
    * até 24h de atraso → desconto de 20% na nota;
    * até 48h de atraso → desconto de 40% na nota;
    * após 48h → o trabalho não será aceito.
