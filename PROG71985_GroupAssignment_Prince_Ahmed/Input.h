#pragma once
#include "User.h"
#include "Ingredient.h"

#include <stdbool.h>

#define MAX_NAME_LENGTH 255
#define MAX_ACCEPTABLE_INPUT 1

char* getUserInput();
char* getMenuInput();
char* checkInputSize(char*);
int getRecipeIDInput();
bool checkYesNo(char*);
bool yesNoShowMenuAgain();
INGREDIENT getIngredientInput(int id);
bool yesNoAddIngredient();
bool yesNoAddEditIngredient();