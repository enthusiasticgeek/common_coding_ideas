#include <iostream>
#include <vector>

class MyObject {
public:
    MyObject() { std::cout << "Default constructor" << std::endl; }
    MyObject(const MyObject& other) { std::cout << "Copy constructor" << std::endl; }
    MyObject(MyObject&& other) { std::cout << "Move constructor" << std::endl; }
};

/*
In main(), a std::vector of MyObject objects is created, and an instance of MyObject called obj is also defined. 
By calling std::move(obj), obj is cast into an rvalue, and the move constructor is invoked to move it into the vector. 
This avoids the unnecessary overhead of making a copy.
*/

int main() {
    std::vector<MyObject> vec;
    MyObject obj;
    vec.push_back(std::move(obj)); // Move obj into the vector
    return 0;
}
