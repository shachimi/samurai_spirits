#ifndef BOARD_HH_
# define BOARD_HH_

# include <iostream>
# include <stack>
# include <vector>

# include "card/brigand.hh"
# include "village/village.hh"

class Board {
public:
    Board(void);
    ~Board(void);

    std::ostream &print(std::ostream& out);

    void init_board(int nb_players);

    /* Getter and setters */
    std::vector<Brigand *> getDeck(void) { return this->deck; };
    void setDeck(std::vector<Brigand *> deck) { this->deck = deck; };
    void addToDeck(Brigand *brigand) { this->deck.push_back(brigand); };
    std::stack<Brigand *> getSpies(void) { return this->spies; };
    void setSpies(std::stack<Brigand *> spies) { this->spies = spies; };
    void pushToSpies(Brigand *brigand) { this->spies.push(brigand); };
    std::vector<Brigand *> getGraveyard(void) { return this->graveyard; };
    void setGraveyard(std::vector<Brigand *> graveyard) { this->graveyard = graveyard; };
    void addToGraveyard(Brigand *brigand) { this->graveyard.push_back(brigand); };
    Village *getVillage(void) { return this->village; };
    void setVillage(Village *village) { this->village = village; };

private:
    std::vector<Brigand *> deck;
    std::stack<Brigand *> spies;
    std::vector<Brigand *> graveyard;
    Village * village;
};

#endif /* !BOARD_HH_ */
