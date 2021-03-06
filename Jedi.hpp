#ifndef JEDI_HPP
#define JEDI_HPP
#include "Planet.hpp"

enum class JediRank {
    Youngling,
    Padawan,
    Knight,
    Master,
    GrandMaster,
    Unknown
};

class Jedi {
private:
    char* name;
    JediRank rank;
    double midiChlorian;
    Planet planet;
    char* spicies;
    char* militaryRank;
    
    
public:
    Jedi();
    Jedi(const char *name_, const JediRank rank_, const double midiChlorian_, const Planet &pl_, const char *spicies_, const char* militaryRank_);
    Jedi(const Jedi &obj);
    Jedi& operator=(const Jedi &obj);
    ~Jedi();
    //std::ostream& operator<<(std::ostream& out);
    //void print() const;
    char* getName() const;
    JediRank getRank() const;
    double getMidiChlorian() const;
    const Planet& getPlanet() const;
    char* getSpicies() const;
    char* getMilitaryRank() const;
    void setName(char *name_);
    void setRank(JediRank rank_);
    void setMidiChlorian(double midiChlorian_);
    void setPlanet(const Planet&);
    void setSpicies(char *spicies_);
    void setMilitaryRank( char *militaryRank_);
    const char* enumToString(const JediRank &r) const;

    friend std::ostream& operator<<(std::ostream &out, const Jedi &obj);
    friend std::istream& operator>>(std::istream &in, Jedi &obj);
};
inline JediRank jediRankToEnum(char *str) {
    toLower(str);

    if (!strcmp(str, "youngling")) return JediRank::Youngling;

    if (!strcmp(str, "padawan")) return JediRank::Padawan;

    if (!strcmp(str, "knight")) return JediRank::Knight;

    if (!strcmp(str, "master")) return JediRank::Master;

    if (!strcmp(str, "grand master")) return JediRank::GrandMaster;

    return JediRank::Unknown;
}

#endif