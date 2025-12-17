#include <iostream>
#include "grad.h"
using namespace std;
Grad::Grad(string a, int b, studentType c) : Student(a, b, c) {

}
void Grad::displayInfo() {
	cout << "Undergrad student: " << Student::getName() << endl;
	cout << "Roll number: " << Student::getRollNo() << endl;

}


