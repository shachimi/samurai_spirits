#include <iostream>

#include "game/game.hh"
#include "game/player-dead.hh"
#include "game/family-killed.hh"
#include "game/farm-burned.hh"


int main(void)
{
    Game *game = Game::getInstance();

    game->init_game(2);

    game->print(std::cout);
    try {
        while (1) {
            game->play_round();
            game->print(std::cout);
            game->resolve_round_end();
            game->print(std::cout);
            std::cout << "Ok we can go to next round then :)" << std::endl;
        }
    } catch (PlayerDead *pd) {
        std::cout << "Player " << pd->getPlayer() << " is dead" <<std::endl;
    } catch (FarmBurned *fb) {
        std::cout << "Farm are all burned" << std::endl;
    } catch (FamilyKilled *fk) {
        std::cout << "There is no one left to save" << std::endl;
    }

    /* if (!game->play_round()) { */
    /*     std::cout << "x_x Dead" << std::endl; */
    /* } else { */
    /*     game->print(std::cout); */
    /*     if (!game->resolve_round_end()) { */
    /*         std::cout << "Game Over :(" << std::endl; */
    /*     } else { */
    /*         std::cout << "Nice now go to round 2 ;)" << std::endl; */
    /*     } */
    /* } */
    /* game->print(std::cout); */

    return 0;
}
