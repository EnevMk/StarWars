#include <iostream>
#include <cstring>
#include "Planet.hpp"
#include "Stormtrooper.hpp"
#include "Jedi.hpp"

int main() {
    
    std::cout << "C++ gives me nightmares.\n";

    Stormtrooper st;
    std::cout << (st.getPlanet().getName() == nullptr);
    
    std::cin >> st;

    std::cout << "\n\ntry the print foo\n\n";
    print(st);
    return 0;
}
