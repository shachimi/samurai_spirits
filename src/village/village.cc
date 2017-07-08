#include "village.hh"

#include "game/farm-burned.hh"
#include "game/family-killed.hh"

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

void Village::burn(void)
{
    if (this->barricades > 0) {
        this->barricades--;
        return;
    }
    this->farms.pop_back();

    if (!this->farms.size()) {
        throw new FarmBurned();
    }
}

void Village::kill_family(void)
{
    this->families.pop_back();

    if (!this->families.size()) {
        throw new FamilyKilled();
    }
}
