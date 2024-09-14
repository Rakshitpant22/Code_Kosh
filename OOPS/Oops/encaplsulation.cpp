//! Encapsulation 
In C++ is defined as the wrapping up of data and information in a single unit
Encapsulation is defined as binding together the data and the functions that manipulate them.

Two Important  property of Encapsulation 
//& > Data Protection: 
    • Encapsulation protects the internal state of an object by keeping its data members private. 
    • Access to and modification of these data members is restricted to the class's public methods, ensuring controlled and secure data manipulation.
//& > Information Hiding: 
	• Internal implementation details are hidden from external code.
	• Only the public interface is exposed, allowing for abstraction and easier maintenance.


//! Abstraction
Data abstraction is a core feature of object-oriented programming that involves providing only essential information to the outside world while hiding the implementation details.
Types of Abstraction:

	1.	Data Abstraction:    Focuses on providing only necessary information about data, ignoring unnecessary details.
	2.	Control Abstraction: Focuses on providing only necessary information about implementation, ignoring unnecessary details.

Abstraction in C++:

	1.	Using Classes:
        •	Classes group data members and functions.
	    •	Access specifiers (public, private) control visibility of class members.
	2.	Using Header Files:
        •	Functions like pow() in math.h provide functionality without revealing the underlying implementation.
	3.	Using Access Specifiers:
	    •	Public Members: Accessible from anywhere in the program.
	    •	Private Members: Accessible only within the class.
	    •	Public members can interact with private members, enforcing controlled access.

Implementation:
	•	Mark internal implementation details as private.
	•	Expose necessary information via public methods.