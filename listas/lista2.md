# Lista 2: Fila de Atendimento em um Banco

## Descrição

Em um banco, há apenas um caixa, e os clientes devem ser atendidos por ordem de chegada. No entanto, clientes idosos possuem prioridade no atendimento. Para evitar que a fila fique completamente desbalanceada em dias com muitos idosos, foi estabelecida a seguinte regra:

1. O atendimento ocorre na ordem de chegada, respeitando as regras de prioridade.
2. No máximo **dois idosos** podem ser atendidos antes que uma pessoa da fila geral seja atendida.

### 1) Exemplo de Funcionamento

Suponha que as seguintes pessoas entrem na fila antes do início do atendimento:

```
Entrada:
1 Geral
2 Geral
3 Idoso
4 Idoso
5 Idoso
6 Geral
7 Idoso
```

A ordem de atendimento, seguindo as regras estabelecidas, será:

```
Saída:
3 4 1 5 7 2 6
```

### 2) Exemplo de Funcionamento

Suponha que as seguintes pessoas entrem na fila antes do início do atendimento:

```
Entrada:
1 Idoso
2 Idoso
3 Idoso
4 Geral
5 Geral
6 Idoso
```

A ordem de atendimento, seguindo as regras estabelecidas, será:

```
Saída:
1 2 3 4 6 5
```


## Entregável
O trabalho deve ser enviado conforme as seguintes especificações:
1. **Formato**: O arquivo final deve ser um arquivo zip contendo os 3 arquivos mencionados abaixo (`main.cpp`, `WaitingQueue.h`, e `WaitingQueue.cpp`).
2. **Nome do arquivo zip**: O nome do arquivo zip deve seguir o formato: `lista2_{nome completo com undescore no lugar de espaços}.zip`. Exemplo: `lista2_nome_sobrenome.zip`.
3. **Envio**: Como ainda continuamos sem acesso ao eclass, o arquivo final deve ser enviado para o meu e-mail institucional: `matheus.werner@fgv.br` até **Quarta-feira, 02 de Abril, às 23h59**.

## Implementação

O aluno deve implementar uma estrutura de dados para organizar a fila de atendimento.

### Estruturas de Dados

```cpp
struct Client {
   char name[50];
   int priority;  // 0 = Geral; 1 = Idoso
};

struct QueueNode {
   Client client;
   QueueNode* next;
   QueueNode* previous;
   <Demais variáveis a serem definidas>
};

struct WaitingQueue {
   int generalCount;
   int elderlyCount;
   <Demais variáveis a serem definidas>
};
```

Os arquivos devem ser organizados da seguinte maneira:
- `main.cpp`: Arquivo principal contendo testes para todas as funções implementadas, demonstrando o seu correto funcionamento.
- `WaitingQueue.h`: Declaração das funções e estruturas do TAD.
- `WaitingQueue.cpp`: Implementação das funções do TAD.

### Requisitos
* As funções devem ser implementadas nos arquivos descritos acima.
* As funções devem seguir as assinaturas estabelecidas para cada exercício.
* Será atribuído nota 0 caso o programa não compile.
* Use o namespace `WaitingQueueTAD` para todas as funções.
* Utilize boas práticas de programação, incluindo:
    - Documentação das funções (comentários explicativos sobre sua funcionalidade).
    - Verificações básicas (evitar acessos inválidos à memória, checagem de ponteiros nulos, etc.).

### Funcionalidades Obrigatórias

1. **Inicializar a fila**
   ```cpp
   WaitingQueue* createQueue();
   ```
   
2. **Inserir um cliente na fila**
   ```cpp
   void enqueue(WaitingQueue* queue, Client client);
   ```

3. **Próximo a ser atendido (sem remover da fila)**
   ```cpp
   int peek(const WaitingQueue* queue, Client* returnClient);
   ```
   No caso de lista vazia, retornar `0`. Caso contrário, `1`.

4. **Remover o próximo da fila** (após atendimento)
   ```cpp
   int dequeue(WaitingQueue* queue, Client* returnClient);
   ```
   No caso de lista vazia, retornar `0`. Caso contrário, `1`.

5. **Remover um cliente específico da fila (desistência)**
   ```cpp
   int removeClient(WaitingQueue* queue, char* name);
   ```
   Retornar `1` se cliente foi removido com sucesso. Caso contrário, retornar `0`.

6. **Obter a ordem de atendimento conforme o estado atual da fila**
   ```cpp
   Client* getQueueOrder(const WaitingQueue* queue, int* numClients);
   ```
   No caso de lista vazia, retornar `nullptr` e preencher `numClients` com `0`.\
   O array deve estar ordenado na ordem exata dos atendimentos seguindo as regras de prioridade, considerando o estado atual da fila.

7. **Deletar toda a fila e liberar memória**
   ```cpp
   void deleteQueue(WaitingQueue* queue);
   ```
   Deletar todos os dados alocados dinâmicamente.

### Restrições e Considerações

- Os clientes são inseridos na estrutura de dados conforme chegam ao banco;
- Não há clientes com o mesmo nome;
- Clientes podem ser adicionados, removidos a qualquer momento e atendidos conforme as regras de prioridade;
- As funções **Inserir**, **Remover o próximo** e **Próximo a ser atendido** devem ser implementadas com complexidade **O(1)**;
- A estrutura de dados **deve utilizar uma ou mais listas encadeadas**;
- Pode ser interessante criar funções internas para evitar duplicação de código.
