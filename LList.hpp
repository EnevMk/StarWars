#ifndef LLIST_HPP
#define LLIST_HPP

template <typename T>
class LList {

private:

    struct box {
        T data;
        box *next;
    };
    
    box *first;

    box* locate(size_t i) const;
    box* copy(box *pt) const;

public:
    
    LList();
    LList(T *ptr, size_t size_);
    LList(const int x, const int y);
    LList(const LList<T> &obj);
    LList<T>& operator=(const LList<T> &obj);
    void push(const T &data);
    void pushBack(const T &data);
    bool insertAt(size_t i, const T &data_);
    T getAt(size_t i) const;
    void pop();
    bool removeAt(size_t i);
    size_t size() const;
    void print() const;
    int count(const T x);
    void operator+=(const T& obj);
    const T& getIth(size_t i) const;
    //new
    void removeAll(const T x);
    void append(const LList<T> &obj);
    void concat(const LList<T> &obj);
    LList<T> operator+(const LList<T> &obj);
    LList<T>& operator+=(const LList<T> &obj);
    ~LList();
};
#endif