#pragma once
#include "Planet.hpp"

enum class JediRank {
    Youngling,
    Padawan,
    Knight,
    Master
};

class Jedi {
private:
    char* name;
    JediRank rank;
    double midiChlorian;
    Planet planet;
    char* spicies;
    char* militaryRank;
    friend std::ostream& operator<<(std::ostream &out, const Jedi &obj) {

    out << "\nName: " << obj.getName()
    << "\nRank: " << obj.enumToString(obj.getRank())
    << "\nMidi-Chlorian: " << obj.getMidiChlorian() << '\n';
    
    Planet pl = obj.getPlanet();

    out << "\nPlanet Name:" << pl.getName()
    <<"\nPlanet System: " << pl.getPlanetSystem()
    <<"\nRepublic: " << pl.getRepublic() << '\n';

    out << "\nSpicies: " << obj.getSpicies()
    << "\nMilitary Rank: " << obj.getMilitaryRank() << '\n';

    return out;
}
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

};