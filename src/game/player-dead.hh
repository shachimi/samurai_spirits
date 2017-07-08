#ifndef PLAYER_DEAD_HH_
# define PLAYER_DEAD_HH_

# include "players/player.hh"

class PlayerDead {
public:
    PlayerDead(Player *p): player(p) {};
    ~PlayerDead(void) {};

    Player *getPlayer(void) { return this->player; };

private:
    Player *player;
};

#endif /* !PLAYER_DEAD_HH_ */
