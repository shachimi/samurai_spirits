#ifndef BRIGAND_HH_
# define BRIGAND_HH_

class Brigand {
public:
    Brigand(void);
    ~Brigand(void);

    /* Getter and setters */
    // Symbol * getSymbol(void) const { return this->symbol; };
    // void setSymbol(Symbol * symbol) { this->symbol = symbol; };
    // Penalty * getPenalty(void) const { return this->penalty; };
    // void setPenalty(Penalty * penalty) { this->penalty = penalty; };
    bool getIsBurning(void) const { return this->is_burning; };
    void setIsBurning(bool is_burning) { this->is_burning = is_burning; };
    int getValue(void) const { return this->value; };
    void setValue(int value) { this->value = value; };

private:
    // Symbol *symbol;
    // Penalty *penalty;
    bool is_burning;
    int value;
};

#endif /* !BRIGAND_HH_ */
