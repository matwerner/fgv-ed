# Lista 2: Fila de Atendimento em um Banco

## Descrição

Em um banco, há apenas um caixa, e os clientes devem ser atendidos por ordem de chegada. No entanto, clientes idosos possuem prioridade no atendimento. Para evitar que a fila fique completamente desbalanceada em dias com muitos idosos, foi estabelecida a seguinte regra:

1. **Prioridade para Idosos**:
   * Sempre que possível, dois idosos devem ser atendidos antes de cada atendimento a um cliente não idoso.
   * A ordem de chegada entre os idosos é respeitada;
   * A ordem de chegada entre não idosos é respeitada;

2. **Intercalamento Obrigatório**:
   * Após o atendimento de dois idosos, um cliente da fila geral (não idoso) deve ser atendido, mesmo que outros idosos estejam aguardando.
   * Ou seja, A sequência de atendimento deve seguir o padrão: Idoso → Idoso → Geral → Idoso → Idoso → Geral, e assim por diante.
   * Se não houver idosos ou não idosos suficientes para manter a proporção (por exemplo, apenas um idoso disponível), o atendimento segue com quem estiver disponível na fila.

### Exemplo de Funcionamento

Suponha que as seguintes pessoas entrem na fila antes do início do atendimento:

```
Entrada:
1 idoso
2 idoso
3 idoso
4 Geral
5 Geral
6 Geral
7 Idoso
8 Idoso
```

A ordem de atendimento, seguindo as regras estabelecidas, será:

```
Saída:
1 2 4 3 7 5 8 6 
```

#### Explicação (analisar inserção por inserção):

* Pessoa 1 (idoso) chega → entra na fila normalmente.
* Pessoa 2 (idoso) chega → entra depois da 1.
* Pessoa 3 (idoso) chega → entra depois da 2.

```
Ordem atual: [1, 2, 3]
```

* Pessoa 4 (geral) chega
   - Como no máximo 2 idosos são atendidos antes de uma pessoa não idosa → 4 entre na frente de 3

```
Ordem atual: [1, 2, 4, 3]
```

* Pessoa 5 (geral) chega → entra depois da 3.
* Pessoa 6 (geral) chega → entra depois da 5.

```
Ordem atual: [1, 2, 4, 3, 5, 6]
```

* Pessoa 7 (idoso) chega
   - Pessoa 4 já tem 2 idosos antes dela → não pode entrar antes da 4;
   - 5 tem 1 idoso (a 3) antes dela → 7 entra antes de 5.

```
Ordem atual: [1, 2, 4, 3, 7, 5, 6]
```
     
* Pessoa 8 (idoso) chega
   - Pessoa 4 já tem 2 idosos antes dela → não pode entrar antes da 4.
   - Pessoa 5 já tem 2 idosos antes dela → também não.
   - Ainda não há nenhum idoso entre pessoas 5 e 6, então pessoa 8 entra antes da 6.

```
Ordem atual: [1, 2, 4, 3, 7, 5, 8, 6]
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
