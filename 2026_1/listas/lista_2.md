# Trabalho 2: Order Book (Sistema de Ordens de Compra e Venda)

## Organização do trabalho

Este trabalho deve ser realizado em duplas.

Caso algum aluno não possua dupla, deverá entrar em contato com o professor o quanto antes para que seja possível organizar os grupos ou, se necessário, autorizar a formação de um trio.

Ambos os alunos da dupla são responsáveis pela implementação, documentação e entrega do projeto.

## Descrição do trabalho

Neste trabalho, os alunos devem implementar um sistema simples para gerenciar ordens de **compra** e **venda** de uma única ação.

Uma ordem representa a intenção de comprar ou vender a ação por um determinado preço. O sistema deve ser capaz de armazenar ordens em aberto e executar automaticamente transações sempre que houver compatibilidade entre ordens.

Cada ordem possui:

* um identificador único;
* um tipo (`'B'` para compra, `'S'` para venda);
* um preço;
* um timestamp, que representa a ordem de chegada.

Ao inserir uma nova ordem, o sistema deve verificar automaticamente se existe alguma ordem compatível já cadastrada.

Caso exista, a transação deve ser executada imediatamente.
Caso contrário, a ordem deve ser armazenada no sistema.

### Regras do sistema

Considere as seguintes regras:

* O sistema gerencia **apenas uma única ação**.
* Cada ordem possui **quantidade igual a 1**.
* Cada ordem pode ser executada **no máximo uma vez**.
* Os **identificadores de ordens são únicos** dentro do sistema.
* Não é necessário tratar tentativas de inserção de IDs duplicados.
* O timestamp será fornecido e representa a ordem de chegada.

#### Compatibilidade de ordens

* Uma ordem de **compra** pode ser executada com uma ordem de venda tal que:
    ```
    sell.price <= buy.price
    ```

* Uma ordem de **venda** pode ser executada com uma ordem de compra tal que:
    ```
    buy.price >= sell.price
    ```

#### Escolha da contraparte

Caso existam múltiplas ordens compatíveis:

* Para uma ordem de compra, deve-se escolher a ordem de venda com **menor preço**;
* Para uma ordem de venda, deve-se escolher a ordem de compra com **maior preço**;
* Em caso de empate, deve-se escolher a ordem com **menor timestamp**.

#### Execução de transações

Quando uma transação ocorre:

* uma ordem de compra e uma ordem de venda são removidas do sistema;
* ambas deixam de estar em aberto;
* uma nova transação deve ser registrada.

O preço da transação deve ser:

> o preço da ordem que já estava cadastrada no sistema.

### Transações

Cada transação deve registrar, no mínimo:

* id da ordem de compra;
* id da ordem de venda;
* preço de execução.

### Funcionalidades do sistema

O sistema deve permitir:

* inserir uma nova ordem;
* cancelar uma ordem existente;
* exibir ordens de compra em aberto;
* exibir ordens de venda em aberto;
* exibir transações executadas.

Os alunos devem **projetar e implementar a estrutura de dados responsável por armazenar e gerenciar as ordens**, decidindo como representar em memória:

* ordens de compra;
* ordens de venda;
* transações executadas.

A solução deve ser implementada em **C++**, utilizando **classes e modularização** (`.hpp` e `.cpp`).

## Exemplos de funcionamento

Nos exemplos abaixo, o estado do sistema será representado da seguinte forma:

```
Buy Orders:
[id | preço | timestamp]

Sell Orders:
[id | preço | timestamp]

Transactions:
[buy_id, sell_id, preço]
```

### Exemplo 1: ordem sem execução

Inserindo:

```
submit(Order(1, 'B', 10.0, 1))
```

Resultado:

```
Buy Orders:
[1 | 10.0 | 1]

Sell Orders:
(empty)

Transactions:
(empty)
```

Retorno: `false`

### Exemplo 2: execução imediata

Estado inicial:

```
Buy Orders:
(empty)

Sell Orders:
[2 | 9.0 | 1]

Transactions:
(empty)
```

Inserindo:

```
submit(Order(3, 'B', 10.0, 2))
```

Resultado:

```
Buy Orders:
(empty)

Sell Orders:
(empty)

Transactions:
[3, 2, 9.0]
```

Retorno: `true`

### Exemplo 3: escolha da melhor contraparte

Estado inicial:

