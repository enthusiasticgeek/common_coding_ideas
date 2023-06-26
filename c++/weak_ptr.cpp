#include <iostream>
#include <memory>

class MyClass {
public:
    std::weak_ptr<MyClass> next;

    MyClass() {
        std::cout << "MyClass constructor called." << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass destructor called." << std::endl;
    }
};

int main() {
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
    std::shared_ptr<MyClass> ptr2 = std::make_shared<MyClass>();

    // Creating a weak pointer from the shared pointer
    std::weak_ptr<MyClass> weakPtr = ptr2;

    // Checking if the weak pointer is expired or not
    if (auto sharedPtr = weakPtr.lock()) {
        std::cout << "Weak pointer is valid." << std::endl;
        ptr1->next = sharedPtr;
    } else {
        std::cout << "Weak pointer is expired." << std::endl;
    }

    // Resetting the shared pointer to nullptr
    ptr2.reset();

    // Checking if the weak pointer is expired or not after resetting
    if (auto sharedPtr = weakPtr.lock()) {
        std::cout << "Weak pointer is valid." << std::endl;
    } else {
        std::cout << "Weak pointer is expired." << std::endl;
    }

    return 0;
}
