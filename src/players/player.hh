#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <iostream>
# include <vector>

# include "card/brigand.hh"
# include "samurai/samurai.hh"

class Player {
public:
    Player(void);
    ~Player(void);

    std::ostream &print(std::ostream& out);


    /* Getter and setters */
    Brigand * getDefenseFarm(void) { return this->defense_farm; };
    void setDefenseFarm(Brigand * defense_farm) { this->defense_farm = defense_farm; };
    // std::vector<Talent *> getTokens(void) { return this->tokens; };
    // void setTokens(std::vector<Talent *> tokens) { this->tokens = tokens; };
    Samurai * getSamurai(void) { return this->samurai; };
    void setSamurai(Samurai * samurai) { this->samurai = samurai; };
    void addOnBattleTrack(Brigand *brigand) { this->battle_track.push_back(brigand); };
    std::vector<Brigand *> getBattleTrack(void) { return this->battle_track; };
    void setBattleTrack(std::vector<Brigand *> battle_track) { this->battle_track = battle_track; };
    Brigand * getDefenseFamily(void) { return this->defense_family; };
    void setDefenseFamily(Brigand * defense_family) { this->defense_family = defense_family; };
    Brigand * getDefenseHat(void) { return this->defense_hat; };
    void setDefenseHat(Brigand * defense_hat) { this->defense_hat = defense_hat; };

protected:
    int getCurrentTrack(void);

protected:
    Samurai *samurai;
    // std::vector<Talent *> tokens;
    std::vector<Brigand *> battle_track;
    Brigand *defense_hat;
    Brigand *defense_farm;
    Brigand *defense_family;
};

#endif /* !PLAYER_HH_ */
