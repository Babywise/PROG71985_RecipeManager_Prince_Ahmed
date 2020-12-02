#include "RecipeADT.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
RLIST createRecipeList() {
	RLIST newList = { 0 };
	return newList;
}

bool addRecipeToList(PRLIST thisRecipeList, RECIPE thisRecipe) {

	PRNODE newNode = createRecipeNode(thisRecipe);

	if (!newNode) {
		return false;
	}
	//if list is empty
	if (thisRecipeList->list == NULL) {
		setNextRecipeNode(newNode, thisRecipeList->list);
		thisRecipeList->list = newNode;
	} else {

		PRNODE currNode = thisRecipeList->list;

		while (getNextRecipeNode(currNode) != NULL) {
			currNode = getNextRecipeNode(currNode);
		}

		setNextRecipeNode(currNode, newNode);

	}

	return true;

}

bool removeRecipeFromList(PRLIST thisRecipeList, int recipeIDToBeDeleted) {

	PRNODE current = thisRecipeList->list;

	if (compareRecipeID(current->recipeData, recipeIDToBeDeleted)) {
		if (getNextRecipeNode(current) != NULL) {
			thisRecipeList->list = getNextRecipeNode(current);
		} else {
			thisRecipeList->list = NULL;
		}
		removeRecipeNode(current);
		return true;
	}

	PRNODE prev = NULL;

	while (current != NULL && !compareRecipeID(current->recipeData, recipeIDToBeDeleted)) {
		prev = current;
		current = getNextRecipeNode(current);
	}

	if (current == NULL) {
		return false;
	}

	setNextRecipeNode(prev, getNextRecipeNode(current));

	removeRecipeNode(current);
	return true;

}

void getRecipeListFromADT(PRLIST thisRecipeList) {

	if (thisRecipeList->list == NULL) {

		printf("Err: No recipes found");
		return;

	} else {

		PRNODE currNode = thisRecipeList->list;

		while (currNode != NULL) {

			char* currRecipeName = getRecipeName(getRecipeData(currNode));
			int currRecipeID = getRecipeID(getRecipeData(currNode));
			printf("%d) %s\n", currRecipeID + 1, currRecipeName);
			currNode = getNextRecipeNode(currNode);
		}
	}
}

RECIPE getRecipeFromRecipeList(PRLIST thisRecipeList, int recipeOption) {

	if (thisRecipeList->list == NULL) {

		printf("Err: No recipes found");
		return createRecipe("", NULL);

	} else {

		PRNODE currNode = thisRecipeList->list;

		while (currNode != NULL) {

			if (compareRecipeID(getRecipeData(currNode), recipeOption)) {
				return getRecipeData(currNode);
			}
			currNode = getNextRecipeNode(currNode);
		}
	}
	return createRecipe("", NULL);
}

bool checkRecipeExists(PRLIST thisRecipeList, int recipeOption) {

	if (thisRecipeList->list == NULL) {

		printf("Err: No recipes found");
		return false;;

	} else {

		PRNODE currNode = thisRecipeList->list;

		while (currNode != NULL) {

			if (compareRecipeID(getRecipeData(currNode), recipeOption)) {
				return true;
			}
			currNode = getNextRecipeNode(currNode);
		}
	}
	return false;
}

bool displayRecipe(PRLIST thisRecipeList, int recipeOption) {

	if (thisRecipeList->list == NULL) {

		printf("Err: No recipes found");
		return false;

	} else {

		PRNODE currNode = thisRecipeList->list;

		while (currNode != NULL) {

			if (compareRecipeID(getRecipeData(currNode), recipeOption - 1)) {
				char* currRecipeName = getRecipeName(getRecipeData(currNode));
				printf("\n%s:\n", currRecipeName);
				displayIngredients(getIngredientList(getRecipeData(currNode)));
				return true;
			}
			currNode = getNextRecipeNode(currNode);
		}
	}
	return false;
}