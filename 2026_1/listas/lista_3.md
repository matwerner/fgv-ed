# Trabalho 3: Sistema de Matchmaking para Jogos Online

## Organização do trabalho

Este trabalho deve ser realizado em duplas.

Caso algum aluno não possua dupla, deverá entrar em contato com o professor o quanto antes para que seja possível organizar os grupos ou, se necessário, autorizar a formação de um trio.

Ambos os alunos da dupla são responsáveis pela implementação, documentação e entrega do projeto.

## Descrição do trabalho

Neste trabalho, os alunos devem implementar um sistema simples de **matchmaking** para jogadores que estão buscando uma partida online.

Um sistema de matchmaking é responsável por armazenar jogadores em uma fila de espera e formar grupos de jogadores com níveis de habilidade semelhantes. Esse tipo de sistema é comum em jogos online competitivos, como MOBAs, jogos de tiro, jogos de estratégia e jogos de xadrez online.

Cada jogador possui:

* um identificador único;
* um nome;
* um score, representando seu nível de habilidade;
* um timestamp, representando sua ordem de chegada na fila.

O sistema deve armazenar jogadores que estão aguardando partida, ordenar esses jogadores por score e formar grupos com jogadores de níveis próximos.

A ideia central do trabalho é utilizar **ordenação** para facilitar a formação de grupos. Ao ordenar os jogadores pelo score, o sistema pode explorar essa organização para buscar grupos válidos de maneira mais simples.

A solução deve ser implementada em **C++**, utilizando **classes e modularização** (`.hpp` e `.cpp`).

## Regras do sistema

Considere as seguintes regras:

* O sistema armazena jogadores que estão aguardando partida.
* Cada jogador possui um identificador único.
* Não é necessário tratar tentativas de inserção de IDs duplicados.
* O timestamp será fornecido e representa a ordem de chegada do jogador na fila.
* A inserção de jogadores deve ser feita sempre no final da estrutura interna.
* A classe `Matchmaking` deve armazenar os jogadores em um array estático com capacidade máxima.
* O sistema deve implementar manualmente dois algoritmos de ordenação:
    * insertion sort;
    * merge sort.
* Não é permitido utilizar `std::sort` ou qualquer outra função pronta de ordenação.
* Não é permitido utilizar estruturas de dados da STL, como `vector`, `list`, `map`, `queue`, `stack`, entre outras.
* É permitido utilizar `std::string`.

## Critério de formação de grupo

Um grupo válido é formado por `groupSize` jogadores tal que:

