#pragma once
#include "User.h"

#define MAX_NAME_LENGTH 255
#define MAX_ACCEPTABLE_INPUT 1

char* getMenuInput();
char* checkInputSize(char*);
void getAccountOption(USER*);
void getLoginFromUser(USER*);
void getRecipeMenuOption();