#include <iostream>
#include <stdexcept>
 
using namespace std;
class Shape;
class PaintCost;
// Base class
class Shape {
   public:
      void setWidth(int w) {
        if (w < 0) {
            throw std::invalid_argument("width cannot be negative.");
         }
         width = w;
      }
      void setHeight(int h) {
        if (h < 0) {
            throw std::invalid_argument("Height cannot be negative.");
         }
         height = h;
      }
      
   protected:
      int width;
      int height;
};

// Base class PaintCost
class PaintCost {
   public:
      int getCost(int area) {
         return area * 70;
      }
};

// Derived class
class Rectangle: public virtual Shape, public virtual PaintCost { //avoid diamond problem -make virtual
   public:
      int getArea() { 
         return (width * height); 
      }
};

int main(void) {
try{
   Rectangle* Rect = new Rectangle();
 
   Rect->setWidth(5);
   Rect->setHeight(7);

   // Print the area of the object.
   cout << "Total area: " << Rect->getArea() << endl;
   cout << "Total area: " << Rect->getCost(Rect->getArea()) << endl;

   delete Rect;
} catch (const std::exception &e) {
          std::cerr << "Exception occurred: " << e.what() << std::endl;
}

   return 0;
}
