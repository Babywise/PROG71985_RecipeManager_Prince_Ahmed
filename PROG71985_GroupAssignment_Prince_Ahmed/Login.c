
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdbool.h>

#include "Login.h"
#include "User.h"
#include "Allocation.h"

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


