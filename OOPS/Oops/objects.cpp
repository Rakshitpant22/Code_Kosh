// A structure is a convenient tool for handling a group of logically related data items. 
// It is a user-defined data type with a template that serves to define its data properties. 
// Once the structure type has been defined, we can create variables of that type using declarations that are similar to the built-in type declarations.

//! Limitations of C Structure
The standard Cdoes not alow the struct data type to be treated like built-in types. ex:
struct complex{
float x;
float y:
};

struct complex cl, c2, c3;

// The complex numbers c1, c2, and c3 can easily be assigned values using the dot operator, but we cannot add two complex numbers or subtract one from the other. For example,
// c3 = cl + c2; is illegal in C.
// Another important limitation of C structures si that they do not permit data hiding. 
// Structure members can be directly accessed by the structure variables by any function anywhere in their scope. 
// In other words, the structure members are public members.

//! Member functions can be defined in two places --> Outside & Inside  the class definition.

//& Outside the class definition :
return_type class-name :: function_name (argument declaration){
Function body
}    
ex:  

 void item :: getdata(int a, float b){
    number = a; 
    cost = b;
}

//& Inside the Class Definition
 class item{
 int number; float cost;
 public:
 void getdata(int a, float b);//inline  function 
};




//! FRIEND FUNCTIONS:
// The function definition does not use either the keyword friend or the scope operator ::.
// The functions that are declared with the keyword friend are known as friend functions. Afunction can be declared as a friend in any number of classes. 
// A friend function, although not a member function, has full access rights to the private members of the class.

//& A friend function possesses certain special characteristics:
-> It is not in the scope of the class to which it has been declared as friend.So It can be invoked like a normal function without the help of any object of that class
-> Unlike member functions, it cannot access the member names directly and has to use an object name and dot membership operator with each member name.(e.g. A.x).
-> It can be declared either in the public or the private part of a class without affecting its meaning.
-> Usually, it has the objects as arguments

#include <iostream>
using namespace std;

class sample{
int a;
int b;

public: 
void setvalue(){
    a=25;b=40;
    } 
friend float mean(sample s); //we have to pass object to friend function
};

float mean(sample s){
    return float(s.a+s.b)/2.0;
}

 int main(){
    sample x;
    x.setvalue();
    cout<<mean(x);
 }
// Friend function accesses the class variables a and b by using the dot operator and the object passed to it. 
// The function call mean(x) passes the object x by value to the friend function;


//friend function ex:
#include <iostream>
using namespace std;

class ABC; //Forward declaration 
// The function max has arguments from both XYZ and ABC. When the function max is declared as a friend in XYZ for the first time, 
// The compiler wil not acknowledge the presence of ABC unless its name is declared in the beginning as class ABC; This is known as 'forward' declaration.
class XYZ{
int x ; 
public:
void setvalue(int i){
 x=i;
} 
friend void max(XYZ,ABC);
};

class ABC{
int y ; 
public:
void setvalue(int i){
 y=i;
} 
friend void max(XYZ,ABC);
};

void max(XYZ b,ABC a){ //DEfinition  of friend
   if(b.x>=a.y){
    cout<<b.x;
   }
   else 
      cout<<a.y;
}
int main(){
    ABC abc;
    abc.setvalue(123);
    XYZ xyz;
    xyz.setvalue(233);
    max(xyz,abc);
}