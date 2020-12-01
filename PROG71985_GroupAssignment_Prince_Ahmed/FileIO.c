#define _CRT_SECURE_NO_WARNINGS
#define MAX_INPUT 256
#define TXTDOT_LENGTH 4

#define RECIPE_LIST_NAME "Recipe Manager/RecipeList.txt"
#define RECIPE_DIR "Recipe Manager/Recipes/"

#include "FileIO.h"
#include "Allocation.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

RLIST readRecipeList() {

	RLIST recipeList = createRecipeList();
	FILE* listFile = fopen(RECIPE_LIST_NAME, "r");

	if (listFile == NULL) {
		printf("Recipe list file cannot be found, Initizalizing\n");
		listFile = fopen(RECIPE_LIST_NAME, "w");
		fclose(listFile);
		//createRecipe(); // error check thing
		//return &recipeList
	} else if (listFile != NULL) {

		int i = 0;
		bool file = true;

		char* tempRecipeFileName = allocateCharArray();

		while (fscanf(listFile, "%s", tempRecipeFileName) != EOF) {

			RECIPE recipe = readRecipe(recipeList, tempRecipeFileName);
			
			if (recipe.name != NULL) {
				addRecipeToList(&recipeList, recipe);
			}

			i++;
		}
		free(tempRecipeFileName);
	}

	fclose(listFile);

	return recipeList;
}

RECIPE readRecipe(RLIST recipeList, char* recipeFileName) {

	// Gets recipe directory
	char* recipeDir = allocateCharArray();
	sprintf(recipeDir, "%s%s", RECIPE_DIR, recipeFileName);

	char* tempRecipeName = recipeFileName;
	for (int i = 0; i < TXTDOT_LENGTH; i++) {
		tempRecipeName[strlen(tempRecipeName) - 1] = '\0';
	}

	FILE* recipeFile = fopen(recipeDir, "r");

	if (recipeFile == NULL) {
		RECIPE r = createRecipe(NULL);
		return r;
	}

	RECIPE tempRecipe = createRecipe(tempRecipeName);

	int i = 0;

	char* tempIngredientID = allocateCharArray();
	char* tempIngredientName = allocateCharArray();
	char* tempIngredientQuantity = allocateCharArray();
	char* tempIngredientMeasurment = allocateCharArray();

	while (fscanf(recipeFile, "%s\t%s\t%s\t%s[^\n]", tempIngredientID, tempIngredientName, tempIngredientQuantity, tempIngredientMeasurment) != EOF){
			
		// Convert char* to proper types
		int ingredientID = atoi(tempIngredientID);
		tempIngredientName = reallocateCharArray(tempIngredientName, strlen(tempIngredientName));
		float ingredientQuantity = atof(tempIngredientQuantity);
		tempIngredientMeasurment = reallocateCharArray(tempIngredientMeasurment, strlen(tempIngredientMeasurment));

		// Create ingredient with ingredient info, then add ingredient to Recipe
		INGREDIENT ingredient = createIngredient(ingredientID, tempIngredientName, ingredientQuantity, tempIngredientMeasurment);

		addIngredientToRecipe(&(tempRecipe), ingredient);

		i++;
	}

	free(tempIngredientID);
	free(tempIngredientName);
	free(tempIngredientQuantity);
	free(tempIngredientMeasurment);
	
	free(recipeDir);
	fclose(recipeFile);

	return tempRecipe;

}