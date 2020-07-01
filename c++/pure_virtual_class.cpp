#include <iostream>
class A;
class B;
class A {
    public:
     A(){ 
         std::cout << "A" << std::endl;
     }
     virtual void Area(int i, int j) = 0;
     virtual ~A(){};
    
};

class B : virtual A {
    public:
     B(){ 
         std::cout << "B" << std::endl;
         
     }
     void Area(int i, int j){
         std::cout << i*j << std::endl;
     }
    virtual ~B(){};

};

class C : virtual A {
    public:
     C(){ 
         std::cout << "C" << std::endl;
         
     }
     void Area(int i, int j){
         std::cout << 3.14*i*j << std::endl;
     }
    virtual ~C(){};

};


//forward declaration
class car;
class jet;

//pure virtual function
class Vehicle{
  public:
    virtual void speed() = 0;
    virtual int rpm() = 0;
    ~Vehicle(){};
};

class car: virtual public Vehicle{
    public:
    
    void speed(){
        std::cout << "Max speed 200 mph" << std::endl;
    }
    int rpm(){ 
        std::cout << "10000 rpm" << std::endl;
        return 10000;
    }
    ~car(); // cannot be virtual for an interface class
};
class jet: virtual public Vehicle{
    public:
    
    void speed(){
        std::cout << "Max speed 2000 mph" << std::endl;
    }
    int rpm(){ 
        std::cout << "100000 rpm" << std::endl;
        return 100000;
    }
    ~jet(); // cannot be virtual for an interface class
};

// main() is where program execution begins.
int main() {
    B* b = new B();
    C* c = new C();
    b->Area(3,4);
    c->Area(3,4);
    delete b;
    delete c;
    

    Vehicle* cr = new car();
    Vehicle* jt = new jet();
    
    cr->rpm();
    jt->rpm();
    
    delete cr;
    delete jt;
   return 0;
}
