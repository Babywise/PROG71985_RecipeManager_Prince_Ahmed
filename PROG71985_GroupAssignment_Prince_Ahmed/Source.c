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
 *			2020/11/16 - Fixed Login.c
 *					   - Cleaned up the console
 *
 */

#include <stdio.h>
#include "Input.h"
#include "Login.h"
#include "User.h"


int main(void) {

	USER* userArray = getUsersFromFile();

	displayLogo();
	displayFunctions();
	getUserOption(userArray);

	return 0;
}