//https://www.scaler.com/topics/cpp/lvalue-and-rvalue/
#include <iostream>

using namespace std;

class A {
    int *arr, size;
    bool flag;
    
    public:
        // parameterized constructor
        A(int len) {
            cout<<"Inside parameterized constructor\n";
            size = len;
            arr = new int[size];
            flag = false;
        }    
        
        // copy constructor
        A (const A& temp) {
            cout<<"Inside copy constructor\n";
            size = temp.size;
            arr = new int[temp.size];
            for ( int i = 0; i < temp.size; ++i ) {
                arr[ i ] = temp.arr[ i ];
            }
            flag = temp.flag;
        }
        
        // move constructor
        A (A&& temp) {
            cout<<"Inside move constructor\n";
            arr = temp.arr;
            size = temp.size;
            flag = temp.flag;
            temp.arr = nullptr;
        }
    
        // destructor
        ~A () {
            delete [] arr;
        }
    
};

int main()
{
    A a1(100);
    A a2(std::move(a1));

    return 0;
}

