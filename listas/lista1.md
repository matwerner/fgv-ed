# Lista 1 - TAD PatientArray

## Introdução

Nesta lista de exercícios, você irá implementar um Tipo Abstrato de Dados (TAD) chamado `PatientArray` utilizando a linguagem C++, porém seguindo um estilo de programação mais próximo da linguagem C (sem orientação a objetos). O objetivo deste TAD é armazenar e gerenciar uma lista dinâmica de pacientes de maneira eficiente, garantindo um uso otimizado de memória.

### Estrutura `Patient`

Cada paciente será representado pela seguinte estrutura `Patient`:

```cpp
struct Patient {
    char name[50];
    int severity;         // Número positivo. Quanto maior, mais severo.
    char arrival_time[6]; // Formato "XXhYY"
};
```

### Estrutura `PatientArray`

A estrutura PatientArray armazenará um array dinâmico de pacientes, com as seguintes características:
* Inicialmente, terá uma capacidade de 4 posições.
* Quando o array atingir 75% de sua capacidade, ele deverá dobrar de tamanho.
* Quando a ocupação cair abaixo de 25% da capacidade, o array deverá reduzir seu tamanho pela metade, mas nunca pode ter menos de 4 posições.

A estrutura `PatientArray` será definida da seguinte forma:

```cpp
struct PatientArray {
    Patient *patients; // Ponteiro para o array de pacientes
    int size;          // Número atual de pacientes armazenados
    int capacity;      // Capacidade total do array
};
```

Os arquivos devem ser organizados da seguinte maneira:
- `main.cpp`: Arquivo principal contendo testes para todas as funções implementadas, demonstrando o seu correto funcionamento.
- `PatientArray.h`: Declaração das funções e estruturas do TAD.
- `PatientArray.cpp`: Implementação das funções do TAD.

### Requisitos
* As funções devem ser implementadas nos arquivos descritos acima.
* As funções devem seguir as assinaturas estabelecidas para cada exercício.
* Será atribuído nota 0 caso o programa não compile.
* Use o namespace `PatientArray` para todas as funções.
* Utilize boas práticas de programação, incluindo:
    - Documentação das funções (comentários explicativos sobre sua funcionalidade).
    - Verificações básicas (evitar acessos inválidos à memória, checagem de ponteiros nulos, etc.).

### Entregável
O trabalho deve ser enviado conforme as seguintes especificações:
1. **Formato**: O arquivo final deve ser um arquivo zip contendo os 3 arquivos mencionados (`main.cpp`, `PatientArray.h`, e `PatientArray.cpp`).
2. **Nome do arquivo zip**: O nome do arquivo zip deve seguir o formato: `lista1_{nome completo sem espaços e com parênteses no lugar de espaços}.zip`. Exemplo: `lista1_nome_sobrenome.zip`.
3. **Envio**: Como ainda não temos acesso ao eclass, o arquivo final deve ser enviado para o meu e-mail institucional: `matheus.werner@fgv.br` até **Segunda-feira, 17 de Março, às 23h59**.

---

## Exercício 1: Inicialização da Estrutura

Implemente a função para inicializar um `PatientArray`, garantindo que ele comece vazio, mas com capacidade inicial para 4 pacientes.

**Definição da função:**
```cpp
PatientArray * initializePatientArray();
```

---

## Exercício 2: Exibição da Lista de Pacientes

Crie uma função que exiba a lista de pacientes, formatando corretamente os dados de cada paciente.

**Definição da função:**
```cpp
void printPatients(PatientArray *pa);
```

**Formato esperado de saída:**
```
Capacity: <X>
Current size: <Y>

Patients:
* <Time> | <Severity> | <Name>
* ...
```

---

## Exercício 3: Inserção de Pacientes

Crie uma função para inserir um paciente no final do array. Se o array atingir 3/4 da capacidade, sua capacidade deve ser dobrada.

**Definição da função:**
```cpp
void insertPatient(PatientArray *pa, Patient p);
```

---

## Exercício 4: Busca do Próximo Paciente a Ser Atendido

Crie uma função auxiliar que encontre o índice do paciente mais urgente a ser atendido. O critério de urgência é:
1. Maior índice de gravidade.
2. Em caso de empate, o paciente que chegou mais cedo (Considerar que não existem dois pacientes que chegam no mesmo horário).

**Dicas**:
* Para comparar strings, você pode utilizar a função `strcmp` da biblioteca `cstring`;
* Para facilitar legibilidade, você pode criar uma função auxiliar `int comparePatients(Patient p1, Patient p2)`, que retorna
  - `1` se p1 for mais urgente que p2.
  - `0` se p1 e p2 tiverem o mesmo nível de urgência.
  - `-1` se p2 for mais urgente que p1.

**Definição da função:**
```cpp
int findNextPatient(PatientArray *pa);
```

---

## Exercício 5: Remoção de Pacientes

Implemente uma função para remover um paciente em uma posição qualquer, garantindo que os elementos restantes fiquem contíguos no array. Se a quantidade de pacientes cair para menos de 1/4 da capacidade total, o array deve ser reduzido pela metade, mas nunca menor que 4.

**Definição da função:**
```cpp
void removePatient(PatientArray *pa, int index);
```

---

## Exercício 6: Remoção e Retorno do Próximo Paciente

Crie uma função que encontre o paciente mais urgente e o remova da lista, retornando o objeto `Patient` por referência.\
**Dica:** Utilize a função `findNextPatient` para encontrar o índice do paciente antes de removê-lo.

**Definição da função:**
```cpp
Patient popNextPatient(PatientArray *pa);
```

---

