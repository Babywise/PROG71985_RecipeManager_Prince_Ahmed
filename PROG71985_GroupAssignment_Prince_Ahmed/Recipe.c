#define _CRT_SECURE_NO_WARNINGS
#include "Recipe.h"
#include "RecipeADT.h"

#include <string.h>
#include <ctype.h>

RECIPE createRecipe(char* name) {
	RECIPE recipe;
	strcpy(recipe.name, name);
	//memset(recipe.ingredientArray, ingredientList, sizeof(ingredientList)); // Check if mem address is also copied
	recipe.ingredientArray = createIngredientList();
	//recipe.ingredientArray;
	return recipe;
}

char* getRecipeName(RECIPE r) {
	return r.name;
}

bool compareRecipe(RECIPE a, RECIPE b) {
	if ((strcmp(getRecipeName(a), getRecipeName(b))) == 0) {
		return true;
	} else {
		return false;
	}
}

void addIngredientToRecipe(PRECIPE thisRecipe, INGREDIENT thisIngredient) {

	addIngredientToList(&thisRecipe->ingredientArray, thisIngredient);

}