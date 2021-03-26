#include <iostream>
#include <cstring>
#include "Planet.hpp"
#include "Stormtrooper.hpp"
#include "Jedi.hpp"
#include "BattleShip.hpp"

int main() {
    
    std::cout << "C++ gives me nightmares.\n";

    Stormtrooper st;
    st.setId("ST109");
    st.setRank(Rank::SERGEANT);
    st.setType("desert");
    //std::cin >> st;

    BattleShip<Stormtrooper> b(13, 5, 1, 100, st);
    print(b);

    /* std::cout << "\ntesting print foo\n";
    print(st); */
    return 0;
}
