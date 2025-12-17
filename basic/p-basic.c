#include <stdio.h>

void main() {

	float num1 = 50.2;
	int num2 = 10;
	printf("num1= %f, num2= %d\n", num1, num2);

	printf("Error Type: Syntactic Error - not defined num2, Semantic Error - 50.2 is not int type, num1 is float, use %%f not %%d \n\n");

	float num3 = num1 + num2;
	printf("num3= %f\n", num3);
	printf("Error Type: Semantic Error : num3 is float not int, so we have to use %%f not %%d \n\n");
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
	printf("Error Type: Semantic Error : if(num = 0), we have to use right operation, Syntactic error : wrong operation it is <= not =< \n\n");

	int num5 = 20;

	if (num5 % 2 != 0)
		printf("%d is an odd number.\n", num5);
	if (num5 % 2 == 0)
		printf("%d is an even number.\n", num5);
	
	printf("Error Type: Contextual Error : we have to use %% operation when we decide odd even number \n\n");
	int courseNum = 220;
	char grade = 'A';
	printf("I study in CSE %d and hoping to get %c grade.\n", courseNum, grade);
	printf("Error Type: Semantic Error : %%f is for float number, but since grade is char type, we have to use %%c \n\n");

	system("pause");	// needed to keep console open in VS
}

