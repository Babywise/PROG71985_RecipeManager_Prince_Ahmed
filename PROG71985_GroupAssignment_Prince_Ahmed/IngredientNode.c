#include "IngredientNode.h"

#include <stdio.h>
#include <stdlib.h>


PINODE createIngredientNode(INGREDIENT ingredient) {

	PINODE newNode = (PINODE)malloc(sizeof(INODE));

	if (!newNode) {

		fprintf(stderr, "error allocating memory\n");
		return (PINODE)NULL;
	}

	newNode->ingredientData = ingredient;
	newNode->next = NULL;

	return newNode;

}

PINODE getNextIngredientNode(PINODE ingredientNode) {

	return ingredientNode->next;

}

void setNextIngredientNode(PINODE sourceIngredientNode, PINODE newNextIngredientNode) {

	sourceIngredientNode->next = newNextIngredientNode;

}

void removeIngredientNode(PINODE ingredientNode) {

	free(ingredientNode);

}