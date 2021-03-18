#pragma once

class Planet {
private:
    char *name;
    char *planetSystem;
    char *republic;
    void msg();
    
public:
    Planet();
    Planet(const char *name_, const char *planetSystem_,const char *republic_);
    Planet(const Planet &obj);
    Planet& operator=(const Planet &obj);
    ~Planet();
    //void print() const;
    char* getName() const;
    char* getPlanetSystem() const;
    char* getRepublic() const;
    void setName(const char* name_);
    void setPlanetSystem(const char* planetSystem_);
    void setRepublic(const char* republic_);

    friend std::ostream& operator<<(std::ostream &out, const Planet &obj) {
        out << "\nPlanet Name:" << obj.name
        <<"\nPlanet System: " << obj.planetSystem
        <<"\nRepublic: " << obj.republic<< '\n';

        return out;
    }
};

template<typename T>
void print(T obj) {
    std::cout << obj;
}




