#include <iostream>

#include "game/game.hh"


int main(void)
{
    Game *game = Game::getInstance();

    game->init_game(2);
    game->print(std::cout);

    return 0;
}
