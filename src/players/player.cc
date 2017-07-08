#include "player.hh"

#include <cstddef>

#include "game/player-dead.hh"

Player::Player(void)
    : samurai(NULL),
      defense_hat(NULL),
      defense_farm(NULL),
      defense_family(NULL),
      wound(false),
      has_passed(false)
{
}

Player::~Player(void)
{
}


int Player::getCurrentTrack(void)
{
    int track_value = 0;

    for (unsigned int i = 0; i < this-> battle_track.size(); i++) {
        track_value += this->battle_track[i]->getValue();
    }

    return track_value;
}

turn_action_t Player::chooseTurnAction(void/*turn_action_t available_actions[]*/)
{
    return TURN_ACTION_FIGHT;
}

raider_reaction_t Player::chooseReaction(Brigand *brigand/*turn_action_t available_actions[]*/)
{
    if (this->canDefend(brigand)) {
        return REACTION_DEFEND;
    }

    return REACTION_FIGHT;
}

bool Player::canDefend(Brigand *brigand)
{
    return brigand->getSymbol() != DEFENSE_KIND_NONE
        && ((brigand->getSymbol() == DEFENSE_KIND_HAT && !this->defense_hat)
        ||  (brigand->getSymbol() == DEFENSE_KIND_FARM && !this->defense_farm)
        ||  (brigand->getSymbol() == DEFENSE_KIND_FAMILY && !this->defense_family));
}

void Player::putInDef(Brigand *brigand)
{
    if (brigand->getSymbol() == DEFENSE_KIND_HAT) {
        this->defense_hat = brigand;
    }
    if (brigand->getSymbol() == DEFENSE_KIND_FARM) {
        this->defense_farm = brigand;
    }
    if (brigand->getSymbol() == DEFENSE_KIND_FAMILY) {
        this->defense_family = brigand;
    }
}

void Player::woundSamurai(void)
{
    if (this->wound) {
        if (!this->samurai->getUnleashMode()) {
            throw new PlayerDead(this);
        }
        this->wound = false;
        this->samurai = this->samurai->getUnleashMode();
    } else {
        this->wound = true;
    }
}

std::ostream &Player::print(std::ostream &out)
{
    out << "Samurai (" << (this->wound ? "Wounded" : "Ok") << ")- "
        << this->getCurrentTrack() << "/" << this->samurai->getBattleGauge()
        << "  " << (this->has_passed ? "Paused" : "Active") << std::endl
        << (this->defense_hat    ? "v" : " ") << "H   " << std::endl
        << (this->defense_farm   ? "v" : " ") << "F   " << std::endl
        << (this->defense_family ? "v" : " ") << "f   " << std::endl;

    return out;
}
