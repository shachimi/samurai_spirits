#ifndef GAME_HH_
# define GAME_HH_

# include "board/board.hh"
# include "players/player.hh"

class Game {
public:
    static Game *getInstance(void);

    /* {{{ Game system */

    void init_game(int nb_players);
    bool play_round(void);
    bool play_turn(void);
    void play_player_turn(Player *);
    bool resolve_round_end(void);

    /* }}} */
    /* {{{ Misc. */

    std::ostream &print(std::ostream& out);

    /* }}} */
    /* {{{ getters / setters */
    Board *getBoard(void) { return this->board; };
    void setBoard(Board *board) { this->board = board; };
    std::vector<Player *> getPlayers(void) { return this->players; };
    void setPlayers(std::vector<Player *> players) { this->players = players; };
    /* }}} */

private:
    Board *board;
    std::vector<Player *> players;

    int round;

    unsigned int current_player;

private: /* Singleton constructor */
    Game(void);
    ~Game(void);

    static Game *instance;
};

#endif /* !GAME_HH_ */
