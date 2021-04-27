#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP
#include <cstring>
#include "Planet.hpp"
#include "Stormtrooper.hpp"
#include "Jedi.hpp"

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

/* String enumToString(Ammunition ammo_) {
    switch (ammo_)
    {
    case Ammunition::Light : return "Light";
    case Ammunition::Medium : return "Medium";
    case Ammunition::Heavy : return "Heavy";
    default: return "Invalid";
    }
} */

inline TypeIdentifier eval(char* buff) {
    toLower(buff);

    if (!strcmp(buff, "jedi")) return TypeIdentifier::Jedi;

    if (!strcmp(buff, "stormtrooper")) return TypeIdentifier::Stormtrooper;

    return TypeIdentifier::Invalid;
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
    
    //Ammunition stringToEnum(const String str);

public:
    /* template <typename T>
    typedef void (BattleShip<T>::*fptr)(String); */

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
    String getAmmoLevel() const;
    size_t getArmoryLevel() const;
    void setVelocity(const double vel_);
    void setWeaponsCount(const unsigned cnt_);
    void setJumpAbility(const bool b);
    void setSize(const double size_);
    void setPilot(const T &obj);
    void setFuel(const double fuel_);
    void setAmmoLevel(const String ammo_);
    void setArmoryLevel(const size_t armory_);

    friend std::ostream& operator<<(std::ostream &os, const BattleShip<T> &obj) {

        os << "\nBattleship velocity: " << obj.getVelocity()
        << "\nWeapons count: " << obj.getWeaponsCount()
        << "\nHyperspace Jumps: " << std::boolalpha << obj.getHyperJump()
        << "\nShip size: " << obj.getSize()
        << "\nFuel amount: " << obj.getFuel()
        //<< "\n Ammunition level: " << enumToString(obj.level)
        << "\n Armory level: " << obj.armory;

        print(obj.getPilot());

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

#endif