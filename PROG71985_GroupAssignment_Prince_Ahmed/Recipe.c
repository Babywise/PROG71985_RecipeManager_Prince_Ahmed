#define _CRT_SECURE_NO_WARNINGS
#include "Recipe.h"
#include "RecipeADT.h"

#include <string.h>
#include <ctype.h>

RECIPE createRecipe(char* name, int id) {
	RECIPE recipe;
	recipe.id = id;
	strcpy(recipe.name, name);
	recipe.ingredientArray = createIngredientList();
	return recipe;
}

char* getRecipeName(RECIPE recipe) {
	return recipe.name;
}

int getRecipeID(RECIPE recipe) {
	return recipe.id;
}

PILIST getIngredientList(RECIPE recipe) {
	return &(recipe.ingredientArray);
}

//bool compareRecipe(RECIPE a, RECIPE b) {
//	if (getRecipeID(a) == getRecipeID(b)) {
//		return true;
//	} else {
//		return false;
//	}
//}

bool compareRecipeID(RECIPE recipe, int id) {
	if (recipe.id == id) {
		return true;
	} else {
		return false;
	}
}

void addIngredientToRecipe(PRECIPE thisRecipe, INGREDIENT thisIngredient) {
	addIngredientToList(&thisRecipe->ingredientArray, thisIngredient);
}

