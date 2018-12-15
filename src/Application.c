/*
 *
 * File Name:		Application.c
 * Name:			Kensal J. Ramos
 * Course:			COP 2220C at Valencia College
 * Instructor:		David Stendel
 * Description: 	For the Final Project, you will need to create an address book program, which will
 * 					utilize a menu system and the equivalent of a database. The menu system should use
 * 					a main menu and submenus as needed, and allow the user to preform the typical
 * 					features of a database, i.e., Create, Retrieve, Update, and Delete.
 * 					(More in ReadMe file)
 * Team Members:	Kensal J. Ramos
 * Date:			November 21st	-	Project Created
 *
 *
 */

// Libraries
#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
#include "Menu.h"

// Prototypes
void createEntry();
void delEntry(int);
void printAll();
void printEntry(int);
int retEntry();
void saveFile();
void sort(int);
void updateEntry();



// Structs
struct person {

	char fName[50];
	char lName[50];
	char address[50];
	char city[50];
	char state[50];
	char email[50];
	char pNumber[11];

	int zipCode;
	int isEmpty;
} ;

struct person database[50] = {};

/*
 * Name:			main()
 * Parameters:		None
 * Return Value:	An integer representing an error code; if the program ends without error, zero
 * 					will be returned to the calling program or operating system.
 */
int main(void) {

	// Local Declarations
	int
		choice = 0,
		exitVal = 1;

	// Processing
	do {
		printMenu();

		// Get Main Choice ---------------
		fflush(stdout);
		scanf("%i", &choice);

		switch (choice) {
		case 0:
			exitVal = 0;
			break;
		case 1:
			printCMenu();
			do {

				createEntry();

				printf("\nDo you want to create another entry? (1 - yes, 0 - no) \n");
				fflush(stdout);
				scanf("%i", &exitVal);
			} while(exitVal == 1);

			//printRMenu();
			//retEntry();
			//printAll();
			exitVal = 1;
			break;
		case 2:
			printRMenu();
			do {
				printEntry(retEntry());

				printf("\n\nWould you like to retrieve another entry? (1 - yes, 0 - no)\n");
				fflush(stdout);
				scanf("%i", &exitVal);

			} while(exitVal == 1);

			exitVal = 1;
			break;
		case 3:
			printUMenu();

			do {
				updateEntry();
				printf("\n\nWould you like to update another entry? (1 - yes, 0 - no)\n");
				fflush(stdout);
				scanf("%i", &exitVal);

			} while(exitVal == 1);

			exitVal = 1;
			break;

		case 4:
			printDMenu();
			do {

				printf("\n\nWould you like to delete another entry? (1 - yes, 0 - no)\n");
				fflush(stdout);
				scanf("%i", &exitVal);

			} while(exitVal == 1);

			exitVal = 1;
			break;
		case 5:
			printAll();
			break;
		case 6:
			saveFile();
			break;
		default:
			break;
		}
	} while (exitVal == 1);


	// End
	//system("pause");
	return 0;
}

/*
 * Name:			createEntry()
 * Parameters:		None
 * Return Value:	None
 * Description: 	Creates a new entry to the database structure array
 */
void createEntry() {

	for(int i = 0; i < SIZE; i++)
		if(database[i].isEmpty == 0) {

			// Get last name
			printf("Please enter a last name: ");
			fflush(stdout);
			scanf("%s", database[i].lName);
			printf("You entered: %s\n", database[i].lName);

			// Get first name
			printf("Please enter a first name: ");
			fflush(stdout);
			scanf("%s", database[i].fName);
			printf("You entered: %s\n", database[i].fName);

			// Get address
			printf("Please enter an address: ");
			fflush(stdout);
			scanf("%s", database[i].address);
			printf("You entered: %s\n", database[i].address);

			// Get city
			printf("Please enter a city: ");
			fflush(stdout);
			scanf("%s", database[i].city);
			printf("You entered: %s\n", database[i].city);

			// Get state
			printf("Please enter a state: ");
			fflush(stdout);
			scanf("%s", database[i].state);
			printf("You entered: %s\n", database[i].state);

			// Get email
			printf("Please enter an email: ");
			fflush(stdout);
			scanf("%s", database[i].email);
			printf("You entered: %s\n", database[i].email);

			// Get ZIP Code
			printf("Please enter a ZIP code: ");
			fflush(stdout);
			scanf("%i", &database[i].zipCode);
			printf("You entered: %d\n", database[i].zipCode);

			// Get phone number
			printf("Please enter a phone number: ");
			fflush(stdout);
			scanf("%s", database[i].pNumber);
			printf("You entered: %s\n", database[i].pNumber);

			//printAll();
			database[i].isEmpty = 1;
			break;
		}

	sort(0);

}

