#include <iostream>
#include <tuple>
#include <algorithm>
#include <string>
#include <memory>

using namespace std;

class Vehicle {
   public:
      virtual int rim_size() = 0;
      virtual std::string vehicle_type() = 0;
      virtual ~Vehicle(){};
};

class SUV : virtual public Vehicle {
   public: 
      int rim_size(){
        return 18;
      }
      std::string vehicle_type(){
          return "RAV4"; 
      }  
      ~SUV(){
      }
};
class Sedan : virtual public Vehicle {
   public: 
      int rim_size(){
        return 16;
      }
      std::string vehicle_type(){
          return "Camry"; 
      }  
      ~Sedan(){
      }
};


// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const string& word : words) {
    cout << word;
  }
  
  auto t = std::make_tuple(1,2,2.0);
  cout <<  std::tuple_size<decltype(t)>::value;
  
  /*
  Vehicle* sedan = new Sedan;
  //delete SUV;
  if(sedan != nullptr){
    delete sedan;
  }
  */
  std::unique_ptr<Vehicle> suv = std::make_unique<SUV>();
  std::unique_ptr<Vehicle> sed = std::make_unique<Sedan>();
  std::cout << std::endl;
  std::cout<< suv->rim_size() << std::endl;
  std::cout<< suv->vehicle_type() << std::endl;
   

  return 0;
}

