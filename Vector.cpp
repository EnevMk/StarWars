#include "Vector.hpp"
#include "BattleShip.hpp"

template class Vector<int>;
template class Vector<double>;/* 
template class Vector<Definition>;
template class Vector<String>; */
//template class Vector<BattleShip<Jedi>>;
template class Vector<BattleShip<Stormtrooper>>;

template <typename T>
Vector<T>::Vector() {
    arr = new T[1];
    current = 0;
    capacity = 1;
}


template <typename T>
Vector<T>::Vector(const T *arr_, int count) {
    arr = new T[count];

    capacity = count;
    current = count;

    for (int i = 0; i < current; ++i) {
        arr[i] = arr_[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> &obj) {
    if(this != &obj) {
        capacity = obj.capacity;
        current = obj.current;

        delete[] arr;
        arr = new T[capacity];

        for (int i = 0; i < current; ++i) {
            arr[i] = obj.arr[i];
        }
    }
    return *this;
}

template <typename T>
Vector<T>::~Vector() {

    delete[] arr;
    current = 0;
    capacity = 0;
}


template <typename T>
void Vector<T>::push(T data) {
    if (current == capacity) {
        T *temp = new T[2 * capacity];

        for (int i = 0; i < current; ++i) {
            temp[i] = arr[i];
        }

        delete[] arr;
        capacity *= 2;
        arr = temp;
    }
    arr[current] = data;
    current++;

}

template <typename T>
void Vector<T>::popBack() {
    current--;
}

template <typename T>
void Vector<T>::removeAtIndex(const int index) {
    if (index < size()) {
        for (int i = index; i < size() - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        current--;
    }
}

template <typename T>
int Vector<T>::size() const{
    return current;
}

template <typename T>
int Vector<T>::maxCapacity() const {
    return capacity;
}

template <typename T>
T& Vector<T>::operator[](int index) const {
    return *(arr + index);
}

template <typename T>
void Vector<T>::reserve(unsigned n) {
    if (n > capacity) {
        T *temp = new T[n];

        for (int i = 0; i < current; ++i) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity = n;
    }
}

