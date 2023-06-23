#include <iostream>

template<class T>
void foo(T&& arg) {
   std::cout << arg << std::endl;
}
/*
The wrapper function is also a template function that takes a forwarding reference arg. 
Inside wrapper, the arg parameter is always treated as an lvalue. 
It then calls the foo function, forwarding arg using std::forward<T>(arg). 
The use of std::forward preserves the value category (lvalue or rvalue) of the original argument passed to wrapper.
*/
template<class T>
void wrapper(T&& arg) 
{
    // arg is always lvalue
    foo(std::forward<T>(arg)); // Forward as lvalue or as rvalue, depending on T
}

/*
The wrapper1 function is similar to wrapper, but it demonstrates a more complex forwarding scenario. 
In this case, instead of directly forwarding arg to foo, it calls the member function c_str() on arg and forwards the result to foo. 
The type of the forwarded argument is determined using decltype and std::forward is used to preserve the value category.
*/
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
