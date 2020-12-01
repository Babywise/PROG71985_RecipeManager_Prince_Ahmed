#pragma once
#include "User.h"
#include <stdbool.h>
#define MAX_NAME_LENGTH 255

void getLoginFromUser(USER*);
bool checkCreds(char*, char*, USER*);