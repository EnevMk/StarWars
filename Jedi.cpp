#include <cstring>
#include <iostream>
#include "Jedi.hpp"

//template void print<Jedi>(Jedi);

Jedi::Jedi() {
    const int nameLen = 17;
    char buffName[] = "Anakin Skywalker";

    name = new char[nameLen];
    strcpy(name, buffName);

    rank = JediRank::Knight;

    midiChlorian = 20000;

    planet = {"Tatooine", "Tatoo System", "Arkanis"};

    const int spiciesLen = 6;
    char buffSpicies[] = "Human";
    spicies = new char[spiciesLen];
    strcpy(spicies, buffSpicies);

    const int militaryLen = 7;
    char buffMilitary[] = "Loshav";
    militaryRank = new char[militaryLen];
    strcpy(militaryRank, buffMilitary);

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
    delete[] name;
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
    delete[] spicies;
    spicies = new char[strlen(spicies_) + 1];
    strcpy(spicies, spicies_);
}

void Jedi::setMilitaryRank(char* militaryRank_) {
    delete[] militaryRank;
    militaryRank = new char[strlen(militaryRank_) + 1];
    strcpy(militaryRank, militaryRank_);
}