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
 *    Date Started:		2020/11/15
 *    Date Completed:	2020/
 *
 *	  Program Description:	
 *
 *			
 *
 *    Revision History:
 *
 *			2020/11/15 - Started Main (Source.c)
 *					   - Started User.c/.h
 *					   - Started Login.c/.h
 *					   - Started Input.c/.h
 *					   - Started Allocation.c/.h
 * 
 *			2020/11/16 - Fixed Login.c (was previously only checking the first user's credentials).
 *					   - Cleaned up the console.
 *
 */

#include "Input.h"
#include "Login.h"
#include "User.h"
#include "Menu.h"
#include "FileIO.h"


#include <stdio.h>

int main(void) {
	//USER* userArray = getUsersFromFile();
	//RECIPE p = createRecipe("SoyGingerGlaze");
	PRLIST recipeList = readRecipeList();
	displayLogo();
	//displayAccountFunctions();
	//getAccountOption(userArray);
	
	//read
	displayRecipeFunctions();
	getRecipeMenuOption();

	

	return 0;
}