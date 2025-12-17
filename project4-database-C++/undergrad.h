#ifndef _UNDERGRAD_H
#define _UNDERGRAD_H
#include <string>
#include "student.h"
using namespace std;
class Undergrad : public Student {
public:
	Undergrad();
	Undergrad(string, int, studentType);
	virtual void displayInfo() override;
};

#endif // _UNDERGRAD_H
