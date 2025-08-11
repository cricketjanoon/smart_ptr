#include <iostream>
#include <cassert>
#include <smart_ptr.hpp>

using namespace CJ;

class Person {
public:
    std::string name;
    size_t age;
    Person(const std::string& n, const size_t a) : name(n), age(a) {
        std::cout << "Person created: " << name << ", Age: " << age << std::endl;
    }
    ~Person() {
        std::cout << "Person destroyed: " << name << std::endl;
    }
};

int main() {

    smart_ptr<Person> ptr(new Person("Shahbaz", 30));
    
    return 0;
}