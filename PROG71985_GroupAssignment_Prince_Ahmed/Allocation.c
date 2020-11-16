#include "Allocation.h"
#include <stdlib.h>

char* allocateCharArray() {

	char* str;
	str = (char*)malloc(MAX_NAME_LENGTH);
	memset(str, 0, MAX_NAME_LENGTH);

	return str;

}

char* reallocateCharArray(char* str, int size) {

	str = (char*)realloc(str, size * sizeof(char*));

	return str;

}