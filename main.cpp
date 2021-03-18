#include <iostream>
#include "Planet.hpp"
#include "Stormtrooper.hpp"
#include "Jedi.hpp"

int main() {
    Jedi *anakin = new Jedi;
    
    anakin->setRank(JediRank::Master);
    
    print(*anakin);
    delete anakin;
    
    std::cout << "C++ gives me nightmares.\n";
    return 0;
}