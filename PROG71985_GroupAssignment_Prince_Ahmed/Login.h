#pragma once
#include "User.h"
#include <stdbool.h>
#define MAX_NAME_LENGTH 255

//typedef struct user {
//
//	char username[MAX_NAME_LENGTH];
//	char password[MAX_NAME_LENGTH];
//
//} USER, * PUSER;

bool checkCreds(char*, char*, USER*);