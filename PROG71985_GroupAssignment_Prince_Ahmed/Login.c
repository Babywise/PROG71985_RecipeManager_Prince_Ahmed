
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdbool.h>

#include "Login.h"
#include "User.h"
#include "Allocation.h"


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


bool checkCreds(char* username, char* password, USER* userArray) {

	int sizeOfArray = getSizeOfUserArray(userArray);
	int usernameResult, passwordResult;
	bool validCheck = false;

	for (int i = 0; i < sizeOfArray; i++) {

		char* tempUsername = allocateCharArray();
		char* tempPassword = allocateCharArray();

		strcpy(tempUsername, getUsername(userArray, i));
		strcpy(tempPassword, getPassword(userArray, i));
		
		usernameResult = strcmp(tempUsername, username);
		passwordResult = strcmp(tempPassword, password);

		if (usernameResult == 0 && passwordResult == 0) {
			validCheck = true;
			break;
		} else {
			validCheck = false;
		}

		free(tempPassword);
		free(tempUsername);
	}

	if (validCheck) {
		return true;
	} else {
		return false;
	}

}


