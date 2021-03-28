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

    BattleShip<Stormtrooper> b;
    std::cin >> b;
    
    print(b);

    return 0;
}
