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

template <typename T>
void removeWeakShips(Vector<BattleShip<T>> &obj) {
    size_t cnt = obj.size();
    size_t armoryAverage = 0;

    for (size_t i = 0; i < cnt; ++i) { 
        armoryAverage += obj[i].getArmoryLevel();
    }
    armoryAverage /= cnt;

    for (size_t i = 0; i < cnt; ++i) {

        if (obj[i].getArmoryLevel() < armoryAverage) {
            obj.removeAtIndex(i);
            i--;
            cnt--;
        }
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
    korabi.push(j2);
    korabi.push(j1);

    //std::cout << "\n\n" << enumToString(korabi[2].getAmmoLevel());

    String h = "Heavy";
    map(korabi, &BattleShip<Stormtrooper>::setAmmoLevel, h);

    std::cout << korabi.size();
    removeWeakShips(korabi);

    std::cout << korabi.size() << '\n';

    for (int i = 0; i < korabi.size(); ++i) {
        std::cout << korabi[i];
    }

    return 0;
}
