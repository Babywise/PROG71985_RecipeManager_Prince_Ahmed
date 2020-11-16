#define _CRT_SECURE_NO_WARNINGS
#include "User.h"
#include "Allocation.h"
#include <stdio.h>
#include <string.h>

USER* getUsersFromFile() {

	FILE* login;
	login = fopen(LOGIN_FILE, "r");

	if (login == NULL) {
		printf("Unable to open the login file.\n");
		exit(EXIT_FAILURE);
	}

	char* tempUsername = allocateCharArray();
	char* tempPassword = allocateCharArray();


	USER userArray[MAX_USERS] = { NULL };
	//PUSER *pUserArray = (PUSER*)malloc(sizeof(PUSER));
	//printf("%u", (unsigned int) sizeof(pUserArray));
	int currLine = 0;

	while (fscanf(login, "%s\t%s[^\n]", tempUsername, tempPassword) != EOF) {

		tempUsername = reallocateCharArray(tempUsername, strlen(tempUsername));
		tempPassword = reallocateCharArray(tempPassword, strlen(tempPassword));

		USER tempUser = createUser(tempUsername, tempPassword);

		strcpy(userArray[currLine].username, tempUser.username);
		strcpy(userArray[currLine].password, tempUser.password);

		//userArray[currLine] = tempUser;

		//free(tempUser);
		currLine++;
	}

	free(tempUsername);
	free(tempPassword);
	printf("\n");
	for (int i = 0; i < currLine; i++) {

		printf("%s -- %s\n", userArray[i].username, userArray[i].password);

	}


	//fflush(login);
	fclose(login);

	return userArray;

}

USER createUser(char* username, char* password) {
	
	//PUSER pCurrUser = (PUSER*)malloc(sizeof(PUSER));
	USER currUser;

	strcpy(currUser.username, username);
	strcpy(currUser.password, password);

	return currUser;

}
