#include <iostream>
#include <functional>
#include <vector>

//std::function is predicate

void test_vect(const std::vector<int> &vect, std::function<bool(int)> func) {
std::cout << ">";
  for (int i: vect){
    if (func(i)){
       std::cout << i << " ";
    }
  }
}

int main(){

std::vector<int> test {1,2,3,4,5};

//predicate lambdas
test_vect(test,[](int a){return (a>3);});
return 0;

}
