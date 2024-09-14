

//! STATIC 
//they are attribute of classes or class member ,it is declared using static keyword
/* 
• It is initialized to zero when the first object of its class is created. No other initialization is permitted.
• Only one copy of that member is created for the entire class and is shared by all the objects of that class, no matter how many objects are created.
• It is visible only within the class, but its lifetime is the entire program.
*/

// practical need 
// -> In a certain bank for same accnt type same class is prewritten so every time new customer is registered for that same class is called
// -> To calculate the no of accounts of same type we need a variable to cnt these accnts for that static is used 

//-> to know how much balaance is in the entire bank
class customer{
    string name; int account_num,balance; // ye har object k lie har bar create honge(alag copy bnegi)
public:
    static int totalcustomers; // but iski 1 hi copy bnegi ie (ye har object k lie call nhi hoega bar bar) all object ka totalcust points to single copy 
    // this is part of the class (attribute of class) // as its static class memeber so it can be called directly withit objects
    customer(string a,int acc,int,bal){
    name=a;
    account_num=acc;
    balance=bal;
    totalcustomers++;
}

};
int customer:: totalcustomers=0; //! definition of static data member 

int main(){
    customer a1("deepak",2345,12345);
    customer a2("raman",2325,2235);

}

// Note that the type and scope of each static member variable must be defined outside the class definition. 
// This is necessary because the static data members are stored separately rather than as a part of an object. 
// Since they are associated with the class itself rather than with any class object, they are also known as class variables.

// another implementation of static -> is static meber functions
//! we want to acceess private static member with help of  class  only ::--> static meber function is used

#include<iostream>
using namespace std;

class customer{
    string name; int account_num,balance; // ye har object k lie har bar create honge(alag copy bnegi)
    static int totalcustomers; 
public:
customer(string a,int acc,int bal){
    name=a;
    account_num=acc;
    balance=bal;
    totalcustomers++;
}
void display_total(){
    cout<<"by object:"<<totalcustomers<<endl;
}
static void nowdisplay(){
     cout<<"BY STATIC MEMEBR FUNCTION:"<<totalcustomers<<endl;
}

};
int customer:: totalcustomers=0; 

int main(){
    customer a1("deepak",1,12345);
    customer a2("raman",2,2235);
    a2.display_total();  // using objects 
    customer a3("raman",3,2235);
    // customer::display_total(); //!error: call to non-static member function without an object argument 
    // bcs objects can only access display_total() but we cannot d this way by class

    // this can be done by static member function 
    // but static member function can only acces static memebrs onlyyy
    customer::nowdisplay();

}

//! Const Member Functions
//Const member functions ensure that an object’s state is not modified when these functions are called.
// If a member function does not alter any data ni the class, then we may declare ti sa a const member function as follows:
void mul(int, int) const; 
double get_balancel() const;

// practical example of a class representing a Book in a library management system. We will use const in various places to ensure immutability and safety.

