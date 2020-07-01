#include <iostream>
 
using namespace std;
class Shape;
class PaintCost;
// Base class
class Shape {
   public:
      void setWidth(int w) {
         width = w;
      }
      void setHeight(int h) {
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
   Rectangle* Rect = new Rectangle();
 
   Rect->setWidth(5);
   Rect->setHeight(7);

   // Print the area of the object.
   cout << "Total area: " << Rect->getArea() << endl;
   cout << "Total area: " << Rect->getCost(Rect->getArea()) << endl;

   delete Rect;
   return 0;
}
