#ifndef _UNDERGRAD_H
#define _UNDERGRAD_H
#include <string>
#include "student.h"
// Q1a: Create Undergrad class (5 points)
// Part 1: Create a child class of the Student class named 'Undergrad'
using namespace std;
class Undergrad : public Student {
public:
	Undergrad();
	Undergrad(string, int, studentType);
	virtual void displayInfo() override;
};
// Part2: Declare constructor which accepts the same 3 parameters as the parent class Student's constructor.
// Pass the 3 parameters to the super constructor of the Student class.

// Part 3: Re-declare the method displayInfo (virtual method found inside of parent class Student)

#endif // _UNDERGRAD_H