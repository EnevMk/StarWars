#pragma once
#include "Planet.hpp"

enum class Rank {
    TROOPER,
    SERGEANT,
    SQUADLEADER,
    CHIEF,
    CAPTAIN
};

class Stormtrooper {

private:
    char* id;
    Rank rank;
    char* type;
    Planet planet;
    friend std::ostream& operator<<(std::ostream &out, const Stormtrooper &obj) {

    out << "Id: " << obj.getId() 
    << "\nRank: " << obj.enumToString(obj.getRank())
    << "\nType: " << obj.getType();

    Planet pl = obj.getPlanet();

    out << "\nPlanet Name:" << pl.getName()
    <<"\nPlanet System: " << pl.getPlanetSystem()
    <<"\nRepublic: " << pl.getRepublic() << '\n';
    
    return out;
}
public:
    Stormtrooper();
    Stormtrooper(const char* id_, const Rank rank_, const char* type_, const Planet &planet_);
    Stormtrooper(const Stormtrooper &obj);
    Stormtrooper& operator=(const Stormtrooper &obj);
    ~Stormtrooper();
    char* getId() const;
    Rank getRank() const;
    char* getType() const;
    const Planet& getPlanet() const;
    //void print() const;
    const char* enumToString(Rank r) const;
    void setId(char *id);
    void setRank(Rank r);
    void setType(char *type_);
    void setPlanet(const Planet &obj);

};