// CSE220 Spring 2025, Project 3

// Your name here
// Programming environment used: VS or gcc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable : 4996)  // to avoid scanf error, Visual Studio only

#define MAX_DIM 3
#define STUDENTS 5		// total number of students
int matrixA[MAX_DIM][MAX_DIM], matrixB[MAX_DIM][MAX_DIM], sum[MAX_DIM][MAX_DIM];
int scores[STUDENTS];
int *pScores = NULL;

/*
Question 1: Forward declaration (5 points)
Declare here the functions used in the program, as needed
*/
// all void function no return
void inputMatrixA();
void copyToMatrixB();
void addMatrix();
void displaySumMatrix();
void inputScores();
void scoreStats();
void createUsername();
void lowerToUpperCase();
void searchPattern();
// DO NOT modify main()
int main()
{
	printf("\nProblem 2,3,4,5: \n");
	
	inputMatrixA();
	
	copyToMatrixB();

	addMatrix();

	displaySumMatrix();
	
	printf("\nProblem 6,7: \n");
	inputScores();

	scoreStats();
	
	getchar();
	// neded to flushout Enter(\n) character left behind. Comment out if not needed
	
	printf("\nProblem 8: \n");
	createUsername();

	printf("\n\nProblem 9: \n");
	lowerToUpperCase();

	printf("\nProblem 10: \n");
	searchPattern();

	return 0;
}




/*
Question 2: inputMatrixA (5 points)
matrixA[][] is already declared. Input the elements of matrixA from the user.
Use the macro MAX_DIM in your code, so that when MAX_DIM is changed from 3 to any other number, this function would still work.
Note: Usually, matrix is entered row-wise. So input 1st row of elemets , followed by 2nd row and so on.
*/
void inputMatrixA()
{
	for(int i = 0; i < MAX_DIM; i++){
		for(int j = 0; j <MAX_DIM; j++){
		      printf("Enter matrix element: ");
		      scanf("%d",&matrixA[i][j]);// take input
		      printf("%d", matrixA[i][j]);
		      printf("\n");
		}
	}
	      			      
}
/*

Question 3: copyToMatrixB (5 points)
matrixB[][] is already declared. Compose matrixB identical to matrixA.
Copy elements of matrixA to matrixB. You may use array operation or pointer to do the copying.
So, after calling this function, matrixB and matrixA should have same elements.
Use the macro MAX_DIM in your code, so that when MAX_DIM is changed from 3 to any other number, this function would still work.
Debug tip: Use display function below to temporarily display matrixA and matrixB to verify if your functions work correctly.
*/

void copyToMatrixB()
{
	for(int i = 0; i < MAX_DIM; i++){
		for(int j = 0; j < MAX_DIM; j++){
			matrixB[i][j] = matrixA[i][j]; // element-by-element copy
		}
	}
}


/*
Question 4: addMatrix (10 points)
sum[][] is already declared. Implement this math operation: (2*A) + B and store the result in matrix 'sum'.
Use the macro MAX_DIM in your code, so that when MAX_DIM is changed from 3 to any other number, this function would still work.
*/

void addMatrix()
{
	for(int i = 0; i < MAX_DIM; i++){
		for(int j = 0; j < MAX_DIM; j++){
			sum[i][j] = 2 * matrixA[i][j] + matrixB[i][j]; // basic calculation
		}
	}
}

/*
Question 5: displaySumMatrix (10 points)
Implement the function to display the 'sum' matrix. Display in this format :
The matrix sum=
1	2	3
4	5	6
7	8	9
*/

void displaySumMatrix()
{
	printf("\n");
	printf("The matrix 'sum' : ");
	printf("\n");
	for(int i = 0; i < MAX_DIM; i++){
		for(int j = 0; j < MAX_DIM; j++){
			printf("%d", sum[i][j]); // print each element
			printf("\t"); // with space
		}
		printf("\n");
	}
}

/*
Question 6: inputScores (10 points)
Input the scores of students.
The valid range of score is 0 to 100 (0 and 100 included). Keep prompting the user to input valid score if invalid score is input.
This function should work as expected when STUDENTS macro is changed.
You MUST use pointer 'pScores' to input the scores to gain full points. 
Using array operation (scores[i]) will earn you half points.
*/
void inputScores()
{
	pScores = &scores[0];
	for(int i = 0; i <STUDENTS; i++){
		int temp;
		printf("Enter score %d: ", i+1);
		do{
			
			scanf("%d", &temp); // take input
			if(temp > -1 && temp < 101){
				printf("%d\n", temp);
				*(pScores + i) = temp; // store value using pointer
			}

		}while(temp <0 || temp >100); // if temp is more than 100, less than 0, keep scan
		
	}		
	


}