/*
 * Name:			delEntry()
 * Parameters:		int index - position of desired person struct
 * Return Value: 	None
 * Description:		Deletes desired entry from database structure array
 */
void delEntry(int index) {

	// Reset entries for first name array
	for(int i = 0; i < SIZE; i++)
		database[index].fName[i] 	=   '\0' ;

	// Reset entries for last name array
	for(int i = 0; i < SIZE; i++)
		database[index].lName[i] 	=   '\0' ;

	// Reset entries for city array
	for(int i = 0; i < SIZE; i++)
		database[index].city[i] 	=   '\0' ;

	// Reset entries for state array
	for(int i = 0; i < SIZE; i++)
		database[index].state[i] 	=   '\0' ;

	// Reset entries for address array
	for(int i = 0; i < SIZE; i++)
		database[index].address[i] 	=   '\0' ;

	// Reset entries for email array
	for(int i = 0; i < SIZE; i++)
		database[index].email[i] 	=   '\0' ;

	// Reset entries for pNumber array
	for(int i = 0; i < SIZE; i++)
		database[index].pNumber[i] 	=   '\0' ;
	database[index].zipCode = 0;
	database[index].isEmpty = 0;

}


/*
 * Name:			printfAll()
 * Parameters:		None
 * Return Value:	None
 * Description:		Prints all non-empty entries
 */
void printAll() {

	for(int i = 0; i < SIZE; i++) {

		if (database[i].isEmpty == 1) {
			printf("Index: %d\n", i);
			printf("\tName: %s, %s \n", database[i].lName, database[i].fName);
			printf("\tZIP: %i\n", database[i].zipCode);
			printf("\tAddress: %s\n", database[i].address);
			printf("\tState: %s\n", database[i].state);
			printf("\tCity: %s\n", database[i].city);
			printf("\tEmail: %s\n", database[i].email);
			printf("\tPhone Number: %s\n\n", database[i].pNumber);
		}

	}

}

/*
 * Name: 			printEntry()
 * Parameters:		int i	-	The index of the desired entry
 * Return Value: 	None
 * Description: 	Prints the information of the given entry
 */
void printEntry(int i) {

	if (i != -99) {
		printf("Index: %d\n", i);
		printf("\tName: %s, %s \n", database[i].lName, database[i].fName);
		printf("\tZIP: %i\n", database[i].zipCode);
		printf("\tAddress: %s\n", database[i].address);
		printf("\tState: %s\n", database[i].state);
		printf("\tCity: %s\n", database[i].city);
		printf("\tEmail: %s\n", database[i].email);
		printf("\tPhone Number: %s\n\n", database[i].pNumber);
	}
	else
		printf("Entry not found");
}

/*
 * Name:			retEntry()
 * Parameters: 		None.
 * Return Value:	Index of entry
 * Description: 	Gets the index of an entry with given last name.
 */
int retEntry() {

	char temp[50] = { '\0' };
	int count = 0;

	printf("Please enter the last name of the desired person: ");
	fflush(stdout);
	scanf("%s", temp);

	// Search
	for (int i = 0; i < SIZE; i++) {

		// If it is not empty...
		if (database[i].isEmpty != 0) {

			for (int j = 0; j < SIZE; j++) {
				// Test each character individually
				if (database[i].lName[j] == temp[j])
					count++;
			}

		}

		// If all characters were the same...
		if (count == 50)
			return i;
		else
			count = 0;

	}

	return -99;
}

