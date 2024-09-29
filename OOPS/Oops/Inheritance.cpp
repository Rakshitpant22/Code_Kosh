//! Inheritance
capability of a class to derive property & characterstics from another class 

Access Modifier and inheritance

               external code   within class    derived class
PUBLIC :         ✅                ✅                ✅

PROTECTED:       ❌                ✅                ✅

PRIVATE:         ❌                ✅                ❌  


//! how to make derived class:

//^ class child_classname: access_modifier parent_classname;

#include<iostream>
using namespace std;
class human{
public:
 string name;
 int age,weight;
};

class student: protected human{
    int rollno,fees;

};
int main()
{
    student a;
    a.name="raman";  // error= 'name' is a private member of 'human' if name in human class was private same for protected
  return 0;
}


//!type of inheritance 

//^ 1. single inheritance     🎁
                              ⬇️
                              🎁

#include<iostream>
using namespace std;
class human{
  protected:
 string name;
 int age;

public:
void work(){
    cout<<"working<<endl";
}
};

class student: public human{ // protected members of base class becomes protected in derived class 
    int rollno,fees;
    public:
    student(string name,int age,int rollno,int fees){ //constructor
        this->name=name;
        this->age=age;
        this->rollno=rollno;
        this->fees=fees;
    }

};
int main()
{
    student s1("Aditya",23,2345,12000);
    s1.work(); // as work function base class m public or derived m public rhega to we can access outside by child object
  
}

can also be done by this way:

#include<iostream>
using namespace std;
class human{

 protected:
 string name;
 int age;

public:
human(string name,int age){
    this->name=name;
    this->age=age;
    cout<<"base constructor"<<endl;
}
void display(){
        cout<<"BASE:"<<name<<" "<<age<<" "<<endl;
    }
};

class student: public human{ // protected members of base class becomes protected in derived class 
    int rollno,fees;
    public:
    student(string name,int age,int rollno,int fees): human(name,age) { // pehle parent constructor caal kia fir child ka call hua
        // this->name=name;
        // this->age=age;
        this->rollno=rollno;
        this->fees=fees;
        cout<<"derived constructor"<<endl;
    }
    void display(){
        cout<<"DERIVED:"<<name<<" "<<age<<" "<<fees<<endl;
    }

};
int main()
{
    student s1("Aditya",23,2345,12000);
    //s1.name="raj"; this shows error bc name is protected and can be accesed by derived and base class only not in external code
    s1.display();
    //agr same display base or derived m likha ho to jiska object call hua h us class ka function run hoga 
  
}

//^ 2. Multilevel inheritance    🎁     person    or  animal
                                 ⬇️       
                                 🎁      employee     dog
                                 ⬇️
                                 🎁      manager     pitbull
#include<iostream>
using namespace std;

class Person{
    protected:
    string name;

    public:
    void intro(){
        cout<<"my name is:"<<name<<endl;
    }
};
class Employee: public Person{
    protected:
    int  salary;
    
    public:
    void mysalary(){
        cout<<"my salary is:"<<salary<<endl;
    }
};
class Manager: public Employee{
    public:
    string  dept;
    
     Manager(string name,int salary,string dept){
        this->name=name;
        this->salary=salary;
        this->dept=dept;
    }
    void work(){
        cout<<"I am head of dept:"<<dept<<endl;
    }
};

int main()
{
  Manager a1("Rakshit",18000000,"TECH");
  a1.work();
  a1.mysalary();
  a1.intro();
  return 0;
}



//^ 3. Multiple inheritance      🎁      🎁 ....
                                     ⬇️
                                     🎁
#include<iostream>
using namespace std;
class Engineer{
public:
string specialization;
void work(){
    cout<<"specialization in:"<<specialization<<endl;
}
};

class Youtuber{
    public:
    int subscribers;
    void contentcreator(){
        cout<<"have subs:"<<subscribers<<endl;
    }
};

class Codeteacher:public Engineer,public Youtuber{ //constructor bhi same order m call hoga first engineer and then for youtuber
    public:
    string name;

    Codeteacher(string name,string specialization,int subscribers){
        this->name=name;
        this->specialization=specialization;
        this->subscribers=subscribers;
    }
  void display(){
    cout<<name<<endl<<specialization<<endl<<subscribers<<endl;
  }
};
int main(){
    Codeteacher a("raha","iot",1234);
    a.work();
    a.display();
}


//^ 4. Hieraracical inheritance      🎁
                                     ⬇️
                                  🎁    🎁...


//^ 5. Hybrid inheritance-> combination of Hieraracical  & Multiple inheritance  
                                     🎁
                                     ⬇️
                                  🎁    🎁...
                                     ⬇️
                                     🎁  ...