#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <memory>
#include <thread>
#include <chrono>

// C++ features
void cppFeatures() {
  std::cout << "C++ Features:\n";

  // Standard library containers
  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);

  // Standard library algorithms
  int sum = 0;
  for (int num : vec) {
    sum += num;
  }
  std::cout << "Sum of elements: " << sum << std::endl;

  // Pointers and dynamic memory allocation
  int* ptr = new int(42);
  std::cout << "Pointer value: " << *ptr << std::endl;
  delete ptr;

  std::cout << std::endl;
}

// C++11 features
void cpp11Features() {
  std::cout << "C++11 Features:\n";

  // Uniform initialization
  int a{10};
  int b = {20};

  // Auto type inference
  auto result = a + b;
  std::cout << "Result: " << result << std::endl;

  // Range-based for loop
  std::vector<int> numbers = {1, 2, 3, 4, 5};
  std::cout << "Numbers: ";
  for (int num : numbers) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  // Lambda expressions
  auto multiplyByTwo = [](int x) { return x * 2; };
  std::cout << "Result of lambda: " << multiplyByTwo(5) << std::endl;

  // Smart pointers
  std::shared_ptr<int> sharedPtr = std::make_shared<int>(42);
  std::cout << "Shared pointer value: " << *sharedPtr << std::endl;

  // Unordered map
  std::unordered_map<std::string, int> map;
  map["one"] = 1;
  map["two"] = 2;
  map["three"] = 3;

  std::cout << "Map elements:\n";
  for (const auto& pair : map) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  // Threading
  std::thread thread([]() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread executed." << std::endl;
  });

  std::cout << "Main thread continues." << std::endl;

  thread.join();

  std::cout << std::endl;
}

int main() {
  cppFeatures();
  cpp11Features();

  return 0;
}
