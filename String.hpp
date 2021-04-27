#ifndef STRING_HPP
#define STRING_HPP
#include <iostream>

class String {

private:
    char *str;
    
public:
    String();
    String(const char *str_);
    String(const String &obj);
    String& operator=(const String &obj);
    ~String();
    String operator+(const String &obj);
    bool operator==(const String &obj);
    void toLower();
    int size() const;
    char* getStr() const;
    void setStr(const char *str_);

    friend std::ostream& operator<<(std::ostream& os, const String &obj);
};

#endif