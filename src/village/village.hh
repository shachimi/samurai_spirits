#ifndef VILLAGE_HH_
# define VILLAGE_HH_

# include <iostream>
# include <vector>

# include "farm.hh"
# include "family.hh"

class Village {
public:
    Village(void);
    ~Village(void);

    std::ostream &print(std::ostream& out);


    /* Getter and setters */
    std::vector<Farm *> getFarms(void) const { return this->farms; };
    void setFarm(std::vector<Farm *> farms) { this->farms = farms; };
    void addToFarms(Farm *farm) { this->farms.push_back(farm); };
    std::vector<Family *> getFamilies(void) const { return this->families; };
    void setFamilies(std::vector<Family *> families) { this->families = families; };
    void addToFamilies(Family *family) { this->families.push_back(family); };
    int getBarricades(void) const { return this->barricades; };
    void setBarricades(int barricades) { this->barricades = barricades; };

private:
    std::vector<Farm *> farms;
    std::vector<Family *> families;
    int barricades;
};

#endif /* !VILLAGE_HH_ */
