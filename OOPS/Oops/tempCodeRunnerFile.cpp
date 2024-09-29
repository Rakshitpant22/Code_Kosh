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
std::cout << &e2 << std::endl;  /