#define _CRT_SECURE_NO_WARNINGS
#include "IngredientADT.h"
#include "Recipe.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ILIST createIngredientList() {
	ILIST newList = { 0 };
	return newList;
}

bool addIngredientToList(PILIST thisIngredientList, INGREDIENT thisIngredient) {

	PINODE newNode = createIngredientNode(thisIngredient);

	if (!newNode) {
		return false;
	}
	//if list is empty
	if (thisIngredientList->list == NULL) {
		setNextIngredientNode(newNode, thisIngredientList->list);
		thisIngredientList->list = newNode;
	} else {

		PINODE currNode = thisIngredientList->list;

		while (getNextIngredientNode(currNode) != NULL) {
			currNode = getNextIngredientNode(currNode);
		}

		setNextIngredientNode(currNode, newNode);

	}

	return true;

}

bool displayIngredients(PILIST thisIngredientList) {

	if (thisIngredientList->list == NULL) {

		printf("Err: No ingredients found");
		return false;;

	} else {

		PINODE currNode = thisIngredientList->list;
		PINODE tempNode = thisIngredientList->list;

		char* currIngredientName = "";
		float currIngredientQuantity = 0.0f;
		char* currIngredientMeasurement = "";

		char* tempIngredientName = "";
		int tempIngredientNameSize = 0;
		
		while (currNode != NULL) { 

			char* currIngredientName = getIngredientName(getIngredientData(currNode));
			float currIngredientQuantity = getIngredientQuantity(getIngredientData(currNode));
			char* currIngredientMeasurement = getIngredientMeasurement(getIngredientData(currNode));

			printf("\t%s\t%0.2f\t%s\n", currIngredientName, currIngredientQuantity, currIngredientMeasurement);
			
			currNode = getNextIngredientNode(currNode);

		}

		return true;

	}
	return false;
}