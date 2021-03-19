#pragma once

enum class PlanetType {
    Chthonian,
    Carbon,
    Coreless,
    Desert,
    GasDwarf,
    GasGiant,
    Helium,
    IceGiant,
    Ice,
    Iron,
    Lava,
    Ocean,
    Protoplanet,
    Puffy,
    Silicate,
    Terrestrial,
    Unknown
};

class Planet {
private:
    char *name;
    char *planetSystem;
    char *republic;
    PlanetType pType;
    
public:
    Planet();
    Planet(const char *name_, const char *planetSystem_,const char *republic_, const PlanetType plType);
    Planet(const Planet &obj);
    Planet& operator=(const Planet &obj);
    ~Planet();
    //void print() const;
    char* getName() const;
    char* getPlanetSystem() const;
    char* getRepublic() const;
    PlanetType getType() const;
    void setName(const char* name_);
    void setPlanetSystem(const char* planetSystem_);
    void setRepublic(const char* republic_);
    void setType(const PlanetType pt);
    const char* typeToString() const;    

    friend std::ostream& operator<<(std::ostream &out, const Planet &obj);
    friend std::istream& operator>>(std::istream &in, Planet &obj);
};

template<typename T>
void print(T obj) {
    std::cout << obj;
}




