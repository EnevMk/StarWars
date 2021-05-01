#include <iostream>
#include <typeinfo>
//#include <cstring>
#include "Planet.hpp"
#include "Stormtrooper.hpp"
#include "Jedi.hpp"
#include "BattleShip.hpp"
#include "String.hpp"
#include "Vector.hpp"
#include "LList.hpp"

template <typename T>
void removeWeakShips(Vector<BattleShip<T>> &obj, LList<String> &activityLog_) {
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

    activityLog_.pushBack("removed weak ships");
}

template <typename V, typename W>
void map(Vector<BattleShip<V>> &obj, void (BattleShip<V>::*ptr)(W), W funcArg, LList<String> &activityLog_) {

    String test = "HH";
    double num = 2.5;

    for (size_t i = 0; i < obj.size(); ++i) {
        (obj[i].*ptr) (funcArg);
    }

    if (/* ptr == &BattleShip<Stormtrooper>::setAmmoLevel */ typeid(W).name() == typeid(test).name()) {

        activityLog_.pushBack("Changed ammunition level");
        //std::cout << "Cool\n";
    } 
    else if (/* ptr == &BattleShip<Stormtrooper>::setFuel */ typeid(W).name() == typeid(num).name()) {
        activityLog_.pushBack("Fuel recharged");
    }
    
}

int main() {
    
    std::cout << "\nC++ gives me nightmares.\n";

    LList<String> activityLog;
    activityLog.push("ACTIVITY LOG TEST");
    
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
    String h2 = "Light";
    map(korabi, &BattleShip<Stormtrooper>::setFuel, 165.0, activityLog);

    std::cout << korabi.size();
    removeWeakShips(korabi, activityLog);

    //std::cout << korabi.size() << '\n';

    /* for (int i = 0; i < korabi.size(); ++i) {
        std::cout << korabi[i];
    } */

    activityLog.print();

    //std::cout << (typeid(h).name() == String);
    
    return 0;
}
