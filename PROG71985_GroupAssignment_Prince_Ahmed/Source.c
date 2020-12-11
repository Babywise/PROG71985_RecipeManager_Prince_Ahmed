/* Written By:
 * 
 *    Name:		Nick Prince
 *    Email:	nprince3037@conestogac.on.ca
 *    Course:	PROG71985 - Fall2020
 * 
 *    Name:		Islam Ahmed
 *    Email:	Iahmed9886@conestogac.on.ca
 *    Course:	PROG71985 - Fall2020
 * 
 *
 *    Date Started:		2020/11/10
 *    Date Completed:	2020/12
 *
 *	  Program Description:
 * 
 * 
 *	  Usernames/Passwords:
 * 
 *			Nick/Prince
 *			Islam/Ahmed
 *			Admin/Admin
 *
 *    Revision History:		
	
			Nov 10 - Created Empty VS Solution
				   - Created Starting .c and .h Files
						
			Nov 15 - Logo and Display, Get Users from File, Allocation Functions and Login Functions

			Nov 16 - Fixed login (checkCreds) function

			Nov 29 - Fixed Login... Again
				   - Guess what.... Login is now actually fixed :)

			Nov 30 - Fixed Double Linked Lists and remove Recipe works partially, remove works but when function returns to call position, Recipe list is corrupted
				   - Fixed list corruption and cleaned up Reading in FileIO.c

			Dec 01 - Added Menu Options: display single recipe, remove recipe file
				   - Fixed Ingredient Formating, Updated Menu decription, removed commented lines that weren't in use

			Dec 02 - Removed comments that werent in use and updated menu description
				   - Changed how menu is display: do while in main, so menu can be displayed again to the user, this way program ends in main if everything is successful
				   - Changed getRecipeFromRecipeList to a pointer so it works for editing as well as deleting
				   - Removed and moved unnecessary/redunant return statements
				   - Fixed Errors with File.io when a recipe exists in the RecipeList.txt but the actually recipe is missing from the sub-directory
				   - Removed Dirent.h, removed comments in recipeMenuOptions, Changed formating for invalid option (Case: Default)
				   - Changed invalid readRecipe return value to NULL

			Dec 07 - Added Write to Files, fixed some id inconsistencies, Delete head recipe fixed, Added ask user if they want to display menu again
				   - Added Create and edit recipes, error checking needed, moved toupper from getUserInput to getMenuInput

			Dec 09 - Fixed display menu bug after quit is selected (if statement in main)
						
			Dec 10 - Made createAccount() & writeUserToFile()
				   -
						

 */

#include "Input.h"
#include "Login.h"
#include "User.h"
#include "Menu.h"
#include "FileIO.h"


#include <stdio.h>
#include <stdbool.h>

int main(void) {
	USER* userArray = getUsersFromFile();
	RLIST recipeList = readRecipeList();
	displayLogo();

	displayAccountFunctions();
	getAccountOption(userArray);

	bool yesNo = true;
	do {

		displayRecipeFunctions();
		yesNo = getRecipeMenuOption(&recipeList);
		recipeList = readRecipeList();

		if (yesNo) {
			yesNo = yesNoShowMenuAgain();
		}

	} while(yesNo);

	return 0;

}