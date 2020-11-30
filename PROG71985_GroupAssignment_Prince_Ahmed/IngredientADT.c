#include "IngredientADT.h"
#include "Recipe.h"

#include <stdlib.h>

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