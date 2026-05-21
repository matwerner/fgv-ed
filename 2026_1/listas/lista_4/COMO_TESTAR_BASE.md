# Testando a Base de Jogos

Este arquivo explica como verificar se a base de jogos foi carregada corretamente.

Os arquivos `check_database.cpp` e `Game.hpp` fornecidos nesta pasta são apenas auxiliares para esse teste inicial. Eles servem para compilar um programa simples que lê alguns jogos do arquivo `GamesDatabase.cpp` e imprime suas informações no terminal.

Esses arquivos auxiliares não substituem a implementação final do trabalho.

Na entrega final, o grupo deve seguir o enunciado do Trabalho 4 e implementar todos os arquivos exigidos, incluindo o `main.cpp`, a Trie, o relatório e o `README.md` do projeto.

O `main.cpp` final deve seguir o formato especificado no enunciado:

```bash
./app k prefixo
```

## Arquivo auxiliar

Para testar a base, crie um arquivo chamado `check_database.cpp` com o seguinte conteúdo:

```cpp
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "GamesDatabase.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./check_database k" << std::endl;
        return 1;
    }

    int numGamesToRead = std::atoi(argv[1]);

    numGamesToRead = std::max(numGamesToRead, 0);
    numGamesToRead = std::min(numGamesToRead, numberOfGames);

    std::cout << "Reading " << numGamesToRead << " games:\n\n";

    for (int i = 0; i < numGamesToRead; i++) {
        std::cout << "Title: " << games[i].getTitle() << std::endl;
        std::cout << "Description: " << games[i].getShortDescription() << std::endl;
        std::cout << "Popularity: " << games[i].getPopularity() << std::endl;
        std::cout << "------------------------" << std::endl;
    }

    return 0;
}
```

Compile com:

```bash
g++ check_database.cpp Game.cpp GamesDatabase.cpp -o check_database
```

Execute com:

```bash
./check_database 10
```

Se os jogos forem impressos corretamente no terminal, então a base foi carregada corretamente.

# Observações sobre tempo de compilação

A base contém milhares de jogos e muitas strings, então é normal que a compilação demore mais que o habitual.

## Dica 1: reduzir a quantidade de jogos durante testes locais

Caso queira compilar mais rapidamente durante testes iniciais, é possível manter temporariamente apenas parte dos jogos no arquivo `GamesDatabase.cpp`.

Por exemplo, durante os primeiros testes, você pode manter apenas algumas dezenas ou centenas de jogos.

Antes da entrega final, restaure a base completa fornecida pelo professor.

## Dica 2: utilizar objetos intermediários compilados

Em C++, é possível compilar arquivos separadamente para evitar recompilar toda a base a cada alteração.

Em vez de fazer sempre:

```bash
g++ check_database.cpp Game.cpp GamesDatabase.cpp -o check_database
```

você pode compilar os arquivos separadamente:

```bash
g++ -c GamesDatabase.cpp
g++ -c Game.cpp
g++ -c check_database.cpp
g++ check_database.o Game.o GamesDatabase.o -o check_database
```

Isso gera arquivos intermediários com extensão `.o`.

Depois disso, se você alterar apenas o arquivo `check_database.cpp`, basta recompilar somente ele e fazer a ligação novamente:

```bash
g++ -c check_database.cpp
g++ check_database.o Game.o GamesDatabase.o -o check_database
```

Assim, o arquivo grande da base de jogos não precisa ser recompilado toda vez.
