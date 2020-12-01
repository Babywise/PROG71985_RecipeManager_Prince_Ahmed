#pragma once
#include "RecipeADT.h"
#include "User.h"
#include "Input.h"
#include "Login.h"
#include "FileIO.h"

void displayLogo();
void displayAccountFunctions();
void getAccountOption(USER*);
void displayRecipeFunctions();
void getRecipeMenuOption(PRLIST);
void displayRecipeList(PRLIST);