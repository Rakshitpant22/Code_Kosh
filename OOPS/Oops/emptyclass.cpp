//! Concept of empty class having 1 byte 

#include<iostream>
using namespace std;
class Empty {
};

int main() {
    Empty e1, e2;
    std::cout << "Size of empty class: " << sizeof(Empty) << std::endl;
    std::cout << "Address of e1: " << &e1 << std::endl;
    std::cout << "Address of e2: " << &e2 << std::endl;
    return 0;
}

//! an empty class has a size of 1 byte to ensure that each object of that class has a unique address.
//  The decision to make the size of an empty class 1 byte in C++ is a practical compromise 
//? To ensure that each object has a unique address and that pointer arithmetic, memory allocation, and object lifetime management function correctly.
//? This design choice avoids the complications and undefined behavior that would arise if empty classes had a size of 0 bytes.


class Empty {};
Empty e1, e2;
std::cout << &e1 << std::endl;  // Prints address of e1
std::cout << &e2 << std::endl;  // Should print a different address
//If sizeof(Empty) were 0, both addresses could be the same, leading to undefined behavior when accessing or modifying e1 and e2.


//! Padding concept
class a {
    char c; // 1 byte
    int  a; // 4 byte
    char b; // 1 byte
};
 int main() {
     std::cout << "Size of empty class: " << sizeof(a) << std::endl; 
     return 0;
 }
// it should return size of all class datatypes but that's not the case
// our Operating System reads the data by dividing into segments and for each segment the next data goes to another memory segment thats why:

// Rule in padding --> place datatypes in multiple of size 
//                 --> final memory size must be a multiple of largest datatype of class
// the greedy allignmnet also reduces the memory allocation for class (fromt low to large size datatypes)


