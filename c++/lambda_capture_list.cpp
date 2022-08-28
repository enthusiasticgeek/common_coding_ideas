#include <iostream>

int main(){

int x {1};


// variables in capture list can be thought of as member variables of class created by compiler using lambda
//x in capture list of lambda/closure
auto l = [x]() mutable {
 x+=10;
 std::cout << x << std::endl;
};

l();

l();

std::cout << x << std::endl;

//Now capture everything by value
auto l1 = [=]() mutable {
 x+=10;
 std::cout << x << std::endl;
};

l1();

l1();

std::cout << x << std::endl;


//Now capture by reference
auto l2 = [&x]() mutable {
 x+=10;
 std::cout << x << std::endl;
};

l2();

l2();

std::cout << x << std::endl;

//auto l3 = [this]() mutable {  //can also use this pointer too

return 0;
}
