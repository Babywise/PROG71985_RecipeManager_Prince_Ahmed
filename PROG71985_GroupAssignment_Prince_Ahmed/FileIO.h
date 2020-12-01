#pragma once
#include "RecipeADT.h"

RLIST readRecipeList();
RECIPE readRecipe(RLIST, char*, int);
void deleteRecipeTextFile(PRLIST, int);