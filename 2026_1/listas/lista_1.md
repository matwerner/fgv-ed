# Trabalho 1: Room Reservation System

## Organização do trabalho

Este trabalho deve ser realizado em duplas.

Caso algum aluno não possua dupla, deverá entrar em contato com o professor o quanto antes para que seja possível organizar os grupos ou, se necessário, autorizar a formação de um trio.

Ambos os alunos da dupla são responsáveis pela implementação, documentação e entrega do projeto.

## Descrição do trabalho

Neste trabalho, os alunos devem implementar um sistema simples para gerenciar a alocação de disciplinas em salas de aula durante uma semana.

Um usuário pode solicitar a reserva de uma sala para ministrar uma disciplina em um determinado **dia da semana** e **intervalo de horário**. O sistema deve verificar automaticamente se existe alguma sala disponível naquele período.

Caso exista, a reserva deve ser criada e **a primeira sala disponível que comporte a disciplina** deve ser atribuída automaticamente.
Caso contrário, o sistema deve informar que **não há salas disponíveis naquele horário**.

Cada reserva corresponde a **uma única disciplina em um único dia da semana**, ocupando um intervalo contínuo de tempo.

### Restrições do sistema

Considere as seguintes regras:
* A semana possui **5 dias**: `segunda`, `terca`, `quarta`, `quinta`, `sexta`.
* Considere que os dias da semana fornecidos **sempre estarão corretos**. Não é necessário validar ou normalizar entradas como `"Segunda"` ou `"segunda-feira"`.
* O horário das aulas vai de **7h até 21h**.
* Os horários devem ser representados por **inteiros**, correspondendo à hora de início e hora de término.

Exemplo:

```
7 9
```
representa uma aula das **7h às 9h**.

* O horário final deve ser **estritamente maior** que o horário inicial.
* Considere que o horário final não está incluído no intervalo. Assim, reservas `7-9` e `9–11` **não entram em conflito**.
* Cada reserva ocorre em **um único dia da semana**.
* Uma sala **não pode possuir duas reservas com sobreposição de horário no mesmo dia**.
* O **nome da disciplina é único** dentro do sistema. Não é necessário tratar tentativas de cadastro duplicado.

#### Salas e capacidade

Cada sala possui uma **capacidade máxima de alunos**.

A solicitação de reserva deve informar também o **número de alunos da disciplina**.

Uma reserva só pode ser atribuída a uma sala que:
* esteja disponível naquele horário;
* possua **capacidade suficiente** para comportar a turma.

O sistema deve atribuir **automaticamente a primeira sala que satisfaça essas condições**.

As capacidades das salas serão fornecidas na criação do sistema.

### Funcionalidades do sistema

O sistema deve permitir:
* realizar uma nova reserva de aula;
* cancelar uma reserva existente;
* exibir os horários ocupados das salas.

Os alunos devem **projetar e implementar a estrutura de dados responsável por armazenar e gerenciar as reservas**, decidindo como representar em memória:
* as salas disponíveis;
* os dias da semana;
* os horários;
* as reservas realizadas.

A solução deve ser implementada em **C++**, utilizando **classes e modularização** (`.hpp` e `.cpp`).
Os alunos podem criar classes, estruturas ou métodos auxiliares caso julguem necessário.
O programa deve garantir que não existam conflitos de horário para uma mesma sala.

#### Estrutura `ReservationRequest`

A classe `ReservationRequest` representa uma solicitação de reserva de sala.

```cpp
class ReservationRequest {

private:
    std::string course_name;
    std::string weekday;
    int start_hour;
    int end_hour;
    int student_count;

public:

    ReservationRequest(std::string course_name, std::string weekday, int start_hour, int end_hour, int student_count);
    ~ReservationRequest();

    int getStartHour();
    int getEndHour();
    std::string getCourseName();
    std::string getWeekday();
    int getStudentCount();
};
```

Essa classe encapsula as informações necessárias para realizar uma reserva.

#### Estrutura `ReservationSystem`

```cpp
class ReservationSystem {

private:
    int room_count;
    int* room_capacities;

    // Estruturas internas escolhidas pelos alunos
    // para armazenar e gerenciar as reservas, os horários, ...

public:

    ReservationSystem(int room_count, int* room_capacities);
    ~ReservationSystem();

    bool reserve(ReservationRequest request);
    bool cancel(std::string course_name);

    void printSchedule();

    // Outros métodos utilitários necessários
    // para auxiliar nas funções requisitadas
};
```

A classe `ReservationSystem` é responsável por gerenciar todas as reservas do sistema.

O construtor recebe:
* `room_count`: número total de salas disponíveis;
* `room_capacities`: um array contendo a capacidade máxima de cada sala.

#### Exemplo de criação do sistema

Um exemplo de inicialização no `main.cpp` seria:

