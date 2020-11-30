#define _CRT_SECURE_NO_WARNINGS
#define NUM_OF_MEASUREMENTS 9

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


	char* measurement[NUM_OF_MEASUREMENTS] = { "Tbps", "Tsp", "ml", "L", "Cups","oz", "lbs", "ToTaste", "ToSight" };

	for (int i = 0; i < NUM_OF_MEASUREMENTS; i++) {
		
		if (strcmp(measurement[i], recipeMeasurement) == 0) {
			return true;
		} else {
			return false;
		}
		
	}
}