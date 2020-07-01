#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void myfunction (int i) {  // function:
  std::cout << ' ' << i;
}

struct myclass {           // function object type:
  void operator() (int i) {std::cout << ' ' << i;}
} myobject;

int main() {
cout << "Hello World how are you"; // prints Hello World

std::vector<int> test;
test.push_back(1);
test.push_back(2);
test.push_back(13);
test.push_back(14);
std::cout << std::endl;
std::vector<int>::iterator it = test.begin();
for_each(test.begin(),test.end(),myfunction);
std::cout << std::endl;
for_each(it,test.end(),myobject);
// main() is where program executi
return 0;
}
