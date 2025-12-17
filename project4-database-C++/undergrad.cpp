
#include <iostream>
#include "undergrad.h"
using namespace std;
Undergrad::Undergrad(string a, int b, studentType c) : Student(a, b, c) {

}
void Undergrad::displayInfo() {
	cout << "Undergrad student: " << Student::getName() << endl;
	cout << "Roll number: " << Student::getRollNo() << endl;

}


