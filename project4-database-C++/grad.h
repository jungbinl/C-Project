#ifndef _GRAD_H_
#define _GRAD_H_
#include <string>
#include "student.h"
// Q1b: Create Grad class (5 points)
// Part 1: Create a child class of the Student class named 'Grad'
using namespace std;

class Grad : public Student {
public:
	Grad();
	Grad(string, int, studentType);
	virtual void displayInfo() override;
};

// Part2: Declare constructor which accepts the same 3 parameters as the parent class Student's constructor.
// Pass the 3 parameters to the super constructor of the Student class.

// Part 3: Re-declare the method displayInfo (virtual method found inside of parent class Student)

#endif // _GRAD_H_