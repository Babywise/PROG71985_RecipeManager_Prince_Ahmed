#pragma once
#define NUM_ITEMS_IN_INGREDIENT 4 
#define MAX_INGREDIENTS 100
#define MAX_NAME 50
#define NUM_OF_MEASUREMENTS_FOR_READ 10
#include <stdbool.h>
typedef struct ingredient {

	int id;
	char name[MAX_NAME];
	float quantity;
	char measurement[MAX_NAME];

}INGREDIENT, *PINGREDIENT;

INGREDIENT createIngredient(int, char*, float, char*);
bool compareMeasurement(char*);
char* getIngredientName(INGREDIENT ingredient);
float getIngredientQuantity(INGREDIENT ingredient);
char* getIngredientMeasurement(INGREDIENT ingredient);