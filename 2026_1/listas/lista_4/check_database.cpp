// check_database.cpp

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "GamesDatabase.hpp"

/**
 * Programa auxiliar para testar se a base de jogos foi carregada corretamente.
 *
 * Entrada:
 * argc: indica o número de parâmetros de entrada.
 * argv: contém os parâmetros escritos na linha de comando.
 *
 * Exemplo:
 * ./check_database 10
 *
 * Nesse caso:
 * argc = 2
 * argv[0] = "./check_database"
 * argv[1] = "10"
 */
int main(int argc, char* argv[]) {
    // Garante que o usuário escreveu o número correto de parâmetros
    if (argc != 2) {
        std::cout << "Usage: ./check_database k" << std::endl;
        return 1;
    }

    // Converte o parâmetro para inteiro
    int numGamesToRead = std::atoi(argv[1]);

    // Garante que a quantidade esteja no intervalo [0, numberOfGames]
    numGamesToRead = std::max(numGamesToRead, 0);
    numGamesToRead = std::min(numGamesToRead, numberOfGames);

    std::cout << "Reading " << numGamesToRead << " games:\n\n";

    for (int i = 0; i < numGamesToRead; i++) {
        std::cout << "Title: " << games[i].title << std::endl;
        std::cout << "Description: " << games[i].description << std::endl;
        std::cout << "Popularity: " << games[i].popularity << std::endl;
        std::cout << "------------------------" << std::endl;
    }

    return 0;
}