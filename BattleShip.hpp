#pragma once
#include "Planet.hpp"
#include "Stormtrooper.hpp"
#include "Jedi.hpp"

template <typename T>
class BattleShip {

private:

    double velocity;
    unsigned weaponsCount;
    bool hyperSpaceJump;
    double size;
    T pilot;

public:
    BattleShip();
    BattleShip(const double vel_, const unsigned weapons_, const bool jump, const double size_, const T& pilot_);
    //default constructors will do the job.
    //~BattleShip();
    double getVelocity() const;
    unsigned getWeaponsCount() const;
    bool getHyperJump() const;
    double getSize() const;
    const T& getPilot() const;
    void setVelocity(const double vel_);
    void setWeaponsCount(const unsigned cnt_);
    void setJumpAbility(const bool b);
    void setSize(const double size_);
    void setPilot(const T &obj);

    friend std::ostream& operator<<(std::ostream &os, const BattleShip<T> &obj) {

        os << "\nBattleship velocity: " << obj.getVelocity()
        << "\nWeapons count: " << obj.getWeaponsCount()
        << "\nHyperspace Jumps " << std::boolalpha << obj.getHyperJump()
        << "\nShip size: " << obj.getSize();
        //<< "Pilot: " << obj.getPilot() << '\n';

        print(obj.getPilot());

        return os;
    }
    //friend std::ostream& operator<<(std::ostream &os, const BattleShip<Stormtrooper> &obj);
    //friend std::ostream& operator<<(std::ostream &os, const BattleShip<Jedi> &obj);
    
};
//explicit instantiation
template class BattleShip<Stormtrooper>;
template class BattleShip<Jedi>;
