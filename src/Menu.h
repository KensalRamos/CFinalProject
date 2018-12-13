/*
 *
 * File Name:		Menu.c
 * Name:			Kensal J. Ramos
 * Course:			COP 2220C at Valencia College
 * Instructor:		David Stendel
 * Description: 	This file will handle the processing of menus.
 * Team Members:	Kensal J. Ramos
 * Date:			November 21st	-	Menu file created
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

// Prototypes
void printMenu();
void printCMenu();
void printRMenu();
void printDMenu();
void printUMenu();

/*
 * Name: 			printMenu()
 * Parameters:	 	None
 * Return Value: 	None
 */
void printMenu() {

	printf("\n-----------------------------------------\n");
	printf("|\t\tAddress Book\t\t|\n");
	printf("-----------------------------------------\n");
	printf("|\t\t0) Exit			|\n");
	printf("|\t\t1) Create entry	\t|\n");
	printf("|\t\t2) Retrieve entry	|\n");
	printf("|\t\t3) Update entry	\t|\n");
	printf("|\t\t4) Delete entry	\t|\n");
	printf("|\t\t5) Display entries	|\n");
	printf("|\t\t6) Save File		|\n");
	printf("-----------------------------------------\n");
	printf("Select option: ");

}

/*
 * Name: 			printCMenu()
 * Parameters:	 	None
 * Return Value: 	None
 */
void printCMenu() {

	printf("\n-----------------------------------------\n");
	printf("|\t\tCreate Entry\t\t|\n");
	printf("-----------------------------------------\n");
	printf("( Enter each piece of information as it comes up.\n");
	printf("  If you would like that piece of information to\n  remain empty enter 0 )\n");
	printf("-----------------------------------------\n");
}

/*
 * Name: 			printRMenu()
 * Parameters:	 	None
 * Return Value: 	None
 */
void printRMenu() {

	printf("\n-----------------------------------------\n");
	printf("|\t\tRetrieve Entry\t\t|\n");
	printf("-----------------------------------------\n");

}

/*
 * Name: 			printUMenu()
 * Parameters:	 	None
 * Return Value: 	None
 */
void printUMenu() {

	printf("\n-----------------------------------------\n");
	printf("|\t\tUpdate Entry\t\t|\n");
	printf("-----------------------------------------\n");

}

/*
 * Name: 			printDMenu()
 * Parameters:	 	None
 * Return Value: 	None
 */
void printDMenu() {

	printf("\n-----------------------------------------\n");
	printf("|\t\tDelete Entry\t\t|\n");
	printf("-----------------------------------------\n");

}