```
Sell Orders:
[10 | 9.5 | 1]
[11 | 8.0 | 2]
[12 | 8.0 | 3]
```

Inserindo:

```
submit(Order(13, 'B', 10.0, 4))
```

Resultado:

```
Sell Orders:
[10 | 9.5 | 1]
[12 | 8.0 | 3]

Transactions:
[13, 11, 8.0]
```

✔ Escolheu:

* menor preço → `8.0`
* empate → menor timestamp → id `11`

### Exemplo 4: ordem não compatível

Estado inicial:

```
Sell Orders:
[20 | 12.0 | 1]
```

Inserindo:

```
submit(Order(21, 'B', 10.0, 2))
```

Resultado:

```
Buy Orders:
[21 | 10.0 | 2]

Sell Orders:
[20 | 12.0 | 1]

Transactions:
(empty)
```

Retorno: `false`

### Exemplo 5: cancelamento

Estado inicial:

```
Buy Orders:
[30 | 11.0 | 1]
```

Executando:

```
cancel(30)
```

Resultado:

```
Buy Orders:
(empty)
```

Retorno: `true`

### Exemplo 6: métodos `get...`

Se o sistema estiver no estado:

```
Buy Orders:
[1 | 10.0 | 1]
[2 | 9.0 | 2]

Transactions:
[3, 4, 8.0]
```

Então:

```
getBuyOrders(&n)
→ n = 2

getTransactions(&n)
→ n = 1
```

Se não houver elementos:

```
getSellOrders(&n)
→ retorna nullptr
→ n = 0
```

## Estruturas

### Estrutura `Order`

A classe `Order` representa uma ordem de compra ou venda.

```cpp
class Order {

private:
    int id;
    char type; // 'B' ou 'S'
    float price;
    int timestamp;

public:

    Order(int id, char type, float price, int timestamp);
    ~Order();

    int getId();
    char getType();
    float getPrice();
    int getTimestamp();
};
```

### Estrutura `Transaction`

A classe `Transaction` representa uma transação executada.

```cpp
class Transaction {

private:
    int buy_order_id;
    int sell_order_id;
    float execution_price;

public:

    Transaction(int buy_order_id, int sell_order_id, float execution_price);
    ~Transaction();

    int getBuyOrderId();
    int getSellOrderId();
    float getExecutionPrice();
};
```

### Estrutura `OrderBook`

```cpp
class OrderBook {

private:

    // Estruturas internas escolhidas pelos alunos
    // para armazenar ordens de compra, venda e transações

public:

    OrderBook();
    ~OrderBook();

    bool submit(Order order);
    bool cancel(int id);

    Order* getBuyOrders(int* n);
    Order* getSellOrders(int* n);
    Transaction* getTransactions(int* n);

    void printBuyOrders();
    void printSellOrders();
    void printTransactions();

    // Outros métodos auxiliares, se necessário
};
```

A classe `OrderBook` é responsável por gerenciar todas as ordens e transações do sistema.

#### Métodos de consulta

Os métodos:

```cpp
Order* getBuyOrders(int* n);
Order* getSellOrders(int* n);
Transaction* getTransactions(int* n);
```

devem retornar um **novo array alocado dinâmicamente** contendo os elementos atualmente armazenados no sistema.

Além disso:

* o parâmetro `n` deve ser utilizado para informar a quantidade de elementos retornados;
* caso não existam elementos, o método deve retornar `nullptr` e definir `*n = 0`;
* a memória alocada para o array retornado deve ser liberada por quem chamou a função, utilizando `delete[]`.

## Organização dos arquivos

O projeto deve possuir a seguinte organização mínima:

```
main.cpp
OrderBook.hpp
OrderBook.cpp
Order.hpp
Order.cpp
Transaction.hpp
Transaction.cpp
```

Descrição dos arquivos:

* **main.cpp**: Arquivo principal contendo testes para todas as funções implementadas.
* **OrderBook.hpp**: Declaração da classe `OrderBook`.
* **OrderBook.cpp**: Implementação da classe `OrderBook`.
* **Order.hpp**: Declaração da classe `Order`.
* **Order.cpp**: Implementação da classe `Order`.
* **Transaction.hpp**: Declaração da classe `Transaction`.
* **Transaction.cpp**: Implementação da classe `Transaction`.

### Observações

