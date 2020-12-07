#pragma once
#include "RecipeADT.h"
#include "User.h"
#include "Input.h"
#include "Login.h"
#include "FileIO.h"

#include <stdbool.h>

void displayLogo();
void displayAccountFunctions();
void getAccountOption(USER*);
void displayRecipeFunctions();
bool getRecipeMenuOption(PRLIST);
void displayRecipeList(PRLIST);