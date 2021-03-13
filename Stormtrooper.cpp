#include <iostream>
#include <cstring>
#include "Stormtrooper.hpp"

char* Stormtrooper::getId() const {
    return id;
}
Rank Stormtrooper::getRank() const {
    return rank;
}
char* Stormtrooper::getType() const {
    return type;
}
const Planet& Stormtrooper::getPlanet() const {
    return planet;
}

Stormtrooper::Stormtrooper() {
    char buff[] = "000000";
    id = new char[7];
    strcpy(id, buff);

    rank = Rank::TROOPER;

    char buffType[] = "Clone Trooper";
    type = new char[14];
    strcpy(type, buffType);
}

Stormtrooper::Stormtrooper(const char* id_, const Rank rank_, const char* type_, const Planet &planet_) {

    id = new char[strlen(id_) + 1];
    strcpy(id, id_);

    rank = rank_;

    type = new char[strlen(type_) + 1];
    strcpy(type, type_);

    planet = planet_;
}

Stormtrooper::Stormtrooper(const Stormtrooper &obj) {

    id = new char[strlen(obj.id) + 1];
    strcpy(id, obj.id);

    rank = obj.rank;

    type = new char[strlen(obj.type) + 1];
    strcpy(type, obj.type);

    planet = obj.planet;
}

Stormtrooper& Stormtrooper::operator=(const Stormtrooper &obj) {
    if (this != &obj) {

        delete[] id;
        id = new char[strlen(obj.id) + 1];
        strcpy(id, obj.id);

        rank = obj.rank;

        delete[] type;
        type = new char[strlen(obj.type) + 1];
        strcpy(type, obj.type);

        planet = obj.planet;
    }
    return *this;
}

Stormtrooper::~Stormtrooper() {
    delete[] id;
    id = nullptr;

    delete[] type;
    type = nullptr;

}

const char* Stormtrooper::enumToString(Rank r) const {
    switch (r)
    {
    case Rank::TROOPER:
        return "TROOPER";
        break;
    case Rank::SERGEANT:
        return "SERGEANT";
    case Rank::SQUADLEADER:
        return "SQUADLEADER";
    case Rank::CHIEF:
        return "CHIEF";
    case Rank::CAPTAIN:
        return "CAPTAIN";
    default:
        return "Unknown";
        break;
    }
}

void Stormtrooper::print() const {
    std::cout << "Stormtrooper info: \n";
    std::cout << "ID: " << id << '\n';
    std::cout << "Rank: " << enumToString(rank) << '\n';
    std::cout << "Type: " << type;
}

void Stormtrooper::setId(char *id_) {
    delete[] id;
    id = new char[strlen(id_) + 1];
    strcpy(id, id_);
}

void Stormtrooper::setRank(Rank r) {
    rank = r;
}

void Stormtrooper::setType(char *type_) {
    delete[] type;
    type = new char[strlen(type_) + 1];
    strcpy(type, type_);
}

void Stormtrooper::setPlanet(const Planet &obj) {
    planet = obj;
}

