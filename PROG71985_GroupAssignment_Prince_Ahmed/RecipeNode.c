#include "RecipeNode.h"

#include <stdio.h>
#include <stdlib.h>


PRNODE createRecipeNode(RECIPE recipe) {

	PRNODE newNode = (PRNODE)malloc(sizeof(RNODE));

	if (!newNode) {

		fprintf(stderr, "error allocating memory\n");
		return (PRNODE)NULL;
	}

	newNode->recipeData = recipe;
	newNode->next = NULL;

	return newNode;

}

PRNODE getNextRecipeNode(PRNODE recipeNode) {

	return recipeNode->next;

}

void setNextRecipeNode(PRNODE sourceRecipeNode, PRNODE newNextRecipeNode) {

	sourceRecipeNode->next = newNextRecipeNode;

}

RECIPE getRecipeData(PRNODE recipeNode) {

	return recipeNode->recipeData;

}

void removeRecipeNode(PRNODE recipeNode) {

	free(recipeNode);

}