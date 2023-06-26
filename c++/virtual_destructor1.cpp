#include <iostream>

/*
    Declare the destructor in the base class as virtual. 
    This ensures that when deleting an object through a pointer to the base class, 
    the destructor of the derived class is called as well.
    If any class in the hierarchy is intended to be used as a base class, 
    it's recommended to make its destructor virtual, 
    even if it's not explicitly necessary for the current implementation.
*/

class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor called" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() override {
        std::cout << "Derived destructor called" << std::endl;
    }
};

int main() {
    Base* basePtr = new Derived();
    delete basePtr;
    return 0;
}
