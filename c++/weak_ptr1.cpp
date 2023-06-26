#include <iostream>
#include <memory>

class ClassB; // Forward declaration

class ClassA {
public:
    ClassA() {
        std::cout << "ClassA constructor called." << std::endl;
    }

    ~ClassA() {
        std::cout << "ClassA destructor called." << std::endl;
    }

    void SetClassB(const std::weak_ptr<ClassB>& b);

    void DoSomething();

private:
    std::weak_ptr<ClassB> classBPtr;
    bool hasBeenCalled = false; // Flag to track if DoSomething() has already been called
};

class ClassB {
public:
    ClassB() {
        std::cout << "ClassB constructor called." << std::endl;
    }

    ~ClassB() {
        std::cout << "ClassB destructor called." << std::endl;
    }

    void SetClassA(const std::weak_ptr<ClassA>& a);

    void DoSomething();

private:
    std::weak_ptr<ClassA> classAPtr;
    bool hasBeenCalled = false; // Flag to track if DoSomething() has already been called
};

void ClassA::SetClassB(const std::weak_ptr<ClassB>& b) {
    classBPtr = b;
}

void ClassA::DoSomething() {
    std::cout << "ClassA doing something." << std::endl;

    if (hasBeenCalled) {
        std::cout << "ClassA has already been called. Exiting." << std::endl;
        return; // Stop the infinite loop
    }

    hasBeenCalled = true; // Mark ClassA as already called

    // Access ClassB using the weak_ptr
    if (auto sharedPtr = classBPtr.lock()) {
        sharedPtr->DoSomething();
    } else {
        std::cout << "ClassB is no longer available." << std::endl;
    }
}

void ClassB::SetClassA(const std::weak_ptr<ClassA>& a) {
    classAPtr = a;
}

void ClassB::DoSomething() {
    std::cout << "ClassB doing something." << std::endl;

    if (hasBeenCalled) {
        std::cout << "ClassB has already been called. Exiting." << std::endl;
        return; // Stop the infinite loop
    }

    hasBeenCalled = true; // Mark ClassB as already called

    // Access ClassA using the weak_ptr
    if (auto sharedPtr = classAPtr.lock()) {
        sharedPtr->DoSomething();
    } else {
        std::cout << "ClassA is no longer available." << std::endl;
    }
}

int main() {
    // Create shared pointers
    std::shared_ptr<ClassA> classAPtr = std::make_shared<ClassA>();
    std::shared_ptr<ClassB> classBPtr = std::make_shared<ClassB>();

    // Set weak pointers in the respective classes
    classAPtr->SetClassB(classBPtr);
    classBPtr->SetClassA(classAPtr);

    // Call DoSomething on ClassA
    classAPtr->DoSomething();

    // Call DoSomething on ClassB
    classBPtr->DoSomething();

    // Reset the shared pointers
    classAPtr.reset();
    classBPtr.reset();

    return 0;
}
