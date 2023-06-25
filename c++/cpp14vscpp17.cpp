#include <iostream>
#include <vector>
#include <optional>


    // Variable templates for C++14
    template<typename T>
    constexpr T pi = T(3.1415926535897932385);
    
    
    

// C++14 features
void cpp14Features() {
    std::cout << "C++14 Features:\n";


    std::cout << "Variable templates: " << pi<double> << std::endl;

    // Generic lambdas
    auto multiplyBy = [](auto x, auto y) { return x * y; };
    std::cout << "Generic lambda result: " << multiplyBy(5, 2.5) << std::endl;

    // Return type deduction for functions
    auto addNumbers = [](int x, int y) {
        return x + y;
    };

    std::cout << "Return type deduction for functions: " << addNumbers(2, 3) << std::endl;

    // Initialization of member variables in a class
    struct Example {
        int value = 42;
    };

    Example ex;
    std::cout << "Initialization of member variables: " << ex.value << std::endl;

    std::cout << std::endl;
}

// C++17 features
void cpp17Features() {
    std::cout << "C++17 Features:\n";
   // Structured bindings
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;




    // if constexpr
    if constexpr (std::is_same<int, int>::value) {
        std::cout << "if constexpr: Types are the same." << std::endl;
    } else {
        std::cout << "if constexpr: Types are different." << std::endl;
    }

    // Fold expressions
    auto sum = [](auto... args) {
        return (args + ...);
    };
    std::cout << "Fold expressions: " << sum(1, 2, 3, 4, 5) << std::endl;

    // std::optional
    std::optional<std::string> name;
    std::cout << "std::optional: ";
    if (name) {
        std::cout << *name << std::endl;
    } else {
        std::cout << "Name is empty." << std::endl;
    }

    std::cout << std::endl;
}

int main() {
    cpp14Features();
    cpp17Features();

    return 0;
}
