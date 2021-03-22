#include <iostream>
#include <cstring>
#include "Planet.hpp"
#include "Stormtrooper.hpp"
#include "Jedi.hpp"

int main() {
    
    std::cout << "C++ gives me nightmares.\n";

    Planet earth;
    std::cin >> earth;

    std::cout << "\ntesting print foo\n";
    print(earth);
    return 0;
}
