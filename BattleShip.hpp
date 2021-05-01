#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP
//#include <cstring>
#include "Planet.hpp"
#include "Stormtrooper.hpp"
#include "Jedi.hpp"
#include "Vector.hpp"


/* template <typename T>
class BattleShip;

template <typename T>
std::ostream& operator<<(std::ostream&, const BattleShip<T> &obj); */

enum class TypeIdentifier {
    Jedi,
    Stormtrooper,
    Invalid
};

enum class Ammunition {
    Light,
    Medium,
    Heavy,
    Invalid
};

Ammunition stringToEnum(String str) {
    str.toLower();
    if (str == "light") return Ammunition::Light;
    if (str == "medium") return Ammunition::Medium;
    if (str == "heavy") return Ammunition::Heavy;
    return Ammunition::Invalid;
}

String enumToString(Ammunition ammo_) {
    switch (ammo_)
    {
        case Ammunition::Light : return "Light";
        case Ammunition::Medium : return "Medium";
        case Ammunition::Heavy : return "Heavy";
        default: return "Invalid";
    }
}

template <typename T>
class BattleShip {

private:

    double velocity;
    unsigned weaponsCount;
    bool hyperSpaceJump;
    double size;
    T pilot;
    double fuel;
    Ammunition level;
    size_t armory;
    
public:

    BattleShip();
    BattleShip(const double vel_, const unsigned weapons_, const bool jump, const double size_, 
               const T& pilot_, const double fuel_, const String ammo_, const size_t armory_);
    //default constructors will do the job.
    //~BattleShip();
    double getVelocity() const;
    unsigned getWeaponsCount() const;
    bool getHyperJump() const;
    double getSize() const;
    const T& getPilot() const;
    double getFuel() const;
    Ammunition getAmmoLevel() const;
    size_t getArmoryLevel() const;
    void setVelocity(const double vel_);
    void setWeaponsCount(const unsigned cnt_);
    void setJumpAbility(const bool b);
    void setSize(const double size_);
    void setPilot(const T &obj);
    void setFuel(const double fuel_);
    void setAmmoLevel(const String ammo_);
    void setArmoryLevel(const size_t armory_);
    //String getAmmoLevelString();

    //friend std::ostream& operator<< (std::ostream &os, const BattleShip &obj);
    
    friend std::ostream& operator<< (std::ostream &os, const BattleShip<T> &obj) {

        os << "\nBattleship velocity: " << obj.getVelocity()
        << "\nWeapons count: " << obj.getWeaponsCount()
        << "\nHyperspace Jumps: " << std::boolalpha << obj.getHyperJump()
        << "\nShip size: " << obj.getSize()
        << "\nFuel amount: " << obj.getFuel()
        << "\n Ammunition level: " << enumToString(obj.getAmmoLevel())
        << "\n Armory level: " << obj.armory;

        print(obj.getPilot());
        std::cout << "\n\n";
        
        return os;
    }
    //friend std::ostream& operator<<(std::ostream &os, const BattleShip<Stormtrooper> &obj);
    //friend std::ostream& operator<<(std::ostream &os, const BattleShip<Jedi> &obj);
    friend std::istream& operator>>(std::istream &is, BattleShip<T> &obj) {
        double vel;
        is >> vel;
        obj.setVelocity(vel);

        unsigned weaponsCount_;
        is >> weaponsCount_;
        obj.setWeaponsCount(weaponsCount_);

        bool hyperJump;
        is >> hyperJump;
        obj.setJumpAbility(hyperJump);

        double size_;
        is >> size_;
        obj.setSize(size_);

        is.clear();
        is.ignore(10000, '\n');

        is >> obj.pilot;

        return is;
    }
    
};
//explicit instantiation
template class BattleShip<Stormtrooper>;
template class BattleShip<Jedi>;

/* template<typename T>
std::ostream& operator<<(std::ostream &os, const BattleShip<T> &obj) {

    os << "\nBattleship velocity: " << obj.getVelocity()
    << "\nWeapons count: " << obj.getWeaponsCount()
    << "\nHyperspace Jumps: " << std::boolalpha << obj.getHyperJump()
    << "\nShip size: " << obj.getSize()
    << "\nFuel amount: " << obj.getFuel()
    //<< "\n Ammunition level: " << enumAmmoToString(obj.level)
    << "\n Armory level: " << obj.armory;

    print(obj.getPilot());

    return os;
} */
//template std::ostream& operator<<(std::ostream &os, const BattleShip<Stormtrooper> &obj);


/* inline Ammunition stringToEnum(String str) {
    str.toLower();
    if (str == "light") return Ammunition::Light;
    if (str == "medium") return Ammunition::Medium;
    if (str == "heavy") return Ammunition::Heavy;
    return Ammunition::Invalid;
} */

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

template <typename T>
Ammunition BattleShip<T>::getAmmoLevel() const {
    return this->level;
}

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
    
    double velocityChangeCoef = 0.15 * ((int)newAmmo - (int)level) * velocity;
    velocity -= velocityChangeCoef;

    level = newAmmo;
}

template <typename T>
void BattleShip<T>::setArmoryLevel(const size_t armory_) {
    if (armory_ < 0 || armory_ > 100) return;

    armory = armory_;
}
/* template <typename T>
String BattleShip<T>::getAmmoLevelString() {
    switch (this->level)
    {
    case Ammunition::Light : return "Light";
    case Ammunition::Medium : return "Medium";
    case Ammunition::Heavy : return "Heavy";
    default: return "Invalid";
    }
} */
#endif