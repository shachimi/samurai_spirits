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

bool Village::burn(void)
{
    if (this->barricades > 0) {
        this->barricades--;
        return true;
    }
    this->farms.pop_back();

    return this->farms.size();
}

bool Village::kill_family(void)
{
    this->families.pop_back();

    return this->families.size();
}