/*
 * Name: 			saveFile()
 * Parameters:		None
 * Return Value:	None
 * Description:		Saves information of non-empty entries
 */
void saveFile() {

	FILE *fp;
	char buff[255];

	fp = fopen("file.txt", "w");

	// Save all information
	for (int i = 0; i < SIZE; i++) {

		if (database[i].isEmpty == 1) {

			fprintf(fp, database[i].lName);
			fprintf(fp, "\r\n");
			fprintf(fp, database[i].fName);
			fprintf(fp, "\r\n");
			fprintf(fp, database[i].address);
			fprintf(fp, "\r\n");
			fprintf(fp, database[i].city);
			fprintf(fp, "\r\n");
			fprintf(fp, database[i].state);
			fprintf(fp, "\r\n");
			fprintf(fp, database[i].email);
			fprintf(fp, "\r\n");
			fprintf(fp, "%i", database[i].zipCode);
			fprintf(fp, "\r\n");
			fprintf(fp, database[i].pNumber);
			fprintf(fp, "\r\n");
			fprintf(fp, "\r\n");

		}

	}

	fclose(fp);
	printf("File saved successfully.\n");
}


/*
 * Name:			sort()
 * Parameters:		int pos	-	Position of check
 * Return value:	None
 * Description:		Sorts alphabetically based on first character
 */
void sort(int pos) {

	int i, k;

	char temp[50] = { '\0' };

	// Use ascii table to sort based on last names
	// Cycle through database structures
	for (i = 1; i < SIZE; i++) {

		// If ascii value is greater...
		if (database[i].lName[pos] < database[i - 1].lName[pos] && database[i].isEmpty != 0) {

			// If that is the case we will move it one back
			for (k = 0; k < SIZE; k++) {
				// Make the substitution
				temp[k] = database[i].lName[k];
				database[i].lName[k] = database[i - 1].lName[k];
				database[i - 1].lName[k] = temp[k];
			}
			break;
		}
	}

}

/*
 * Name: 			updateEntry()
 * Parameters:		None
 * Return Value:	None
 * Description:		Updates given entry.
 */
