#include <iostream>

// Abstract base class
class Shape {
public:
    virtual double area() const = 0;  // Pure virtual function
    virtual void print() const = 0;   // Pure virtual function
    virtual ~Shape() {}               // Virtual destructor (recommended for base classes)
};

// Derived class - Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    void print() const override {
        std::cout << "Rectangle: width = " << width << ", height = " << height << std::endl;
    }
};

// Derived class - Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void print() const override {
        std::cout << "Circle: radius = " << radius << std::endl;
    }
};

int main() {
    // Create objects of derived classes
    Shape* shape1 = new Rectangle(5.0, 3.0);
    Shape* shape2 = new Circle(2.5);

    // Call area() and print() functions polymorphically
    std::cout << "Shape 1 - Area: " << shape1->area() << std::endl;
    shape1->print();

    std::cout << "Shape 2 - Area: " << shape2->area() << std::endl;
    shape2->print();

    // Delete objects (recommended to delete through base class pointers)
    delete shape1;
    delete shape2;

    return 0;
}
