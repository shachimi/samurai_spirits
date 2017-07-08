#ifndef GAME_HH_
# define GAME_HH_

# include "board/board.hh"
# include "players/player.hh"

class Game {
public:
    static Game *getInstance(void);

    void init_game(int nb_players);
    std::ostream &print(std::ostream& out);

    Board *getBoard(void) { return this->board; };
    void setBoard(Board *board) { this->board = board; };
    std::vector<Player *> getPlayers(void) { return this->players; };
    void setPlayers(std::vector<Player *> players) { this->players = players; };

private:
    Board *board;
    std::vector<Player *> players;


private: /* Singleton constructor */
    Game(void);
    ~Game(void);

    static Game *instance;
};

#endif /* !GAME_HH_ */
