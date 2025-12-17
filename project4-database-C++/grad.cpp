
// Q2b: Define displayInfo() (5 points)
// Define the function displayInfo() for Grad class.
// See expected output in question file.
#include <iostream>
#include "grad.h"
using namespace std;
Grad::Grad(string a, int b, studentType c) : Student(a, b, c) {

}
void Grad::displayInfo() {
	cout << "Undergrad student: " << Student::getName() << endl;
	cout << "Roll number: " << Student::getRollNo() << endl;

}
// (displayList() function in main.cpp can call this function.)
// Include necessary header files
