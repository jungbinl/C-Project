#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996) // for Visual Studio

#define MAX_NAME 30

// global linked list 'list' contains the list of patients
struct patientList {
	struct patient* patient;
	struct patientList* next;
} *list = NULL;				// currently empty list

// structure "patient" contains the patient's name, room number and linked list of doctors
struct patient {
	char name[MAX_NAME];
	unsigned int roomNumber;
	struct doctor* doctors;		// linked list 'doctors' contains names of doctors
};

//  structure 'doctor' contains doctor's name 
struct doctor {
	char name[MAX_NAME];
	struct doctor* next;
};

// forward declaration of functions (already implmented)
void flushStdIn();
void executeAction(char);

// functions that need implementation:
void addPatient(char* patientNameInput, unsigned int roomNumInput);
struct patient* searchPatient(char* patientNameInput);
void displayList(struct patientList* tempList);
void addDoctor(char* patientNameInput, char* doctorNameInput);
void removePatient(char* patientNameInput);
char* kthDoctor(char* patientNameInput, int n);
struct patientList* patientsOnThisFloor(unsigned int floorNumber);
void deleteList(struct patientList* pList);


int main()
{
	char selection = 'a';		// initialized to a dummy value
	do
	{
		printf("\nCSE220 Project 5\n");
		printf("Please enter your selection:\n");
		printf("\t a: add a new patient to the list\n");
		printf("\t d: display patient list\n");
		printf("\t c: add a doctor of a patient\n");
		printf("\t r: remove a patient\n");
		printf("\t l: display k-th added doctor of a patient\n");
		printf("\t b: display patients on a floor\n");
		printf("\t q: quit\n");

		selection = getchar();
		flushStdIn();
		executeAction(selection);
	} while (selection != 'q');

	return 0;
}

// flush out leftover '\n' characters
void flushStdIn()
{
	char c;
	do c = getchar();
	while (c != '\n' && c != EOF);
}

// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	char patientNameInput[MAX_NAME], doctorNameInput[MAX_NAME];
	unsigned int roomNumInput, floorNumber;
	struct patient* searchResult = NULL;
	int n;

	switch (c)
	{
	case 'a':	// add patient
		// input patient details from user
		printf("\nPlease enter patient's name: ");
		fgets(patientNameInput, sizeof(patientNameInput), stdin);
		patientNameInput[strlen(patientNameInput) - 1] = '\0';	// discard the trailing '\n' char
		printf("Please enter room number: ");
		scanf("%d", &roomNumInput);
		flushStdIn();

		if (searchPatient(patientNameInput) == NULL)
		{
			addPatient(patientNameInput, roomNumInput);
			printf("\nPatient successfully added to the list!\n");
		}
		else
			printf("\nThat patient is already on the list!\n");
		break;

	case 'd':		// display the list
		displayList(list);
		break;

	case 'c':		// add doctor
		printf("\nPlease enter patient's name: ");
		fgets(patientNameInput, sizeof(patientNameInput), stdin);
		patientNameInput[strlen(patientNameInput) - 1] = '\0';	// discard the trailing '\n' char

		if (searchPatient(patientNameInput) == NULL)
			printf("\nPatient name does not exist or the list is empty! \n\n");
		else
		{
			printf("\nPlease enter doctor's name: ");
			fgets(doctorNameInput, sizeof(doctorNameInput), stdin);
			doctorNameInput[strlen(doctorNameInput) - 1] = '\0';	// discard the trailing '\n' char

			addDoctor(patientNameInput, doctorNameInput);
			printf("\nDoctor added! \n\n");
		}
		break;

	case 'r':		// remove patient
		printf("\nPlease enter patient's name: ");
		fgets(patientNameInput, sizeof(patientNameInput), stdin);
		patientNameInput[strlen(patientNameInput) - 1] = '\0';	// discard the trailing '\n' char

		if (searchPatient(patientNameInput) == NULL)
			printf("\nPatient name does not exist or the list is empty! \n\n");
		else
		{
			removePatient(patientNameInput);
			printf("\nPatient successfully removed from the list! \n\n");
		}
		break;

	case 'l':		// k-th doctor
		printf("\nPlease enter patient's name: ");
		fgets(patientNameInput, sizeof(patientNameInput), stdin);
		patientNameInput[strlen(patientNameInput) - 1] = '\0';    // discard the trailing '\n' char

		if (searchPatient(patientNameInput) == NULL)
			printf("\nPatient name does not exist or the list is empty! \n\n");
		else
		{
			printf("\nPlease enter k-th number (k must greater than 0): ");
			scanf("%d", &n);
			if (n < 1) {
				printf("%d is invalid input!\n", n);
				break;
			}
			printf("\nK-th doctor added: %s\n\n", kthDoctor(patientNameInput, (n - 1)));
		}
		break;

	case 'b':		// patients on a floor
		printf("Please enter floor number: ");
		scanf("%d", &floorNumber);
		flushStdIn();
		struct patientList* result = patientsOnThisFloor(floorNumber);
		displayList(result);
		deleteList(result);
		break;

	case 'q':		// quit
		deleteList(list);
		break;

	default: printf("%c is invalid input!\n", c);
	}
}

void addPatient(char* patientNameInput, unsigned int roomNumInput)
{
	// allocate memory for new patientList node
	struct patientList* newNode = (struct patientList*)malloc(sizeof(struct patientList));
	// allocate memory for patient structure inside the node
	newNode->patient = (struct patient*)malloc(sizeof(struct patient));

	// copy patient name and store roomnumber
	strcpy(newNode->patient->name, patientNameInput);
	newNode->patient->roomNumber = roomNumInput;
	newNode->patient->doctors = NULL;

	newNode->next = list;
	list = newNode;
}


