#include <iostream>
#include <cstring>
#include "Planet.hpp"
#include "Stormtrooper.hpp"
#include "Jedi.hpp"

int main() {
    
    std::cout << "C++ gives me nightmares.\n";

    Stormtrooper st;
    std::cin >> st;

    std::cout << "\ntesting print foo\n";
    print(st);
    return 0;
}
