#include <iostream>
#include <cassert>
#include "LList.hpp"
#include "String.hpp"

template class LList<int>;
template class LList<String>;

template <typename T>
LList<T>::LList():first(nullptr) {

}

template <typename T>
void LList<T>::push(const T &data_) {

    first = new box{data_, first};
}

template <typename T>
void LList<T>::pushBack(const T &data_) {
    box* crr = first;
    while (crr->next != nullptr) {
        crr = crr->next;
    }
    crr->next = new box{data_, crr->next};
}

template <typename T>
LList<T>::LList(T *ptr, size_t size_) {
    
    first = nullptr;

    for (int i = size_ - 1; i >= 0; --i) {
        push(ptr[i]);
    }
}

template<>
LList<int>::LList(const int x, const int y) {
    if (x <= y) {
        first = nullptr;
        for (int i = y; i >= x; --i) {

            first = new box{i, first};
        }
    }
}

template <typename T>
typename LList<T>::box* LList<T>::copy(box *pt) const {
    if (pt == nullptr) return pt;

    box *copied = new box{pt->data, copy(pt->next)};
    return copied;
}

template <typename T>
LList<T>::LList(const LList<T> &obj) {

    first = copy(obj.first);
}

template <typename T>
LList<T>& LList<T>::operator=(const LList<T> &obj) {
    if (this != &obj) {

        box *crr = first;

        while (crr != nullptr) {
            box *temp = crr->next;
            delete crr;
            crr = temp;
        }

        first = copy(obj.first);

    }
    return *this;
}

template <typename T>
typename LList<T>::box* LList<T>::locate(size_t i) const {
    box* crr = first;
    
    if (i > this->size()) return nullptr;

    i--;
    while (i != 0) {
        i--;
        crr = crr->next;
    }

    return crr;

}

template <typename T>
size_t LList<T>::size() const {

    box *crr = first;
    size_t cnt = 0;

    while (crr != nullptr) {
        cnt++;
        crr = crr->next;
    }

    return cnt;
}

template <typename T>
bool LList<T>::insertAt(size_t i, const T &data_) {

    if (i == 1 || i == 0) {
        push(data_);
        return true;
    }

    //box *ptr = first;
    size_t cnt = 1;
    size_t size_ = this->size();
    
    if (size_ < i) i == size_ + 1;

    box *ptr = locate(i-1);
    
    box *temp = ptr->next;
    ptr->next = new box{data_, temp};
    
    return true;
}

template <typename T>
T LList<T>::getAt(size_t i) const {
    box *crr = locate(i);

    assert(crr != nullptr);

    return crr->data;
}

template <typename T>
void LList<T>::pop() {
    box* temp;
    temp = first->next;

    delete first;
    first = temp;
}

template <typename T>
bool LList<T>::removeAt(size_t i) {

    if (i == 1) {
        pop();
        return true;
    }
    box *pred = locate(i-1);
    
    box *toBeDeleted = pred->next;
    pred->next = toBeDeleted->next;

    delete toBeDeleted;
    return true;

}

template <typename T>
void LList<T>::print() const {
    std::cout << '\n';
    for (int i = 1; i <= size(); ++i) {
        std::cout << locate(i)->data << '\n';
    }
}

template <typename T>
int LList<T>::count(const T x) {
    box* crr = first;
    int cnt = 0;

    while(crr != nullptr) {
        (crr->data == x) ? ++cnt : 1;
        crr = crr->next;
    }

    return cnt;
}

template <typename T>
void LList<T>::operator+=(const T& obj) {
    box *crr = first;

    while (crr->next != nullptr) {
        crr = crr->next;
    }

    crr->next = new box{obj, crr->next};
}

template <typename T>
const T& LList<T>::getIth(size_t i) const {
    assert(i <= size() && i > 0);
    box* ptr = first;
    i--;
    
    while (i != 0) {
        ptr = ptr->next;
        i--;
    }

    return ptr->data;
}

template <typename T>
void LList<T>::removeAll(const T x) {
    box* crr = first;

    if(crr->data == x) {
        first = crr->next;
        delete crr;
    }
    
    while (crr->next != nullptr) {

        if (crr->next->data == x) {
            box* temp = crr->next;
            crr->next = crr->next->next;
            delete temp;
        }
        crr = crr-> next;
    }
}

template <typename T>
void LList<T>::append(const LList<T> &obj) {

    box* last = locate(size());
    last->next = new box{obj.first->data, nullptr};
    last = last->next;

    box* crr = obj.first->next;

    while(crr != nullptr) {
        last->next = new box{crr->data, last->next};
        crr = crr->next;
        last = last->next;
    }
    
}

template <typename T>
LList<T>::~LList() {
    box *crr = first;

    while (crr != nullptr) {
        box *temp = crr->next;
        delete crr;
        crr = temp;
    }
}