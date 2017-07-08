#include "board.hh"

#include <cstddef>
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
        brigand->setValue((random() % 4) + 1);
        brigand->setIsBurning(random() % 2);
        this->addToDeck(brigand);
    }

    this->village = village;
}

Brigand *Board::draw(void)
{
    Brigand *res;

    if (!this->deck.size()) {
        return NULL;
    }

    res = this->deck.back();
    this->deck.pop_back();
    return res;
}

void Board::forward_raiders_to_intruders(void)
{
    while (this->deck.size()) {
        Brigand *raider = this->deck.back();

        this->deck.pop_back();
        this->spies.push(raider);
    }
}

/* after call to it intruders go back to the deck */
bool Board::intruders_burn_the_village(void)
{
    while (this->spies.size()) {
        Brigand *intruders = this->spies.top();

        this->spies.pop();
        if (intruders->getIsBurning()) {
            bool has_still_farm = this->village->burn();

            if (!has_still_farm) {
                return false;
            }
        }
        this->deck.push_back(intruders);
    }
    return true;
}

void Board::restore_graveyard_to_deck(void)
{
    while (this->graveyard.size()) {
        Brigand *raider = this->graveyard.back();

        this->graveyard.pop_back();
        this->deck.push_back(raider);
    }
}

std::ostream &Board::print(std::ostream &out)
{
    out << "Board: " << this->deck.size() << " brigand(s) remaining" << std::endl
        << "       " << this->graveyard.size() << " brigand(s) dead" << std::endl
        << "       " << this->spies.size() << " intruders" << std::endl;


    this->village->print(out);
    return out;
}
