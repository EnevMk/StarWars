#include <iostream>
#include <cstring>
#include "Planet.hpp"

char* Planet::getName() const {
    return name;
}
char* Planet::getPlanetSystem() const {
    return planetSystem;
}
char* Planet::getRepublic() const {
    return republic;
}

void Planet::setName(const char *name_) {
    delete[] name;
    name = new char[strlen(name_) + 1];
    strcpy(name, name_);
}

void Planet::setPlanetSystem(const char *planetSystem_) {
    delete[] planetSystem;
    planetSystem = new char[strlen(planetSystem_) + 1];
    strcpy(planetSystem, planetSystem_);
}

void Planet::setRepublic(const char *republic_) {
    delete[] republic;
    republic = new char[strlen(republic) + 1];
    strcpy(republic, republic_);
}

Planet::Planet() {

    char name_[] = "Bulgaria";
    char planetSystem_[] = "Solar";
    char republic_[] = "Bulgaria";
    
    name = new char[strlen(name_) + 1];
    planetSystem = new char[strlen(planetSystem_) + 1];
    republic = new char[strlen(republic_) + 1];

    strcpy(name, name_);
    strcpy(planetSystem, planetSystem_);
    strcpy(republic, republic_);
}

Planet::Planet(const char *name_, const char *planetSystem_, const char *republic_) {

    name = new char[strlen(name_) + 1];
    planetSystem = new char[strlen(planetSystem_) + 1];
    republic = new char[strlen(republic_) + 1];

    strcpy(name, name_);
    strcpy(planetSystem, planetSystem_);
    strcpy(republic, republic_);
}

Planet::Planet(const Planet &obj) {
    name = new char[strlen(obj.name) + 1];
    planetSystem = new char[strlen(obj.planetSystem) + 1];
    republic = new char[strlen(obj.republic) + 1];

    strcpy(name, obj.getName());
    strcpy(planetSystem, obj.planetSystem);
    strcpy(republic, obj.republic);
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

void Planet::print() const {
    std::cout << "\nPlanet Information: \n";
    std::cout << "Name: " << name << '\n';
    std::cout << "Planet System: " << planetSystem << '\n';
    std::cout << "Republic: " << republic << '\n';
}