#include <iostream>

class MyClass {
private:
    int data;

public:
    MyClass(int value) : data(value) {}

    // Declare the friend function inside the class
    friend void FriendFunction(MyClass obj);
};

// Define the friend function outside the class
void FriendFunction(MyClass obj) {
    std::cout << "FriendFunction accessing private data: " << obj.data << std::endl;
}

int main() {
    MyClass myObj(42);
    FriendFunction(myObj); // Call the friend function to access private data

    return 0;
}
