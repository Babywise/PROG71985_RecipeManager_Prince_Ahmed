#pragma once
#include "Ingredient.h"

typedef struct ingredientnode {

	INGREDIENT ingredientData;
	struct ingredientnode* next;

}INODE, *PINODE;

PINODE createIngredientNode(INGREDIENT);
PINODE getNextIngredientNode(PINODE);
void setNextIngredientNode(PINODE, PINODE);
void removeIngredientNode(PINODE);