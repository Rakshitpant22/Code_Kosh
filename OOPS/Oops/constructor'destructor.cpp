//! CONSTRUCTOR 
// A constructor is a special member function with the same name as the class, invoked to initialize objects when they are created.
// A constructor that accepts no parameters is called the default constructor. 
// The default constructor for class A is A(). If no such constructor is defined, then the compiler supplies a default constructor. ex  A a;
// Constructors should be declared in PUBLIC:
#include<iostream>
using namespace std;

class customer{
 int a;
 string b;
 public:
 customer(){   //!default constructor
 cout<<"default constructor ";
 }
 customer(int a,string b){ //!parameterized constructor
 this->a=a;  // this points to the particular object that is formed (address store krke rkhta h object ka jisne call kia h)
 this->b=b;
 cout<<"parameterised constructor ";
 }
 inline customer(int aa,string bb): a(aa),b(bb) {//!Inline constructor
 }

};
int main(){
    customer c1; // invokes the default constructor of the compiler to create the object 
    customer c2(123,"RAMA");
    customer c3(c2);//! Copy constructor
}

// The constructor functions have some special characteristics,
// •	They are declared in the public section and invoked automatically when objects are created, with no return type.
// •	They cannot be inherited but can be called by derived class constructors and can have default arguments.
// •	They cannot be virtual, their addresses cannot be referenced, and they make implicit calls to new and delete for memory allocation.

//! constructor overloading-->
// when name of constructor are same but have different parameters 

// A reference variable has been used as an argument to the copy constructor. We cannot pass the argument by value to a copy constructor.
// When no copy constructor is defined, the compiler supplies its own copy constructor.

//! dynamic constructor
// It is used to allocate the memory to the objects at the runtime
// All other constructor allocate memory at compile time 
// It's done with the help of 'new' operator and with this we can dynamically allot memory  as per user need(flexible)

example: 
class customer{
 int size;
 int *p;

 public:
 customer(){
    size=s;
    p= new int[size];
 }
};

//!DESTRUCTOR  
// It is the last function that is going to be called before an object is destroyed
// called by same name as custructor but uses(~) before name 
// they are automatically called if not made and release the dynamically allocated memory 
//~ if we specifically call destructor than it our task to free the memory alloted

ex:
class customer{
    public:
    string name;
    int *balance;
    
    customer (string name,int bal){
        this.name=name;
        balance= new int;
        *balance=bal
    }
    ~customer(){
        delete balance;  // It does'nt delete the object but deletes the memory dynamically allocated to it(release the memory)
    }
}

// here name etc are stored in stack memory and once object created then it gets removed from the stack  and gets destroyed by themselves
// for dynamically allocated memory we use destructors;

// Use Cases of Destructors
// 1.	Memory Management  • Releasing dynamically allocated memory to prevent memory leaks.
// 2.	Resource Management• Closing file handles, network sockets, or releasing other system resources.
// 3.	RAII (Resource Acquisition Is Initialization)• Ensuring that resources are properly acquired and released by binding their lifecycle to the lifespan of objects.


//  ! Construction and Destruction Order

//& 	1.	Construction Order:
// 	•	When objects are constructed, they are initialized in a specific order. For example, if you have a base class and a derived class, the base class constructor is called first, followed by the derived class constructor.
// 	•	Similarly, if you have member objects within a class, they are constructed in the order they are declared within the class.

//& 	2.	Destruction Order:
// 	•	Destructors are called in the reverse order of construction. This means that the most recently constructed object is the first to be destroyed.

//! REASON reverse Destruction Order:

#include <iostream>
class Base {
public:
     Base() { std::cout << "Base Constructor" << std::endl; }
    ~Base() { std::cout << "Base Destructor" << std::endl; }
};

class Derived : public Base {
public:
     Derived() { std::cout << "Derived Constructor" << std::endl; }
    ~Derived() { std::cout << "Derived Destructor" << std::endl; }
};

int main() {
    Derived d;
    return 0;
}
//output
Base Constructor
Derived Constructor
Derived Destructor
Base Destructor

//reason
//! 1.	Construction:
// 	• The Base constructor is called first, followed by the Derived constructor.This ensures that the base part of the derived object is initialized first.
//! 2.	Destruction:
// 	• The Derived destructor is called first, followed by the Base destructor. 
//  • Reverse order ensures that the resources and dependencies managed by the Derived class are cleaned up before the Base class is destroyed.

//  Destructors are called in reverse order of construction to ensure proper resource management and to handle dependencies between objects correctly. 
//  This prevents potential issues that could arise if dependent objects were destroyed while their dependencies were still active.  EX
//^ EX agr same order hota to pehle base class hi ud jati to derived class jo dependent hai base p vo kaam kr nhi pata or active bhi rehti