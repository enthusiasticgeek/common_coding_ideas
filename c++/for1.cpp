#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <exception>

void printMe(int i){
    std::cout << i << std::endl;
}

struct printObj1{
    void operator()(int i){
       std::cout << i << std::endl;
    }
} printObj;

int main()
{
   try{
       std::cout << "Hello World" << std::endl;
       std::vector<int>* vect = new std::vector<int>();
       vect->push_back(2);
       vect->push_back(3);
       vect->push_back(4);
       vect->push_back(5);
       std::vector<int>::iterator it_begin = vect->begin(); 
       std::vector<int>::iterator it_end = vect->end(); 
       for_each(vect->begin(), vect->end(), printMe);
       for_each(vect->begin(), vect->end(), printObj);
       for (std::vector<int>::iterator it = it_begin; it < it_end ; it++){
            std::cout << " > " << *it << std::endl;
       }
       delete vect;
    } catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    
   try{
      std::list<int> lister;
      lister.push_back(3);
      lister.push_back(4);
      lister.push_back(5);
      lister.push_back(6);
      //r_each();
      for_each(lister.begin(), lister.end(), printObj);
   } catch (std::exception &e){
       std::cout << e.what() << std::endl;
   }    
   return 0;
}
