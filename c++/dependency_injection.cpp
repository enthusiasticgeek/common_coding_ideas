#include <iostream>

// Forward declaration of classes
class ClassB;
class ClassC;

class ClassA {
public:
    // Dependency Injection using interfaces
    ClassA(ClassB* b, ClassC* c) : bPtr(b), cPtr(c) {}

    void DoSomething();

private:
    ClassB* bPtr;
    ClassC* cPtr;
};

class ClassB {
public:
    void DoSomething() {
        std::cout << "ClassB doing something." << std::endl;
    }
};

class ClassC {
public:
    // Dependency Inversion using interface
    virtual void DoSomething() = 0;
};

class ClassCImpl : public ClassC {
public:
    void DoSomething() override {
        std::cout << "ClassCImpl doing something." << std::endl;
    }
};

class Mediator {
public:
    void NotifyClassB() {
        classBObj.DoSomething();
    }

    void NotifyClassC() {
        classCObj.DoSomething();
    }

private:
    ClassB classBObj;
    ClassCImpl classCObj;
};

int main() {
    // Creating objects with reduced dependencies
    ClassB classBObj;
    ClassCImpl classCObj;

    // Creating the mediator
    Mediator mediator;

    // Creating ClassA with injected dependencies
    ClassA classAObj(&classBObj, &classCObj);

    // Using the mediator to communicate between classes
    mediator.NotifyClassB();
    mediator.NotifyClassC();
    classAObj.DoSomething();

    return 0;
}

void ClassA::DoSomething() {
    std::cout << "ClassA doing something." << std::endl;

    // Using the injected dependencies
    bPtr->DoSomething();
    cPtr->DoSomething();
}
