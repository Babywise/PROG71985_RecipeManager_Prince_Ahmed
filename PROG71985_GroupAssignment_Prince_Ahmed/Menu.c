#include "Menu.h"
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

void displayAccountFunctions() {

	printf("Welcome to the recipe manager, please select one of the options:\n\n"
		"a) Login to your account\n"
		"b) Create an account\n"
		"c) exit\n");
		
}

void displayRecipeFunctions() {
	
	printf("Choose a function:\n\n");
	printf("a) Display a single recipe\n"
			"b) Display a range of recipes\n"
			"c) Display all recipes (prepare for operation rape eyes)\n"
			"\n"
			"d) Create a new recipe\n"
			"e) Edit an exisiting recipe\n"
			"f) Delete an exisiting recipe\n"
			"\n"
			"g) Search for an existing recipe\n"
			"h) Sort existing recipes (????????)\n"
			"\n"
			"i) Quit\n");

}