#include <iostream>
//#include <cstring>
#include "Planet.hpp"
#include "Stormtrooper.hpp"
#include "Jedi.hpp"
#include "BattleShip.hpp"
#include "String.hpp"
#include "Vector.hpp"


template <typename T, typename V, typename W>
void map(Vector<T> &obj, void (BattleShip<V>::*ptr)(W), W w) {
    for (size_t i = 0; i < obj.size(); ++i) {
        (obj[i].*ptr) (w);
    }
}

int main() {
    
    std::cout << "C++ gives me nightmares.\n";

    Stormtrooper st;
    st.setId("ST109");
    st.setRank(Rank::SERGEANT);
    st.setType("desert");
    //std::cin >> st;

    
    Vector<BattleShip<Stormtrooper>> korabi;
    BattleShip<Stormtrooper> j (12000, 5, 0, 45, st, 60, "Heavy", 70);
    BattleShip<Stormtrooper> j1(15000, 3, 1, 35, st, 60, "Medium", 55);
    BattleShip<Stormtrooper> j2(17000, 2, 1, 20, st, 60, "Light", 40);
    korabi.push(j);
    korabi.push(j1);
    korabi.push(j2);

    std::cout << "\n\n" << enumToString(korabi[2].getAmmoLevel());

    String h = "Heavy";
    map(korabi, &BattleShip<Stormtrooper>::setAmmoLevel, h);

    for (int i = 0; i < 3; ++i) {
        std::cout << korabi[i];
    }

    std::cout << '\n' << korabi[2].getVelocity();

    std::cout << '\n' << enumToString(korabi[2].getAmmoLevel());

    std::cout << '\n' << korabi[2].getFuel();
    return 0;
}
