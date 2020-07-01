#include <algorithm>
#include <iostream>
#include <cmath>

void abssort(float* x, unsigned n) {
    std::sort(x, x + n,
        // Lambda expression begins
        [](float a, float b) {
            return (std::abs(a) < std::abs(b));
        } // end of lambda expression
    );
}

int main(int argc, char* argv[]){
    float arr[5]={1.2,3.4,5.3,3.7,0.8};
    abssort(arr,5);
    for (auto a : arr) {
        std::cout << a << " ";
    }   
    std::cout << '\n';
    return 0;
}

