#ifndef BOARD_HH_
# define BOARD_HH_

# include <stack>
# include <vector>

# include "card/brigand.hh"
# include "village/village.hh"

class Board {
public:
    Board(void);
    ~Board(void);

    /* Getter and setters */
    std::vector<Brigand *> getDeck(void) { return this->deck; };
    void setDeck(std::vector<Brigand *> deck) { this->deck = deck; };
    std::stack<Brigand *> getSpies(void) { return this->spies; };
    void setSpies(std::stack<Brigand *> spies) { this->spies = spies; };
    std::vector<Brigand *> getGraveyard(void) { return this->graveyard; };
    void setGraveyard(std::vector<Brigand *> graveyard) { this->graveyard = graveyard; };
    Village *getVillage(void) { return this->village; };
    void setVillage(Village *village) { this->village = village; };

private:
    std::vector<Brigand *> deck;
    std::stack<Brigand *> spies;
    std::vector<Brigand *> graveyard;
    Village * village;
};

#endif /* !BOARD_HH_ */
