#include <string.h>
#include <stdbool.h>

#include "Login.h"
#include "User.h"
#include "Allocation.h"

bool checkCreds(char* username, char* password, USER* userArray) {

	int sizeOfArray = 0;

	while (strcmp(userArray[sizeOfArray].username, "") != 0 ||
		   strcmp(userArray[sizeOfArray].password, "") != 0) {
		
		sizeOfArray++;

	}
	int usernameResult;
	int passwordResult;

	for (int i = 0; i < sizeOfArray; i++) {

		usernameResult = strcmp(username, userArray[i].username);
		passwordResult = strcmp(password, userArray[i].password);

		if (usernameResult == 0 && passwordResult == 0) {

			return true;

		} else {

			return false;

		}
	}
	

}


