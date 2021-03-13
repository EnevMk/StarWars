#pragma once

class Planet {
private:
    char *name;
    char *planetSystem;
    char *republic;

public:
    Planet();
    Planet(const char *name_, const char *planetSystem_,const char *republic_);
    Planet(const Planet &obj);
    Planet& operator=(const Planet &obj);
    ~Planet();
    void print() const;
    char* getName() const;
    char* getPlanetSystem() const;
    char* getRepublic() const;
    void setName(char* name_);
    void setPlanetSystem(char* planetSystem_);
    void setRepublic(char* republic_);
};