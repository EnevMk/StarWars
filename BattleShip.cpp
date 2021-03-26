#include <iostream>
#include "BattleShip.hpp"

/* template <typename T>
template void print<BattleShip<T>(BattleShip<T>) */
//template void print<Stormtrooper>(Stormtrooper)

template <typename T>
BattleShip<T>::BattleShip() {
    velocity = 0;
    weaponsCount = 0;
    hyperSpaceJump = false;
}
template <typename T>
BattleShip<T>::BattleShip(const double vel_, const unsigned weapons_, const bool jump, const double size_, const T& pilot_) {
    velocity = vel_;
    weaponsCount = weapons_;
    hyperSpaceJump = jump;
    size = size_;
    pilot = pilot_;
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