void updateEntry() {

	int
		i 		= retEntry(),
		num 	= 0,
		choice	= 0;
	char
		temp = '\0';

	// Is the entry found?
	if (i != -99) {

		printf("Entry found was: \n");
		printEntry(i);


		// Last name
		do {
			scanf("%c", &temp);
			printf("Would you like to update the last name? (1 - yes, 0 - no)\n");
			fflush(stdout);
			scanf("%c", &temp);
			scanf("%i", &choice);

			if (choice == 1) {
				printf("Please enter desired last name: ");
				fflush(stdout);
				scanf("%s", database[i].lName);

				printf("\nEntry has been modifed. Entry now has the following information: \n");
				printEntry(i);

				num = 0;
			}
			else if (choice == 0) {
				printf("No changes made.\n");
				num = 0;
			}
			else {
				printf("Invalid number entered!\n");
				num = 1;
			}


		} while (num == 1);

		// First name
		do {
			scanf("%c", &temp);
			printf("Would you like to update the first name? (1 - yes, 0 - no)\n");
			fflush(stdout);
			scanf("%c", &temp);
			scanf("%i", &choice);

			if (choice == 1) {
				printf("Please enter desired first name: ");
				fflush(stdout);
				scanf("%s", database[i].fName);

				printf("\nEntry has been modifed. Entry now has the following information: \n");
				printEntry(i);

				num = 0;
			}
			else if (choice == 0) {
				printf("No changes made.\n");
				num = 0;
			}
			else {
				printf("Invalid number entered!\n");
				num = 1;
			}
		} while (num == 1);

		// ZIP Code
		do {
			scanf("%c", &temp);
			printf("Would you like to update the ZIP code? (1 - yes, 0 - no)\n");
			fflush(stdout);
			scanf("%c", &temp);
			scanf("%i", &choice);

			if (choice == 1) {
				printf("Please enter desired ZIP code: ");
				fflush(stdout);
				scanf("%i", &database[i].zipCode);

				printf("\nEntry has been modifed. Entry now has the following information: \n");
				printEntry(i);

				num = 0;
			}
			else if (choice == 0) {
				printf("No changes made.\n");
				num = 0;
			}
			else {
				printf("Invalid number entered!\n");
				num = 1;
			}
		} while (num == 1);

		// Address
		do {
			scanf("%c", &temp);
			printf("Would you like to update the address? (1 - yes, 0 - no)\n");
			fflush(stdout);
			scanf("%c", &temp);
			scanf("%i", &choice);

			if (choice == 1) {
				printf("Please enter desired address: ");
				fflush(stdout);
				scanf("%s", database[i].address);

				printf("\nEntry has been modifed. Entry now has the following information: \n");
				printEntry(i);

				num = 0;
			}
			else if (choice == 0) {
				printf("No changes made.\n");
				num = 0;
			}
			else {
				printf("Invalid number entered!\n");
				num = 1;
			}
		} while (num == 1);

		// State
		do {
			scanf("%c", &temp);
			printf("Would you like to update the state? (1 - yes, 0 - no)\n");
			fflush(stdout);
			scanf("%c", &temp);
			scanf("%i", &choice);

			if (choice) {
				printf("Please enter desired state of residence: ");
				fflush(stdout);
				scanf("%s", database[i].state);

				printf("\nEntry has been modifed. Entry now has the following information: \n");
				printEntry(i);

				num = 0;
			}
			else if (choice == 0) {
				printf("No changes made.\n");
				num = 0;
			}
			else {
				printf("Invalid number entered!\n");
				num = 1;
			}
		} while (num == 1);

		// City
		do {
			scanf("%c", &temp);
			printf("Would you like to update the city? (1 - yes, 0 - no)\n");
			fflush(stdout);
			scanf("%c", &temp);
			scanf("%i", &choice);

			if (choice == 1) {
				printf("Please enter desired city: ");
				fflush(stdout);
				scanf("%s", database[i].city);

				printf("\nEntry has been modifed. Entry now has the following information: \n");
				printEntry(i);

				num = 0;
			}
			else if (choice == 0) {
				printf("No changes made.\n");
				num = 0;
			}
			else {
				printf("Invalid number entered!\n");
				num = 1;
			}
		} while (num == 1);

		// Email
		do {
			scanf("%c", &temp);
			printf("Would you like to update the email? (1 - yes, 0 - no)\n");
			fflush(stdout);
			scanf("%c", &temp);
			scanf("%i", &choice);

			if (choice == 1) {
				printf("Please enter desired email: ");
				fflush(stdout);
				scanf("%s", database[i].email);

				printf("\nEntry has been modifed. Entry now has the following information: \n");
				printEntry(i);

				num = 0;
			}
			else if (choice == 0) {
				printf("No changes made.\n");
				num = 0;
			}
			else {
				printf("Invalid number entered!\n");
				num = 1;
			}
		} while (num == 1);

		// Phone Number
		do {
			scanf("%c", &temp);
			printf("Would you like to update the phone number? (1 - yes, 0 - no)\n");
			fflush(stdout);
			scanf("%c", &temp);
			scanf("%i", &choice);

			if (choice == 1) {
				printf("Please enter desired phone number: ");
				fflush(stdout);
				scanf("%s", database[i].pNumber);

				printf("\nEntry has been modifed. Entry now has the following information: \n");
				printEntry(i);

				num = 0;
			}
			else if (choice == 0) {
				printf("No changes made.\n");
				num = 0;
			}
			else {
				printf("Invalid number entered!\n");
				num = 1;
			}
		} while (num == 1);

	}
	else
		printf("Entry not found");

}

