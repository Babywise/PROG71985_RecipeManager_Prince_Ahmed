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

void createAccount() {

	char* username = allocateCharArray();
	char* confirmUsername = allocateCharArray();
	char* password = allocateCharArray();
	char* confirmPassword = allocateCharArray();

	printf("Please enter a username: ");
	scanf("%s", username);
	printf("Please re-enter your username: ");
	scanf("%s", confirmUsername);
	printf("Please enter a password: ");
	scanf("%s", password);
	printf("Please re-enter your password: ");
	scanf("%s", confirmPassword);

	reallocateCharArray(username, strlen(username));
	reallocateCharArray(confirmUsername, strlen(confirmUsername));
	reallocateCharArray(password, strlen(password));
	reallocateCharArray(confirmPassword, strlen(confirmPassword));

	if (strncmp(username, confirmUsername, strlen(username)) == 0 && strncmp(password, confirmPassword, strlen(password)) == 0) {
		writeUserToFile(username, password);
	} else {
		printf("\nCredentials did not match\n");
		exit(EXIT_SUCCESS);
	}

	return 0;

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


