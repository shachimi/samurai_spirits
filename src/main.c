#include <iostream>

#include "board/board.hh"
#include "card/brigand.hh"
#include "players/player.hh"
#include "samurai/samurai.hh"


int main(void)
{
    Player *player = new Player();
    std::vector<Brigand *> bt = std::vector<Brigand *>();
    Samurai *samurai = new Samurai();
    Brigand *brigand = new Brigand();

    player->setBattleTrack(bt);
    samurai->setBattleGauge(10);
    player->setSamurai(samurai);
    brigand->setValue(2);
    player->addOnBattleTrack(brigand);
    brigand = new Brigand();
    brigand->setValue(3);
    player->addOnBattleTrack(brigand);
    player->setDefenseFarm(brigand);

    player->print(std::cout);

    return 0;
}
