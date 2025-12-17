#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>
using namespace std;

enum studentType { undergrad = 0, grad };	// definition of studentType

class Student {
private:
	string name; // private local variables
	int rollNo;
	studentType level;

public:
	Student(string studentName, int studentRollNo, studentType studentLevel); // constructor

	// accessor methods
	string getName();
	int getRollNo();
	studentType getstudentType();
	virtual void displayInfo()
	{}
	friend void changeRollNo(Student*, int);

};


#endif // _STUDENT_H_
