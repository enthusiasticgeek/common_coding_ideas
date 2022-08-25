//https://www.scaler.com/topics/cpp/lvalue-and-rvalue/
class A {
    int *arr, size;
    bool flag;
    
    public:
        // parameterized constructor
        A(int len) {
            size = len;
            arr = new int[size];
            flag = false;
        }    
        
        // copy constructor
        A (const A& temp) {
            size = temp.size;
            arr = new int[temp.size];
            for ( int i = 0; i < temp.size; ++i ) {
                arr[ i ] = temp.arr[ i ];
            }
            flag = temp.flag;
        }
        
        // destructor
        ~A () {
            delete [] arr;
        }
    
};

int main()
{
    A obj(100000);
    A obj1(obj);    // !!! BAD CODE !!! Copy constructor get's called and 100000 elements of the array are copied

    return 0;
}

