//https://www.scaler.com/topics/cpp/lvalue-and-rvalue/
//https://en.cppreference.com/w/cpp/language/rule_of_three
class A {
    int* arr;
    int size;
    bool flag;

public:
    //Rule of Five by implementing the copy constructor, copy assignment operator, move constructor, and move assignment operator

    // parameterized constructor
    A(int len) : size(len), arr(new int[size]), flag(false) {}

    // copy constructor
    A(const A& temp) : size(temp.size), arr(new int[temp.size]), flag(temp.flag) {
        for (int i = 0; i < temp.size; ++i) {
            arr[i] = temp.arr[i];
        }
    }

    // copy assignment operator
    A& operator=(const A& temp) {
        if (this == &temp) {
            return *this;
        }
        delete[] arr;
        size = temp.size;
        arr = new int[temp.size];
        for (int i = 0; i < temp.size; ++i) {
            arr[i] = temp.arr[i];
        }
        flag = temp.flag;
        return *this;
    }

    // move constructor
    A(A&& temp) noexcept : size(temp.size), arr(temp.arr), flag(temp.flag) {
        temp.arr = nullptr;
        temp.size = 0;
        temp.flag = false;
    }

    // move assignment operator
    A& operator=(A&& temp) noexcept {
        if (this == &temp) {
            return *this;
        }
        delete[] arr;
        size = temp.size;
        arr = temp.arr;
        flag = temp.flag;
        temp.arr = nullptr;
        temp.size = 0;
        temp.flag = false;
        return *this;
    }

    // destructor
    ~A() {
        delete[] arr;
    }
};

int main() {
    A obj(100000);
    A obj1(obj);
    A obj2 = std::move(obj);
    obj1 = std::move(obj2);
    return 0;
}


int main()
{
    A obj(100000);
    A obj1(obj);    // !!! BAD CODE !!! Copy constructor get's called and 100000 elements of the array are copied
    A obj2 = std::move(obj);
    obj1 = std::move(obj2);
    return 0;
}

