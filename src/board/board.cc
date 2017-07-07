#include "board.hh"

Board::Board(void)
{
}

Board::~Board(void)
{
}

std::ostream &Village::print(std::ostream &out)
{
    out << "Board: " << this->deck.size() << "brigand(s) remaining" << std::endl
        << "       " << this->graveyard.size() << "brigand(s) dead" << std::endl
        << "       " << this->spies.size() << "intruders" << std::endl;


    this->village->print(out);
    return out;
}
