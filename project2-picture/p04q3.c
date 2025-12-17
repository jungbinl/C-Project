#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "proj4.txt"
#define WORD_LENGTH 20

#pragma warning(disable: 4996)	// needed for VS

FILE *fp;		// Use this file pointer to open the file in readFile() and use this pointer through out this file.

void readFile()
{
	int fileSize = 0;
	// enter code here
	fp = fopen(FILE_PATH, "r+"); //open file reading and writing
	fseek(fp, 0, 2); // move file pointer to the end
	fileSize = ftell(fp); // get current position,which mean file size
	fseek(fp ,0, 0); // move file pointer back to begin
	printf("The file size = %d bytes\n", fileSize);
}

void wordCount()
{
	int words = 0;
	char c;
	char prev = ' ';
	// enter code here
	fseek(fp, 0, 0); //reset file pointer
	//read file from beggining to end
	while((c = fgetc(fp)) != EOF) {
	// if previous letter is not space then word is not finished
	if((c == ' ' || c == '\n' || c == '\t') && (prev != ' ' && prev != '\n' && prev != '\t')){
	       words++;
	       }
prev = c;
	}
	// count last word
	if(prev != ' ' && prev != '\n' && prev != '\t'){
		words++;
	}
	printf("Total words = %d \n", words);
}

void sentenceCount()
{
	int sentences = 0;
	// enter code here
	char c;
	fseek(fp, 0, 0);
	// if ch is .,!,? sentence and, count sentences
	while((c = fgetc(fp)) !=  EOF){
		if(c == '.' || c == '?' || c == '!'){
			sentences++;
		}
	}
	printf("Total sentences = %d \n", sentences);
}

void findAndReplace()
{
	char find[WORD_LENGTH], replace[WORD_LENGTH];
	// enter code here
	printf("Enter the word to find: ");
	scanf("%s", find);
	printf("Enter the replacement word: ");
	scanf("%s", replace);
	
	// rewind the file
	fseek(fp, 0 ,0);

	char word[WORD_LENGTH];
	// make a change file
	FILE *result = fopen("result.txt", "w");
	int found = 0;
	// keep doing until the file end
	while(fscanf(fp, "%s", word) != EOF){
		if(strcmp(word, find) == 0){
			fprintf(result, "%s ", replace);
			found = 1;
		}else {
			fprintf(result, "%s ", word);
		}
	}
	fclose(result);
	
	// replace the file
	remove(FILE_PATH);
	rename("result.txt", FILE_PATH);

	if(found){
		printf("Found and replaced\n");
	}else{
		printf("Word not found\n");
	}
	
}

int main()
{
	printf("CSE 220 p04q3: \n");
	printf("\nProblem 1: \n");
	readFile();
	
	printf("\nProblem 2: \n");
	wordCount();

	printf("\nProblem 3: \n");
	sentenceCount();
	
	printf("\nProblem 4: \n");
	findAndReplace();

	fclose(fp);
	return 0;
}

