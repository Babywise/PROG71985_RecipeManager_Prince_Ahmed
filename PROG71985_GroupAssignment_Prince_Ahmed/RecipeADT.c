#include "RecipeADT.h"

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

bool removeRecipeFromList(PRLIST thisRecipeList, RECIPE recipeToBeDeleted) {

	PRNODE current = thisRecipeList->list;

	if (compareRecipe(current->recipeData, recipeToBeDeleted)) {
		if (getNextRecipeNode(current) != NULL) {
			thisRecipeList->list = getNextRecipeNode(current);
		} else {
			thisRecipeList->list = NULL;
		}
		removeRecipeNode(current);
		return true;
	}

	PRNODE prev = NULL;

	while (current != NULL && !compareRecipe(current->recipeData, recipeToBeDeleted)) {
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