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
        A (const A& temp) noexcept {
            size = temp.size;
            arr = new int[temp.size];
            for ( int i = 0; i < temp.size; ++i ) {
                arr[ i ] = temp.arr[ i ];
            }
            flag = temp.flag;
        }
        
	// move assignment operator
	A& operator=(A&& temp) noexcept {
	    
	    // Check against self assignment
	    if (this != &temp) {
		// Free the existing resource.
		delete[] arr;

		// Copy the primitive types
		size = temp.size;
		flag = temp.flag;
		
		// Move the pointer in temporary object
		arr = temp.arr;

		temp.arr = nullptr;
		
	   }
	   return *this;
	}

        // destructor
        ~A () {
            delete [] arr;
        }
    
};

int main()
{
    A obj(100000);
    A obj1(obj);    // Copy constructor get's called and 100000 elements of the array are copied

    return 0;
}

