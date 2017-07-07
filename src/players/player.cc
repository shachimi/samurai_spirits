#include "player.hh"

Player::Player(void)
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

std::ostream &Player::print(std::ostream &out)
{
    out << "Samurai - " << this->getCurrentTrack() << "/"
        << this->samurai->getBattleGauge() << std::endl
        << (this->defense_hat    ? "v" : " ") << "H   " << std::endl
        << (this->defense_farm   ? "v" : " ") << "F   " << std::endl
        << (this->defense_family ? "v" : " ") << "f   " << std::endl;

    return out;
}
