#define _CRT_SECURE_NO_WARNINGS


#include "Ingredient.h"

#include <string.h>
#include <stdlib.h>
INGREDIENT createIngredient(int id, char* ingredientName, float quantity, char* measurement) {
	
	INGREDIENT ingredient;
	ingredient.id = id;
	strcpy(ingredient.name, ingredientName);
	ingredient.quantity = quantity;
	strcpy(ingredient.measurement, measurement);
	
	return ingredient;

}

bool compareMeasurement(char* recipeMeasurement) {

	char* measurementArrForRead[NUM_OF_MEASUREMENTS_FOR_READ] = { "Tbps", "Tsp", "ml", "L", "Cups","oz", "lbs", "ToTaste", "ToSight", "Cans" }; 

	for (int i = 0; i < NUM_OF_MEASUREMENTS_FOR_READ; i++) {
		
		if (strcmp(measurementArrForRead[i], recipeMeasurement) == 0) {
			return true;
		} else {
			return false;
		}
		
	}
}

char* getIngredientName(INGREDIENT ingredient) {
	return ingredient.name;
}
float getIngredientQuantity(INGREDIENT ingredient) {
	return ingredient.quantity;
}
char* getIngredientMeasurement(INGREDIENT ingredient) {
	return ingredient.measurement;
}