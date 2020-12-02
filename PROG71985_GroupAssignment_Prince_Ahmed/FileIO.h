#pragma once
#include "RecipeADT.h"

RLIST readRecipeList();
PRECIPE readRecipe(RLIST, char*, int);
void deleteRecipeTextFile(PRLIST, int);