//! super keyword
// In C++, there is no direct equivalent of the super keyword found in languages like Java. 
//~ However, C++ provides mechanisms to achieve similar behavior through inheritance. 
//~ The super keyword in other languages is used to refer to the superclass or base class from within a derived class, typically to call base class methods or constructors.
//~ In C++, this can be accomplished using the scope resolution operator (::) to access members of the base class.
#include <iostream>
using namespace std;
class Base {
public:
    void show() {
        cout << "Base class show method" << endl;
    }
};
class Derived : public Base {
public:
    void show() {
        cout << "Derived class show method" << endl;
        Base::show();// Call the base class show method
    }
};
int main() {
    Derived obj;
    obj.show();
    return 0;
}
// Example: Calling a Base Class Constructor
// C++ allows you to call the base class constructor from the derived class constructor using an initialization list:
#include <iostream>
using namespace std;

class Base {
public:
    Base(int x) {
        cout << "Base class constructor with value: " << x << endl;
    }
};

class Derived : public Base {
public:
    Derived(int x, int y) : Base(x) {
        cout << "Derived class constructor with value: " << y << endl;
    }
};

int main() {
    Derived obj(10, 20);
    return 0;
}


//! final keyword
// In Java, we can use final for a function to make sure that it cannot be overridden. We can also use final in Java to make sure that a class cannot be inherited. 
// Similarly, the latest C++ standard C++ 11 added final. Use of final specifier in C++ 11: 
// Sometimes you don’t want to allow derived class to override the base class’ virtual function. C++ 11 allows built-in facility to prevent overriding of virtual function using final specifier. 

//agr hum base class k func  k age final lagade to vo error dedeg (bcs die to final derived class cannot override vritual base function);

//! this keyword
// The this keyword in C++ is a special pointer that points to the object that is currently executing a member function. 
// It is used within a class’s member functions to refer to the invoking object, allowing you to differentiate between member variables and parameters with the same name, chain member function calls.
#include<iostream>
using namespace std;

class Rectangle {
private:
    int length, width;
public:
    Rectangle(int length, int width) {// Constructor
        // Using 'this' to differentiate between member variables and parameters
        this->length = length;
        this->width = width;
    }
};
int main() {
    Rectangle rect(10, 5);
    return 0;
}

//! new keyword & delete keyword
#include <iostream>
using namespace std;

class NewExample1 {
public:
    // Method to display a message
    void display() {
        cout << "Invoking Method" << endl;
    }
};
int main() {
    NewExample1* obj = new NewExample1; // Creating an object of the class dynamically using 'new'
    obj->display();
    // It is used to create the object,It allocates the memory at runtime.,ll objects occupy memory in the heap area.It invokes the object constructor.
    delete obj;// Deleting the dynamically allocated object to free memory
}

//! const keyword
// In C++, the const keyword is used to define constants and enforce immutability. It can be applied to variables, pointers, member functions, and function arguments, among other things. 
// Using const correctly can help make your code safer and more efficient by preventing unintended modifications.
const int* ptr = &maxValue;
// *ptr = 200; // Error: cannot modify the data through the pointer