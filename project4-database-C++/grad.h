#ifndef _GRAD_H_
#define _GRAD_H_
#include <string>
#include "student.h"
using namespace std;

class Grad : public Student {
public:
	Grad();
	Grad(string, int, studentType);
	virtual void displayInfo() override;
};

#endif // _GRAD_H_
