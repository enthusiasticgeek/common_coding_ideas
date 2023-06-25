#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>

// C++11 features
void cpp11Features() {
  std::cout << "C++11 Features:\n";

  // Auto type inference
  auto value = 42;
  std::cout << "Auto type inference: " << value << std::endl;

  // Range-based for loop
  std::vector<int> numbers = {1, 2, 3, 4, 5};
  std::cout << "Range-based for loop: ";
  for (auto num : numbers) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  // Lambda expressions
  auto multiplyByTwo = [](int x) { return x * 2; };
  std::cout << "Lambda expression result: " << multiplyByTwo(5) << std::endl;

  // Type traits
  std::cout << "Type traits:\n";
  std::cout << "Is int const? " << std::is_const<int>::value << std::endl;
  std::cout << "Is float const? " << std::is_const<float>::value << std::endl;

  std::cout << std::endl;
}

// C++14 features
template<typename T>
constexpr T pi = T(3.1415926535897932385);

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
  class Example {
  public:
    int value = 42;
  };

  Example ex;
  std::cout << "Initialization of member variables: " << ex.value << std::endl;

  std::cout << std::endl;
}

int main() {
  cpp11Features();
  cpp14Features();

  return 0;
}
