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
		return true;
	}
}

bool removeRecipeFromList(PRLIST thisRecipeList, int recipeIDToBeDeleted) {

	PRNODE currNode = thisRecipeList->list;

	if (compareRecipeID(currNode->recipeData, recipeIDToBeDeleted)) {
		if (getNextRecipeNode(currNode) != NULL) {
			thisRecipeList->list = getNextRecipeNode(currNode);
		} else {
			thisRecipeList->list = NULL;
		}
		removeRecipeNode(currNode);
		return true;
	}

	PRNODE prev = NULL;

	while (currNode != NULL && !compareRecipeID(*getRecipeData(currNode), recipeIDToBeDeleted - 1)) {
		prev = currNode;
		currNode = getNextRecipeNode(currNode);
	}

	if (currNode == NULL) {
		return false;
	}
	//if deleting the first node, set the list to the 2nd node
	if (prev == NULL) {
		currNode = thisRecipeList->list;
		thisRecipeList->list = getNextRecipeNode(thisRecipeList->list);
	} else {
		setNextRecipeNode(prev, getNextRecipeNode(currNode));
	}
	
	removeRecipeNode(currNode);
	return true;
}

void getRecipeListFromADT(PRLIST thisRecipeList) {

	if (thisRecipeList->list == NULL) {

		printf("Err: No recipes found");
		return;

	} else {

		PRNODE currNode = thisRecipeList->list;

		while (currNode != NULL) {

			char* currRecipeName = getRecipeName(*getRecipeData(currNode));
			int currRecipeID = getRecipeID(*getRecipeData(currNode));
			printf("%d) %s\n", currRecipeID + 1, currRecipeName);
			currNode = getNextRecipeNode(currNode);
		}
	}
}

PRECIPE getRecipeFromRecipeList(PRLIST thisRecipeList, int recipeOption) {

	if (thisRecipeList->list == NULL) {

		printf("Err: No recipes found");
		return NULL;

	} else {

		PRNODE currNode = thisRecipeList->list;

		while (currNode != NULL) {

			if (compareRecipeID(*getRecipeData(currNode), recipeOption - 1)) {
				return getRecipeData(currNode);
			}
			currNode = getNextRecipeNode(currNode);
		}
		return NULL;
	}
}

bool checkRecipeExists(PRLIST thisRecipeList, int recipeOption) {

	if (thisRecipeList->list == NULL) {

		printf("Err: No recipes found");
		return false;;

	} else {

		PRNODE currNode = thisRecipeList->list;

		while (currNode != NULL) {

			if (compareRecipeID(*getRecipeData(currNode), recipeOption - 1)) {
				return true;
			}
			currNode = getNextRecipeNode(currNode);
		}
		return false;
	}
}

bool displayRecipe(PRLIST thisRecipeList, int recipeOption) {

	if (thisRecipeList->list == NULL) {

		printf("Err: No recipes found");
		return false;

	} else {

		PRNODE currNode = thisRecipeList->list;

		while (currNode != NULL) {

			if (compareRecipeID(*getRecipeData(currNode), recipeOption - 1)) {
				char* currRecipeName = getRecipeName(*getRecipeData(currNode));
				printf("\n%s:\n", currRecipeName);
				displayIngredients(getIngredientList(getRecipeData(currNode)));
				return true;
			}
			currNode = getNextRecipeNode(currNode);
		}
	}
}

int getLastRecipeID(PRLIST thisRecipeList) {

	if (thisRecipeList->list == NULL) {

		printf("Err: No recipes found");
		return;

	} else {

		PRNODE currNode = thisRecipeList->list;
		int currRecipeID;
		while (currNode != NULL) {

			currRecipeID = getRecipeID(*getRecipeData(currNode));
			currNode = getNextRecipeNode(currNode);
		}
		return currRecipeID;
	}
}