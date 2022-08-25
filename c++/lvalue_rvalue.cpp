//https://www.scaler.com/topics/cpp/lvalue-and-rvalue/
#include <iostream>

using namespace std;

void func1(const int &x) {
    cout<<"Inside lvalue func1 : x = "<<x<<endl;
}

void func1(int &&x) {
    cout<<"Inside rvalue func1 : x = "<<x<<endl;
}


int main()
{
    int x = 10;
    func1(x);
    func1(15);
    return 0;
}

