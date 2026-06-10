# Aula 26: Lista de Exercícios sobre Tabelas Hash

## Q1. Método da Divisão

Considere uma tabela hash com `m = 10` buckets e função hash:

```text
h(x) = x % 10
````

Insira os elementos na seguinte ordem:

```text
12 → 25 → 31 → 22 → 44 → 32 → 52
```

Mostre:

* O bucket calculado para cada chave;
* Quais colisões ocorrem;
* A configuração final da tabela usando encadeamento separado.

Represente a tabela no seguinte formato:

```text
0: -
1: ...
2: ...
...
9: ...
```

## Q2. Escolha do Tamanho da Tabela

Considere os seguintes conjuntos de chaves:

```text
A = 20, 30, 40, 50, 60
B = 21, 32, 43, 54, 65
```

Para cada conjunto, calcule os buckets usando:

```text
h(x) = x % m
```

para os seguintes valores de `m`:

```text
m = 10
m = 11
```

Responda:

* Qual escolha de `m` gerou mais colisões?
* Por que `m = 10` pode ser uma escolha ruim para alguns padrões de entrada?
* Por que números primos costumam ser usados no método da divisão?

## Q3. Método da Multiplicação

Considere o método da multiplicação com:

```text
W = 8
M = 3
m = 2^M = 8
a = 37
```

A função hash é:

```text
h(x) = ((37 * x) mod 256) >> 5
```

Calcule o valor de `h(x)` para:

```text
20, 30, 40, 50
```

Para cada chave, mostre:

* O valor de `37 * x`;
* O valor de `(37 * x) mod 256`;
* A representação binária com 8 bits;
* Os 3 bits mais significativos;
* O bucket final.

Compare o resultado com o método da divisão usando:

```text
h(x) = x % 10
```

para as mesmas chaves.

## Q4. Encadeamento Separado

Considere uma tabela hash com `m = 7` buckets e função hash:

```text
h(x) = x % 7
```

Insira os elementos na seguinte ordem:

```text
10 → 3 → 17 → 24 → 31 → 4 → 18 → 25
```

Utilize encadeamento separado para tratar colisões.

Mostre:

* O bucket calculado para cada chave;
* A configuração final da tabela;
* A maior lista formada em algum bucket;
* O fator de carga `α = n/m`.

Depois, responda:

* Qual seria o custo esperado de busca se os elementos estivessem bem distribuídos?
* Qual seria o pior caso de busca em uma tabela com encadeamento separado?

## Q5. Busca e Remoção com Encadeamento Separado

Considere a tabela hash abaixo, construída com encadeamento separado:

```text
0: -
1: 22 -> 36
2: 9 -> 16 -> 30
3: -
4: 11
5: 19 -> 26
6: -
```

Suponha que a função hash é:

```text
h(x) = x % 7
```

Execute as operações:

```cpp
contains(30)
contains(23)
remove(16)
remove(22)
insert(44)
```

Para cada operação:

* Indique o bucket acessado;
* Mostre quais elementos são visitados;
* Mostre a configuração da tabela após a operação, quando houver alteração.

## Q6. Endereçamento Aberto com Sondagem Linear

Considere uma tabela hash com `m = 10` posições.

Use endereçamento aberto com sondagem linear e função hash:

```text
h(x) = x % 10
```

Insira os elementos na seguinte ordem:

```text
12 → 22 → 32 → 42 → 25 → 35
```

Para cada inserção:

* Calcule o bucket inicial;
* Mostre as posições testadas;
* Indique a posição final onde o elemento foi inserido;
* Mostre o estado da tabela após cada inserção.

Use o formato:

```text
índice: 0  1  2  3  4  5  6  7  8  9
valor:  -  -  -  -  -  -  -  -  -  -
```

## Q7. Remoção em Endereçamento Aberto

Considere uma tabela hash com sondagem linear:

```text
índice: 0   1   2   3   4   5   6   7   8   9
valor:  -   -   12  22  32  42  25  35  -   -
```

A função hash é:

```text
h(x) = x % 10
```

Suponha que desejamos remover o elemento `22`.

Responda:

* Por que não é correto simplesmente trocar `22` por uma posição vazia?
* O que poderia acontecer ao buscar por `32` depois dessa remoção?
* Qual é o papel de uma marcação especial como `DELETED`?
* Mostre a tabela após remover `22` usando a marcação `DELETED`.

## Q8. Duplo Hashing

Considere uma tabela hash com `m = 10` posições.

Use endereçamento aberto com duplo hashing:

```text
h(k, i) = (h1(k) + i * h2(k)) % m
```

onde:

```text
h1(k) = k % 10
h2(k) = 1 + (k % 7)
```

Insira os elementos:

```text
20 → 30 → 40 → 50
```

Para cada inserção:

* Calcule `h1(k)`;
* Calcule `h2(k)`;
* Mostre a sequência de posições testadas;
* Indique a posição final onde o elemento foi inserido;
* Mostre o estado final da tabela.

## Q9. Necessidade de Coprimalidade no Duplo Hashing

Considere uma tabela com `m = 10`.

Suponha que, para uma certa chave `k`, temos:

```text
h1(k) = 0
h2(k) = 2
```

A sequência de sondagem será:

```text
h(k, i) = (0 + i * 2) % 10
```

Responda:

* Quais posições são visitadas para `i = 0, 1, 2, 3, 4, 5`?
* A sequência visita todas as posições da tabela?
* O que acontece se todas essas posições estiverem ocupadas, mas houver espaço livre em outra posição?
* Qual é a relação entre esse problema e o fato de `gcd(2, 10) ≠ 1`?

Agora considere:

```text
h1(k) = 0
h2(k) = 3
```

Responda:

* Quais posições são visitadas até a sequência repetir?
* Por que `h2(k)` ser coprimo com `m` é importante?
