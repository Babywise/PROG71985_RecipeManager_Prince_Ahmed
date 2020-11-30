#pragma once
#include "IngredientNode.h"
#include <stdbool.h>

typedef struct ingredientADT {

	PINODE list;

}ILIST, *PILIST;

ILIST createIngredientList();
bool addIngredientToList(PILIST, INGREDIENT);