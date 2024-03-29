//https://en.cppreference.com/w/cpp/utility/forward
#include <iostream>
#include <memory>
#include <utility>
 
struct A {
    A(int&& n) { std::cout << "rvalue overload, n=" << n << "\n"; }
    A(int& n)  { std::cout << "lvalue overload, n=" << n << "\n"; }
};
 
class B {
public:
    template<class T1, class T2, class T3>
    B(T1&& t1, T2&& t2, T3&& t3) :
        a1_{std::forward<T1>(t1)},
        a2_{std::forward<T2>(t2)},
        a3_{std::forward<T3>(t3)}
    {
    }
 
private:
    A a1_, a2_, a3_;
};

/*
make_unique1 function template:

    This function template takes a type T and a forwarding reference U&& u.
    It uses std::forward to forward the argument u when constructing an object of type T using new T(std::forward<U>(u)).
    The resulting object is wrapped in a std::unique_ptr<T> and returned.

make_unique2 function template:

    This function template takes a type T and a parameter pack of forwarding references (U&&... u).
    Inside the function, std::forward is used to forward each argument u in the parameter pack when constructing an object of type T using new T(std::forward<U>(u)...).
    The resulting object is wrapped in a std::unique_ptr<T> and returned.
*/
 
template<class T, class U>
std::unique_ptr<T> make_unique1(U&& u)
{
    return std::unique_ptr<T>(new T(std::forward<U>(u)));
}
 
template<class T, class... U>
std::unique_ptr<T> make_unique2(U&&... u)
{
    return std::unique_ptr<T>(new T(std::forward<U>(u)...));
}
 
int main()
{   
    auto p1 = make_unique1<A>(2); // rvalue
    int i = 1;
    auto p2 = make_unique1<A>(i); // lvalue
 
    std::cout << "B\n";
    auto t = make_unique2<B>(2, i, 3);
}
