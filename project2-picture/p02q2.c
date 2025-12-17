// CSE 220 Spring 2025
// Project 4

// Enter your name here
// Mention which environment you used: VS or gcc

#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "myBMP.bmp"

#pragma warning(disable: 4996)	// needed for VS only

// functions that need implementation
void loadFile(const char *filename);
void displayBmpFile();
void changePixelToWhite();
void saveNewFile(const char *);

// gloabl variables
unsigned char *fp = 0;			//pointer to navigate through the opened file.
unsigned char *fileStart = 0;	// pointer to save the start address of the file, in case you need to go back to start of file
unsigned char fileSize = 0;		// stores the size of file

/*
Problem 1: loadFile (10 points)
Implement loadfile() to open the myBMP.bmp file. By default, file name is myBMP.bmp
Use dynamic memory allocation to store the entire contents of the file and let that memory be pointed by 'fp'.
Save the start of file in 'fileStart' so that you use it to go to start of file in other functions.
Print the size of the file by reading the appropriate byte from BITMAPFILEHEADER.
Hint: After opening the file, read the file size and use it for dynamic memory allocation to read entire file.
Note: If using VS, the bmp file should be placed in "C:\Users\<username>\Documents\Visual Studio 2017\Projects\Project1\Project1" if using default project location.
*/
void loadFile(const char *filename)
{
	FILE *fp_file;
	int size = 0;
	fp_file = fopen(filename, "rb"); // open the file 
	fseek(fp_file, 2, 0);	// read offset 2
	fread(&size, 4, 1, fp_file); //read 4 bytes
	fileSize = (unsigned char)size; // setting the global
	fp = (unsigned char *)malloc(size); // allocate memory for the file
	fileStart = fp; // start address
	// read the entire file content
	fseek(fp_file , 0, 0);  
	fread(fp, 1, size,fp_file);
	printf("File loaded. File size = 0x%x bytes\n", size);
	fclose(fp_file);
}

/*
Problem 2: displayBmpFile (10 points)
Display myBMP.bmp file in hex.
Display neatly the content of myBMP.bmp file as seen in hex editor, as per expected output given in project question file.
Even after closing the file with fclose(), we have the contents of the file in memory pointed by 'fp' (or 'fileStart' in loadFile()).
So you don't have to open and read the file again.
*/
void displayBmpFile()
{
printf("Hex view of loaded bmp file:\n");
// print header in hexadecimal format
for(int i = 0; i < 16; i++){
	if(i <10 ){
		printf("%4d",i);
	} else{
		printf("%4c", 'a' + (i -10));
	}
}
printf("\n");
// print element
for(int i = 0; i < fileSize; i++){
	if(i > 0 && i % 16 == 0){
		printf("\n"); // change row after f
	}
	printf("%4x", fileStart[i]); //print content of file
}
printf("\n");
}

/*
Problem 3: (15 points)
Ask the user for a pixel location and store the location in 'row' & 'col'. Change that pixel to white color.
Valid pixel locations are 0  to 4. Check for valid location and keep asking the user until valid location is entered.
White color is RGB= (255, 255, 255).
For instance, if user enters row=2, column=0 then change the pixel (2,0) to white color.
*/
void changePixelToWhite()
{
	unsigned int row = 0, col = 0;
	// enter code here
	// keep asking until user input untill 0 <= row <=4  
	do{
		printf("Enter row of pixel: ");
		scanf("%d", &row);
	} while(row <0 || row > 4);
	// keep asking until user input until 0 <= col <= 4
	do{
		printf("Enter column of pixel: ");
		scanf("%d", &col);
	} while (col < 0 || col > 4);
	// pixeloffeset = headersize + infosize + (height - 1 - row)*rowSize + col * 3
	int pixeloffset = 14 + 40 + (5 - 1 -row) * 16 + col * 3;
	// change the element
	fp[pixeloffset] = 255;
	fp[pixeloffset+1] = 255;
	fp[pixeloffset+2] = 255;
	printf("Changed pixel (%d, %d) to white \n", row, col);
}

/*
Problem 4: saveNewFile (10 points)
Open a new file and write that file with the modified .bmp image with the white pixel.
You should have the file content pointed by 'fileStart'.
File name is provided as parameter when calling in main()
Note: If using VS, the bmp file will be saved in "C:\Users\<username>\Documents\Visual Studio 2017\Projects\Project1\Project1" if using default project location.
*/
void saveNewFile(const char *fileName)
{
	// enter code here
	FILE *f = fopen(fileName, "wb");
	// fwrite the whole element in the file
	fwrite(fileStart, 1, fileSize, f);
	fclose(f);
	printf("File %s saved.\n", fileName);
}

int main()
{
	printf("CSE 220 p04q2: \n");
	printf("Problem 1: \n");
	loadFile(FILE_PATH);
	
	printf("Problem 2: \n");
	displayBmpFile();
	
	printf("Problem 3: \n");
	changePixelToWhite();
	
	printf("Problem 4: \n");
	saveNewFile("myBMP2.bmp");
	return 0;
}
