#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <iostream>
# include <vector>

# include "card/brigand.hh"
# include "samurai/samurai.hh"

typedef enum {
    TURN_ACTION_FIGHT,
    /* TURN_ACTION_SUPPORT, */
    TURN_ACTION_PASS,
} turn_action_t;

typedef enum {
    REACTION_FIGHT,
    /* REACTION_SKILL, */
    REACTION_DEFEND,
} raider_reaction_t;

class Player {
public:
    Player(void);
    ~Player(void);

    std::ostream &print(std::ostream& out);

    /* {{{ Gameplay */

    int getCurrentTrack(void);
    void putInDef(Brigand *brigand);
    bool canDefend(Brigand *brigand);
    void woundSamurai(void);
    Brigand *removeFirstOnTrack(void);

    /* }}} */
    /* {{{ Play */
    virtual turn_action_t chooseTurnAction(/* turn_action_t available_actions[] */void);
    virtual raider_reaction_t chooseReaction(Brigand *brigand/* , */
                                             /* raider_reaction_t available_actions[] */);
    /* }}} */
    /* {{{ Getter and setters */
    Brigand * getDefenseFarm(void) { return this->defense_farm; };
    void setDefenseFarm(Brigand * defense_farm) { this->defense_farm = defense_farm; };
    // std::vector<Talent *> getTokens(void) { return this->tokens; };
    // void setTokens(std::vector<Talent *> tokens) { this->tokens = tokens; };
    Samurai * getSamurai(void) { return this->samurai; };
    void setSamurai(Samurai * samurai) { this->samurai = samurai; };
    void addOnBattleTrack(Brigand *brigand) { this->battle_track.push_back(brigand); };
    std::vector<Brigand *> *getBattleTrack(void) { return &this->battle_track; };
    void setBattleTrack(std::vector<Brigand *> battle_track) { this->battle_track = battle_track; };
    Brigand *getDefenseFamily(void) { return this->defense_family; };
    void setDefenseFamily(Brigand * defense_family) { this->defense_family = defense_family; };
    Brigand *getDefenseHat(void) { return this->defense_hat; };
    void setDefenseHat(Brigand * defense_hat) { this->defense_hat = defense_hat; };
    bool hasPassed(void) { return this->has_passed; };
    void setHasPassed(bool has_passed) { this->has_passed = has_passed; };
    /* }}} */
    /* {{{ */

protected:
    Samurai *samurai;
    // std::vector<Talent *> tokens;
    std::vector<Brigand *> battle_track;
    Brigand *defense_hat;
    Brigand *defense_farm;
    Brigand *defense_family;

    bool wound;
    bool has_passed;
};

#endif /* !PLAYER_HH_ */
