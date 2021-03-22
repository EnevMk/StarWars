#include <iostream>
#include <cstring>
#include "Planet.hpp"

//template void print<Planet>(Planet);
PlanetType plTypeToEnum(char *str);

Planet::Planet() {

    name = nullptr;
    planetSystem = nullptr;
    republic = nullptr;
    pType = PlanetType::Unknown;
}

Planet::Planet(const char *name_, const char *planetSystem_, const char *republic_, const PlanetType plType) {

    name = new char[strlen(name_) + 1];
    planetSystem = new char[strlen(planetSystem_) + 1];
    republic = new char[strlen(republic_) + 1];

    strcpy(name, name_);
    strcpy(planetSystem, planetSystem_);
    strcpy(republic, republic_);
    pType = plType;
}

Planet::Planet(const Planet &obj) {
    name = new char[strlen(obj.name) + 1];
    planetSystem = new char[strlen(obj.planetSystem) + 1];
    republic = new char[strlen(obj.republic) + 1];
    
    strcpy(name, obj.getName());
    strcpy(planetSystem, obj.planetSystem);
    strcpy(republic, obj.republic);

    pType = obj.pType;
}

Planet& Planet::operator=(const Planet &obj) {
    if (this != &obj) {

        delete[] name;
        delete[] planetSystem;
        delete[] republic;

        name = new char[strlen(obj.name) + 1];
        planetSystem = new char[strlen(obj.planetSystem) + 1];
        republic = new char[strlen(obj.republic) + 1];

        strcpy(name, obj.getName());
        strcpy(planetSystem, obj.planetSystem);
        strcpy(republic, obj.republic);
        pType = obj.pType;
    }
    return *this;
}

Planet::~Planet() {
    delete[] name;
    name = nullptr;

    delete[] planetSystem;
    planetSystem = nullptr;
    
    delete[] republic;
    republic = nullptr;
}

char* Planet::getName() const {
    return name;
}
char* Planet::getPlanetSystem() const {
    return planetSystem;
}
char* Planet::getRepublic() const {
    return republic;
}
PlanetType Planet::getType() const {
    return pType;
}

void Planet::setName(const char *name_) {
    if (name != nullptr) {
        delete[] name;
    }
    name = new char[strlen(name_) + 1];
    strcpy(name, name_);
}

void Planet::setPlanetSystem(const char *planetSystem_) {
    if (planetSystem != nullptr) {
        delete[] planetSystem;
    }
    planetSystem = new char[strlen(planetSystem_) + 1];
    strcpy(planetSystem, planetSystem_);
}

void Planet::setRepublic(const char *republic_) {
    if (republic != nullptr) {
        delete[] republic;
    }
    republic = new char[strlen(republic_) + 1];
    strcpy(republic, republic_);
}

void Planet::setType(const PlanetType pt) {
    pType = pt;
}

std::ostream& operator<<(std::ostream &out, const Planet &obj) {
    out << "\nPlanet Name:" << obj.getName()
    <<"\nPlanet System: " << obj.planetSystem
    <<"\nRepublic: " << obj.republic<< '\n';
    
    out << "Planet type: " << obj.typeToString();

    return out;
}

std::istream& operator>>(std::istream &in, Planet &obj) {
    /* delete[] obj.name;
    delete[] obj.planetSystem;
    delete[] obj.republic; */

    const int maxLen = 20;

    char buffer[maxLen];
    
    in.getline(buffer, maxLen, '\n');
    /* obj.name = new char[strlen(buffer) + 1];
    strcpy(obj.name, buffer); */
    obj.setName(buffer);

    in.getline(buffer, maxLen, '\n');
    /* obj.planetSystem = new char[strlen(buffer) + 1];
    strcpy(obj.planetSystem, buffer); */
    obj.setPlanetSystem(buffer);

    in.getline(buffer, maxLen, '\n');
    /* obj.republic = new char[strlen(buffer) + 1];
    strcpy(obj.republic, buffer); */
    obj.setRepublic(buffer);

    /* in.clear();
    in.ignore(10000, '\n');

    in.getline(buffer, maxLen, '\n');
    obj.pType = plTypeToEnum(buffer);
    obj.pType = plTypeToEnum(buffer); */
    
    return in;
}

PlanetType plTypeToEnum(char *str) {
    toLower(str);

    if (!strcmp(str, "chthonian")) return PlanetType::Chthonian;

    if (!strcmp(str, "carbon")) return PlanetType::Carbon;

    if (!strcmp(str, "coreless")) return PlanetType::Coreless;

    if (!strcmp(str, "desert")) return PlanetType::Desert;

    if (!strcmp(str, "gasdwarf")) return PlanetType::GasDwarf;

    if (!strcmp(str, "gasgiant")) return PlanetType::GasGiant;

    if (!strcmp(str, "helium")) return PlanetType::Helium;

    if (!strcmp(str, "icegiant")) return PlanetType::IceGiant;

    if (!strcmp(str, "ice")) return PlanetType::Ice;

    if (!strcmp(str, "iron")) return PlanetType::Iron;

    if (!strcmp(str, "lava")) return PlanetType::Lava;

    if (!strcmp(str, "ocean")) return PlanetType::Ocean;

    if (!strcmp(str, "protoplanet")) return PlanetType::Protoplanet;

    if (!strcmp(str, "puffy")) return PlanetType::Puffy;

    if (!strcmp(str, "silicate")) return PlanetType::Silicate;

    if (!strcmp(str, "terrestrial")) return PlanetType::Terrestrial;
    
    return PlanetType::Unknown;
}

const char* Planet::typeToString() const {
    
    switch (pType)
    {
    case PlanetType::Chthonian:
        return "Chtonian";
        
    case PlanetType::Coreless:
        return "Coreless";

    case PlanetType::Desert:
        return "Desert";

    case PlanetType::GasDwarf:
        return "GasDwarf";

    case PlanetType::GasGiant:
        return "GasGiant";

    case PlanetType::Helium:
        return "Helium";

    case PlanetType::Ice:
        return "Ice";

    case PlanetType::IceGiant:
        return "IceGiant";

    case PlanetType::Iron:
        return "Iron";

    case PlanetType::Lava:
        return "Lava";

    case PlanetType::Ocean:
        return "Ocean";

    case PlanetType::Protoplanet:
        return "Protoplanet";

    case PlanetType::Puffy:
        return "Puffy";

    case PlanetType::Silicate:
        return "Silicate";

    case PlanetType::Terrestrial:
        return "Terrestrial";

    default:
        return "Unknown";
    }
}