#include <iostream>
#include <vector>
#include <algorithm>

class Print {
public:
	void operator()(int elem) const {
		std::cout << elem << " ";
	}
};

int main () {
	std::vector<int> vect;
	for (int i=1; i<10; ++i) {
		vect.push_back(i);
	}

	Print print_it;
	//std::for_each (vect.begin(), vect.end(), print_it);
	//std::cout << std::endl;

        std::for_each(vect.begin(), vect.end(), [](int elem) { std::cout << elem << " "; });
	std::cout << std::endl;
	return 0;
}
