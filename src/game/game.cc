#include "game.hh"

#include <cstddef>

#include "card/brigand.hh"

/* {{{ Singleton */

Game *Game::instance = NULL;

Game::Game(void)
{
}

Game::~Game(void)
{
}

Game *Game::getInstance()
{
    if (!instance) {
        instance = new Game();
    }

    return instance;
}

/* }}} */
/* {{{ Game mechanics */

void Game::init_game(int nb_players)
{
    Board *board = new Board();

    for (int i = 0; i < nb_players; i++) {
        Player *player = new Player();
        Samurai *samurai = new Samurai();

        samurai->setBattleGauge(10);
        player->setSamurai(samurai);
        this->players.push_back(player);
    }

    board->init_board(nb_players);
    this->board = board;
}

/* }}} */
/* {{{ Utils */

std::ostream &Game::print(std::ostream &out)
{
    this->board->print(out);
    for (unsigned int i = 0; i < this->players.size(); i++) {
        this->players[i]->print(out);
    }

    return out;
}

/* }}} */
