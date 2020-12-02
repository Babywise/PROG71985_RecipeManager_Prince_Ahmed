#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <stdio.h>
#include <string.h>

void displayLogo() {

	int backslash = 92;

	printf("                 .##########.\n"
		"      ########/###          ###/########\n"
		"   ###(       #,              .#       (###\n"
		"  ##.                                     ##		__________________   __________________\n"
		" (##                                      ###      .-/|                  %c /                  |%c-.\n"
		"  ##                                      ##       ||||                   |                   ||||\n"
		"   ##                                    ##.       ||||                   |                   ||||\n"
		"     ###(                            /###.         ||||                   |       ~~*~~       ||||\n"
		"     ##(                            /##            ||||    --==*==--      |                   ||||\n"
		"     ##(                            /##            ||||                   |                   ||||\n"
		"     ##(                            /##            ||||     Recipe        |                   ||||\n"
		"     ##################################            ||||     Manager       |     --==*==--     ||||\n"
		"     #############/####################            ||||                   |                   ||||\n"
		"      ##########...........##########              ||||    By: Nick  &    |                   ||||\n"
		"     ######...  0 ....... 0 ....######             ||||        Islam      |                   ||||\n"
		"     ##.............................##             ||||                   |                   ||||\n"
		"     %c##...##..................##...##             ||||__________________ | __________________||||\n"
		"      ##..,# #...##########..# #*..##              ||/===================%c|/===================%c||\n"
		"        ###.,# ######  ###### #*.###               `--------------------~___~-------------------''\n"
		"           ####               ####\n"
		"              .##############,\n\n", backslash, backslash, backslash, backslash, backslash);

	printf("---------------------------------------------------------------------------------------------------------\n\n");

	
}

void displayAccountFunctions() {

	printf("Welcome to the recipe manager, please select one of the options:\n\n"
		"a) Login to your account\n"
		"b) Create an account\n"
		"c) exit\n");
		
}

void getAccountOption(USER* userArray) {

	char* userOption;
	bool validOption = false;

	do {

		char* userOption = getMenuInput();
		char* userOptionRemoved = checkInputSize(userOption);

		int sizeOfInput = 0;
		//counts size of input from user
		for (int i = 0; i < strlen(userOption); i++) {
			if (userOptionRemoved == '\n') {
				userOptionRemoved = NULL;
			} else if (i > MAX_ACCEPTABLE_INPUT) {
				userOptionRemoved = NULL;
			}
		}

		switch (*userOptionRemoved) {
		case 'A':
			validOption = true;
			getLoginFromUser(userArray);
			break;

		case 'B':
			validOption = true;
			//function
			break;

		case 'C':
			validOption = true;
			exit(EXIT_SUCCESS);
			break;

		default:
			printf("Please enter a valid option: ");
			validOption = false;
			break;
		}

		free(userOption);

	} while (!validOption);

}

void displayRecipeFunctions() {
	
	printf("\nRecipe functions:\n\n");
	printf("a) Display a single recipe\n"
			"b) Display a range of recipes\n"
			"c) Display all recipes\n"
			"\n"
			"d) Create a new recipe\n"
			"e) Edit an exisiting recipe\n"
			"f) Delete an exisiting recipe\n"
			"\n"
			"g) Search for an existing recipe\n"
			"h) Sort existing recipes (????????)\n"
			"\n"
			"i) Quit\n\n");
	printf("Choose a function: ");

}

bool getRecipeMenuOption(PRLIST recipeList) {

	//char* userOption;
	//bool validOption = false;

	//do {

		char* userOption = getMenuInput();
		char* userOptionRemoved = checkInputSize(userOption);
		
		int sizeOfInput = 0;
		// counts size of input from user
		for (int i = 0; i < strlen(userOption); i++) {
			if (userOptionRemoved == '\n') {
				userOptionRemoved = NULL;
			} else if (i > MAX_ACCEPTABLE_INPUT) {
				userOptionRemoved = NULL;
			}
		}
		int recipeOption = 1;
		switch (*userOptionRemoved) {
		case 'A':
			//validOption = true;
			displayRecipeList(recipeList);
			printf("\nPlease select a recipe ID: ");
			recipeOption = getRecipeIDInput();

			if (!displayRecipe(recipeList, recipeOption)) {
				printf("\nThis recipe doesn't exist\n");
			}
			//break;
			free(userOption);
			return true;

		case 'B':
			//validOption = true;
			displayRecipeList(recipeList);
			printf("\nPlease select the first recipe ID: ");
			int recipeOption1 = getRecipeIDInput();
			printf("Please select the second recipe ID: ");
			int recipeOption2 = getRecipeIDInput();

			for (recipeOption1; recipeOption1 <= recipeOption2; recipeOption1++) {
				if (!displayRecipe(recipeList, recipeOption1)) {
					break;
				}
			}
			//break;
			free(userOption);
			return true;

		case 'C':
			//validOption = true;
			do {
				if (!displayRecipe(recipeList, recipeOption)) {
					break;
				}
				recipeOption++;
			} while (true);
			//break;
			free(userOption);
			return true;

		case 'D':
			//validOption = true;
			//createNewRecipe
			//break;
			//free(recipeOption);
			free(userOption);
			return true;
		case 'E':
			//validOption = true;
			displayRecipeList(recipeList);
			printf("\nPlease select an ID to edit a recipe: ");
			recipeOption = getRecipeIDInput();



			//editRecipe
			//break;
			free(userOption);
			return true;

		case 'F':
			//validOption = true;
			displayRecipeList(recipeList);
			printf("\nPlease select an ID to delete a recipe: ");
			recipeOption = getRecipeIDInput();

			if (checkRecipeExists(recipeList, recipeOption)) {
				deleteRecipeTextFile(recipeList, recipeOption);
				removeRecipeFromList(recipeList, recipeOption);
			} else {
				printf("\nThis recipe doesn't exist\n");
			}
			//break;
			free(userOption);
			return true;

		case 'G':
			//validOption = true;
			//searchRecipe
			//break;
			free(userOption);
			return true;

		case 'H':
			//validOption = true;
			//sortRecipe
			//break;
			free(userOption);
			return true;

		case 'I':
			//validOption = true;
			//exit(EXIT_SUCCESS);
			//break;
			free(userOption);
			return false;

		default:
			printf("\nPlease enter a valid option: ");
			//validOption = false;
			//break;
			free(userOption);
			return true;
		}

		//free(userOption);

	//} while (!validOption);

}


void displayRecipeList(PRLIST recipeList) {

	printf("\nRecipe list: \n\n");
	getRecipeListFromADT(recipeList);

}
