#pragma once

#include <stdio.h> 
#include <stdlib.h>

#define MAX_NAME_LENGTH 255
#define MAX_USERS 50
#define LOGIN_FILE "Recipe Manager/Accounts.txt"

typedef struct user {

	char username[MAX_NAME_LENGTH];
	char password[MAX_NAME_LENGTH];

} USER, *PUSER;



USER* getUsersFromFile();

USER createUser(char*, char*);

//char* getUsername(PUSER*, int);
//char* getPassword(PUSER*, int);
//
//char* setUsername(PUSER*, int, char*);
//
//char* setPassword(PUSER*, int, char*);


