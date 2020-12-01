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

int getRecipeIDInput() {

	char* userInput = getMenuInput();
	userInput = checkInputSize(userInput);
	int userInputAsInt = atoi(userInput);
	return userInputAsInt;

}