```text
maior_score - menor_score <= delta
````

Ou seja, a diferença entre o maior score e o menor score dentro do grupo deve ser menor ou igual a um valor máximo permitido.

Por exemplo, considere os scores:

```text
1000, 1010, 1020
```

Se:

```text
groupSize = 3
delta = 30
```

Então esse grupo é válido, pois:

```text
1020 - 1000 = 20 <= 30
```

Por outro lado, considere os scores:

```text
1000, 1100, 1120
```

Esse grupo não é válido para `delta = 30`, pois:

```text
1120 - 1000 = 120 > 30
```

## Uso da ordenação

Antes de formar grupos, os jogadores devem ser ordenados por score.

A implementação deve tirar proveito da ordenação dos jogadores para facilitar a busca por grupos válidos.

No relatório, os alunos devem explicar como a ordenação foi utilizada na formação dos grupos e qual é o custo computacional dessa operação.

## Regra determinística para formação de grupos

Para tornar o comportamento do sistema determinístico, o método de formação de grupos deve considerar os jogadores na ordem atual do array após a ordenação por score.

O grupo retornado deve ser o primeiro grupo válido encontrado nessa ordem.

Considere como candidatos apenas grupos formados por `groupSize` jogadores em posições consecutivas após a ordenação.

Caso um grupo válido seja encontrado:

* os jogadores do grupo devem ser removidos da fila de espera;
* o grupo formado deve ser retornado;
* os demais jogadores permanecem aguardando partida.

Caso nenhum grupo válido seja encontrado:

* nenhum jogador deve ser removido;
* o método deve indicar que não foi possível formar grupo.

## Ordenação dos jogadores

Os jogadores devem ser ordenados por score em ordem crescente.

Em caso de empate no score, deve vir primeiro o jogador com menor timestamp.

Ou seja, a ordenação deve seguir os critérios abaixo:

1. menor score;
2. em caso de empate, menor timestamp.

Por exemplo, considere os jogadores:

```text
[1 | Ana   | 1000 | 3]
[2 | Bruno | 900  | 2]
[3 | Carla | 1000 | 1]
```

Após a ordenação, o resultado deve ser:

```text
[2 | Bruno | 900  | 2]
[3 | Carla | 1000 | 1]
[1 | Ana   | 1000 | 3]
```

Observe que Carla aparece antes de Ana porque ambas possuem score `1000`, mas Carla possui timestamp menor.

## Funcionalidades do sistema

O sistema deve permitir:

* inserir um novo jogador na fila de espera;
* remover um jogador da fila pelo ID;
* ordenar os jogadores por score usando insertion sort;
* ordenar os jogadores por score usando merge sort;
* formar um grupo de jogadores com scores próximos;
* recuperar os jogadores atualmente na fila;
* exibir os jogadores atualmente na fila.

Os alunos devem projetar e implementar a classe responsável por armazenar e gerenciar os jogadores em espera.

## Exemplos de funcionamento

Nos exemplos abaixo, o estado do sistema será representado da seguinte forma:

```text
Waiting Players:
[id | nome | score | timestamp]
```

Um grupo formado será representado da seguinte forma:

```text
Group:
[id | nome | score | timestamp]
```

### Exemplo 1: inserção de jogador

Inserindo:

```cpp
insert(Player(1, "Ana", 1000, 1));
```

Resultado:

```text
Waiting Players:
[1 | Ana | 1000 | 1]
```

Retorno:

```text
true
```

### Exemplo 2: múltiplas inserções

Inserindo:

```cpp
insert(Player(1, "Ana", 1000, 1));
insert(Player(2, "Bruno", 1100, 2));
insert(Player(3, "Carla", 1020, 3));
```

Resultado:

```text
Waiting Players:
[1 | Ana | 1000 | 1]
[2 | Bruno | 1100 | 2]
[3 | Carla | 1020 | 3]
```

Observe que os jogadores são inseridos no final do array. Portanto, após as inserções, o array não necessariamente está ordenado por score.

### Exemplo 3: ordenação por score

Estado inicial:

```text
Waiting Players:
[1 | Ana   | 1000 | 1]
[2 | Bruno | 1100 | 2]
[3 | Carla | 1020 | 3]
[4 | Diego | 1010 | 4]
```

Executando:

```cpp
sortByScoreInsertion();
```

ou:

```cpp
sortByScoreMerge();
```

Resultado esperado:

```text
Waiting Players:
[1 | Ana   | 1000 | 1]
[4 | Diego | 1010 | 4]
[3 | Carla | 1020 | 3]
[2 | Bruno | 1100 | 2]
```

### Exemplo 4: ordenação com empate no score

Estado inicial:

```text
Waiting Players:
[1 | Ana   | 1000 | 5]
[2 | Bruno | 900  | 2]
[3 | Carla | 1000 | 1]
[4 | Diego | 900  | 4]
```

Após a ordenação por score:

```text
Waiting Players:
[2 | Bruno | 900  | 2]
[4 | Diego | 900  | 4]
[3 | Carla | 1000 | 1]
[1 | Ana   | 1000 | 5]
```

O score é o primeiro critério de ordenação. Em caso de empate, o timestamp é usado como critério de desempate.

### Exemplo 5: formação de grupo bem-sucedida

Estado inicial, já ordenado por score:

```text
Waiting Players:
[1 | Ana   | 1000 | 1]
[4 | Diego | 1010 | 4]
[3 | Carla | 1020 | 3]
[2 | Bruno | 1100 | 2]
```

Executando:

```cpp
int n;
Player* group = matchmaking.formGroup(3, 30, &n);
```

Resultado retornado:

```text
Group:
[1 | Ana   | 1000 | 1]
[4 | Diego | 1010 | 4]
[3 | Carla | 1020 | 3]
```

Como:

```text
1020 - 1000 = 20 <= 30
```

o grupo é válido.

Nesse caso:

```text
n = 3
```

Novo estado do sistema:

```text
Waiting Players:
[2 | Bruno | 1100 | 2]
```

A memória alocada para o grupo retornado deve ser liberada por quem chamou a função, utilizando `delete[]`.

### Exemplo 6: nenhuma formação de grupo possível

Estado inicial, já ordenado por score:

```text
Waiting Players:
[1 | Ana   | 1000 | 1]
[2 | Bruno | 1100 | 2]
[3 | Carla | 1250 | 3]
```

Executando:

```cpp
int n;
Player* group = matchmaking.formGroup(3, 50, &n);
```

Resultado:

```text
group == nullptr
n = 0
```

Estado do sistema permanece igual:

```text
Waiting Players:
[1 | Ana   | 1000 | 1]
[2 | Bruno | 1100 | 2]
[3 | Carla | 1250 | 3]
```

Nenhum grupo de 3 jogadores possui diferença entre maior e menor score menor ou igual a 50.

### Exemplo 7: formação do primeiro grupo válido

Estado inicial, já ordenado por score:

```text
Waiting Players:
[1 | Ana    | 1000 | 1]
[2 | Bruno  | 1010 | 2]
[3 | Carla  | 1020 | 3]
[4 | Diego  | 1030 | 4]
[5 | Eduarda| 1040 | 5]
```

Executando:

```cpp
int n;
Player* group = matchmaking.formGroup(3, 30, &n);
```

Existem vários grupos possíveis, mas o método deve retornar o primeiro grupo válido na ordem atual:

```text
Group:
[1 | Ana   | 1000 | 1]
[2 | Bruno | 1010 | 2]
[3 | Carla | 1020 | 3]
```

Novo estado do sistema:

```text
Waiting Players:
[4 | Diego   | 1030 | 4]
[5 | Eduarda | 1040 | 5]
```

### Exemplo 8: remoção de jogador

Estado inicial:

```text
Waiting Players:
[1 | Ana   | 1000 | 1]
[2 | Bruno | 1100 | 2]
[3 | Carla | 1250 | 3]
```

Executando:

```cpp
removePlayer(2);
```

Resultado:

```text
Waiting Players:
[1 | Ana   | 1000 | 1]
[3 | Carla | 1250 | 3]
```

Retorno:

```text
true
```

### Exemplo 9: métodos `get...`

Se o sistema estiver no estado:

```text
Waiting Players:
[1 | Ana   | 1000 | 1]
[2 | Bruno | 1100 | 2]
```

Então:

```cpp
int n;
Player* players = matchmaking.getWaitingPlayers(&n);
```

Resultado:

```text
n = 2
```

O array retornado deve conter cópias dos jogadores atualmente armazenados no sistema.

Se não houver jogadores na fila:

```cpp
getWaitingPlayers(&n);
```

deve retornar:

```text
nullptr
n = 0
```

A memória alocada para o array retornado deve ser liberada por quem chamou a função, utilizando `delete[]`.

## Estruturas

### Constante `MAX_PLAYERS`

O sistema deve utilizar uma constante para definir a capacidade máxima de jogadores:

```cpp
const int MAX_PLAYERS = 100000;
```

Essa constante deve ser utilizada pela classe `Matchmaking` para definir o tamanho máximo do array interno de jogadores.

### Estrutura `Player`

A classe `Player` representa um jogador aguardando partida.

```cpp
class Player {

private:
    int id;
    std::string name;
    int score;
    int timestamp;

public:

