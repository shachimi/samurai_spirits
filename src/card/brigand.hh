#ifndef BRIGAND_HH_
# define BRIGAND_HH_

# include <iostream>

typedef enum {
    DEFENSE_KIND_NONE   = 0,
    DEFENSE_KIND_HAT    = 1,
    DEFENSE_KIND_FARM   = 2,
    DEFENSE_KIND_FAMILY = 3,
} defense_kind_t;


class Brigand {
public:
    Brigand(void);
    ~Brigand(void);

    std::ostream &print(std::ostream &out);

    /* Getter and setters */
    defense_kind_t getSymbol(void) const { return this->symbol; };
    void setSymbol(defense_kind_t symbol) { this->symbol = symbol; };
    void setSymbol(int symbol) { this->symbol = (defense_kind_t)(symbol % 4); };
    // Penalty * getPenalty(void) const { return this->penalty; };
    // void setPenalty(Penalty * penalty) { this->penalty = penalty; };
    bool getIsBurning(void) const { return this->is_burning; };
    void setIsBurning(bool is_burning) { this->is_burning = is_burning; };
    int getValue(void) const { return this->value; };
    void setValue(int value) { this->value = value; };

private:
    defense_kind_t symbol;
    // Penalty *penalty;
    bool is_burning;
    int value;
};

#endif /* !BRIGAND_HH_ */
