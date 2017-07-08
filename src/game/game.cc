#include "game.hh"

#include <cstddef>

#include "card/brigand.hh"
#include "game/player-dead.hh"

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
    this->current_player = 0;

    board->init_board(nb_players);
    this->board = board;

    this->round = 1;
}

bool Game::play_round(void)
{
        while (this->play_turn() && this->board->getDeck().size()) {
        }
    return true;
}

bool Game::play_turn(void)
{
    unsigned int start_idx;
    Player *player;

    start_idx = this->current_player % this->players.size();
    do {
        player = this->players[this->current_player++ % this->players.size()];
        if (player->getCurrentTrack() <= player->getSamurai()->getBattleGauge()
        &&  !player->hasPassed())
        {
            this->play_player_turn(player);
            return true;
        }
    } while (start_idx != this->current_player % this->players.size());
    return false;
}

void Game::play_player_turn(Player *player)
{
    turn_action_t action;

    /* TODO: apply_penalty */

    /* choose action to do */
    action = player->chooseTurnAction();

    switch (action) {
      case TURN_ACTION_PASS:
        player->setHasPassed(true);
        break;

      case TURN_ACTION_FIGHT: {
        raider_reaction_t reaction;
        Brigand *brigand = this->board->draw();

        brigand->print(std::cout);
        /* filter if defend possible for player */
        reaction = player->chooseReaction(brigand);
        switch (reaction) {
          case REACTION_FIGHT:
            player->addOnBattleTrack(brigand);
            /* TODO: check for power and battle gauge */
            break;
          case REACTION_DEFEND:
            player->putInDef(brigand);
            break;
          /* case REACTION_SKILL: */
          /*   break; */
        }
      } break;
    }
}

void Game::resolve_round_end(void)
{
    this->board->forward_raiders_to_intruders();

    /* blessure */
    for (unsigned int i = 0; i < this->players.size(); i++) {
        Player *player = this->players[i];

        if (!player->getDefenseHat()) {
            player->woundSamurai();
        } else {
            this->board->addToDeck(player->getDefenseHat());
            player->setDefenseHat(NULL);
        }

        if (!player->getDefenseFarm()) {
            this->board->burn();
        } else {
            this->board->addToDeck(player->getDefenseFarm());
            player->setDefenseFarm(NULL);
        }

        if (!player->getDefenseFamily()) {
            this->board->kill_family();
        } else {
            this->board->addToDeck(player->getDefenseFamily());
            player->setDefenseFamily(NULL);
        }

        while (player->getBattleTrack()->size()) {
            this->board->addToDeck(player->getBattleTrack()->back());
            player->getBattleTrack()->pop_back();
        }
    }

    this->board->intruders_burn_the_village();
    this->board->restore_graveyard_to_deck();

    /* TODO: add brigand depending of round */
    this->round++;
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
