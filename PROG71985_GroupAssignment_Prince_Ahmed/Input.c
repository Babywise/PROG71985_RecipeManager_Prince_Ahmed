/*
 *	  Description: Functions related to user input
 *
 *    Name:		Nick Prince
 *    Email:	nprince3037@conestogac.on.ca
 *    Course:	PROG71985 - Fall2020
 *
 *    Name:		Islam Ahmed
 *    Email:	Iahmed9886@conestogac.on.ca
 *    Course:	PROG71985 - Fall2020
 */

#define _CRT_SECURE_NO_WARNINGS
#include "Allocation.h"
#include "User.h"
#include "Input.h"
#include "Login.h"

#include <ctype.h>
#include <string.h>
#include <stdio.h>

char* getUserInput() {

	int maxCount = sizeof(char);
	char* userInput = allocateCharArray();

	if (userInput == NULL) {

		printf("Memory could not be allocated");
		exit(EXIT_FAILURE);

	} else {

		char ch = NULL;
		int i = 0;

		// Accept input until user hits enter
		while ((ch = getchar()) != '\n' && ch != NULL) {

			userInput[i] = ch;
			i++;

			// Input starts at 1 byte and is reallocated everytime it increases by 1
			if (i == maxCount) {

				maxCount++;
				userInput = reallocateCharArray(userInput, maxCount);

				if (userInput == NULL) {

					printf("Memory could not be re-allocated");
					exit(EXIT_FAILURE);

				}
			}
		}

		// Replaces last char '\n' with NULL
		userInput[i] = NULL;

	}

	return userInput;

}

char* checkInputSize(char* userInputLetter) {

	int sizeOfInput = 0;

	// Counts size of input from user
	for (int i = 0; i < strlen(userInputLetter); i++) {
		if (userInputLetter[i] != NULL) {
			sizeOfInput++;
		}
	}

	// If user input is larger than 1 character, set to null for automatic invalid entry
	if (sizeOfInput > MAX_ACCEPTABLE_INPUT) {
		for (int i = 0; i < strlen(userInputLetter); i++) {
			userInputLetter[i] = NULL;
		}
	}

	return userInputLetter;

}

char* getMenuInput() {

	char* userInput = getUserInput();
	userInput = convertStringToUpper(userInput);
	userInput = checkInputSize(userInput);
	// Counts size of input from user
	for (int i = 0; i < strlen(userInput); i++) {
		if (userInput == '\n') {
			userInput = NULL;
		} else if (i > MAX_ACCEPTABLE_INPUT) {
			userInput = NULL;
		}
	}

	
	return userInput;
}


int getRecipeIDInput() {

	char* userInput = getUserInput();
	userInput = convertStringToUpper(userInput);
	userInput = checkInputSize(userInput);
	int userInputAsInt = atoi(userInput);
	free(userInput);
	return userInputAsInt;

}

bool checkYesNo(char* userInput) {

	if (strcmp("N", userInput) == 0 || strcmp("NO", userInput) == 0) {
		return false;
	} else if (strcmp("Y", userInput) != 0 && strcmp("YES", userInput) != 0) {
		printf("\nYour Input Was Invalid\n");
		return false;
	} else {
		return true;
	}
}

bool yesNoShowMenuAgain() {

	bool yesNo = false;

	do {

		printf("\nWould you like to show the menu again? (Y/N): ");
		char* userInput = getUserInput();
		userInput = convertStringToUpper(userInput);
		if (checkYesNo(userInput)) {
			return true;
		} else {
			return false;
		}

	} while (true);
}

INGREDIENT getIngredientInput(int id) {

	printf("\nPlease name your ingredient: ");
	char* userIngredientName = getUserInput();
	printf("Enter a measurement: ");
	char* userMeasurement = getUserInput();
	printf("How much? (Format = '0.00') (Enter 0 for no amount): ");
	char* userAmountAsChar = getUserInput();
	float userAmount = atof(userAmountAsChar);

	INGREDIENT userIngredient = createIngredient(id, userIngredientName, userAmount, userMeasurement);
	return userIngredient;
}

bool yesNoAddIngredient() {

	bool yesNo = false;

	do {
		printf("\nWould you like to add another ingredient? (Y/N): ");
		char* userInput = getUserInput();
		userInput = convertStringToUpper(userInput);
		if (checkYesNo(userInput)) {
			return true;
		} else {
			return false;
		}

	} while (true);

}

bool yesNoAddEditIngredient() {

	bool yesNo = false;

	do {
		printf("\nWould you like to add or edit another ingredient? (Y/N): ");
		char* userInput = getUserInput();
		userInput = convertStringToUpper(userInput);
		if (checkYesNo(userInput)) {
			return true;
		} else {
			return false;
		}

	} while (true);
}

char* convertStringToUpper(char* input) {

	for (int i = 0; i < strlen(input); i++) {
		input[i] = toupper(input[i]);
	}
	return input;

}