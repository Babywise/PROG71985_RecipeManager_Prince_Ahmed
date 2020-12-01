#pragma once
#define MAX_NAME 50
#include "IngredientADT.h"

#include <stdbool.h>

typedef struct recipe {

	char name[MAX_NAME];
	//INGREDIENT ingredientArray[MAX_INGREDIENTS];
	ILIST ingredientArray;

}RECIPE, *PRECIPE;

RECIPE createRecipe(char*);
char* getRecipeName(RECIPE);
bool compareRecipe(RECIPE, RECIPE);
void addIngredientToRecipe(PRECIPE, INGREDIENT);