#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable : 4996) 

#define MAX_DIM 3
#define STUDENTS 5		// total number of students
int matrixA[MAX_DIM][MAX_DIM], matrixB[MAX_DIM][MAX_DIM], sum[MAX_DIM][MAX_DIM];
int scores[STUDENTS];
int *pScores = NULL;

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

void copyToMatrixB()
{
	for(int i = 0; i < MAX_DIM; i++){
		for(int j = 0; j < MAX_DIM; j++){
			matrixB[i][j] = matrixA[i][j]; // element-by-element copy
		}
	}
}

void addMatrix()
{
	for(int i = 0; i < MAX_DIM; i++){
		for(int j = 0; j < MAX_DIM; j++){
			sum[i][j] = 2 * matrixA[i][j] + matrixB[i][j]; // basic calculation
		}
	}
}

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


