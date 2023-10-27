//Delegate constructors - This way we can reuse one constructor's functionality inside another constructor.
#include <iostream>

class X {
   const int i;
   public:
   X(int x, int y) : X(x+y) { }
   X(int x, int y, int z) : X((y*z)/x) {}
   X(int x) : i(x) { }
   int getI(){ return i;}
};

int main(int argc, char* argv[]){
   X var1(55,11);
   X var2(2,4,6);
   std::cout << var1.getI() << " and "<< var2.getI() << std::endl;
   return 0;
} 
