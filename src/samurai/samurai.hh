#ifndef SAMURAI_HH_
# define SAMURAI_HH_

class Samurai {
public:
    Samurai(void);
    ~Samurai(void);

    /* Getter and setters */
    // Talent * getTalent(void) const { return this->talent; };
    // void setTalent(Talent * talent) { this->talent = talent; };
    // Kiai * getKiai(void) const { return this->kiai; };
    // void setKiai(Kiai * kiai) { this->kiai = kiai; };
    int getBattleGauge(void) const { return this->battle_gauge; };
    void setBattleGauge(int battle_gauge) { this->battle_gauge = battle_gauge; };
    Samurai *getUnleashMode(void) const { return this->unleash_mode; };
    void setUnleashMode(Samurai *samurai) { this->unleash_mode = samurai; };

private:
    // Talent * talent;
    // Kiai * kiai;
    int battle_gauge;
    Samurai *unleash_mode;
};

#endif /* !SAMURAI_HH_ */
