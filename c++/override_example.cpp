#include <iostream>

class Base {
public:
    virtual void Print() const {
        std::cout << "Base::Print()" << std::endl;
    }

    virtual void Display() const {
        std::cout << "Base::Display()" << std::endl;
    }
};

class Derived : public Base {
public:
    void Print() const override {
        std::cout << "Derived::Print()" << std::endl;
    }

    // Error: Trying to override a non-virtual function
    // void Display() const override {
    //     std::cout << "Derived::Display()" << std::endl;
    // }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    // Call the overridden functions
    baseObj.Print();    // Output: Base::Print()
    derivedObj.Print(); // Output: Derived::Print()

    // Call the base class function
    baseObj.Display();    // Output: Base::Display()

    return 0;
}
