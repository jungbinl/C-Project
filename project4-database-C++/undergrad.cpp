
// Q2a: Define displayInfo() (5 points)
// Define the fucntion displayInfo() for Undergrad class
// See expected output in question file.
#include <iostream>
#include "undergrad.h"
using namespace std;
Undergrad::Undergrad(string a, int b, studentType c) : Student(a, b, c) {

}
void Undergrad::displayInfo() {
	cout << "Undergrad student: " << Student::getName() << endl;
	cout << "Roll number: " << Student::getRollNo() << endl;

}
// (displayList() function in main.cpp can call this function.)
// Include necessary header files
