#include <cstring>
#include <iostream>
#include "Jedi.hpp"

//template void print<Jedi>(Jedi);

Jedi::Jedi() {

    name = nullptr;
    rank = JediRank::Unknown;
    midiChlorian = 0;
    spicies = nullptr;
    militaryRank = nullptr;

    this->setPlanet({"unknown", "unknown", "unknown", PlanetType::Unknown});

}

Jedi::Jedi(const char *name_, const JediRank rank_, const double midiChlorian_, const Planet &pl_, const char *spicies_, const char* militaryRank_) {

    name = new char[strlen(name_) + 1];
    strcpy(name, name_);

    rank = rank_;

    midiChlorian = midiChlorian_;

    planet = pl_;

    spicies = new char[strlen(spicies_) + 1];
    strcpy(spicies, spicies_);

    militaryRank = new char[strlen(militaryRank_) + 1];
    strcpy(militaryRank, militaryRank_);
}

Jedi::Jedi(const Jedi &obj) {

    name = new char[strlen(obj.name) + 1];
    strcpy(name, obj.name);

    rank = obj.rank;

    midiChlorian = obj.midiChlorian;

    planet = obj.planet;

    spicies = new char[strlen(obj.spicies) + 1];
    strcpy(spicies, obj.spicies);

    militaryRank = new char[strlen(obj.militaryRank) + 1];
    strcpy(militaryRank, obj.militaryRank);
}

Jedi& Jedi::operator=(const Jedi &obj) {

    if (this != &obj) {
        delete[] name;
        name = new char[strlen(obj.name) + 1];
        strcpy(name, obj.name);

        rank = obj.rank;

        midiChlorian = obj.midiChlorian;

        planet = obj.planet;

        delete[] spicies;
        spicies = new char[strlen(obj.spicies) + 1];
        strcpy(spicies, obj.spicies);

        delete[] militaryRank;
        militaryRank = new char[strlen(obj.militaryRank) + 1];
        strcpy(militaryRank, obj.militaryRank);
    }
    return *this;

}

Jedi::~Jedi() {
    
    delete[] name;
    name = nullptr;
    
    delete[] spicies;
    spicies = nullptr;

    delete[] militaryRank;
    militaryRank = nullptr;
}

std::ostream& operator<<(std::ostream &out, const Jedi &obj) {

    out << "\nName: " << obj.getName()
    << "\nRank: " << obj.enumToString(obj.getRank())
    << "\nMidi-Chlorian: " << obj.getMidiChlorian() << '\n';
    
    out << obj.getPlanet();

    out << "\nSpicies: " << obj.getSpicies()
    << "\nMilitary Rank: " << obj.getMilitaryRank() << '\n';

    return out;
}

const char* Jedi::enumToString(const JediRank &r) const {
    switch (r)
    {
    case JediRank::Youngling :
        return "YOUNGLING";
    case JediRank::Padawan :
        return "PADAWAN";
    case JediRank::Knight :
        return "KNIGHT";
    case JediRank::Master :
        return "MASTER";
    
    default:
        return "UNKNOWN";
    }
}

char* Jedi::getName() const {
    return name;
}

JediRank Jedi::getRank() const {
    return rank;
}

double Jedi::getMidiChlorian() const {
    return midiChlorian;
}

const Planet& Jedi::getPlanet() const {
    return planet;
}

char* Jedi::getSpicies() const {
    return spicies; 
}

char* Jedi::getMilitaryRank() const {
    return militaryRank;
}

void Jedi::setName(char* name_) {
    if (name != nullptr) {
        delete[] name;
    }
    name = new char[strlen(name_) + 1];
    strcpy(name, name_);
}

void Jedi::setRank(JediRank rank_) {
    rank = rank_;
}

void Jedi::setMidiChlorian(double midiChlorian_) {
    midiChlorian = midiChlorian_;
}

void Jedi::setPlanet(const Planet &obj) {
    planet = obj;
}

void Jedi::setSpicies(char *spicies_) {
    if (spicies != nullptr) {
        delete[] spicies;
    }
    
    spicies = new char[strlen(spicies_) + 1];
    strcpy(spicies, spicies_);
}

void Jedi::setMilitaryRank(char* militaryRank_) {
    if (militaryRank != nullptr) {
        delete[] militaryRank;
    }
    
    militaryRank = new char[strlen(militaryRank_) + 1];
    strcpy(militaryRank, militaryRank_);
}

std::istream& operator>>(std::istream &in, Jedi &obj) {
    
    const int maxLen = 20;
    char buff[maxLen];

    in.getline(buff, maxLen, '\n');
    /* obj.name = new char[strlen(buff) + 1];
    strcpy(obj.name, buff); */
    obj.setName(buff);

    in.getline(buff, maxLen, '\n');
    obj.rank = jediRankToEnum(buff);

    std::cout << "midichlorian: ";
    double midi;
    in >> midi;

    obj.midiChlorian = midi;

    in.clear();
    in.ignore(10000,'\n');
    
    in.getline(buff, maxLen, '\n');
    obj.planet.setName(buff);

    in.getline(buff, maxLen, '\n');
    obj.setSpicies(buff);

    in.getline(buff, maxLen, '\n');
    obj.setMilitaryRank(buff);

    return in;
}