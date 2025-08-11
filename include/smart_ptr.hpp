#ifndef SMART_PTR_HPP
#define SMART_PTR_HPP

#include <iostream>

namespace CJ {

class RefCount {
private:
    int count;
public:
    RefCount() : count(0) {}
    void AddRef() { count++; }
    void RemRef() { count--; }
    int GetCount() const { return count; }
};

template <typename T>
class smart_ptr {
private:
    T* ptr;
    RefCount* refCount;
public:

    smart_ptr() : ptr(nullptr), refCount(new RefCount()) {
        refCount->AddRef();
    }

    smart_ptr(T* t) : ptr(t), refCount(new RefCount()) {
        refCount->AddRef();
    }

    smart_ptr(const smart_ptr<T>& other) : ptr(other.ptr), refCount(other.refCount) {
        refCount->AddRef();
    }
    
    smart_ptr<T>& operator=(const smart_ptr<T>& other) {
        if (this != &other) {
            // this check is if current object is already pointing to someother object, so free it if needed
            refCount->RemRef();
            if (refCount->GetCount() == 0) {
                delete ptr;
                delete refCount;
            }

            ptr = other.ptr;
            refCount = other.refCount;
            refCount->AddRef();
        }
        return *this;
    }

    T& operator*() { // Dereference operator
        return *ptr;
    } 
    
    T* operator->() { // Member access operator
        return ptr; 
    }
    
    ~smart_ptr() {
        refCount->RemRef();
        if (refCount->GetCount() == 0) {
            delete ptr;
            delete refCount;
        }
    }

};

}

/*
Usage Example:
#include "smart_ptr.hpp"

class Person {
public:
    std::string name;
    Person(const std::string& n) : name(n) {}
}

smart_ptr<Person> ptr = new smart_ptr(new Person("Shahbaz")); // paramter constructor
smart_ptr<Person> ptr2 = ptr; // copy constructor
smart_ptr<Person> ptr3(ptr2); // copy constructor
smart_ptr<Person> ptr4; // parameter less constructor
ptr4=ptr3; // copy assignment
~ destructor

-> member access operator 

*/

#endif // SMART_PTR_HPP