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
	//if ingredient list is empty
	if (thisIngredientList->list == NULL) {
		setNextIngredientNode(newNode, thisIngredientList->list);
		thisIngredientList->list = newNode;
	} else {
		PINODE currNode = thisIngredientList->list;
		//find the last node
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
		
		while (currNode != NULL) {
			char* currIngredientName = getIngredientName(getIngredientData(currNode));
			float currIngredientQuantity = getIngredientQuantity(getIngredientData(currNode));
			char* currIngredientMeasurement = getIngredientMeasurement(getIngredientData(currNode));

			char biggestIngredientName[MAX_NAME] = { "" };
			int biggestIngredientSize = 0;
			while (tempNode != NULL) {
				char* tempIngredientName = getIngredientName(getIngredientData(tempNode));
				if (getNextIngredientNode(tempNode) != NULL) {
					char* tempNextIngredientName = getIngredientName(getIngredientData(getNextIngredientNode(tempNode)));

					if (strlen(biggestIngredientName) < strlen(tempIngredientName)) {
						strcpy(biggestIngredientName, tempIngredientName);
						biggestIngredientSize = strlen(biggestIngredientName);

					} else if (strlen(biggestIngredientName) < strlen(tempNextIngredientName)) {
						strcpy(biggestIngredientName, tempNextIngredientName);
						biggestIngredientSize = strlen(biggestIngredientName);
					}
				}
				tempNode = getNextIngredientNode(tempNode);
			}
			int currIngredientNameSize = strlen(currIngredientName);
			while (currIngredientNameSize < biggestIngredientSize) {
				strcat(currIngredientName, " ");
				currIngredientNameSize++;
			}
			printf("\t%s\t%0.2f\t%s\n", currIngredientName, currIngredientQuantity, currIngredientMeasurement);
			
			currNode = getNextIngredientNode(currNode);
			tempNode = thisIngredientList->list;
		}
		return true;
	}
	return false;
}