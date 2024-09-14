//! Exception Handling in C++

// Exception handling in C++ is a mechanism used to handle runtime errors, providing a way to react to exceptional circumstances (like dividing by zero, memory allocation failures, etc.) in a controlled manner. This helps to make your program robust and prevents it from crashing unexpectedly.

// Key Concepts
// 	1.	Exceptions:
// 	•	An exception is an error or unexpected event that occurs during the execution of a program.
// 	•	When an exception is detected, it can be “thrown” using the throw keyword.

// 	2.	Try Block:
// 	•	A try block is used to enclose the code that might throw an exception.
// 	•	If an exception occurs within the try block, control is transferred to the corresponding catch block.

// 	3.	Catch Block:
// 	•	A catch block handles the exception thrown by the try block.
// 	•	It is defined with a parameter that matches the type of the exception thrown.

// 	4.	Throw Keyword:
// 	•	The throw keyword is used to signal the occurrence of an exception.
// 	•	It transfers control to the nearest enclosing catch block.

// 	5.	Standard Exception Handling:
// 	•	The C++ Standard Library provides a base class std::exception and various derived classes like std::runtime_error, std::out_of_range, etc.

#include <iostream>
using namespace std;

double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw "Division by zero error!";
    }
    return numerator / denominator;
}

int main() {
    double num, den, result;

    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> den;

    try {
        result = divide(num, den);
        cout << "Result: " << result << endl;
    } catch (const char* e) {
        cout << "Error: " << e << endl;
    }

    return 0;
}

//! exception class
                                             STD : EXCEPTION
                                                   ⬇️
----------------------------------------------------------------------------------------------------------------------                              
⬇️                       ⬇️                   ⬇️                    ⬇️                    ⬇️                          ⬇️
std:runtime_error    std:bad_alloc       std:bad_exception       std:bad_alloc     std:bad_cast           logic_failure
                                                                                                   
⬇️                                                                                                                   ⬇️
-------------------------------------------                      --------------------------------------------------------
⬇️                   ⬇️                    ⬇️                     ⬇️             ⬇️                  ⬇️                   ⬇️
std:overflow_error  std:range_error  std:underflow_error    std:domain_error  std:invalid_argument  std:length_error  std:out_of_range


#include<iostream>
using namespace std;
int main()
{
  return 0;
}