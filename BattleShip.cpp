#include <iostream>
#include "BattleShip.hpp"

/* template <typename T>
template void print<BattleShip<T>(BattleShip<T>) */
//template void print<Stormtrooper>(Stormtrooper)

Ammunition stringToEnum(String str) {
    str.toLower();
    if (str == "light") return Ammunition::Light;
    if (str == "medium") return Ammunition::Medium;
    if (str == "heavy") return Ammunition::Heavy;
    return Ammunition::Invalid;
}

template <typename T>
BattleShip<T>::BattleShip():pilot() {
    velocity = 0;
    weaponsCount = 0;
    hyperSpaceJump = false;
    fuel = 0;
    level = Ammunition::Invalid;
    armory = 0;
}
template <typename T>
BattleShip<T>::BattleShip(const double vel_, const unsigned weapons_, const bool jump, const double size_, 
                          const T& pilot_, const double fuel_, const String ammo_, const size_t armory_) {
    velocity = vel_;
    weaponsCount = weapons_;
    hyperSpaceJump = jump;
    size = size_;
    pilot = pilot_;
    fuel = fuel_;
    level = stringToEnum(ammo_);
    armory = (armory_ >= 100) ? 100 : armory_;
}

template <typename T>
double BattleShip<T>::getVelocity() const {
    return velocity;
}

template <typename T>
unsigned BattleShip<T>::getWeaponsCount() const {
    return weaponsCount;
}

template <typename T>
bool BattleShip<T>::getHyperJump() const {
    return hyperSpaceJump;
}

template <typename T>
double BattleShip<T>::getSize() const {
    return size;
}

template <typename T>
const T& BattleShip<T>::getPilot() const {
    return pilot;
}

template <typename T>
double BattleShip<T>::getFuel() const {
    return fuel;
}

/* template <typename T>
String BattleShip<T>::getAmmoLevel() const {
    return enumToString(this->level);
} */

template <typename T>
size_t BattleShip<T>::getArmoryLevel() const {
    return armory;
}

template <typename T>
void BattleShip<T>::setVelocity(const double vel_) {
    velocity = vel_;
}

template <typename T>
void BattleShip<T>::setWeaponsCount(const unsigned cnt_) {
    weaponsCount = cnt_;
}

template <typename T>
void BattleShip<T>::setJumpAbility(const bool b) {
    hyperSpaceJump = b;
}

template <typename T>
void BattleShip<T>::setSize(const double size_) {
    size = size_;
}

template <typename T>
void BattleShip<T>::setPilot(const T &obj) {
    pilot = obj;
}

template <typename T>
void BattleShip<T>::setFuel(const double fuel_) {
    fuel = (fuel_ > 300) ? 300 : fuel_;
    fuel = (fuel < 0) ? 0 : fuel;
}

template <typename T>
void BattleShip<T>::setAmmoLevel(const String ammo_) {
    Ammunition newAmmo = stringToEnum(ammo_);
    
    if (this->level == Ammunition::Invalid) {
        level = newAmmo;
        return;
    }

    size_t velocityChangeCoef = 0.15 * ((int)newAmmo - (int)level) * velocity;
    velocity -= velocityChangeCoef;
}