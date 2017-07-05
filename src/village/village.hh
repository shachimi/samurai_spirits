#ifndef VILLAGE_HH_
# define VILLAGE_HH_

# include <vector>

# include "farm.hh"
# include "family.hh"

class Village {
public:
    Village(void);
    ~Village(void);

    /* Getter and setters */
    std::vector<Farm *> getFarms(void) const { return this->farms; };
    void setFarm(std::vector<Farm *> farms) { this->farms = farms; };
    std::vector<Family *> getFamilies(void) const { return this->families; };
    void setFamilies(std::vector<Family *> families) { this->families = families; };
    int getBarricade(void) const { return this->barricade; };
    void setBarricade(int barricade) { this->barricade = barricade; };

private:
    std::vector<Farm *> farms;
    std::vector<Family *> families;
    int barricade;
};

#endif /* !VILLAGE_HH_ */
