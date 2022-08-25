#include <iostream>

template<class T>
void foo(T&& arg) {
   std::cout << arg << std::endl;
}

template<class T>
void wrapper(T&& arg) 
{
    // arg is always lvalue
    foo(std::forward<T>(arg)); // Forward as lvalue or as rvalue, depending on T
}

template<class T>
void wrapper1(T&& arg)
{
    // A wrapper does not just forward its argument, but calls a member function on the argument, and forwards its result 
    foo(std::forward<decltype(std::forward<T>(arg).c_str())>(std::forward<T>(arg).c_str()));
}

int main(){
int a = 5;
wrapper(a);
std::string hello = "123";
wrapper1(hello);
return 0;
}
