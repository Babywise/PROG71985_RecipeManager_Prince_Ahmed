#pragma once
#include "Recipe.h"

typedef struct recipenode {

	RECIPE recipeData;
	struct recipenode* next;

}RNODE, *PRNODE;

PRNODE createRecipeNode(RECIPE);
PRNODE getNextRecipeNode(PRNODE);
void setNextRecipeNode(PRNODE, PRNODE);
RECIPE getRecipeData(PRNODE);
void removeRecipeNode(PRNODE);