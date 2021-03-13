#include <iostream>
#include <cstring>

#include "Planet.hpp"
#include "Stormtrooper.hpp"
#include "Jedi.hpp"

std::ostream& operator<<(std::ostream& out, Jedi &obj);

int main() {
    Planet p;
    
    Jedi *anakin = new Jedi;
    std::cout << *anakin;
    anakin->setRank(JediRank::Master);
    std::cout << *anakin;
    delete anakin;
    
    return 0;
}

std::ostream& operator<<(std::ostream& out, Jedi &obj) {

    out << "\nJedi Info:\n";
    out << "Name: " << obj.getName()
    << "\nRank: " << obj.enumToString(obj.getRank())
    << "\nMidi-Chlorian: " << obj.getMidiChlorian() << '\n';

    obj.getPlanet().print();

    out <<"\nSpicies: " << obj.getSpicies()
    << "\nmilitary Rank: " << obj.getMilitaryRank() << '\n';

    return out;
}