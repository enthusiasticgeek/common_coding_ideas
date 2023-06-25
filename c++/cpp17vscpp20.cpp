#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>
#include <functional>
#include <ranges>

//C++20
// Concepts
template<typename T>
concept Integral = std::is_integral_v<T>;

//C++20
template<Integral T>
void printValue(T value) {
    std::cout << "Concepts: " << value << std::endl;
}

// C++17 features
void cpp17Features() {
    std::cout << "C++17 Features:\n";

    // Structured bindings
    std::pair<int, std::string> person = {42, "John Doe"};
    auto [age, name] = person;
    std::cout << "Structured bindings: Age = " << age << ", Name = " << name << std::endl;

    // if constexpr
    if constexpr (std::is_same_v<int, int>) {
        std::cout << "if constexpr: Types are the same." << std::endl;
    } else {
        std::cout << "if constexpr: Types are different." << std::endl;
    }

    // Inline variables
    constexpr int value = 42;
    std::cout << "Inline variable: " << value << std::endl;

    // std::optional
    std::optional<std::string> message = "Hello, World!";
    std::cout << "std::optional: ";
    if (message) {
        std::cout << *message << std::endl;
    } else {
        std::cout << "Message is empty." << std::endl;
    }

    std::cout << std::endl;
}

// C++20 features
void cpp20Features() {
    std::cout << "C++20 Features:\n";
    printValue(42);
    // Ranges
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto evenNumbers = numbers | std::views::filter([](int n) { return n % 2 == 0; });
    std::cout << "Ranges: Even numbers - ";
    for (const auto& num : evenNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
}

int main() {
    cpp17Features();
    cpp20Features();

    return 0;
}
