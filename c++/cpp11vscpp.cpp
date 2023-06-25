#include <iostream>
#include <vector>

int main() {
  // C++ style initialization
  int a = 10;
  
  // C++11 style initialization using uniform initialization syntax
  int b{20};
  
  // C++ style array declaration and initialization
  int c[3] = {1, 2, 3};
  
  // C++11 style array declaration and initialization
  int d[] = {4, 5, 6};
  
  // C++ style for loop
  for (int i = 0; i < 3; ++i) {
    std::cout << c[i] << " ";
  }
  std::cout << std::endl;
  
  // C++11 style range-based for loop
  for (int num : d) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
  
  // C++ style vector
  std::vector<int> vec;
  vec.push_back(7);
  vec.push_back(8);
  vec.push_back(9);
  
  // C++11 style auto type inference
  for (auto element : vec) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
  
  // C++11 lambda expression
  auto sum = [](int x, int y) { return x + y; };
  std::cout << "Sum: " << sum(a, b) << std::endl;
  
  return 0;
}