    Player();
    Player(int id, std::string name, int score, int timestamp);
    ~Player();

    int getId();
    std::string getName();
    int getScore();
    int getTimestamp();
};
```

### Estrutura `Matchmaking`

A classe `Matchmaking` é responsável por armazenar os jogadores aguardando partida, ordenar os jogadores por score e formar grupos válidos.

```cpp
class Matchmaking {

private:

    Player players[MAX_PLAYERS];
    int size;

public:

    Matchmaking();
    ~Matchmaking();

    bool insert(Player player);
    bool removePlayer(int id);

    void sortByScoreInsertion();
    void sortByScoreMerge();

    Player* formGroup(int groupSize, int delta, int* n);

    Player* getWaitingPlayers(int* n);

    void printWaitingPlayers();

    // Outros métodos auxiliares, se necessário
};
```

A classe `Matchmaking` deve armazenar os jogadores em um array estático de tamanho `MAX_PLAYERS`.

O atributo `size` deve representar a quantidade atual de jogadores armazenados.

## Especificação dos métodos

### Método `insert`

O método:

```cpp
bool insert(Player player);
```

deve inserir o jogador no final do array.

Caso exista espaço disponível, o jogador deve ser inserido e o método deve retornar `true`.

Caso não exista espaço disponível, o método deve retornar `false`.

### Método `removePlayer`

O método:

```cpp
bool removePlayer(int id);
```

deve remover da fila o jogador com o identificador informado.

O método deve retornar:

* `true`, caso o jogador seja encontrado e removido;
* `false`, caso nenhum jogador com o ID informado seja encontrado.

### Métodos de ordenação

Os métodos:

```cpp
void sortByScoreInsertion();
void sortByScoreMerge();
```

devem ordenar os jogadores por score em ordem crescente.

Em caso de empate no score, deve vir primeiro o jogador com menor timestamp.

Os alunos devem implementar manualmente os dois algoritmos:

* insertion sort;
* merge sort.

O `insertion sort` representa uma estratégia simples de ordenação, com custo quadrático no pior caso.

O `merge sort` representa uma estratégia baseada em recursão e divisão e conquista, com custo `O(n log n)` no pior caso.

É permitido utilizar arrays auxiliares na implementação do merge sort.

Não é permitido utilizar `std::sort` ou qualquer outra função pronta de ordenação.

### Método `formGroup`

O método:

```cpp
Player* formGroup(int groupSize, int delta, int* n);
```

deve tentar formar um grupo com `groupSize` jogadores.

O método assume que os jogadores já estão ordenados por score.

Caso um grupo válido seja encontrado:

* o método deve retornar um novo array alocado dinamicamente contendo os jogadores do grupo;
* o parâmetro `n` deve receber o valor de `groupSize`;
* os jogadores escolhidos devem ser removidos da fila de espera.

Caso nenhum grupo válido seja encontrado:

* o método deve retornar `nullptr`;
* o parâmetro `n` deve receber o valor `0`;
* nenhum jogador deve ser removido da fila.

A memória alocada para o array retornado deve ser liberada por quem chamou a função, utilizando `delete[]`.

### Método `getWaitingPlayers`

O método:

```cpp
Player* getWaitingPlayers(int* n);
```

deve retornar um novo array alocado dinamicamente contendo cópias dos jogadores atualmente armazenados no sistema.

Além disso:

* o parâmetro `n` deve ser utilizado para informar a quantidade de jogadores retornados;
* caso não existam jogadores, o método deve retornar `nullptr` e definir `*n = 0`;
* a memória alocada para o array retornado deve ser liberada por quem chamou a função, utilizando `delete[]`.

### Método `printWaitingPlayers`

O método:

```cpp
void printWaitingPlayers();
```

deve exibir o estado atual da fila de espera de forma legível, seguindo o formato apresentado nos exemplos.

A saída deve ser consistente com o padrão utilizado nos exemplos, incluindo:

* identificação da seção `Waiting Players`;
* representação de cada jogador no formato indicado;
* indicação de fila vazia como `(empty)`, quando aplicável.

## Testes de desempenho

Além dos testes funcionais, os alunos devem realizar uma breve comparação entre os algoritmos de ordenação implementados.

Para isso, devem medir o tempo de execução dos métodos de ordenação para diferentes quantidades de jogadores.

É permitido utilizar a biblioteca `<chrono>` para medir o tempo de execução.

Os resultados devem ser apresentados no relatório, acompanhados de uma breve análise comparando o comportamento dos algoritmos implementados.

A análise deve discutir, no mínimo:

* quais tamanhos de entrada foram utilizados;
* como os dados de teste foram gerados;
* quais tempos foram observados;
* se os resultados estão de acordo com o custo computacional esperado dos algoritmos.

Os testes devem utilizar entradas equivalentes para os dois algoritmos, de modo que a comparação seja justa.

## Organização dos arquivos

O projeto deve possuir a seguinte organização mínima:

```text
main.cpp
Matchmaking.hpp
Matchmaking.cpp
Player.hpp
Player.cpp
```

Descrição dos arquivos:

* **main.cpp**: arquivo principal contendo testes para todas as funções implementadas.
* **Matchmaking.hpp**: declaração da classe `Matchmaking`.
* **Matchmaking.cpp**: implementação da classe `Matchmaking`.
* **Player.hpp**: declaração da classe `Player`.
* **Player.cpp**: implementação da classe `Player`.

### Observações

* A estrutura acima representa o mínimo esperado para o projeto.
* É permitido criar arquivos adicionais (`.hpp` e `.cpp`) para melhor organização do código.
* Todos os arquivos devem estar no mesmo diretório para garantir a compilação correta com o comando fornecido.

## Requisitos

* As funções devem seguir exatamente as assinaturas fornecidas.
* O programa deve compilar corretamente.
* Programas que não compilarem não poderão ser avaliados e receberão nota 0.
* Não é permitido utilizar estruturas de dados da STL (`vector`, `list`, `map`, `queue`, `stack`, etc.).
* Não é permitido utilizar `std::sort` ou qualquer outra função pronta de ordenação.
* É permitido utilizar `std::string`.
* É permitido utilizar `<chrono>` para medição de tempo.
* A classe `Matchmaking` deve utilizar um array estático de tamanho `MAX_PLAYERS`.
* Os algoritmos de ordenação devem ser implementados pelos próprios alunos.
* O código deve utilizar boas práticas de programação, incluindo:

  * modularização;
  * nomes claros;
  * comentários explicativos quando necessário;
  * cuidado com gerenciamento de memória nos métodos que retornam arrays alocados dinamicamente.

## Questões

### Questão 1

Implementar o construtor e o destrutor das classes `Player` e `Matchmaking`.

A classe `Matchmaking` deve inicializar corretamente a quantidade de jogadores armazenados.

### Questão 2

Implementar o método `insert`, seguindo a especificação apresentada anteriormente.

### Questão 3

Implementar o método `removePlayer`, seguindo a especificação apresentada anteriormente.

### Questão 4

Implementar os métodos de ordenação:

```cpp
void sortByScoreInsertion();
void sortByScoreMerge();
```

Ambos devem ordenar os jogadores por score em ordem crescente e, em caso de empate, por timestamp em ordem crescente.

O `sortByScoreMerge` deve utilizar recursão.

### Questão 5

Implementar o método `formGroup`, seguindo a especificação apresentada anteriormente.

O método deve formar apenas um grupo por chamada.

### Questão 6

Implementar o método `getWaitingPlayers`, seguindo a especificação apresentada anteriormente.

### Questão 7

Implementar o método `printWaitingPlayers`, seguindo a especificação apresentada anteriormente.

### Questão 8

Criar um `main.cpp` contendo casos de teste que demonstrem:

* inserção de jogadores;
* remoção de jogadores;
* ordenação utilizando insertion sort;
* ordenação utilizando merge sort;
* ordenação com empate de score;
* formação bem-sucedida de grupo;
* tentativa de formação de grupo sem sucesso;
* recuperação dos dados por meio do método `getWaitingPlayers`;
* exibição do estado do sistema.

### Questão 9

Criar um arquivo `README.md` contendo:

* descrição do projeto;
* instruções de compilação;
* instruções de execução;
* breve explicação da organização dos arquivos;
* breve explicação de como executar os testes criados no `main.cpp`.

### Questão 10

Redigir um relatório em PDF, com aproximadamente 2 páginas, analisando a implementação realizada.

O relatório deve explicar:
* como os algoritmos de ordenação foram implementados;
* como a recursão foi utilizada no merge sort;
* como a ordenação foi aproveitada para formar grupos;
* o custo computacional das principais operações do sistema.

A análise de custo deve considerar:
* inserção;
* remoção;
* ordenação com insertion sort;
* ordenação com merge sort;
* formação de grupo;
* recuperação dos jogadores.

Além disso, o relatório deve apresentar uma breve comparação experimental entre insertion sort e merge sort, incluindo:

* uma tabela com os tempos medidos;
* uma descrição breve de como os testes foram realizados;
* uma comparação entre os tempos observados;
* uma discussão relacionando os resultados obtidos com a complexidade esperada dos algoritmos.

Não é necessário descrever linha por linha o código implementado. O foco do relatório deve estar nas decisões de implementação, nos algoritmos utilizados e na análise de custo computacional.

## Entrega

O trabalho deve ser entregue através de um repositório no GitHub, e o link enviado por e-mail.

O código deve compilar utilizando:

```bash
g++ main.cpp Matchmaking.cpp Player.cpp -o matchmaking
```

Enviar o link do repositório para:

```text
matheus.werner@fgv.br
```

até **Domingo, 17 de Maio, às 23h59**.

## Considerações finais

* Trabalhos que não compilarem receberão nota 0.
* Trabalhos que utilizarem estruturas de dados da STL (`vector`, `list`, `map`, `queue`, `stack`, etc.) na implementação do sistema receberão nota 0.
* Trabalhos que utilizarem `std::sort` ou qualquer outra função pronta de ordenação receberão nota 0.
* Trabalhos muito semelhantes entre si poderão ser chamados para uma breve explicação do código.
* Caso seja necessário, o aluno poderá ser solicitado a explicar a implementação apresentada.
* Política de atraso:

  * até 24h de atraso → desconto de 20% na nota;
  * até 48h de atraso → desconto de 40% na nota;
  * após 48h → o trabalho não será aceito.
