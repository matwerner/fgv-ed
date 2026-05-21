// games_database.hpp

#ifndef GAMES_DATABASE_HPP
#define GAMES_DATABASE_HPP

#include "Game.hpp"

/**
 *    extern means that these variables are defined
 *    in another file (.cpp).
 *
 *    The actual array is created in games_database.cpp.
 *
 *    This avoids creating multiple copies of the array
 *    when several .cpp files include this header.
 */

extern Game games[];
extern int numberOfGames;

#endif