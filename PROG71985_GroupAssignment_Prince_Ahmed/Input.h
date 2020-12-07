#pragma once
#include "User.h"
#include <stdbool.h>

#define MAX_NAME_LENGTH 255
#define MAX_ACCEPTABLE_INPUT 1

char* getUserInput();
char* getMenuInput();
char* checkInputSize(char*);
int getRecipeIDInput();
bool checkYesNo(char*);
bool yesNoShowMenuAgain();