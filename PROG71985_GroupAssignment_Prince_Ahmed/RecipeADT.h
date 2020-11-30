#pragma once
#include "RecipeNode.h"

#include <stdbool.h>

typedef struct RecipeADT {

	PRNODE list;

}RLIST, *PRLIST;

RLIST createRecipeList();
bool addRecipeToList(PRLIST, RECIPE);
bool removeRecipeFromList(PRLIST, RECIPE);