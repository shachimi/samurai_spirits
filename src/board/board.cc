#include "board.hh"

#include <stdlib.h>

Board::Board(void)
{
}

Board::~Board(void)
{
}

void Board::init_board(int nb_players)
{
    Village *village = new Village();

    village->setBarricades(nb_players + 3);
    for (int i = 0; i < 6; i++) {
        village->addToFarms(new Farm());
    }
    for (int i = 0; i < 3; i++) {
        village->addToFamilies(new Family());
    }

    for (int i = 0; i < (nb_players * 6); i++) {
        Brigand *brigand = new Brigand();

        brigand->setSymbol(random() % 4);
        brigand->setValue(random() % 4);
        brigand->setIsBurning(random() % 2);
        this->addToDeck(brigand);
    }

    this->village = village;
}


std::ostream &Board::print(std::ostream &out)
{
    out << "Board: " << this->deck.size() << "brigand(s) remaining" << std::endl
        << "       " << this->graveyard.size() << "brigand(s) dead" << std::endl
        << "       " << this->spies.size() << "intruders" << std::endl;


    this->village->print(out);
    return out;
}
