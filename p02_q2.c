#include <stdio.h>

// CSE 220 project 02 Question 3 (25 points)
// Before starting to edit, please compile and run this program. 
// You will first notice that the program will not compile. Fix the error(s).
// Next, you will notice that the program is printing incorrect information. Fix the errors (2.5 points) and write error types(2.5 points).
void main() {

	// Problem 1: (5 points)
	// The statement below should cause the program to not compile. Correct the error(s). (2.5 points).

	float num1 = 50.2;
	int num2 = 10;
	printf("num1= %f, num2= %d\n", num1, num2);

	// Write error type in blank below  (2.5 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Syntactic Error - not defined num2, Semantic Error - 50.2 is not int type, num1 is float, use %%f not %%d \n\n");

	// Problem 2: (5 points)
	// A garbage value is printed. Correct the error(s).
	float num3 = num1 + num2;
	printf("num3= %f\n", num3);

	// Write error type in blank below  
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Semantic Error : num3 is float not int, so we have to use %%f not %%d \n\n");

	// Problem 3: (5 points)
	// The program does not print any of the three statements. Correct the error(s). 
	int num4 = 5;

	if (num4 == 0)
	{
		printf("num4 is equal to %d.\n", num4);
		printf(" So num4 is 0.\n");
	}

	if (num4 > 0)
	{
		printf("num4 is equal to %d.\n", num4);
		printf("So num4 is positive.\n");
	}

	if (num4 <= 0)
	{
		printf("num4 is equal to %d.\n", num4);
		printf("So num4 is negative.\n");
	}

	// Write error type in blank below  
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Semantic Error : if(num = 0), we have to use right operation, Syntactic error : wrong operation it is <= not =< \n\n");

	// Problem 4: (5 points)	
	// The program prints that 20 is an odd number. Correct the error(s).
	int num5 = 20;

	if (num5 % 2 != 0)
		printf("%d is an odd number.\n", num5);
	if (num5 % 2 == 0)
		printf("%d is an even number.\n", num5);

	// Write error type in blank below  
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Contextual Error : we have to use %% operation when we decide odd even number \n\n");

	// Problem 5: (5 points)
	// We want to print "I study in CSE 220 and hoping to get A grade.". Correct the error(s). 
	int courseNum = 220;
	char grade = 'A';
	printf("I study in CSE %d and hoping to get %c grade.\n", courseNum, grade);

	// Write error type in blank below  
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Semantic Error : %%f is for float number, but since grade is char type, we have to use %%c \n\n");

	system("pause");	// needed to keep console open in VS
}