/*
Question 7: scoreStats (10 points)
Now that the scores of students are stored, find the maximun and the average of those scores. Display these stats.
Ignore the decimal point accuracy since we are dealing with integers. This function should work as expected when STUDENTS macro is changed.
You MUST use pointer 'pScores' to gain full points.
Using array operation (scores[i]) will earn you half points.
Note: Make sure pointer 'pScores' is pointing to correct place.
*/
void scoreStats()
{
int a = 0;
int max = -1;
for(int i = 0; i < STUDENTS; i++){
	a = *(pScores+i) + a; // get a sum
	if(*(pScores+i) > max){
		max = *(pScores+i); // get a max
	}
}
int avg = a / STUDENTS; // sum divided by students, get avg
printf("\nMax score= %d\n", max);
printf("Avg score= %d\n", avg);


}

/*
Question 8: createUsername (15 points)
Implement the function that creates and displays the user name of the user. Ask the user for their first and last name.
The username is the first letter of first name, followed by the last name. For instance, if the user's name is John Doe, then the username is jdoe.
The user may input upper or lower case characters for first and last name. Make sure that the username is all UPPER CASE.
Note : When using fgets(), when you press Enter to finish entering the string, the Enter (\n) character is also added to the string.
	Try to remove that character.
*/
void createUsername()
{
	char firstName[15], lastName[15], userName[20];
	printf("Enter your first name : ");
	fgets(firstName, sizeof(firstName), stdin); // get string
	firstName[strlen(firstName) - 1] = '\0'; // remove newline 
	printf("%s\n", firstName);

	printf("Enter your last name : ");
	fgets(lastName, sizeof(lastName), stdin); // get lastname
	lastName[strlen(lastName)-1] = '\0'; // Remove the newline
	printf("%s\n", lastName);

	int len = strlen(lastName);
	userName[0] = firstName[0];
	for(int i = 1; i <= len; i++){
		userName[i] = toupper(lastName[i-1]); // convert first letter to uppercase
	}
	userName[len + 1] = '\0';
	printf("User name : %s", userName );
}

/*
Question 9: (10 points)
Take in a N-character string (max = 128)'sentence' then count the number of lower case characters in array 'sentence' and afterwards convert lower case characters to upper case. see the sample output in PDF file.
Print the number of lower case characters and print the newly formed sentence[] which has all upper case characters.
You may not add more variables than already declared. You may use 'int i' in 'for' loop, if needed.
Hint: Lookup ASCII chart of alphabets
*/

void lowerToUpperCase()
{
	unsigned int len_max = 128;

	char* sentence = malloc(len_max); // Dynamically allocate memory for the sentence
	int lowerCases = 0;

	//read input string
	fgets(sentence, len_max, stdin);
	sentence[strlen(sentence) -1] = '\0'; // Remove the newline
	for(int i = 0; i < len_max; i++){
		if(islower(sentence[i])){
			lowerCases++;
			sentence[i] = toupper(sentence[i]); // Convert lowercase to uppercase
		}
	}



	printf("Number of lower case characters= %d \n", lowerCases);
	printf("Upper case sentence : %s \n",sentence);
}

/*
Question 10: (20 points)
Implement the function to take in a N-character string (max = 128)'string'1' and 3-character pattern string 'pattern' from the user.
Search for the 'pattern' in 'str' and display "Pattern found" if 'pattern' is found in 'str' also return the locations of the three indexes, else display "Pattern not found".
For instance, if user enters str= "abcdefghij" and pattern = "ghi", then the pattern exists in str at locations 6,7,8 (print these) and display "Pattern found". The start point for location searching is from zero.
You MUST use pointers and not arrays for this question. You may use string functions.
You may not add more variables than already declared. You may use 'int i' in 'for' loop, if needed.

Note : The user input of the string is not predefined and it can be of any length unless user use enter or /n. so try to use realloc here.
*/

void searchPattern()
{
	char* str = NULL, * pattern = NULL;
	size_t len = 0;
	int ch;
	str = (char*)malloc(1);
	if (!str) return;
	str[0] = '\0';
	printf("Enter the N-character string which needs to be searched for a pattern: ");
	while ((ch = getchar()) != '\n' && ch != EOF) { // Read each character until Enter or EOF
		str = (char*)realloc(str, len + 2); // Reallocate memory to hold new char + null
		str[len++] = ch; // Store the new character
		str[len] = '\0';
	}
	printf("%s\n", str);
	printf("Long String value:%s\n", str);
	pattern = (char*)malloc(4);  // Allocate memory for 3-char pattern + null
	if (!pattern) return;
	printf("Enter a 3-character pattern to search: ");
	for (len = 0; len < 3; len++) {
		pattern[len] = getchar();
	}
	printf("%s\n", pattern);
	pattern[3] = '\0';
	for (len = 0; *(str + len + 2) != '\0'; len++) {
		if (*(str + len) == *(pattern) && // Compare 1st character
			*(str + len + 1) == *(pattern + 1) && // Compare 2st character
			*(str + len + 2) == *(pattern + 2)) { // Compare 3st character
			printf("Pattern '%s' found at locations: %d %d %d\n",pattern, (int)len, (int)(len + 1), (int)(len + 2));
			free(str);
			free(pattern);
			return;
		}
	}

	printf("Pattern not found\n");
	free(str);
	free(pattern);
}

