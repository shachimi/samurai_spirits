#include <iostream>

#include "game/game.hh"


int main(void)
{
    Game *game = Game::getInstance();

    game->init_game(2);

    game->print(std::cout);
    if (!game->play_round()) {
        std::cout << "x_x Dead" << std::endl;
    } else {
        game->print(std::cout);
        if (!game->resolve_round_end()) {
            std::cout << "Game Over :(" << std::endl;
        } else {
            std::cout << "Nice now go to round 2 ;)" << std::endl;
        }
    }
    game->print(std::cout);

    return 0;
}
