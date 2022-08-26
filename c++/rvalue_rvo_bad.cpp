//https://www.scaler.com/topics/cpp/lvalue-and-rvalue/
//!!! BAD CODE !!!

#include <iostream>

using namespace std;

class A {
    int *arr, size;
    
    public:
    
    A(int len) {
        size = len;
        arr = new int[len];
    }
    A(const A& temp) noexcept {
        size = temp.size;
        delete [] arr;
        arr = new int[size];
        for(int i=0;i<size;i++)
            arr[i] = temp.arr[i];
    }
    A(A&& temp) noexcept {
        size = temp.size;
        arr = temp.arr;
        temp.arr = nullptr;
    }
    ~A() {
        delete [] arr;
    }
};

A getObj() {
    A obj(10);
    return std::move(obj); //Return Value Optimization
}

int main()
{
    A obj = getObj();

    return 0;
}
