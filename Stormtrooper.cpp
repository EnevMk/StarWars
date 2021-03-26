#include <iostream>
#include <cstring>
#include "Stormtrooper.hpp"

//template void print<Stormtrooper>(Stormtrooper);
Rank toEnum (char *str);

Stormtrooper::Stormtrooper() {
    id = nullptr;
    rank = Rank::Unknown;
    type = nullptr;

    this->setPlanet({"unknown", "unknown", "unknown", PlanetType::Unknown});

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

void Stormtrooper::setId(const char *id_) {
    delete[] id;
    id = new char[strlen(id_) + 1];
    strcpy(id, id_);
}

void Stormtrooper::setRank(Rank r) {
    rank = r;
}

void Stormtrooper::setType(const char *type_) {
    delete[] type;
    type = new char[strlen(type_) + 1];
    strcpy(type, type_);
}

void Stormtrooper::setPlanet(const Planet &obj) {
    planet = obj;
}

std::ostream& operator<<(std::ostream &out, const Stormtrooper &obj) {

    out << "Id: " << obj.id 
    << "\nRank: " << obj.enumToString(obj.getRank())
    << "\nType: " << obj.getType();
    
    out << obj.getPlanet();
        
    return out;
}

std::istream& operator>>(std::istream &in, Stormtrooper &obj) {

    const int maxLen = 20;
    char buff[maxLen];

    in.getline(buff, maxLen, '\n');
    obj.setId(buff);

    in.getline(buff, maxLen, '\n');
    obj.rank = toEnum(buff);

    in.getline(buff, maxLen, '\n');
    obj.setType(buff);

    in.getline(buff, maxLen, '\n');
    obj.planet.setName(buff);

    return in;
}

Rank toEnum (char *str) {
    toLower(str);

    if(!strcmp(str, "trooper")) return Rank::TROOPER;

    if(!strcmp(str, "sergeant")) return Rank::SERGEANT;

    if(!strcmp(str, "squadleader")) return Rank::SQUADLEADER;

    if(!strcmp(str, "chief")) return Rank::CHIEF;

    if(!strcmp(str, "captain")) return Rank::CAPTAIN;

    return Rank::Unknown;
}

const char* Stormtrooper::enumToString(Rank r) const {
    switch (r)
    {
    case Rank::TROOPER:
        return "TROOPER";
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
    }
}