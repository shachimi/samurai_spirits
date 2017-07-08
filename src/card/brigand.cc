#include "brigand.hh"

Brigand::Brigand(void)
{
}

Brigand::~Brigand(void)
{
}

std::ostream &Brigand::print(std::ostream &out)
{
    out << "Raider: " << this->value << "  " << this->symbol << std::endl
        << "        " << /* this->penalty ? this->penalty << */ "   " << (this->is_burning ? "Burn" : "X")
        << std::endl;

    return out;
}
