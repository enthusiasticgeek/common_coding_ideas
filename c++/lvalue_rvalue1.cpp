#include <iostream>

//l-value
int & Square(int & x){
    std::cout << "Inside l-value ref square function" << std::endl;
    x *= x;
    return x;
}

//r-value
int Square(int &&x){    
    std::cout << "Inside r-value ref square function" << std::endl;
    x *= x;
    return x;
}

int main()
{
    int number1 = 2;  // Create an l-value first and then pass.
    std::cout<< Square(number1) << std::endl;
    
    int &&number2 = 3; // Create a r-value ref first;
    std::cout<< Square(std::move(number2)) << std::endl; // Then use std::move to convert to an r-value
    
    std::cout<< Square(5) << std::endl; //r-value ref (temporary)

    return 0;
}
