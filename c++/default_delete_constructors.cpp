#include <iostream>
#include <utility>
using namespace std;

#define DONT_USE_CUSTOM 0

class A {
public:
    A(int x): m(x) {
    }

#if DONT_USE_CUSTOM	
    // Delete the copy constructor
    A(const A&) = default; //Change default to delete to view error

    // Delete the copy assignment operator
    A& operator=(const A&) = default; //Change default to delete to view error

    // Delete the move constructor
    A(A&& other) = default; //Change default to delete to view error

    // Delete the move assignment constructor
    A& operator=(A&& other) = default; //Change default to delete to view error

#else	
    // Custom constructors

    // Copy constructor
    A(const A& other) {
        std::cout << "custom copy constructor" << std::endl;
        m = other.m;
    }

    // Copy assignment operator
    A& operator=(const A& other) {
        std::cout << "custom copy assignment constructor" << std::endl;
        if (this != &other) {
            m = other.m;
        }
        return *this;
    }

    // Move constructor
    A(A&& other) noexcept {
        std::cout << "custom move constructor" << std::endl;
        m = std::exchange(other.m, 0); // Move the value and set the source to 0
    }

    // Move assignment operator
    A& operator=(A&& other) noexcept {
        std::cout << "custom move assignment constructor" << std::endl;
        if (this != &other) {
            m = std::exchange(other.m, 0); // Move the value and set the source to 0
        }
        return *this;
    }
#endif
	
    int m;
};

int main() {
    // Using the constructor that takes an int
    A a1(42);

    // Using the copy constructor
    A a2(a1);

    // Using the copy assignment operator
    A a3(0);
    a3 = a2; // Explicit call to copy assignment

    // Using the move constructor
    A a4(std::move(a3));

    // Using the move assignment operator
    A a5(0);
    a5 = std::move(a4); // Explicit call to move assignment

    return 0;
}
