#pragma once
#define MAX_NAME 50
#include "IngredientADT.h"

#include <stdbool.h>

typedef struct recipe {

	int id;
	char name[MAX_NAME];
	ILIST ingredientArray;

}RECIPE, *PRECIPE;

RECIPE createRecipe(char*, int);
char* getRecipeName(RECIPE);
int getRecipeID(RECIPE);
PILIST getIngredientList(PRECIPE);
bool compareRecipeID(RECIPE, int);
bool compareRecipe(RECIPE, RECIPE);
void addIngredientToRecipe(PRECIPE, INGREDIENT);