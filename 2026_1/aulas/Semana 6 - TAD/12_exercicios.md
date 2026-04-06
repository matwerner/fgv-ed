# Aula 12: Exercícios sobre Listas Encadeadas

## Questão 1
Implemente uma classe de pilha (stack) utilizando uma lista simplesmente encadeada, sem uso de nós cabeça ou cauda. A implementação deve conter métodos para:
- Inserir um elemento (push)
- Remover um elemento (pop)
- Verificar se a pilha está vazia
- Consultar o elemento no topo sem removê-lo (peek)

## Questão 2
Implemente uma classe de fila (queue) utilizando uma lista simplesmente encadeada, sem uso de nós cabeça ou cauda. A implementação deve conter métodos para:
- Inserir um elemento (enqueue)
- Remover um elemento (dequeue)
- Verificar se a fila está vazia
- Consultar o primeiro elemento sem removê-lo (front)

## Questão 3
Dadas duas listas ordenadas **L1** e **L2**, implemente um procedimento que compute **L1 ∩ L2** utilizando apenas operações básicas sobre listas.

## Questão 4
Dadas duas listas ordenadas **L1** e **L2**, implemente um procedimento que compute **L1 ∪ L2** utilizando apenas operações básicas sobre listas.

## Questão 5
Implemente um método para trocar dois elementos adjacentes em uma lista encadeada ajustando apenas os ponteiros (sem modificar os valores armazenados nos nós). Resolva este problema para:
- (a) Listas simplesmente encadeadas
- (b) Listas duplamente encadeadas

## Questão 6
Desenvolva um algoritmo **não recursivo** que inverta uma lista simplesmente encadeada contendo **n** elementos em tempo **O(n)**, utilizando apenas um espaço de armazenamento constante além do necessário para a própria lista.

## Questão 7
Suponha que temos um ponteiro para um nó em uma lista simplesmente encadeada, mas **não temos ponteiros para os nós anteriores**. Sabemos que esse nó **não é o último** da lista. Descreva e implemente um algoritmo **O(1)** que remova logicamente o valor armazenado nesse nó, mantendo a integridade da lista encadeada.

## Questão 8
A operação **UNION** em conjuntos dinâmicos recebe dois conjuntos disjuntos **S1** e **S2** e retorna um conjunto **S = S1 ∪ S2**, destruindo os conjuntos originais **S1** e **S2**. Mostre como realizar essa operação em **tempo O(1)** utilizando uma estrutura de dados de lista adequada.
