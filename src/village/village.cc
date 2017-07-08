#include "village.hh"

Village::Village(void)
{
}

Village::~Village(void)
{
}

std::ostream &Village::print(std::ostream &out)
{
    out << "Village: " << this->barricades << " barricade(s)" << std::endl
        << "         " << this->farms.size() << " ferme(s)" << std::endl
        << "         " << this->families.size() << " famille(s)"<< std::endl;

    return out;
}
