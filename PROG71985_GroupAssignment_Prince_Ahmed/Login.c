
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdbool.h>

#include "Login.h"
#include "User.h"
#include "Allocation.h"

bool checkCreds(char* username, char* password, USER* userArray) {

	int sizeOfArray = getSizeOfUserArray(userArray);

	int usernameResult, passwordResult;

	char* tempUsername = allocateCharArray();
	char* tempPassword = allocateCharArray();

	bool validCheck = false;

	for (int i = 0; i < sizeOfArray; i++) {

		strcpy(tempUsername, getUsername(userArray, i));
		strcpy(tempPassword, getPassword(userArray, i));

		reallocateCharArray(tempUsername, strlen(tempUsername));
		reallocateCharArray(tempPassword, strlen(tempPassword));
		
		usernameResult = strcmp(tempUsername, username);
		passwordResult = strcmp(tempPassword, password);

		if (usernameResult == 0 && passwordResult == 0) {
			
			validCheck = true;
			break;

		} else {

			validCheck = false;

		}
	}

	if (validCheck) {

		return true;

	} else {

		return false;

	}

}


