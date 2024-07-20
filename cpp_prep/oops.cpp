// *******************************OOOPS************************* //
// classes , objects , inheritance, polymorophism , encapsulation , abstraction

/*
polymorphism: allows objects of differenct classes to be treated as objects of common base class during runtime.
            occurs when we have many classes that are related to each other by inheritance.

*/ 
class Shape {
public:
    virtual double area() const = 0; // Pure virtual function(=0), must be overriden by derived class before class is instantiated.
    virtual ~Shape() {} // destructor is responsible for cleaning up resources, releasing memory,
    // or performing any necessary cleanup operations before the object is destroyed.

    /*
    A destructor in C++ is a special member function that is automatically called when an object of the class goes 
    out of scope or is explicitly deleted using the delete keyword. 
    */

    /*
    virtual function is a member function declared within a base class that can be overridden in its derived classes. 
    It enables dynamic polymorphism, allowing different derived classes to provide their own specific implementation
    of the function while being invoked through a common interface.
    */
};

class Circle : public Shape {
private:
    double radius; // Private member variable

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }
    // Derived classes can provide their own implementation of the virtual function by using  "override" keyword (in C++11 and later)
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }
};

void calculateArea(const Shape& shape) {
    std::cout << "Area: " << shape.area() << std::endl;
}

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    calculateArea(circle);     // Polymorphism: Treating circle as a Shape
    calculateArea(rectangle);  // Polymorphism: Treating rectangle as a Shape

    return 0;
}



// Memory managment

#include <memory>

void memoryManagementExample() {
    // Using smart pointers to manage memory
    std::unique_ptr<int> uniquePtr(new int(10));
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(20);

    // No need to manually delete memory, handled by smart pointers
}


// STL

#include <iostream>
#include <vector>
#include <algorithm>

void stlExample() {
    // Using vector and algorithms from STL
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    
    // Sorting vector
    std::sort(numbers.begin(), numbers.end());
    
    // Iterating through vector
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}


// Templates and generic programming

template <typename T>
T add(T a, T b) {
    return a + b;
}

void templateExample() {
    int sumInt = add(5, 10);
    double sumDouble = add(3.5, 2.7);
}

// Exception handling 

void divide(int a, int b) {
    try {
        if (b == 0) {
            throw "Division by zero!";
        }
        int result = a / b;
        std::cout << "Result: " << result << std::endl;
    } catch (const char* msg) {
        std::cout << "Exception caught: " << msg << std::endl;
    }
}

void exceptionHandlingExample() {
    divide(10, 0);
}

