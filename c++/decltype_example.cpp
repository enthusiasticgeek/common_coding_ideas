#include <iostream>
#include <typeinfo>

template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}

int main() {
    int a = 5;
    double b = 3.14;

    auto result = add(a, b);

    std::cout << "Result type: " << typeid(result).name() << std::endl;
    std::cout << "Result value: " << result << std::endl;

    return 0;
}
