#ifndef GAME_HPP
#define GAME_HPP

#include <string>

class Game {
public:
    std::string title;
    std::string description;
    int popularity;

    Game(std::string t, std::string d, int p) {
        this->title = t;
        this->description = d;
        this->popularity = p;
    }
};

#endif