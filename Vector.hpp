#ifndef VECTOR_HPP
#define VECTOR_HPP

template <typename T>
class Vector {

private:
    T *arr;
    int current;
    int capacity;

public:
    Vector();
    Vector(const T *arr_[], int count);
    Vector(const T *arr_, int count);
    Vector<T>& operator=(const Vector<T> &obj);
    void push(T data);
    //void push(T data, int index);
    void popBack();
    void removeAtIndex(const int index);
    int size() const;
    int maxCapacity() const;
    T& operator[](int index) const;
    void reserve(unsigned n);
    ~Vector();
    
};

#endif