//!“polymorphism"
It simply means 'one name, multiple forms'.
The word “polymorphism” means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form. 


                                         POLYMORPHISM
                                             |
                    --------------------------------------------------------   
                    |                                                       |
                COMPILE TIME                                              RUNTIME
                    |                                                        ⬇️   
          ----------|------------                                       Virtual function   
          ⬇️                    ⬇️                                                                                                  virtual functions
       function              operator                                  
     overloading            overloading

//It would be nice if the appropriate member function could be selected while the program is running. This is known as run time polymorphism. 
// How could it happen? C+ supports a mechanism known as virtual function to achieve run time polymorphism.
// At run time, when it is known what class objects are under consideration, the appropriate version of the function is invoked. Since the function is linked with a particular clas much later after hte compilation, this process is termed as late binding. It si also known sa dynamic binding because the selection of the appropriate function is done dynamically at run time.
// Dynamic bindings is one of the powerful features of C++. This requires the use of pointers ot objects. We shall discuss in detail how the object pointers and virtual functions are used to implement dynamic binding.

//^ Function overloading
//  It is a feature in object-oriented programming where multiple functions have the same name but different parameters (different number of arguments or types of arguments).
// Purpose:
// 	•	To perform different tasks under a single function name, improving code readability and organization.
// Key Points:
// 	1.	Same Name, Different Parameters:
// 	•	Functions are distinguished by the number of arguments or types of arguments they accept.
// 	2.	Types of Overloading:
// 	•	Change in Number of Arguments:

#include <iostream>
using namespace std;

class AreaCalculator {
private:
    double area;

public:
    AreaCalculator(double side) {//square
        area = side * side;
    }
    AreaCalculator(double length, double width) {//rectangle
        area = length * width;
    }
    AreaCalculator(double radius, bool isCircle) {//circle
        area = 3.14159 * radius * radius;
    }
    void displayArea() {
        cout << "Area: " << area << endl;
    }
};
int main() {
    AreaCalculator square(5.0);            
    AreaCalculator rectangle(10.0, 4.0);   
    AreaCalculator circle(3.0, true);      

    square.displayArea();     
    rectangle.displayArea();  
    circle.displayArea();     
}

//^ Operator overloading
// allows operators to have different meanings based on the data types of their operands, enabling custom behavior for operators with user-defined types.
// Key Points:

// 	1.	Custom Behavior:
// 	•	Operators can be given custom functionality for user-defined types (e.g. classes).

// 	2.	Syntax:
// 	•	The operator keyword is used to define an operator function.
// 	•	The function can be a member or a non-member function.

// 	3.	Types of Overloadable Operators:
// 	•	Arithmetic operators (+, -, *, /)
// 	•	Relational operators (==, !=, <, >)
// 	•	Logical operators (&&, ||, !)
// 	•	Assignment operators (=, +=, -=)
// 	•	Increment and decrement operators (++, --)
//~ •   except a few like ::, ., .*, and ?:

#include <iostream>
#include <string>
using namespace std;

class String {
private:
    string str;

public:
    String(const string &s) : str(s) {}

    // Overload + operator to concatenate strings
    String operator+(const String &other) {
        return String(str + other.str);
    }

    void display() const {
        cout << str << endl;
    }
};

int main() {
    String s1("Hello, ");
    String s2("World!");

    String s3 = s1 + s2;  // Uses overloaded + operator
    s3.display();  // Output: Hello, World!

    return 0;
}
 
// example:
#include<iostream>
using namespace std;
class Complex{
    int real;
    int img;

    public :
    Complex(){

    }
    Complex(int real,int img){ //constructor 
        this->real=real;
        this->img=img;
    }
    void display(){
        cout<<real<<"+i "<<img<<endl;
    }
    //^ Operator overloading 
    //! withina class we can acces private members of same type of object
    Complex operator-(Complex const &c){ //paseed as a reference
       Complex res;
       res.real= real + c.real;
       res.img = img + c.img;
       return res;
    }
};
int main()
{
Complex c1(3,9);
Complex c2(4,3);
Complex c3=c1-c2; 
c3.display(); 
}
//! Operator overloading allows us to define the behavior of operators (like +) for user-defined types (like Complex).
//! we can use operator as a function (operator overloading)
//~ no matching constructor for initialization of 'Complex'
//~ occours because we have make res object for which tere is no constructor so we have to make default constructor

//^! Runtime Polymorphism / Late binding / dynamic polymorphism
This type of polymorphism is achieved by Function Overriding.The function call is resolved at runtime in runtime polymorphism. 
In contrast, with compile time polymorphism, the compiler determines which function call to bind to the object after deducing it at runtime.

#include<iostream>
using namespace std;

class Animal{
    public:
    virtual void speak() {
        cout<<"huhuhu"<<endl;
    }
};
class Dog :public Animal{
    public:
    void speak(){
     cout<<"Bark"<<endl;
    }

