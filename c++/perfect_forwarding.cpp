/*
In this example, the process template function takes a forwarding reference (T&& arg), 
and two overloaded versions of someFunction are defined, one for an lvalue reference and another for an rvalue reference.

In main(), the process function is called with x, which is an lvalue. 
The template deduction deduces T as int&, and arg becomes an lvalue reference. 
As a result, when someFunction is called within process, the version accepting an lvalue reference is invoked.

Next, process is called with the literal value 10, which is an rvalue. 
This time, T is deduced as int, and arg becomes an rvalue reference. 
Consequently, the version of someFunction accepting an rvalue reference is called within process.
*/


#include <iostream>
#include <utility>

void someFunction(int& value) {
    std::cout << "Called by lvalue reference: " << value << std::endl;
}

void someFunction(int&& value) {
    std::cout << "Called by rvalue reference: " << value << std::endl;
}

template<typename T>
void process(T&& arg) {
    someFunction(std::forward<T>(arg)); // Call someFunction with forwarded argument
}

int main() {
    int x = 25;
    process(x); // lvalue passed, calls someFunction with lvalue reference
    process(10); // rvalue passed, calls someFunction with rvalue reference
    return 0;
}