struct patient* searchPatient(char* patientNameInput)
{
	struct patientList* tempList = list;			// work on a copy of 'list'
	// enter code here
	while (tempList != NULL)
	{
		// if name is same, return patient
		if (strcmp(tempList->patient->name, patientNameInput) == 0)
			return tempList->patient;
		// go next list
		tempList = tempList->next;
	}
	return NULL;		// edit this line if needed
}

void displayList(struct patientList* tempList)
{
	// if tempList is empty then print 'the list is empty'
	if (tempList == NULL)
	{
		printf("\nThe list is empty!\n");
		return;
	}

	while (tempList != NULL)
	{
		// print name and roomnumber
		printf("\nPatient Name: %s\n", tempList->patient->name);
		printf("Room Number: %d\n", tempList->patient->roomNumber);

		struct doctor* doc = tempList->patient->doctors;
		if (doc == NULL)
			printf("Doctors: N/A\n");
		else
		{
			printf("Doctors: ");
			while (doc != NULL)
			{
				printf("%s", doc->name);
				if (doc->next != NULL) printf(", "); // if doctor is multiple, display doctor using comma
				doc = doc->next; // go next doctor
			}
			printf("\n");
		}

		tempList = tempList->next; // go next linkedlist
	}

}

void addDoctor(char* patientNameInput, char* doctorNameInput)
{
	struct patientList* tempList = list;
	while (tempList != NULL)
	{
		if (strcmp(tempList->patient->name, patientNameInput) == 0)
		{
			// create new doctor node
			struct doctor* newDoc = (struct doctor*)malloc(sizeof(struct doctor));
			strcpy(newDoc->name, doctorNameInput);
			newDoc->next = NULL;

			if (tempList->patient->doctors == NULL)
				tempList->patient->doctors = newDoc;
			else
			{
				struct doctor* last = tempList->patient->doctors;
				while (last->next != NULL) // repeat last next is null
					last = last->next;
				last->next = newDoc; // put new doctor node
			}
			return;
		}
		tempList = tempList->next;
	}

}

void removePatient(char* patientNameInput)
{
	struct patientList* tempList = list;
	struct patientList* prev = NULL;

	while (tempList != NULL)
	{
		if (strcmp(tempList->patient->name, patientNameInput) == 0)
		{
			// unlink patient node from list
			if (prev == NULL) list = tempList->next;
			else prev->next = tempList->next;

			// free all doctor nodes
			struct doctor* doc = tempList->patient->doctors;
			while (doc != NULL)
			{
				struct doctor* tmpDoc = doc;
				doc = doc->next;
				free(tmpDoc);
			}

			// free patient struct and list node
			free(tempList->patient);
			free(tempList);
			return;
		}
		prev = tempList;
		tempList = tempList->next;
	}
}

char* kthDoctor(char* patientNameInput, int n)
{

	struct patientList* tempList = list;		// work on a copy of 'list'
	while (tempList != NULL)
	{
		if (strcmp(tempList->patient->name, patientNameInput) == 0)
		{
			struct doctor* doc = tempList->patient->doctors;
			int count = 0;
			// iterate through doctor list to find k-th doctor
			while (doc != NULL)
			{
				if (count == n) // found the k-th doctor
					return doc->name;
				doc = doc->next;
				count++;
			}
			return "No k-th doctor!";
		}
		tempList = tempList->next; // move next node
	}
	return NULL;	// edit this line if needed
}

struct patientList* patientsOnThisFloor(unsigned int floorNumber)
{
	struct patientList* tempList = list;	// work on a copy of 'list'
	struct patientList* resultList = NULL;
	// enter code here
	while (tempList != NULL)
	{
		int patientFloor = tempList->patient->roomNumber / 100;
		if (patientFloor == floorNumber)
		{
			// allocate new patient list node
			struct patientList* newNode = (struct patientList*)malloc(sizeof(struct patientList));
			newNode->patient = (struct patient*)malloc(sizeof(struct patient));

			// copy patient info to new node
			strcpy(newNode->patient->name, tempList->patient->name);
			newNode->patient->roomNumber = tempList->patient->roomNumber;
			newNode->patient->doctors = NULL;

			// copy doctor's linked list
			struct doctor* docSrc = tempList->patient->doctors;
			struct doctor* docDest = NULL;
			struct doctor* lastDoc = NULL;

			while (docSrc != NULL)
			{
				docDest = (struct doctor*)malloc(sizeof(struct doctor));
				strcpy(docDest->name, docSrc->name);
				docDest->next = NULL;
				if (newNode->patient->doctors == NULL)
					newNode->patient->doctors = docDest;
				else
					lastDoc->next = docDest;
				lastDoc = docDest;
				docSrc = docSrc->next;
			}
			// insert new node at head of resultList
			newNode->next = resultList;
			resultList = newNode;
		}
		tempList = tempList->next;
	}

	return resultList;	// result list contains the search result
}

void deleteList(struct patientList* pList)
{
	struct patientList* temp = pList;
	while (temp != NULL)
	{
		struct patientList* nextNode = temp->next;
		struct doctor* doc = temp->patient->doctors;

		// free every doctor node within patient
		while (doc != NULL)
		{
			struct doctor* tmpDoc = doc;
			doc = doc->next;
			free(tmpDoc);
		}

		// free patient and its list node
		free(temp->patient);
		free(temp);
		temp = nextNode;
	}

}