```cpp
int capacities[3] = {30, 50, 80};

ReservationSystem system(3, capacities);
```

Neste exemplo:

* existem **3 salas**;
* suas capacidades são **30, 50 e 80 alunos**, respectivamente.

### Organização dos arquivos

O projeto deve possuir a seguinte organização mínima:

```
main.cpp
ReservationSystem.hpp
ReservationSystem.cpp
ReservationRequest.hpp
ReservationRequest.cpp
```

Descrição dos arquivos:
* **main.cpp**: Arquivo principal contendo testes para todas as funções implementadas.
* **ReservationSystem.hpp**: Declaração da classe `ReservationSystem`.
* **ReservationSystem.cpp**: Implementação da classe `ReservationSystem`.
* **ReservationRequest.hpp**: Declaração da classe `ReservationRequest`.
* **ReservationRequest.cpp**: Implementação da classe `ReservationRequest`.

### Requisitos

* As funções devem seguir **exatamente as assinaturas fornecidas**.
* O programa deve **compilar corretamente**. Programas que não compilarem não poderão ser avaliados e receberão **nota 0**.
* **Não é permitido utilizar estruturas de dados da STL** (`vector`, `list`, `map`, etc.) para implementar o sistema. O objetivo do trabalho é que as estruturas sejam implementadas manualmente pelos próprios alunos.
* O código deve utilizar boas práticas de programação, incluindo:
  * comentários explicativos;
  * verificação básica de erros;
  * cuidado com gerenciamento de memória.

### Questões

#### Questão 1

Implementar o **construtor** e o **destrutor** das classes `ReservationSystem` e `ReservationRequest`, garantindo a correta alocação e liberação de memória.

#### Questão 2

Implementar o método:

```cpp
bool reserve(ReservationRequest request);
```

Esse método deve:

1. verificar se existe alguma sala disponível no dia e horário solicitados;
2. verificar se a sala possui capacidade suficiente para comportar a turma;
3. atribuir automaticamente **a primeira sala disponível que satisfaça essas condições**;
4. criar a reserva correspondente.

O método deve retornar:
* `true` se a reserva foi realizada com sucesso;
* `false` se não houver salas disponíveis.

#### Questão 3

Implementar o método:

```cpp
bool cancel(std::string course_name);
```

Esse método deve localizar a reserva associada à disciplina informada e removê-la do sistema.

O método deve retornar:
* `true` caso a reserva tenha sido cancelada;
* `false` caso a disciplina não seja encontrada.

#### Questão 4

Implementar o método:

```cpp
void printSchedule();
```

Esse método deve exibir a grade atual de reservas organizadas por sala.
Dentro de cada sala, as reservas devem ser exibidas **ordenadas por dia da semana e horário de início**.

Exemplo de saída:

```
Room 1
segunda:
7h~9h: Data Structures
13h~15h: Calculus

Room 2
quarta:
10h~12h: Linear Algebra
```

#### Questão 5

Criar um main.cpp contendo casos de teste que demonstrem o funcionamento completo do sistema, incluindo:
* criação do sistema;
* reservas bem-sucedidas;
* tentativa de reserva sem disponibilidade;
* cancelamentos;
* exibição da grade.

#### Questão 6

Criar um arquivo README.md contendo:
* descrição do projeto;
* instruções de compilação;
* instruções de execução;
* uma breve explicação de como os dados estão organizados internamente no sistema.

#### Questão 7

Redigir um relatório em PDF (aproximadamente 1 página) explicando as decisões de implementação.

O relatório deve incluir:
* quais estruturas de dados foram utilizadas internamente e por quê;
* outras alternativas consideradas;
* trade-offs entre as diferentes soluções;
* custo computacional das principais operações:
	- reserva
	- cancelamento
	- verificação de conflito
	- exibição da grade.

### Entrega

O trabalho deve ser entregue através de um **repositório no GitHub**, e o link enviado por e-mail.

O código deve compilar utilizando:

```
g++ main.cpp ReservationSystem.cpp ReservationRequest.cpp -o reservation_system
```

Enviar o link do repositório para:

```
matheus.werner@fgv.br
```

até **Domingo, 29 de Março, às 23h59**.

### Considerações finais
* Trabalhos que **não compilarem** receberão nota **0**.
* Trabalhos que utilizarem **estruturas de dados da STL** (`vector`, `list`, `map`, etc.) na implementação do sistema receberão nota **0**.
* Trabalhos muito semelhantes entre si poderão ser chamados para uma breve **explicação do código**.
* Caso seja necessário, o aluno poderá ser solicitado a **explicar a implementação apresentada**.
* Política de atraso:
  * até **24h de atraso** → desconto de **20%** na nota;
  * até **48h de atraso** → desconto de **40%** na nota;
  * após **48h** → o trabalho não será aceito.
