#define _CRT_SECURE_NO_WARNINGS
#include "Allocation.h"
#include "User.h"
#include "Input.h"
#include "Login.h"

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

char* getMenuInput() {

	int maxCount = sizeof(char);
	char* userInput = allocateCharArray();

	if (userInput == NULL) {

		printf("Memory could not be allocated");
		exit(EXIT_FAILURE);

	} else {

		char ch = NULL;
		int i = 0;

		//Accept input until user hits enter
		while ((ch = getchar()) != '\n' && ch != NULL) {

			userInput[i] = toupper(ch);
			i++;

			//input should a single char but if a word longer than 1 bytes is entered (like 'abort') size of input allowed is increased by x2
			//if i reaches max expected input (maxCount) buffer for char seatSelection is realloced by x2, 
			if (i == maxCount) {

				maxCount++;
				userInput = reallocateCharArray(userInput, maxCount);

				if (userInput == NULL) {

					printf("Memory could not be re-allocated");
					exit(EXIT_FAILURE);

				}
			}
		}

		//replaces last char '\n' with NULL
		userInput[i] = NULL;

	}

	return userInput;

}

char* checkInputSize(char* userInputLetter) {

	int sizeOfInput = 0;

	//counts size of input from user
	for (int i = 0; i < strlen(userInputLetter); i++) {
		if (userInputLetter[i] != NULL) {
			sizeOfInput++;
		}
	}

	//if user input is larger than 1 character, set to null for automatic invalid entry
	if (sizeOfInput > MAX_ACCEPTABLE_INPUT) {
		for (int i = 0; i < strlen(userInputLetter); i++) {
			userInputLetter[i] = NULL;
		}
	}

	return userInputLetter;

}


void getAccountOption(USER* userArray) {

	char* userOption;
	bool validOption = false;

	do {

		char* userOption = getMenuInput();
		char* userOptionRemoved = checkInputSize(userOption);

		int sizeOfInput = 0;
		//counts size of input from user
		for (int i = 0; i < strlen(userOption); i++) {
			if (userOptionRemoved == '\n') {
				userOptionRemoved = NULL;
			} else if (i > MAX_ACCEPTABLE_INPUT) {
				userOptionRemoved = NULL;
			}
		}

		switch (*userOptionRemoved) {
		case 'A':
			validOption = true;
			getLoginFromUser(userArray);
			break;

		case 'B':
			validOption = true;
			//function
			break;

		case 'C':
			validOption = true;
			exit(EXIT_SUCCESS);
			break;

		default:
			printf("Please enter a valid option: ");
			validOption = false;
			break;
		}

		free(userOption);

	} while (!validOption);

}


void getLoginFromUser(USER* userArray) {

	char username[MAX_NAME_LENGTH] = { "" };
	char password[MAX_NAME_LENGTH] = { "" };

	bool validationCheck = false;

	printf("Please enter your username: ");
	fgets(username, MAX_NAME_LENGTH, stdin);
	strtok(username, "\n");

	printf("Please enter your password: ");
	fgets(password, MAX_NAME_LENGTH, stdin);
	strtok(password, "\n");

	validationCheck = checkCreds(username, password, userArray);

	if (validationCheck) {

		printf("Credentials Accepted - Logging in...\n");

	} else {

		printf("Incorrect Credentials - Failed to log in\n");
		fflush(stdin);
		getLoginFromUser(userArray);

	}

}

void getRecipeMenuOption() {

	char* userOption;
	bool validOption = false;

	do {

		char* userOption = getMenuInput();
		char* userOptionRemoved = checkInputSize(userOption);

		int sizeOfInput = 0;
		//counts size of input from user
		for (int i = 0; i < strlen(userOption); i++) {
			if (userOptionRemoved == '\n') {
				userOptionRemoved = NULL;
			} else if (i > MAX_ACCEPTABLE_INPUT) {
				userOptionRemoved = NULL;
			}
		}

		switch (*userOptionRemoved) {
		case 'A':
			validOption = true;
			//displayRecipeList();
			//displaySingleRecipe();
			break;

		case 'B':
			validOption = true;
			//displayRecipeList();
			//displayRangeRecipe();
			break;

		case 'C':
			validOption = true;
			//displayRecipeList();
			//displayAllRecipe();
			break;

		case 'D':
			validOption = true;
			//createNewRecipe
			break;

		case 'E':
			validOption = true;
			//editRecipe
			break;

		case 'F':
			validOption = true;
			//deleteRecipe
			break;

		case 'G':
			validOption = true;
			//searchRecipe
			break;

		case 'H':
			validOption = true;
			//sortRecipe
			break;

		case 'I':
			validOption = true;
			exit(EXIT_SUCCESS);
			break;

		default:
			printf("Please enter a valid option: ");
			validOption = false;
			break;
		}

		free(userOption);

	} while (!validOption);

}
