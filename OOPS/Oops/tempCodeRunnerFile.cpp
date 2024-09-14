#include<iostream>
using namespace std;

class Animal{
    public:
     void speak(){
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