* A estrutura acima representa o **mínimo esperado** para o projeto.
* É permitido criar arquivos adicionais (`.hpp` e `.cpp`) para melhor organização do código.
* Todos os arquivos devem estar no **mesmo diretório** para garantir a compilação correta com o comando fornecido.

## Requisitos

* As funções devem seguir **exatamente as assinaturas fornecidas**.
* O programa deve **compilar corretamente**. Programas que não compilarem não poderão ser avaliados e receberão **nota 0**.
* **Não é permitido utilizar estruturas de dados da STL** (`vector`, `list`, `map`, etc.).
* A implementação deve utilizar estruturas de dados dinâmicas baseadas em ponteiros, desenvolvidas pelos próprios alunos.
* O código deve utilizar boas práticas de programação, incluindo:
    * comentários explicativos;
    * cuidado com gerenciamento de memória.

## Questões

### Questão 1

Implementar o **construtor** e o **destrutor** das classes `Order`, `Transaction` e `OrderBook`.

### Questão 2

Implementar o método:

```cpp
bool submit(Order order);
```

Esse método deve:

1. verificar se existe alguma ordem compatível no sistema;
2. selecionar a melhor contraparte conforme as regras;
3. executar a transação, se possível;
4. registrar a transação;
5. caso não exista contraparte, inserir a ordem no sistema.

O método deve retornar:

* `true` se a ordem foi executada;
* `false` se a ordem foi apenas armazenada.

### Questão 3

Implementar o método:

```cpp
bool cancel(int id);
```

Esse método deve localizar a ordem com o identificador informado e removê-la do sistema.

O método deve retornar:

* `true` caso a ordem tenha sido cancelada;
* `false` caso a ordem não seja encontrada.

### Questão 4

Implementar os métodos:

```cpp
Order* getBuyOrders(int* n);
Order* getSellOrders(int* n);
Transaction* getTransactions(int* n);
```

Esses métodos devem retornar cópias das ordens e transações atualmente armazenadas no sistema.

### Questão 5

Implementar os métodos:

```cpp
void printBuyOrders();
void printSellOrders();
void printTransactions();
```

Esses métodos devem exibir o estado atual do sistema de forma legível, 
seguindo o mesmo formato de visualização apresentado na seção de exemplos.

A saída deve ser consistente com o padrão utilizado nos exemplos, incluindo:
* identificação das seções (Buy Orders, Sell Orders, Transactions);
* representação de cada elemento no formato indicado;
* indicação de listas vazias como (empty), quando aplicável.

### Questão 6

Criar um `main.cpp` contendo casos de teste que demonstrem:

* inserção de ordens;
* execuções bem-sucedidas;
* ordens não executadas;
* cancelamentos;
* recuperação dos dados por meio dos métodos `get...`;
* exibição do estado do sistema.

### Questão 7

Criar um arquivo README.md contendo:
* descrição do projeto;
* instruções de compilação;
* instruções de execução;
* uma breve explicação de como os dados estão organizados internamente no sistema.

### Questão 8

Redigir um relatório em PDF (aproximadamente 1 página) explicando:

* quais estruturas de dados foram utilizadas internamente e por quê;
* como foi feita a busca por contraparte;
* como foi feita a remoção de ordens;
* custo computacional das operações:

  * inserção
  * cancelamento
  * execução de ordens
  * recuperação das ordens/transações

### Entrega

O trabalho deve ser entregue através de um **repositório no GitHub**, e o link enviado por e-mail.

O código deve compilar utilizando:

```
g++ main.cpp OrderBook.cpp Order.cpp Transaction.cpp -o order_book
```

Enviar o link do repositório para:

```
matheus.werner@fgv.br
```

até **Domingo, 12 de Abril, às 23h59**.

### Considerações finais
* Trabalhos que **não compilarem** receberão nota **0**.
* Trabalhos que utilizarem **estruturas de dados da STL** (`vector`, `list`, `map`, etc.) na implementação do sistema receberão nota **0**.
* Trabalhos muito semelhantes entre si poderão ser chamados para uma breve **explicação do código**.
* Caso seja necessário, o aluno poderá ser solicitado a **explicar a implementação apresentada**.
* Política de atraso:
  * até **24h de atraso** → desconto de **20%** na nota;
  * até **48h de atraso** → desconto de **40%** na nota;
  * após **48h** → o trabalho não será aceito.
