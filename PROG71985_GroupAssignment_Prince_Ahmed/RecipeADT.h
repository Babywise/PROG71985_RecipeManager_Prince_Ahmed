#pragma once
#include "RecipeNode.h"

#include <stdbool.h>

typedef struct RecipeADT {

	PRNODE list;

}RLIST, *PRLIST;

RLIST createRecipeList();
bool addRecipeToList(PRLIST, RECIPE);
bool removeRecipeFromList(PRLIST, int);
void getRecipeListFromADT(PRLIST);
PRECIPE getRecipeFromRecipeList(PRLIST, int);
bool checkRecipeExists(PRLIST, int);
bool displayRecipe(PRLIST, int);
int getLastRecipeID(PRLIST);