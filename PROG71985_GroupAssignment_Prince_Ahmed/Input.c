#define _CRT_SECURE_NO_WARNINGS
#include "Allocation.h"
#include "User.h"
#include "Input.h"
#include "Login.h"

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>


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

void displayFunctions() {

    printf("Welcome to the recipe manager, please select one of the options:\n\n"
			"a) Login to your account\n"
			"b) Create an account\n"
			"c) View public recipies\n"
			"d) exit\n");

}

void getUserOption(USER* userArray) {

	char* userOption = allocateCharArray();

	bool validOption = false;

	do {

		fgets(userOption, MAX_NAME_LENGTH, stdin);
		userOption = reallocateCharArray(userOption, strlen(userOption));
		char userOptionRemoved = userOption[0];
		userOptionRemoved = toupper(userOptionRemoved);

		int sizeOfInput = 0;
		//counts size of input from user
		for (int i = 0; i < strlen(userOption); i++) {
			if (userOptionRemoved == '\n') {
				userOptionRemoved = NULL;
			} else if (i > MAX_ACCEPTABLE_INPUT) {
				userOptionRemoved = NULL;
			}
		}

		switch (userOptionRemoved) {
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
			//function
			break;

		case 'D':
			validOption = true;
			exit(EXIT_SUCCESS);
			break;

		default:
			printf("Please enter a valid option: ");
			validOption = false;
			break;
		}

	} while (!validOption);

	free(userOption);
}


void getLoginFromUser(USER* userArray) {

	char* username = allocateCharArray();
	char* password = allocateCharArray();
	bool validationCheck = false;

	printf("Please enter your username: ");
	fgets(username, MAX_NAME_LENGTH, stdin);
	strtok(username, "\n");

	printf("Please enter your password: ");
	fgets(password, MAX_NAME_LENGTH, stdin);
	strtok(password, "\n");

	reallocateCharArray(username, strlen(username));
	reallocateCharArray(password, strlen(password));

	validationCheck = checkCreds(username, password, userArray);

	if (validationCheck){

		printf("Credentials Accepted - Logging in...\n");

	} else {

		printf("Incorrect Credentials - Failed to log in\n");
		free(username);
		free(password);
		fflush(stdin);
		getLoginFromUser(userArray);

	}

}