    void temp(){
        cout<<"only in derived class"<<endl;
    }
};
int main()
{
    Animal *p;
    p=new Dog();
    p->speak();  // if virtual is not declared then prints huhuhu else bark

// In the main function, an Animal pointer p is used to point to a Dog object.
// The call to p->speak() now invokes the speak() method of the Dog class, with the help of the virtual function mechanism.

    // p->temp(); //this cannot be called bcs temp is not a member in base class whose pointer is called
               // ie agr base class m function ha tabhi use derived m compile/runtime m access kr skte hai
}

//? Need
// hum virtual ka use islea krte h kyuki hum nahi chahte base class ka function call ho islea child class m us func is override krna compulsory hai 
// agr hum pointer ki help s parent se child ko call krvate hai to early binding se parent vala func chal jaega
// so we have to make parent class func virtual to stop its early binding (prevously compiler was deciding on the pointer type that which class func is called)

//! Actual Use of Virtual Functions
// A virtual function is a member function that is declared in the base class using the keyword virtual and is re-defined (Overridden) in the derived class.
//     Virtual functions are Dynamic in nature. 

//     They are defined by inserting the keyword “virtual” inside a base class and are always declared with a base class and overridden in a child class
//     A virtual function is called during Runtime
//     Virtual functions are used to achieve runtime polymorphism in C++, allowing you to call derived class methods through base class pointers or references. 
//     This is particularly useful in situations where the exact type of the object is not known until runtime. 

// Here are some practical scenarios where virtual functions are beneficial:
// --> Frameworks and Libraries:
// 	•	Designing extensible and maintainable frameworks and libraries.
// 	•	Providing a base class with default implementations that can be overridden by users.

// --> Interface Design:
// 	•	Defining interfaces that can be implemented by multiple derived classes.
// 	•	Allowing for flexible and reusable code.

// -->	.	Dynamic Behavior:
// 	•	Enabling dynamic method dispatch based on the actual object type.
// 	•	Allowing derived classes to override base class methods to provide specific behavior.


//!    PURE VIRTUAL FUNCTION:
//  A pure virtual function in C++ is a virtual function that has no implementation in the base class and must be overridden in any derived class.

//!  ABSTRACT CLASS
//~ A class that contains at least one pure virtual function is called an .Abstract classes cannot be instantiated directly; they are meant to be inherited by other classes.
//~ we cannot create object for abstract class/ (we cannot instantiate abstaract class)
//! jab m chahta hu ki meri class ka object kabhi create na ho vaha m abstract class bnata hu 
//  In java we can directly create abstract class using Keyword= abstract  but in c++ we have to create pure virtual func in a class
// agr abstract class bnai h to uski derived class bnani hi pdegi to use base/abstract class(as abstract class ka object nhi bn paega)

// Key Concepts

// 	1.	Pure Virtual Function:
// 	•	Declared by assigning 0 to the virtual function.
// 	•	Must be overridden by any non-abstract derived class.

// 	2.	Abstract Class:
// 	•	Contains at least one pure virtual function.
// 	•	Cannot be instantiated directly.
// 	•	Serves as a blueprint for derived classes.

// 	3.	Derived Classes:
// 	•	Must provide implementations for all pure virtual functions in the base abstract class to be instantiable.

//declaration:
virtual void func_name()=0; //~ Pure virtual function

//! In C++, the constructor cannot be virtual;
// because when a constructor of a class is executed there is no virtual table in the memory, means no virtual pointer defined yet. 
// So, the constructor should always be non-virtual.

//! virtual destructor is possible;
//~ Deleting a derived class object using a pointer of base class type that has a non-virtual destructor results in undefined behavior. 
//~ To correct this situation, the base class should be defined with a virtual destructor. 
// For example, the following program results in undefined behavior. 

// CPP program without virtual destructor 
// causing undefined behavior
#include <iostream>
using namespace std;

class base {
public:
	base()	 
	{ cout << "Constructing base\n"; }
	~base()
	{ cout<< "Destructing base\n"; }	 
};

class derived: public base {
public:
	derived()	 
	{ cout << "Constructing derived\n"; }
	~derived()
	{ cout << "Destructing derived\n"; }
};

int main()
{
derived *d = new derived(); 
base *b = d;
delete b;
getchar();
return 0;
}
//!Here the derived constructor is actually being called, but the derived destructor is not called when you delete the object through a pointer of type base. 
//! This happens because the destructor in the base class is not declared as virtual.


// A program with virtual destructor
#include <iostream>

using namespace std;

class base {
public:
	base()	 
	{ cout << "Constructing base\n"; }
	virtual ~base()
	{ cout << "Destructing base\n"; }	 
};

class derived : public base {
public:
	derived()	 
	{ cout << "Constructing derived\n"; }
	~derived()
	{ cout << "Destructing derived\n"; }
};

int main()
{
derived *d = new derived(); 
base *b = d;
delete b;
getchar();
return 0;
}

